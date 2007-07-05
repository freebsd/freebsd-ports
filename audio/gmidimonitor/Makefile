# New ports collection makefile for:	gmidimonitor
# Date created:		2007-03-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	gmidimonitor
PORTVERSION=	3.2
CATEGORIES=	audio
# WARNING: the path below changes with every release.  It's not enough to change
# the version number above.
MASTER_SITES=	https://files.bountysource.com/file/download/588/

MAINTAINER=	trasz@freebsd.org
COMMENT=	GTK+ application that shows MIDI events

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsamidi
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2

.include <bsd.port.mk>
