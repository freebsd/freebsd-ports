# New ports collection makefile for:	wavbreaker
# Date created:				20 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	wavbreaker
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	http://huli.org/wavbreaker/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Tool to split wav files

USE_GNOME=	gtk20 libxml2 gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
