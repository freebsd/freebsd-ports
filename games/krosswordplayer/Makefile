# New ports collection makefile for: 	krosswordplayer
# Date created:				2004-07-01
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	KrossWordPlayer
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://home.houston.rr.com/epasveer/
EXTRACT_SUFX=	.tgz

MAINTAINER=	arved@FreeBSD.org
COMMENT=	KDE crossword puzzle game

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
