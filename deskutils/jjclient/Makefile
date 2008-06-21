# New ports collection makefile for:	jjclient
# Date created:				07 June 2008
# Whom:					Lucas Holt <luke@justjournal.com>
#
# $FreeBSD$
#

PORTNAME=	jjclient
PORTVERSION=	1.0
CATEGORIES=	deskutils
MASTER_SITES=	http://www.justjournal.com/software/unix/
DISTNAME=	${PORTNAME}_1.0

MAINTAINER=	luke@justjournal.com
COMMENT=	A command line client for posting JustJournal entries

LIB_DEPENDS+=	xmlrpc.9:${PORTSDIR}/net/xmlrpc-c

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/jjclient

.include <bsd.port.mk>
