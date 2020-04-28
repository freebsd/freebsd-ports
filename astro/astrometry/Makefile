# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	astrometry
PORTVERSION=	0.80
CATEGORIES=	astro
MASTER_SITES=	http://astrometry.net/downloads/
DISTNAME=	${PORTNAME}.net-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for describing astronomical images

LICENSE=	GPLv2

BROKEN_armv6=		fails to link: os-features-test.c:10: undefined symbol 'canonicalize_file_name'
BROKEN_armv7=		fails to link: os-features-test.c:10: undefined symbol 'canonicalize_file_name'

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcfitsio.so:astro/cfitsio \
		libpng.so:graphics/png \
		libnetpbm.so:graphics/netpbm
RUN_DEPENDS=	${PYNUMPY}

USES=		gmake jpeg pkgconfig python shebangfix
SHEBANG_FILES=	bin/* blind/*.py sdss/*.py util/[!c]*.py
USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib
ALL_TARGET=	all extra
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX}/${PORTNAME} \
		PYTHON=${PYTHON_CMD} PYTHON_SCRIPT=${PYTHON_CMD}
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message
LDFLAGS+=	-lz

post-install:
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/${PORTNAME}/etc/${PORTNAME}.cfg

.include <bsd.port.mk>
