# $FreeBSD$

PORTNAME=	shfmt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Format shell scripts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	mvdan.cc/sh
GO_TARGET=	mvdan.cc/sh/cmd/shfmt
USE_GITHUB=	yes
GH_ACCOUNT=	mvdan
GH_PROJECT=	sh

PLIST_FILES=	bin/shfmt

.include <bsd.port.mk>
