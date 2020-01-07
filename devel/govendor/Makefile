# $FreeBSD$

PORTNAME=	govendor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.9-6
DISTVERSIONSUFFIX=	-gc5ee5dc # includes the fix for 32-bit systems: https://github.com/kardianos/govendor/issues/386
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	rwestlun@gmail.com
COMMENT=	Go vendor tool that works with the standard vendor file

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=	fails to compile, needs vendor/golang.org/x/sys 33540a1f6037 or later

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	kardianos
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/govendor

.include <bsd.port.mk>
