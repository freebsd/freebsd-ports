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
SCINTERM_HASH=	6a77415
LUA_VER=	5.3.5
LPEG_VER=	1.0.2
LFS_VER=	1_8_0
GTD_HASH=	6458754
CDK_VER=	5.0-20200923
TERMKEY_VER=	0.20

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ARGS=	TA_TARGETS="${_TARGETS}"

OPTIONS_DEFINE=		DOCS NCURSES
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2 NCURSES
OPTIONS_SUB=		yes

UI_DESC=	GTK version
GTK2_USE=	GNOME=gtk20
GTK3_USE=	GNOME=gtk30
GTK3_MAKE_ARGS=	GTK3=yes
_TARGETS=	gtk

# HTML files require patched https://keplerproject.github.io/luadoc/ to
# build, which is also seemingly deprecated upstream, so just grab them
# from the textadept package for GNU/Linux.
DOCS_MASTER_SITES=	https://github.com/orbitalquark/${PORTNAME}/releases/download/${PORTNAME}_${PORTVERSION}/:docs
DOCS_DISTFILES=		${PORTNAME}_${PORTVERSION}.linux.tgz:docs

NCURSES_MASTER_SITES=	https://invisible-mirror.net/archives/cdk/:cdk \
			http://www.leonerd.org.uk/code/libtermkey/:tk
NCURSES_DISTFILES=	cdk-${CDK_VER}.tgz:cdk \
			libtermkey-${TERMKEY_VER}.tar.gz:tk
NCURSES_GH_PROJECT=	scinterm:scitrm
NCURSES_GH_TAGNAME=	${SCINTERM_HASH}:scitrm
NCURSES_VARS=		_TARGETS+=curses

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

post-patch-NCURSES-on:
	@${MKDIR} ${BUILD_WRKSRC}/scintilla/curses
	${LN} -s ${WRKSRC_scitrm}/*.cxx ${WRKSRC_scitrm}/*.h \
		${BUILD_WRKSRC}/scintilla/curses
	@${MKDIR} ${BUILD_WRKSRC}/cdk
	${LN} -s ${WRKDIR}/cdk-${CDK_VER}/include/*.h \
		${WRKDIR}/cdk-${CDK_VER}/*.c ${BUILD_WRKSRC}/cdk
.for ext in h c
	cd ${BUILD_WRKSRC}/cdk && ${SH} \
		${WRKDIR}/cdk-${CDK_VER}/gen-scale.sh SLIDER Slider \
		Int int gen-slider.${ext} > slider.${ext}
.endfor
	${PATCH} -d ${BUILD_WRKSRC}/cdk -N -p1 < ${BUILD_WRKSRC}/cdk.patch
	@${MKDIR} ${BUILD_WRKSRC}/termkey
	${LN} -s ${WRKDIR}/libtermkey-${TERMKEY_VER}/*.[ch] \
		${BUILD_WRKSRC}/termkey
	${PATCH} -d ${BUILD_WRKSRC}/termkey -N -p1 < \
		${BUILD_WRKSRC}/termkey.patch

post-install-DOCS-on:
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}_${PORTVERSION}.linux/docs/*.html \
		${STAGEDIR}${DATADIR}/docs
	${MV} ${STAGEDIR}${DATADIR}/docs ${STAGEDIR}${DOCSDIR}
	${LN} -sf ../../${DOCSDIR_REL} ${STAGEDIR}${DATADIR}/docs

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DATADIR}/docs

.include <bsd.port.mk>
