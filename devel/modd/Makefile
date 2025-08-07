PORTNAME=	modd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	31
CATEGORIES=	devel sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Developer tool that runs processes and responds to filesystem changes
WWW=		https://github.com/cortesi/modd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cortesi
GH_TUPLE=	golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys_v0.6.0

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_v0.6.0 ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
