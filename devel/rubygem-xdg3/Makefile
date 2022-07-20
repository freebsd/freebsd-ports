PORTNAME=	xdg
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# xdg 4.0.0+ requires ruby 2.7+
PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
