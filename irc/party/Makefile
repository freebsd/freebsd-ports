# New ports collection makefile for:	party
# Date created:		4 December 1999
# Whom:			James Howard <howardj@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	party
PORTVERSION=	2.12
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.wam.umd.edu/pub/howardjp/software/party/ \
		http://www.wam.umd.edu/~howardjp/software/party/ \
		ftp://dragon.ham.muohio.edu/pub/howardjp/software/party/

MAINTAINER=	howardjp@wam.umd.edu

MAN1=	party.1

do-install:
	${INSTALL_SCRIPT} -g nobody -o nobody -m 4711 ${WRKSRC}/party ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/party
	${MKDIR} ${PREFIX}/lib/party/log
	${INSTALL_SCRIPT} ${WRKSRC}/chantab ${WRKSRC}/partytab ${PREFIX}/lib/party
	${TOUCH} ${PREFIX}/lib/party/partytmp
	${TOUCH} ${PREFIX}/lib/party/log/party.log
	${CHOWN} -R nobody:nobody ${PREFIX}/lib/party
	${CP} ${WRKSRC}/party.1 ${PREFIX}/man/man1/

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

.include <bsd.port.mk>
