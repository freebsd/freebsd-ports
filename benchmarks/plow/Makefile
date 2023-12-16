PORTNAME=	plow
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	11
CATEGORIES=	benchmarks

MAINTAINER=	nulldutra@proton.me
COMMENT=	HTTP benchmarking tool with real-time web UI and terminal displaying
WWW=		https://github.com/six-ddc/plow

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/six-ddc/plow

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
