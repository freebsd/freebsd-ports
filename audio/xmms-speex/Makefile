# New ports collection makefile for:	xmms-speex
# Date created:				3 Oct 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-speex
PORTVERSION=	0.6.0
CATEGORIES=	audio
MASTER_SITES=	http://jzb.rapanden.dk/speex/
DISTNAME=	speex-xmms-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	speex.0:${PORTSDIR}/audio/speex
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

WRKSRC=		${WRKDIR}/speex-xmms

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes

pre-build:
	@${REINPLACE_CMD} -e 's|^main|all|; \
		s|-lgtk|${CFLAGS} `${GTK_CONFIG} --cflags` `${GTK_CONFIG} --libs` |; \
		s|-I/usr/include/xmms||; \
		s|^install: libspeex.o|install:|; \
		s|-I/usr/lib/glib/include||; \
		s|-I/usr/include/glib-1.2||; \
		s|-I/usr/include/gtk-1.2||; \
		s|/usr/lib/xmms/Input|${X11BASE}/lib/xmms/Input|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
