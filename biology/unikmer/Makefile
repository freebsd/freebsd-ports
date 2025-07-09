PORTNAME=	unikmer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
PORTREVISION=	8
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for nucleic acid k-mer analysis, set operations on k-mers
WWW=		https://bioinf.shenwei.me/unikmer/ \
		https://github.com/shenwei356/unikmer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	csvtk:science/csvtk

USES=		go:modules perl5
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.21.0:sys
USE_PERL5=	test

GO_MODULE=	github.com/shenwei356/unikmer
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-test: # from the benchmark section in README
	@cd ${WRKSRC} && \
		${GO_CMD} test . -bench=Bench* -benchmem \
			| ${GREP} Bench \
			| ${PERL} -pe 's/\s\s+/\t/g' \
			| csvtk cut -Ht -f 1,3-5 \
			| csvtk add-header -t -n test,time,memory,allocs \
			| csvtk pretty -t -r

.include <bsd.port.mk>
