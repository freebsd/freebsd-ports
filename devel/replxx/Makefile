# $FreeBSD$

PORTNAME=	replxx
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	meka@tilda.center
COMMENT=	Portable readline library capable of handling UTF-8

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	AmokHuginnsson

PLIST_FILES=	include/replxx.h \
		include/replxx.hxx \
		lib/libreplxx.a

.include <bsd.port.mk>
