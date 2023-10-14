PORTNAME=	gcta
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94.1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis
WWW=		https://cnsgenomics.com/software/gcta/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		spectra>0:math/spectra
LIB_DEPENDS=	libgsl.so:math/gsl \
		libopenblas.so:math/openblas \
		libsqlite3.so:databases/sqlite3 \
		libzstd.so:archivers/zstd

USES=		cmake eigen:3 localbase:ldflags
USE_GITHUB=	yes

GH_ACCOUNT=	jianyangqt
GH_TUPLE=	zhilizheng:plink-ng:3744540:plink/submods/plink-ng

CONFIGURE_ENV+=	EIGEN3_INCLUDE_DIR=${LOCALBASE}/include/eigen3 \
		BOOST_INCLUDE_DIR=${LOCALBASE}/include/boost \
		OPENBLAS=${LOCALBASE} \
		SPECTRA_INCLUDE_DIR=${LOCALBASE}/include/Spectra

LDFLAGS+=	-fopenmp

PLIST_FILES=	bin/gcta64 bin/gcta

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gcta64 ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/gcta64 ${STAGEDIR}${PREFIX}/bin/gcta

.include <bsd.port.mk>
