# New ports collection makefile for: tagtool
# Date created:                     1st November 2004
# Whom:                             Anthony Ginepro <anthony.ginepro@laposte.net>
#
# $FreeBSD$
#

PORTNAME=	tagtool
PORTVERSION=	0.11.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME application that tag mp3/ogg files

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GNOME=	libglade2

DATADIR=	share/tagtool

.include <bsd.port.mk>
