# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	xdg
PORTVERSION=	5.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc

BROKEN_RUBY26=	yes
BROKEN_RUBY27=	yes

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# xdg 6.0.0+ requires ruby 3.1+
PORTSCOUT=	limit:^5\.

.include <bsd.port.mk>
