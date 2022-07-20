PORTNAME=	xdg
PORTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# xdg 5.0.0+ requires ruby 3.0+
PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
