# New ports collection makefile for:	gnome-media
# Version required:			1.0.1
# Date created:				20 January 1999
# Whom:					Jeremy Lea <reg@shale.csir.co.za>
#
# $Id: Makefile,v 1.1.1.1 1999/03/09 01:22:43 nectar Exp $
#

DISTNAME=	gnome-media-1.0.1
PKGNAME=	gnomemedia-1.0.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media

MAINTAINER=	reg@shale.csir.co.za

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

# implicit dependencies:
# gettext, esound, gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ncurses \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
