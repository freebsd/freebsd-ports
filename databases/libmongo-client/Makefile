# Created by: Denis Generalov <gd.workbox@gmail.com>
# $FreeBSD$

PORTNAME=	libmongo-client
PORTVERSION=	0.1.6.3
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Alternative C driver for MongoDB

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	algernon
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig gmake pathfix
USE_GNOME=	glib20
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=Makefile.am

.include <bsd.port.mk>
