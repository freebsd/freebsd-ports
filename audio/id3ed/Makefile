# New ports collection makefile for:	id3ed
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	id3ed
PORTVERSION=	1.10.4
CATEGORIES=	audio
MASTER_SITES=	http://www.azstarnet.com/~donut/programs/id3ed/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=		id3ed.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/id3ed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3ed.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
