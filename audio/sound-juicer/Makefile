# New ports collection makefile for:	soundjuicer
# Date created:		20 Jan 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sound-juicer
PORTVERSION=	0.5.12
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.burtonini.com/computing/
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Clean, mean and lean CD ripper for GNOME2

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui gstreamerplugins
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--enable-ignore-missing-cd

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You must have gstreamer-plugins built with Cdparanoia support!"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)tests\(.*\)|\1\2|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
