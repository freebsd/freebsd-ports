PORTNAME=	astrometry
PORTVERSION=	0.95
CATEGORIES=	astro
MASTER_SITES=	https://github.com/dstndstn/${PORTNAME}.net/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}.net-${PORTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Astronomic calibration service
WWW=		https://astrometry.net/

LICENSE=	GPLv3+

BROKEN_armv6=		fails to link: os-features-test.c:10: undefined symbol 'canonicalize_file_name'
BROKEN_armv7=		fails to link: os-features-test.c:10: undefined symbol 'canonicalize_file_name'

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY}
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcfitsio.so:astro/cfitsio \
		libgsl.so:math/gsl \
		libnetpbm.so:graphics/netpbm \
		libpng16.so:graphics/png \
		libwcs.so:astro/wcslib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>0:astro/py-astropy@${PY_FLAVOR} \
		${PYNUMPY}

USES=		gmake jpeg localbase pkgconfig python shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	bin/* plot/plotann.py sdss/*.py solver/*.py util/[!c]*.py

MAKE_ARGS=	NETPBM_INC="-I${LOCALBASE}/include/netpbm" \
		NETPBM_LIB="-L${LOCALBASE}/lib -lnetpbm" \
		SYSTEM_GSL=yes
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX} \
		DATA_INSTALL_DIR=${STAGEDIR}${DATADIR} \
		DOC_INSTALL_DIR=${STAGEDIR}${DOCSDIR} \
		EXAMPLE_INSTALL_DIR=${STAGEDIR}${EXAMPLESDIR} \
		MAN1_INSTALL_DIR=${STAGEDIR}${PREFIX}/share/man/man1 \
		PY_BASE_INSTALL_DIR=${STAGEDIR}${PYTHON_LIBDIR}/astrometry \
		PYTHON=${PYTHON_CMD} PYTHON_SCRIPT=${PYTHON_CMD}
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all extra
LDFLAGS+=	-lz

CONFLICTS_INSTALL=	afni p5-Text-RecordParser # bin/imstat bin/tabmerge

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

FILES=	an-fitstopnm an-pnmtofits astrometry-engine augment-xylist \
	build-astrometry-index downsample-fits fit-wcs \
	fits-column-merge fits-flip-endian fits-guess-scale \
	fitscopy fitsgetext fitsverify get-healpix get-wcs \
	hpsplit image2xy imarith imcopy imstat listhead liststruc \
	modhead new-wcs pad-file plot-constellations \
	plotquad plotxy query-starkd solve-field startree \
	subtable tablist tabmerge tabsort wcs-grab wcs-match \
	wcs-pv2sip wcs-rd2xy wcs-resample wcs-to-tan wcs-xy2rd \
	wcsinfo

post-install:
.for file in ${FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libastrometry.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/astrometry/solver/_solver${PYTHON_EXT_SUFFIX}.so
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
