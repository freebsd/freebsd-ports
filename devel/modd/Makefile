# $FreeBSD$

PORTNAME=	modd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	devel sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Developer tool that runs processes and responds to filesystem changes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	cortesi

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
