# New ports collection makefile for:	xmms-midi
# Date created:		2002-10-14
# Whom:			Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$

PORTNAME=	xmms-midi
PORTVERSION=	0.03
CATEGORIES=	audio
MASTER_SITES=	http://ban.joh.cam.ac.uk/~cr212/xmms-midi/

MAINTAINER=	hendrik@scholz.net

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms
RUN_DEPENDS=    timidity:${PORTSDIR}/audio/timidity

USE_GNOMENG=	yes
USE_GNOME=  	gtk12
USE_X_PREFIX=	yes

USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
