# New ports collection makefile for:	libgtop
# Version required:		1.0.1
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.18 1999/04/08 18:08:32 steve Exp $
#

DISTNAME=	libgtop-1.0.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libgtop

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gnome.2:${PORTSDIR}/x11/gnomelibs \
		guile.4:${PORTSDIR}/lang/guile

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
