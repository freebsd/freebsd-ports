# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	smiley
PORTVERSION=	4.0
CATEGORIES=	games
# No external mirror available anymore
#MASTER_SITES=	ftp://ftp.fu-berlin.de/pub/unix/misc/smiley/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A "server" to print out a smiley with it's explanation

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		"smiley.1"
PLIST_FILES=	bin/smiley

NO_STAGE=	yes
post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.input
	${SED} "s|%CFLAGS%|${CFLAGS}|" ${WRKSRC}/Makefile.input > ${WRKSRC}/Makefile
	${RM} -f ${WRKSRC}/Makefile.input

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
