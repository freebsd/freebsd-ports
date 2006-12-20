# New ports collection makefile for:	mpck
# Date created:				25 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	checkmate
PORTVERSION=	0.15
CATEGORIES=	audio
MASTER_SITES=	http://checkmate.linuxonly.nl/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line utility for checking mp3 files for errors

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		mpck.1
MLINKS=		mpck.1 checkmate.1
PLIST_FILES=	bin/mpck

.include <bsd.port.mk>
