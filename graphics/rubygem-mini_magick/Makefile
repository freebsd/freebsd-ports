# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mini_magick
PORTVERSION=	4.2.7
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Manipulate images with minimal use of memory via ImageMagick

LICENSE=	MIT

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

X11_RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
X11_RUN_DEPENDS_OFF=	convert:${PORTSDIR}/graphics/ImageMagick-nox11

.include <bsd.port.mk>
