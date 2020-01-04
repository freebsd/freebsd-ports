# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdg
PORTVERSION=	3.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_RUBY24=	yes
BROKEN_RUBY25=	yes

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# xdg 4.0.0+ requires ruby 2.7+
PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
