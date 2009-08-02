# New ports collection makefile for:	librelp
# Date created:		1 April 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librelp
PORTVERSION=	0.1.3
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reliable event logging protocol library

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

PLIST_FILES=	include/${PORTNAME}.h \
		lib/${PORTNAME}.a lib/${PORTNAME}.la \
		lib/${PORTNAME}.so lib/${PORTNAME}.so.0 \
		libdata/pkgconfig/relp.pc

PORT_VERBS=	relp

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS/s| -g||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^PTHREADS/s|= .*|= ${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
