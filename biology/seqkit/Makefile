PORTNAME=	seqkit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for FASTA/Q file manipulation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/shenwei356/seqkit/v2
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-test: # from https://bioinf.shenwei.me/seqkit/benchmark/
	@cd ${WRKSRC}/tests && \
		${GO_WRKDIR_BIN}/seqkit stat *.fa

.include <bsd.port.mk>
