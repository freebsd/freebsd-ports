# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	astrometry
PORTVERSION=	0.65
CATEGORIES=	astro
MASTER_SITES=	http://www.astrometry.net/downloads/
DISTNAME=	${PORTNAME}.net-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for describing astronomical images

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcfitsio.so:astro/cfitsio \
		libpng.so:graphics/png \
		libnetpbm.so:graphics/netpbm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake jpeg pkgconfig python tar:bzip2
USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib
ALL_TARGET=	all extra
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX}/${PORTNAME}
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -E 's,python (setup|-c),${PYTHON_CMD} \1,' \
		${WRKSRC}/blind/Makefile ${WRKSRC}/libkd/Makefile \
		${WRKSRC}/sdss/Makefile ${WRKSRC}/util/Makefile
# Outwit detection logic that thinks Clang does not support -shared argument
	@${REINPLACE_CMD} -e '/CCTEST/s,\\|warning:,,' \
		${WRKSRC}/util/makefile.common

post-install:
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/${PORTNAME}/etc/${PORTNAME}.cfg
	@${FIND} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin \
		-type f -not -name "*.py" -exec ${STRIP_CMD} {} \;
	@${FIND} ${STAGEDIR}${PREFIX}/${PORTNAME}/lib \
		-type f -name "*.so" -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
