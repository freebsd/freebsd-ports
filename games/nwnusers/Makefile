# New ports collection makefile for:	nwnusers
# Date created:				19 December 2002
# Whom:					Andreas Heil <ah@linux-hq.de>
#
# $FreeBSD$
#

PORTNAME=	nwnusers
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://www.linux-hq.de/pub/
DISTNAME=	nwnusers-v1.4

MAINTAINER=	ah@linux-hq.de
COMMENT=	A tool for monitoring Neverwinter Nights Server with mrtg

PLIST_FILES=	bin/nwnusers

do-build:
	cd ${WRKDIR}/${DISTNAME} &&\
	${CC} ${CFLAGS} -Wall -Werror -DVERSION=\"${PORTVERSION}\" -o nwnusers nwnusers.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/nwnusers ${PREFIX}/bin/nwnusers

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
