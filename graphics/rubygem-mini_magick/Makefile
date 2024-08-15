PORTNAME=	mini_magick
PORTVERSION=	5.0.1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate images with minimal use of memory via ImageMagick
WWW=		https://github.com/minimagick/minimagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem magick:${FLAVOR}

NO_ARCH=	yes

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

.include <bsd.port.mk>
