# New ports collection makefile for:	libgtop
# Version required:		0.99.8
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.14 1999/01/31 19:03:49 vanilla Exp $
#

DISTNAME=	libgtop-0.99.8
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
MASTER_SITE_SUBDIR=	libgtop

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs \
		guile.4:${PORTSDIR}/lang/guile

# implicit dependencies:
# gettext, glib11-devel

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"
USE_GMAKE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
