# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psiconv
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	converters devel
MASTER_SITES=	http://software.frodo.looijaard.name/psiconv/files/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Conversion utility to convert Psion 5(MX) files into other formats

BROKEN=		Unfetchable

USES=		gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-imagemagick=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
