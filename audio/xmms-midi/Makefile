# New ports collection makefile for:	xmms-midi
# Date created:		2002-10-14
# Whom:			Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$

PORTNAME=	xmms-midi
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ban.joh.cam.ac.uk/~cr212/xmms-midi/

MAINTAINER=	hendrik@scholz.net
COMMENT=	XMMS input plugin to play midi files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_GNOME=	gtk12
USE_X_PREFIX=	yes

USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
