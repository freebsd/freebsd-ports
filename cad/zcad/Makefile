# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zcad
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	LOCAL/danfe
DISTNAME=	${PORTNAME}-trunk-r2259

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple CAD program

BUILD_DEPENDS=	lazbuild:editors/lazarus

USES=		tar:xz
USE_FPC=	cairo chm fcl-base fcl-image fcl-json fcl-stl fcl-xml opengl \
		pasjpeg rtl-extra rtl-objpas x11

LAZARUS_VER=	1.8.0
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d --pcp=${WRKSRC}/tmppcp \
		--lazarusdir=${LAZARUS_DIR}
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}
LCL_UNITS_DIR=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}

EXTRACT_CMD=	LC_ALL=en_US.UTF-8 ${TAR}	# for non-ASCII filenames

MAKE_ENV=	LAZBUILD_CMD="${LAZBUILD_CMD}"

WRKSRC=		${WRKDIR}/trunk
BUILD_WRKSRC=	${WRKSRC}/cad_source
INSTALL_WRKSRC=	${WRKSRC}/cad

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	UserGuide.odt UserGuide.pdf

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	GTK2

GTK2_BUILD_DEPENDS=	${LCL_UNITS_DIR}/gtk2/interfaces.ppu:editors/lazarus-lcl-gtk2
GTK2_USE=		GNOME=gtk20 FPC=gtk2
GTK2_MAKE_ENV=		GUI=gtk2
GTK2_VARS=		LAZBUILD_CMD+=--ws=gtk2

QT4_BUILD_DEPENDS=	${LCL_UNITS_DIR}/qt/interfaces.ppu:editors/lazarus-lcl-qt
QT4_LIB_DEPENDS=	libQt4Pas.so:x11-toolkits/qt4pas
QT4_MAKE_ENV=		GUI=qt
QT4_VARS=		LAZBUILD_CMD+=--ws=qt

post-patch:
	@${EGREP} -lR 'IFN?DEF LINUX' ${BUILD_WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E '/IFN?DEF LINUX/s,LINUX,UNIX,g'
	@${REINPLACE_CMD} -e '/}Linux{/d' \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VStream.pas \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VFStream.pas \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VFileSys.pas \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VStrm64.pas
	${CP} ${FILESDIR}/makefile ${BUILD_WRKSRC}/Makefile

pre-build:
# OpenGL component must be fixed and rebuilt locally (to avoid touching
# filesystem outside working directory)
	${SED} -e 's,Linux,${OPSYS},' \
		${LAZARUS_DIR}/components/opengl/openglcontext.pas \
		> ${BUILD_WRKSRC}/openglcontext.pas
	${CP} ${LAZARUS_DIR}/components/opengl/glgtkglxcontext.pas \
		${LAZARUS_DIR}/components/opengl/glqtcontext.pas \
		${LAZARUS_DIR}/components/opengl/openglcontext.res \
		${BUILD_WRKSRC}
# Build components that do not come with precompiled *.ppu files (also
# copy them locally first for the same reason as above)
	${CP} -a  ${LAZARUS_DIR}/components/fpvectorial \
		${LAZARUS_DIR}/components/anchordocking ${WRKSRC}
	${LAZBUILD_CMD} ${WRKSRC}/fpvectorial/fpvectorialpkg.lpk
	${LAZBUILD_CMD} ${WRKSRC}/anchordocking/anchordocking.lpk

do-install:
# Not ready for hier(7)-conforming installation yet
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${PORTNAME}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "blocks components \
		fonts images languages menu programdb rtl sample \
		template" ${STAGEDIR}${PREFIX}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/userguide/UserGuide.odt \
		${INSTALL_WRKSRC}/UserGuide.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
