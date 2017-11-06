# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librelp
PORTVERSION=	1.2.14
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Reliable event logging protocol library

LICENSE=	GPLv3

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	include/${PORTNAME}.h \
		lib/${PORTNAME}.a \
		lib/${PORTNAME}.so lib/${PORTNAME}.so.0 \
		lib/${PORTNAME}.so.0.3.0 \
		libdata/pkgconfig/relp.pc

PORT_VERBS=	relp

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS/s| -g||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
