# New ports collection makefile for:	gnomeaudio2
# Date created:				10 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeaudio
PORTVERSION=	2.0.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-audio/2.0
PKGNAMESUFFIX=	2
DISTNAME=	gnome-audio-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound files for use with GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier
WRKSRC=		${WRKDIR}/${DISTNAME}/sounds

.include <bsd.port.mk>
