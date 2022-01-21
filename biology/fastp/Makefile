PORTNAME=		fastp
DISTVERSIONPREFIX=	v
DISTVERSION=		0.23.2
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra-fast all-in-one FASTQ preprocessor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		libisal.so:devel/isa-l

USES=		gmake localbase:ldflags
USE_GITHUB=	yes
USE_GCC=	yes

GH_ACCOUNT=	OpenGene

ALL_TARGET=	fastp
PLIST_FILES=	bin/fastp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fastp

.include <bsd.port.mk>
