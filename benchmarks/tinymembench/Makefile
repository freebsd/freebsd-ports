PORTNAME=	tinymembench
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	benchmarks

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple benchmark for memory throughput and latency
WWW=		https://github.com/ssvb/tinymembench

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ssvb

PLIST_FILES=	bin/tinymembench

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
pre-configure:
	${REINPLACE_CMD} -e 's,@progbits,%progbits,' ${WRKSRC}/*.S
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
