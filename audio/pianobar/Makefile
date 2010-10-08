# New ports collection makefile for: pianobar
# Date created: 8 October 2010
# Whom: John Hixson <john@pcbsd.org>
#
# $FreeBSD$
#

PORTNAME=	pianobar
PORTVERSION=	2010.10.07
CATEGORIES=	audio
MASTER_SITES=	http://6xq.net/media/00/16/

MAINTAINER=	john@pcbsd.org
COMMENT=	Command line Pandora player

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
	faad:${PORTSDIR}/audio/faad \
	mad:${PORTSDIR}/audio/libmad

MAN1=	pianobar.1
MAN_COMPRESSED=	no

PLIST_FILES=	bin/pianobar

USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
