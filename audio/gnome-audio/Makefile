# New ports collection makefile for:	gnomeaudio
# Version required:			0.1
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/12/30 23:18:11 vanilla Exp $
#

DISTNAME=	gnome-audio-0.1
PKGNAME=	gnomeaudio-0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	vanilla@FreeBSD.ORG

RUN_DEPEND=	gnome-config:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/gnome-audio/sounds
NO_BUILD=	yes

.include <bsd.port.mk>
