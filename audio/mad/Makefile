# New ports collection makefile for:	mad
# Date created:		18 November 2000
# Whom:			Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	mad
PORTVERSION=	0.15.0b
CATEGORIES=	audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	asa@gascom.ru
COMMENT=	The "meta-port" for the MAD sound playback system

RUN_DEPENDS=	madplay:${PORTSDIR}/audio/madplay
LIB_DEPENDS=	id3tag.2:${PORTSDIR}/audio/libid3tag

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
