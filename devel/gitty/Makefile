PORTNAME=	gitty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	22
CATEGORIES=	devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Smart terminal helper for git projects
WWW=		https://github.com/muesli/gitty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/muesli/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
