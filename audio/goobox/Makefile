# New ports collection makefile for:	guikachu
# Date created:		11 Nov 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goobox
PORTVERSION=	0.6.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=     sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=    gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

RUN_DEPENDS=	cddb-slave2-properties:${PORTSDIR}/audio/gnomemedia2

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libglade2 libbonobo \
		gstreamerplugins
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCEMAS=	goobox.schemas

.include <bsd.port.mk>
