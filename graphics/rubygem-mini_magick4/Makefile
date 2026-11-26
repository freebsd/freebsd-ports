PORTNAME=	mini_magick
PORTVERSION=	4.13.2
PORTREVISION=	2
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate images with minimal use of memory via ImageMagick
WWW=		https://github.com/minimagick/minimagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		cpe gem magick

CPE_VENDOR=	minimagick_project
CPE_PRODUCT=	${PORTNAME:tl:S/_//g}

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
