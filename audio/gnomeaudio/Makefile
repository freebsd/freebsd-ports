# New ports collection makefile for:	gnomeaudio
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeaudio
PORTVERSION=	1.0.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-audio
DISTNAME=	gnome-audio-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMELIBS=	yes
NO_BUILD=	yes

post-extract:
	@${RM} -fr ${WRKSRC}/sounds/sounds

.include <bsd.port.mk>
