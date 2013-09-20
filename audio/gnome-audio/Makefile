# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/gnome-audio/Makefile,v 1.10 2008/05/07 18:52:29 mezz Exp $

PORTNAME=	gnome-audio
PORTVERSION=	2.22.2
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound files for use with GNOME 2

USE_BZIP2=	yes
NO_STAGE=	yes
NO_BUILD=	yes
USE_GNOME=	gnomehier
MAKE_ENV=	prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/sounds/Makefile

.include <bsd.port.mk>
