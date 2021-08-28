# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	textadept
PORTVERSION=	11.1
DISTVERSIONPREFIX=	${PORTNAME}_
CATEGORIES=	editors
MASTER_SITES=	https://www.scintilla.org/:sci \
		http://www.lua.org/ftp/:lua \
		http://www.inf.puc-rio.br/~roberto/lpeg/:lpeg
DISTFILES=	scintilla${SCI_VER}.tgz:sci \
		lua-${LUA_VER}.tar.gz:lua \
		lpeg-${LPEG_VER}.tar.gz:lpeg
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, minimalist, extensible cross-platform text editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang desktop-file-utils gmake gnome iconv \
		pkgconfig
USE_CXXSTD=	c++17
USE_GNOME=	cairo gdkpixbuf2 glib20

USE_GITHUB=	yes
GH_ACCOUNT=	orbitalquark keplerproject:lfs
GH_PROJECT=	scintillua:scilua luafilesystem:lfs gtdialog:gtd
GH_TAGNAME=	scintillua_${SCILUA_VER}:scilua v${LFS_VER}:lfs \
		${GTD_HASH}:gtd

SCI_VER=	446
SCILUA_VER=	4.4.5-2
LUA_VER=	5.3.5
LPEG_VER=	1.0.2
LFS_VER=	1_8_0
GTD_HASH=	6458754

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

UI_DESC=	GTK version
GTK2_USE=	GNOME=gtk20
GTK3_USE=	GNOME=gtk30
GTK3_MAKE_ARGS=	GTK3=yes

# HTML files require patched https://keplerproject.github.io/luadoc/ to
# build, which is also seemingly deprecated upstream, so just grab them
# from the textadept package for GNU/Linux.
DOCS_MASTER_SITES=	https://github.com/orbitalquark/${PORTNAME}/releases/download/${PORTNAME}_${PORTVERSION}/:docs
DOCS_DISTFILES=		${PORTNAME}_${PORTVERSION}.linux.tgz:docs

post-patch:
	${LN} -s ${WRKDIR}/scintilla ${BUILD_WRKSRC}
	${PATCH} -d ${BUILD_WRKSRC}/scintilla -N -p1 < \
		${BUILD_WRKSRC}/scintilla.patch
	${LN} -s ${WRKDIR}/lua-${LUA_VER} ${BUILD_WRKSRC}/lua
	${PATCH} -d ${BUILD_WRKSRC}/lua -N -p1 < \
		${BUILD_WRKSRC}/lua.patch
	${LN} -s ${WRKSRC_scilua}/*.cxx ${WRKSRC_scilua}/*.h \
		${BUILD_WRKSRC}
	${LN} -s ${WRKSRC_scilua}/lexers ${BUILD_WRKSRC}/..
	${RM} -r ${WRKSRC_scilua}/lexers/themes
	@${MKDIR} ${BUILD_WRKSRC}/lua/src/lib
	${LN} -s ${WRKDIR}/lpeg-${LPEG_VER}/*.[ch] ${BUILD_WRKSRC}/lua/src/lib
	${LN} -s ${WRKDIR}/luafilesystem-${LFS_VER}/src/*.[ch] \
		${BUILD_WRKSRC}/lua/src/lib
	${LN} -s ${WRKDIR}/gtdialog-${GTD_HASH} ${BUILD_WRKSRC}/gtdialog
# Fix build with glib 2.68.3: see https://github.com/orbitalquark/textadept/issues/110
	${REINPLACE_CMD} -e '/static volatile/s|volatile||g' \
		${BUILD_WRKSRC}/scintilla/gtk/ScintillaGTKAccessible.cxx

post-install-DOCS-on:
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}_${PORTVERSION}.linux/docs/*.html \
		${STAGEDIR}${DATADIR}/docs
	${MV} ${STAGEDIR}${DATADIR}/docs ${STAGEDIR}${DOCSDIR}
	${LN} -sf ../../${DOCSDIR_REL} ${STAGEDIR}${DATADIR}/docs

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DATADIR}/docs

.include <bsd.port.mk>
