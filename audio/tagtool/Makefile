# New ports collection makefile for: tagtool
# Date created:                     1st November 2004
# Whom:                             Anthony Ginepro <anthony.ginepro@laposte.net>
#
# $FreeBSD$
#

PORTNAME=	tagtool
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME application that tag mp3/ogg files

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier libglade2
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/pixmaps|(datadir)/gnome/pixmaps|g' \
		${WRKSRC}/pixmaps/Makefile.in

.include <bsd.port.mk>
