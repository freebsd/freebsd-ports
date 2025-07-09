PORTNAME=	seqkit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
PORTREVISION=	4
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for FASTA/Q file manipulation
WWW=		https://bioinf.shenwei.me/seqkit \
		https://github.com/shenwei356/seqkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/shenwei356/seqkit/v2
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-test: # from https://bioinf.shenwei.me/seqkit/benchmark/
	@cd ${WRKSRC}/tests && \
		${GO_WRKDIR_BIN}/seqkit stat *.fa

.include <bsd.port.mk>
