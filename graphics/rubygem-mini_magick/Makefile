# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mini_magick
PORTVERSION=	4.2.4
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Manipulate images with minimal use of memory via ImageMagick

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

.include <bsd.port.mk>
