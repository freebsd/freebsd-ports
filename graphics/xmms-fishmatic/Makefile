# New ports collection makefile for:	xmms-fishmatic
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	fishmatic
PORTVERSION=	0.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://stukach.com/hosted/
PKGNAMEPREFIX=	xmms-
DISTNAME=	fishmatic

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GLIB=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_MESA=	yes
USE_X_PREFIX=	yes

CFLAGS+=	-I${X11BASE}/include -L${X11BASE}/lib

post-patch:
	@${RM} -f ${WRKSRC}/config.cache
	@${PERL} -pi -e 's@glib-config@${GLIB_CONFIG}@g;' \
		${WRKSRC}/configure

.include <bsd.port.mk>
