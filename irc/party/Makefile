# New ports collection makefile for:	party
# Date created:		4 December 1999
# Whom:			James Howard <ports@vocito.com>
#
# $FreeBSD$
#

PORTNAME=	party
PORTVERSION=	2.13
CATEGORIES=	irc
MASTER_SITES=	http://www.vocito.com/downloads/software/party/ \
		ftp://ftp.vocito.com/pub/vocito.com/software/party/

MAINTAINER=	ports@vocito.com
COMMENT=	Simple multi-user chat system

MAN1=	party.1

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
