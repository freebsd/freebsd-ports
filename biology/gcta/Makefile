PORTNAME=	gcta
DISTVERSION=	1.26.0
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	https://cnsgenomics.com/software/gcta/pre_gcta/:main \
		https://gitlab.com/libeigen/eigen/-/archive/${EIGEN_VERSION}/:eigen
DISTFILES=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX}:main \
		eigen-${EIGEN_VERSION}.tar.gz:eigen

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GNU_General_Public_License_v3.txt

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		compiler:c++11-lang dos2unix gmake localbase:ldflags zip

CXXFLAGS+=	-I${WRKDIR}/eigen-${EIGEN_VERSION} -fopenmp
LDFLAGS+=	-lopenblas

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/gcta

EIGEN_VERSION=	3.3.9

do-extract:
	@${UNZIP_NATIVE_CMD} -d ${WRKSRC} ${DISTDIR}/${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX}
	@cd ${WRKDIR} && \
		${TAR} xzf ${DISTDIR}/eigen-${EIGEN_VERSION}.tar.gz

.include <bsd.port.mk>
