# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/gnome-audio/Makefile,v 1.10 2008/05/07 18:52:29 mezz Exp $

PORTNAME=	gnome-audio
PORTVERSION=	2.22.2
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound files for use with GNOME 2

USES=	tar:bzip2
NO_BUILD=	yes
MAKE_ENV=	prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/sounds/Makefile

.include <bsd.port.mk>
