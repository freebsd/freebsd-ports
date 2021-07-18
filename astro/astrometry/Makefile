# Created by: Sébastien Santoro <dereckson@gmail.com>

PORTNAME=	astrometry
PORTVERSION=	0.85
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>0:astro/py-astropy@${PY_FLAVOR} \
		${PYNUMPY}

USES=		gmake jpeg localbase pkgconfig python shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	bin/* sdss/*.py solver/*.py util/[!c]*.py

MAKE_ARGS=	NETPBM_INC="-I${LOCALBASE}/include/netpbm" \
		NETPBM_LIB="-L${LOCALBASE}/lib -lnetpbm" \
		SYSTEM_GSL=yes
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX} \
		DOC_INSTALL_DIR=${STAGEDIR}${DOCSDIR} \
		EXAMPLE_INSTALL_DIR=${STAGEDIR}${EXAMPLESDIR} \
		MAN1_INSTALL_DIR=${STAGEDIR}${PREFIX}/man/man1 \
		PYTHON=${PYTHON_CMD} PYTHON_SCRIPT=${PYTHON_CMD}
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all extra
LDFLAGS+=	-lz

# Need this to get gzipped man pages
MANDIRS=	${MANPREFIX}/man/man1
SUB_FILES=	pkg-message

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

# Changes search path in astrometry-engine
DATA_INSTALL_DIR=	${STAGEDIR}${DATADIR}

# DATA_INSTALL_DIR does not work globally :(
post-install:
	@${REINPLACE_CMD} -i '' \
		-e 's|${STAGEDIR}/usr/local/data|${DATADIR}|' \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg
	@${RMDIR} ${STAGEDIR}${PREFIX}/data
	@${MKDIR} ${STAGEDIR}${DATADIR}/sdss
	@${MKDIR} ${STAGEDIR}${DATADIR}/solver
	@${MKDIR} ${STAGEDIR}${DATADIR}/catalogs
	${INSTALL_DATA} ${WRKSRC}/sdss/testdata/*.fit* ${STAGEDIR}${DATADIR}/sdss
	${INSTALL_DATA} ${WRKSRC}/solver/index-9918.fits ${STAGEDIR}${DATADIR}/solver
	${INSTALL_DATA} ${WRKSRC}/catalogs/*.fit* ${STAGEDIR}${DATADIR}/catalogs

.include <bsd.port.mk>
