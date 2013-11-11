# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	smiley
PORTVERSION=	4.0
CATEGORIES=	games
MASTER_SITES=	# No external mirror available anymore

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server to print out a smiley with it's explanation

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/smiley man/man1/smiley.1.gz

post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.input
	${SED} "s|%CFLAGS%|${CFLAGS}|" ${WRKSRC}/Makefile.input > ${WRKSRC}/Makefile
	${RM} -f ${WRKSRC}/Makefile.input

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/smiley.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
