# New ports collection makefile for: tagtool
# Date created:                     1st November 2004
# Whom:                             Anthony Ginepro <anthony.ginepro@laposte.net>
#
# $FreeBSD$
#    $MCom: ports/audio/tagtool/Makefile,v 1.1 2006/09/30 01:15:37 ahze Exp $

PORTNAME=	tagtool
PORTVERSION=	0.12.3
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME MP3/Ogg file tagger

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack libglade2
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wno-pointer-sign||g'

.include <bsd.port.mk>
