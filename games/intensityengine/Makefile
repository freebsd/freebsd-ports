# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intensityengine
DISTVERSION=	r20100129
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Engine that forms the basis of Syntensity, 3D games world

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_SDL=	sdl mixer image
USE_GL=		gl glu
USES=		cmake
MAKE_JOBS_SAFE=	yes
SUB_FILES=	intensity_client
USE_GCC=	4.2+

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/intensityengine_client libexec/intensityengine_client

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/set.*CMAKE_CXX_FLAGS/ d' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/src/thirdparty/v8/SConstruct
	@${REINPLACE_CMD} -e '/add_subdirectory.*server/ d' \
		${WRKSRC}/src/CMakeLists.txt

pre-build:
	cd ${WRKSRC}/src/thirdparty/v8 && ${SETENV} CC="${CC}" CXX="${CXX}" \
			CCFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${LOCALBASE}/bin/scons ${_MAKE_JOBS}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/intensity_client ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/client/Intensity_CClient ${PREFIX}/libexec/intensity_client
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"data src/python src/javascript packages intensity_client.py mybrushes.cfg" \
		${DATADIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} '*' ${DOCSDIR}/
.endif

.include <bsd.port.mk>
