# New ports collection makefile for:	gnomeaudio
# Version required:			1.0.0
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gnome-audio-1.0.0
PKGNAME=	gnomeaudio-1.0.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-audio

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	gnome-config:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	gnome-config:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

INSTALL_TARGET=	INSTALL_DATA="${INSTALL_DATA}" install

post-extract:
	@${RM} -fr ${WRKSRC}/sounds/sounds

.include <bsd.port.mk>
