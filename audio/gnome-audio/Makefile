# New ports collection makefile for:	gnomeaudio2
# Date created:				10 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/gnome-audio/Makefile,v 1.8 2008/03/21 12:32:12 ahze Exp $
#

PORTNAME=	gnome-audio
PORTVERSION=	2.22.1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound files for use with GNOME 2

USE_BZIP2=	yes
USE_XLIB=	yes
NO_BUILD=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier
MAKE_ENV=	prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/sounds/Makefile

.include <bsd.port.mk>
