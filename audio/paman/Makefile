# New ports collection makefile for:	paman
# Date created:		2005-03-27
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paman
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/paman/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ frontend for the polypaudio sound server

LIB_DEPENDS=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		polyp-0.7.0:${PORTSDIR}/audio/polypaudio

USE_GCC=	3.4
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--disable-lynx
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"

DATADIR=	share/gnome/${PORTNAME}

PLIST_FILES=	bin/paman \
		%%DATADIR%%/paman.glade
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
