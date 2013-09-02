# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librelp
PORTVERSION=	1.0.7
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Reliable event logging protocol library

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PLIST_FILES=	include/${PORTNAME}.h \
		lib/${PORTNAME}.a lib/${PORTNAME}.la \
		lib/${PORTNAME}.so lib/${PORTNAME}.so.0 \
		libdata/pkgconfig/relp.pc

PORT_VERBS=	relp

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS/s| -g||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
