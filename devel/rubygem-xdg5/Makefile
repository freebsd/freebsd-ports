PORTNAME=	xdg
PORTVERSION=	5.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby
WWW=		https://alchemists.io/projects/xdg \
		https://github.com/bkuhlmann/xdg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc

USES=		gem

NO_ARCH=	yes

# xdg 6.0.0+ requires ruby 3.1+
PORTSCOUT=	limit:^5\.

.include <bsd.port.mk>
