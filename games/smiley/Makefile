# New ports collection makefile for:	smiley
# Date created:		15.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	smiley
PORTVERSION=	4.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.fu-berlin.de/pub/unix/misc/smiley/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de
COMMENT=	A "server" to print out a smiley with it's explanation

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		"smiley.1"
PLIST_FILES=	bin/smiley

post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.input
	${SED} "s|%CFLAGS%|${CFLAGS}|" ${WRKSRC}/Makefile.input > ${WRKSRC}/Makefile
	${RM} -f ${WRKSRC}/Makefile.input

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
