# $FreeBSD$

PORTNAME=	statik
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Embed static files into a Go executable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	rakyll

PLIST_FILES=	bin/statik

.include <bsd.port.mk>
