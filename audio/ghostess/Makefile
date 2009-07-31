# New ports collection makefile for:	ghostess
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	ghostess
PORTVERSION=	20081213
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.smbolton.com/linux/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Graphical DSSI host with JACK MIDI support

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi \
		jackit>=0.109.2:${PORTSDIR}/audio/jack

# Between 0.109.0 and earlier versions there was an api change in JACK.
# However, the library version number was not changed.  The line above
# is supposed to work around that.

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jackmidi
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes

PLIST_FILES=	bin/ghostess bin/ghostess_universal_gui

.include <bsd.port.mk>
