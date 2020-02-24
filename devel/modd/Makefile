# $FreeBSD$

PORTNAME=	modd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	devel sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Developer tool that runs processes and responds to filesystem changes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cortesi
GH_TUPLE=	golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys_fead79001313

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_fead79001313 ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
