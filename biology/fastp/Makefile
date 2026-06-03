PORTNAME=		fastp
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.0
CATEGORIES=		biology

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	Ultra-fast all-in-one FASTQ preprocessor
WWW=		https://github.com/OpenGene/fastp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		libisal.so:devel/isa-l \
		libhwy.so:devel/highway

USES=		gmake localbase:ldflags
USE_GITHUB=	yes

GH_ACCOUNT=	OpenGene

ALL_TARGET=	fastp
PLIST_FILES=	bin/fastp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fastp

.include <bsd.port.mk>
