# New ports collection makefile for:	xmms-iris
# Date created:				25 Apr 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	iris
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/
PKGNAMEPREFIX=	xmms-

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An adaptation of the "OpenGL Spectrum Analyzer" from XMMS

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
PLIST_FILES=	lib/xmms/Visualization/libiris.so
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_MESA=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
