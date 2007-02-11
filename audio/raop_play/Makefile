# New ports collection makefile for:	raop_play
# Date created:        8 Dec 2006
# Whom:                sumikawa
#
# $FreeBSD$
#

PORTNAME=	raop_play
PORTVERSION=	0.5.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	raop-play

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A music file player for Apple Airport Express

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		id3tag.0:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS=	mpg321:${PORTSDIR}/audio/mpg321 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		faad:${PORTSDIR}/audio/faad \
		flac:${PORTSDIR}/audio/flac

BROKEN=		Incomplete pkg-plist and missing CONFLICTS
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GNOME=	glib20

pre-build:
	${CP} ${FILESDIR}/getline.c ${FILESDIR}/getline.h ${WRKSRC}/rendezvous/

.include <bsd.port.mk>
