# $FreeBSD$

PORTNAME=	libtifiles2
PORTVERSION=	1.1.6
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.17

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	TI calculator file types library

LICENSE=	GPLv2

LIB_DEPENDS=	libticonv.so:converters/libticonv

USE_GNOME=	glib20
USE_LDCONFIG=	yes
USES=		gmake libarchive libtool pathfix pkgconfig tar:bzip2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
