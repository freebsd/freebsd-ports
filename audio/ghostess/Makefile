# New ports collection makefile for:	ghostess
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	ghostess
PORTVERSION=	20061127
CATEGORIES=	audio
MASTER_SITES=	http://home.jps.net/~musound/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Graphical DSSI host with JACK MIDI support

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.6:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jackmidi
USE_GMAKE=	yes
USE_GNOME=	gtk20

PLIST_FILES=	bin/ghostess bin/ghostess_universal_gui

.include <bsd.port.mk>
