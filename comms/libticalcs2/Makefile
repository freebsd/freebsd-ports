# $FreeBSD$

PORTNAME=	libticalcs2
PORTVERSION=	1.1.9
CATEGORIES=	comms
MASTER_SITES=	SF/tilp/tilp2-linux/tilp2-1.18

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	TI calculator library

LICENSE=	GPLv2

LIB_DEPENDS=	libticables2.so:comms/libticables2	\
		libticonv.so:converters/libticonv	\
		libtifiles2.so:devel/libtifiles2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
