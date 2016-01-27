# Created by: ache
# $FreeBSD$

PORTNAME=	png
PORTVERSION=	1.6.21
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}16/${PORTVERSION} \
		ftp://ftp.simplesystems.org/pub/lib${PORTNAME}/${PORTNAME}/src/lib${PORTNAME}16/
PATCH_SITES=	SF/apng/lib${PORTNAME}/lib${PORTNAME}16/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Library for manipulating PNG images

USES=		cpe libtool tar:xz
CPE_PRODUCT=	libpng
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=APNG PNGTEST
OPTIONS_DEFAULT=APNG PNGTEST
APNG_DESC=Enable Animated PNG support
PNGTEST_DESC=Enable Regression Test (recommended)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPNG} || make(makesum)
PATCHFILES=	${DISTNAME}-apng.patch.gz
.endif

# Do not fail until https://sourceforge.net/p/libpng/bugs/243/ is fixed
.if ${PORT_OPTIONS:MPNGTEST}
post-build:
	(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} test; then \
	if [ -f ${WRKSRC}/test-suite.log ]; then \
	${CAT} ${WRKSRC}/test-suite.log ; \
	fi; \
	fi)
.endif

.include <bsd.port.mk>
