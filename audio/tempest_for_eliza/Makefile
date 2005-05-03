# New ports collection makefile for:   tempest_for_eliza
# Date created:        17 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tempest_for_eliza
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.erikyyy.de/tempest/

MAINTAINER=	r.c.ladan@student.tue.nl
COMMENT=	A program to send AM radio signals using a PC monitor

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl

post-install:
	@${MKDIR} ${PREFIX}/share/tempest
.for S in forelise jonny fruehling saints oldmacdonald ungarian \
	godfather starwars tempest
	@${INSTALL_DATA} ${WRKSRC}/songs/$S ${PREFIX}/share/tempest
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
