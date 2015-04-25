# Created by: ache
# $FreeBSD$

PORTNAME=	png
PORTVERSION=	1.6.17
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}16/${PORTVERSION}
PATCH_SITES=	SF/apng/lib${PORTNAME}/lib${PORTNAME}16/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Library for manipulating PNG images

USES=		cmake cpe tar:xz
CPE_PRODUCT=	libpng
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DPNG_MAN_DIR:STRING=man

OPTIONS_DEFINE=APNG PNGTEST
OPTIONS_DEFAULT=APNG PNGTEST
APNG_DESC=Enable Animated PNG support
PNGTEST_DESC=Enable Regression Test (recommended)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPNG} || make(makesum)
PATCHFILES=	${DISTNAME}-apng.patch.gz
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|LIBDIR}/pkgconfig|LIBDIR}data/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MPNGTEST}
post-build:
	(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} test; then \
        if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
            ${ECHO_MSG} "===> Compilation failed unexpectedly."; \
            (${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
            fi; \
        ${FALSE}; \
        fi)
.endif

.include <bsd.port.mk>
