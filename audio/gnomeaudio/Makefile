# New ports collection makefile for:	gnomeaudio
# Version required:			0.99.4
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1999/01/27 08:31:48 fenner Exp $
#

DISTNAME=	gnome-audio-0.99.4
PKGNAME=	gnomeaudio-0.99.4
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-audio

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	gnome-config:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	gnome-config:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

INSTALL_TARGET=	INSTALL_DATA="${INSTALL_DATA}" install

.include <bsd.port.mk>
