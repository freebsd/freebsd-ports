# New ports collection makefile for:	mpeg2play
# Version required:	1.1b
# Date created:		June 21, 1996
# Whom:			"Philippe Charnier" <charnier@lirmm.fr>
#
# $Id$
#

DISTNAME=	mpeg2play-1.1b
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.netcom.com/pub/cf/cfogg/mpeg2/
DISTFILES=	mpeg2play_v1.1b.tar.gz

MAINTAINER=	charnier@lirmm.fr

USE_X11=	yes
WRKSRC=		${WRKDIR}/mpeg2play

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/mpeg2play ${PREFIX}/bin

.include <bsd.port.mk>
