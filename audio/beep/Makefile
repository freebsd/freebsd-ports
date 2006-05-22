# New ports collection makefile for:	beep
# Date Created:				June 9, 2002
# Whom:					Tyler Spivey
#
# $FreeBSD$

PORTNAME=	beep
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://ftp.osuosl.org/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beeps a certain duration and pitch out of the PC Speaker

MAN1=		beep.1
MANCOMPRESSED=	maybe
WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386

PLIST_FILES=	bin/beep

.include <bsd.port.mk>
