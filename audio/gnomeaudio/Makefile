# New ports collection makefile for:	gnomeaudio
# Version required:			0.1
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1999/01/05 12:37:45 vanilla Exp $
#

DISTNAME=	gnome-audio-0.1
PKGNAME=	gnomeaudio-0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-audio

MAINTAINER=	vanilla@FreeBSD.ORG

RUN_DEPEND=	gnome-config:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/gnome-audio/sounds
NO_BUILD=	yes

.include <bsd.port.mk>
