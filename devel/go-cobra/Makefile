# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cobra
PORTVERSION=	20160816
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Commander for modern Go CLI interactions

LICENSE=	APACHE20

DEPRECATED=		Go libraries should not be packaged
EXPIRATION_DATE=	2019-03-31

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/spf13/pflag.a:devel/go-pflag

USE_GITHUB=	yes
GH_ACCOUNT=	spf13
GH_TAGNAME=	a272c3cbd5ff80a5bf5c5603df50183f9f3f7324
USES=		go
GO_PKGNAME=	github.com/spf13/cobra

.include <bsd.port.mk>
