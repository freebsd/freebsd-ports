# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paperclip
DISTVERSION=	5.2.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel5>0:databases/rubygem-activemodel5 \
		rubygem-activesupport5>=0:devel/rubygem-activesupport5 \
		rubygem-cocaine>=0.5.5:devel/rubygem-cocaine \
		rubygem-mimemagic>=0.3.0:misc/rubygem-mimemagic \
		rubygem-mime-types>=0:misc/rubygem-mime-types

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

OPTIONS_SINGLE=			IMAGEMAGICK
OPTIONS_SINGLE_IMAGEMAGICK=	IMX11 IMNOX11
OPTIONS_DEFAULT=		IMNOX11

IMAGEMAGICK_DESC=	ImageMagick image processing support
IMNOX11_DESC=		Depend on ImageMagick without X11 support
IMX11_DESC=		Depend on ImageMagick with X11 support

IMNOX11_RUN_DEPENDS=	ImageMagick-nox11>0:graphics/ImageMagick-nox11
IMX11_RUN_DEPENDS=	ImageMagick>0:graphics/ImageMagick

.include <bsd.port.mk>
