# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zcad
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	cad
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
MASTER_SITES=	LOCAL/danfe
DISTNAME=	${PORTNAME}-trunk-r2259

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple CAD program

USES=		fpc lazarus:flavors tar:xz
USE_FPC=	cairo chm fcl-base fcl-image fcl-json fcl-stl fcl-xml opengl \
		pasjpeg rtl-extra rtl-objpas x11

EXTRACT_CMD=	LC_ALL=en_US.UTF-8 ${TAR}	# for non-ASCII filenames

MAKE_ENV=	LAZBUILD_CMD="${LAZBUILD_CMD}" \
		LAZBUILD_ARGS="${LAZBUILD_ARGS}" \
		LCL_PLATFORM="${LCL_PLATFORM}" \
		LAZARUS_DIR="${LAZARUS_DIR}" \
		INSTANTFPCCACHE="${WRKSRC}/.cache"

NO_LAZBUILD=	yes
WRKSRC=		${WRKDIR}/trunk
BUILD_WRKSRC=	${WRKSRC}/cad_source
INSTALL_WRKSRC=	${WRKSRC}/cad

LAZBUILD_ARGS=	-d --pcp=${WRKSRC}/tmppcp
LAZARUS_NO_FLAVORS=qt5

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt4
qt4_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	UserGuide.odt UserGuide.pdf

OPTIONS_DEFINE=		DOCS

.if ${FLAVOR:Ugtk2:Mgtk2}
MAKE_ENV+=	GUI=gtk2
.endif

.if ${FLAVOR:Uqt4:Mqt4}
MAKE_ENV+=	GUI=qt
.endif

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
	${SETENV} ${MAKE_ENV} ${LAZBUILD_CMD} ${LAZBUILD_ARGS} --ws=${LCL_PLATFORM} \
		--lazarusdir=${LAZARUS_DIR} \
			${WRKSRC}/fpvectorial/fpvectorialpkg.lpk
	${SETENV} ${MAKE_ENV} ${LAZBUILD_CMD} ${LAZBUILD_ARGS} --ws=${LCL_PLATFORM} \
		--lazarusdir=${LAZARUS_DIR} \
			${WRKSRC}/anchordocking/anchordocking.lpk

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
