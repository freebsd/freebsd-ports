# $FreeBSD$

PORTNAME=	gcta
DISTVERSION=	1.26.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	https://cnsgenomics.com/software/gcta/pre_gcta/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GNU_General_Public_License_v3.txt

BUILD_DEPENDS=	eigen>=3:math/eigen3
LIB_DEPENDS+=	libopenblas.so:math/openblas

USES=		compiler:openmp dos2unix gmake localbase zip

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3 -fopenmp
LDFLAGS+=	-lopenblas

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/gcta

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
USE_GCC=	yes
.endif

do-extract:
	${UNZIP_NATIVE_CMD} -d ${WRKSRC} ${DISTDIR}/${DISTFILES}

.include <bsd.port.post.mk>
