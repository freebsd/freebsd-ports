# New ports collection makefile for: tagtool
# Date created:                     1st November 2004
# Whom:                             Anthony Ginepro <anthony.ginepro@laposte.net>
#
# $FreeBSD$
#

PORTNAME=	tagtool
PORTVERSION=	0.12.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME MP3/Ogg file tagger

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=	yes
USE_REINPLACE=	yes

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack libglade2

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -Wl,--export-dynamic ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e \
			's|(prefix)/share/applications|(prefix)/share/gnome/applications|g; \
			 s|(datadir)/pixmaps|(prefix)/share/gnome/pixmaps|g' \

.include <bsd.port.mk>
