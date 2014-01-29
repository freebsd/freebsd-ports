# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psiconv
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	converters devel
MASTER_SITES=	http://software.frodo.looijaard.name/psiconv/files/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Conversion utility to convert Psion 5(MX) files into other formats

USES=		gmake
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-imagemagick=no

.include <bsd.port.mk>
