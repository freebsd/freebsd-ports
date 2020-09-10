# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	astrometry
PORTVERSION=	0.80
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://astrometry.net/downloads/
DISTNAME=	${PORTNAME}.net-${PORTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Astronomic calibration service

LICENSE=	GPLv2

BROKEN_armv6=		fails to link: os-features-test.c:10: undefined symbol 'canonicalize_file_name'
BROKEN_armv7=		fails to link: os-features-test.c:10: undefined symbol 'canonicalize_file_name'

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcfitsio.so:astro/cfitsio \
		libgsl.so:math/gsl \
		libpng.so:graphics/png \
		libnetpbm.so:graphics/netpbm \
		libwcs.so:astro/wcslib
RUN_DEPENDS=	${PYNUMPY}

USES=		gmake jpeg localbase pkgconfig python shebangfix
SHEBANG_FILES=	bin/* blind/*.py sdss/*.py util/[!c]*.py
USE_LDCONFIG=	yes

ALL_TARGET=	all extra
MAKE_ARGS=	NETPBM_INC="-I${LOCALBASE}/include/netpbm" \
		NETPBM_LIB="-L${LOCALBASE}/lib -lnetpbm" \
		SYSTEM_GSL=yes
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX} \
		DOC_INSTALL_DIR=${STAGEDIR}${PREFIX}/${PORTNAME}/doc \
		EXAMPLE_INSTALL_DIR=${STAGEDIR}${PREFIX}/${PORTNAME}/examples \
		MAN1_INSTALL_DIR=${STAGEDIR}${PREFIX}/man/man1 \
		PYTHON=${PYTHON_CMD} PYTHON_SCRIPT=${PYTHON_CMD}
MAKE_JOBS_UNSAFE=	yes
# Changes search path in astrometry-engine
DATA_INSTALL_DIR=	${STAGEDIR}${DATADIR}
# Need this to get gzipped man pages
MANDIRS=	${MANPREFIX}/man/man1
SUB_FILES=	pkg-message
LDFLAGS+=	-lz

# DATA_INSTALL_DIR does not work globally :(
post-install:
	@${REINPLACE_CMD} -i '' \
		-e 's|${STAGEDIR}/usr/local/data|${DATADIR}|' \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg
	@${RMDIR} ${STAGEDIR}${PREFIX}/data
	@${MKDIR} ${STAGEDIR}${DATADIR}/sdss
	@${MKDIR} ${STAGEDIR}${DATADIR}/blind
	@${MKDIR} ${STAGEDIR}${DATADIR}/catalogs
	${INSTALL_DATA} ${WRKSRC}/sdss/testdata/*.fit* ${STAGEDIR}${DATADIR}/sdss
	${INSTALL_DATA} ${WRKSRC}/blind/index-9918.fits ${STAGEDIR}${DATADIR}/blind
	${INSTALL_DATA} ${WRKSRC}/catalogs/*.fit* ${STAGEDIR}${DATADIR}/catalogs

.include <bsd.port.mk>
