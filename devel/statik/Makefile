# $FreeBSD$

PORTNAME=	statik
PORTVERSION=	20141209
CATEGORIES=	devel

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Embed static files into a Go executable

LICENSE=	APACHE20

BUILD_DEPENDS=	go:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=	yes
GH_ACCOUNT=	rakyll
GH_TAGNAME=	4a16c83

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
