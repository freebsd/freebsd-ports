# New ports collection makefile for:	xmms-speex
# Date created:				3 Oct 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-speex
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://jzb.rapanden.dk/pub/
DISTNAME=	speex-xmms-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	XMMS input plugin to play speex files

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	speex.3:${PORTSDIR}/audio/speex
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libspeex.so
WRKSRC=		${WRKDIR}/speex-xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

MAKE_FLAGS=	CC="${CC}" CFLAGS="${CFLAGS} -fPIC"

.include <bsd.port.mk>
