# New ports collection makefile for:	gruler
# Date created:				24 October 2004
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	gruler
PORTVERSION=	0.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://linuxadvocate.org/projects/gruler/downloads/
DISTNAME=${PORTNAME:S/gr/gR/}-${PORTVERSION}

MAINTAINER=	smyru@heron.pl
COMMENT=	Screen ruler for GNOME desktop

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libglade2
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
