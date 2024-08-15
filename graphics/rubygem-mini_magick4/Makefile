PORTNAME=	mini_magick
PORTVERSION=	4.13.2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate images with minimal use of memory via ImageMagick
WWW=		https://github.com/minimagick/minimagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem magick:${FLAVOR}

NO_ARCH=	yes

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	4-nox11

PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
