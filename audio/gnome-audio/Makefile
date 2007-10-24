# New ports collection makefile for:	gnomeaudio2
# Date created:				10 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/gnome-audio/Makefile,v 1.6 2007/06/29 22:55:02 mezz Exp $
#

PORTNAME=	gnome-audio
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-audio/2.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound files for use with GNOME 2

USE_BZIP2=	yes
USE_XLIB=	yes
NO_BUILD=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier
WRKSRC=		${WRKDIR}/${DISTNAME}/sounds
MAKE_ENV=	prefix=${PREFIX}

.include <bsd.port.mk>
