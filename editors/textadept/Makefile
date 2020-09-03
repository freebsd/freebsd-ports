# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	textadept
DISTVERSION=	11.0_alpha_3
CATEGORIES=	editors
MASTER_SITES=	http://foicica.com/hg/textadept/archive/ \
		http://foicica.com/hg/scintilla/archive/:sci \
		http://www.lua.org/ftp/:lua \
		http://www.inf.puc-rio.br/~roberto/lpeg/:lpeg \
		http://foicica.com/hg/gtdialog/archive/:gtd
DISTFILES=	${TA_HASH}.zip ${SCI_HASH}.zip:sci \
		lua-${LUA_VER}.tar.gz:lua \
		lpeg-${LPEG_VER}.tar.gz:lpeg ${GTD_HASH}.zip:gtd
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast, minimalist, extensible cross-platform text editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang desktop-file-utils gmake gnome iconv \
		pkgconfig
USE_GNOME=	cairo gdkpixbuf2 glib20

USE_GITHUB=	nodefault
GH_ACCOUNT=	keplerproject:lfs
GH_PROJECT=	luafilesystem:lfs
GH_TAGNAME=	v${LFS_VER}:lfs

TA_HASH=	f7fbf78f9219
SCI_HASH=	d1b254905c74
LUA_VER=	5.3.5
LPEG_VER=	1.0.2
LFS_VER=	1_7_0_2
GTD_HASH=	680b3b41e12c

WRKSRC=		${WRKDIR}/${PORTNAME}-${TA_HASH}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

GTK2_USE=	GNOME=gtk20
GTK3_USE=	GNOME=gtk30
GTK3_MAKE_ARGS=	GTK3=yes

post-patch:
	${LN} -s ${WRKDIR}/scintilla-${SCI_HASH} ${BUILD_WRKSRC}/scintilla
	${PATCH} -d ${BUILD_WRKSRC}/scintilla -N -p1 < \
		${BUILD_WRKSRC}/scintilla.patch
	${LN} -s ${WRKDIR}/lua-${LUA_VER} ${BUILD_WRKSRC}/lua
	${PATCH} -d ${BUILD_WRKSRC}/lua -N -p1 < \
		${BUILD_WRKSRC}/lua.patch
	@${MKDIR} ${BUILD_WRKSRC}/lua/src/lib
	${LN} -s ${WRKDIR}/lpeg-${LPEG_VER}/*.[ch] ${BUILD_WRKSRC}/lua/src/lib
	${LN} -s ${WRKDIR}/luafilesystem-${LFS_VER}/src/*.[ch] \
		${BUILD_WRKSRC}/lua/src/lib
	${LN} -s ${WRKDIR}/gtdialog-${GTD_HASH} ${BUILD_WRKSRC}/gtdialog
	@${RM} ${WRKSRC}/core/.*.luadoc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
