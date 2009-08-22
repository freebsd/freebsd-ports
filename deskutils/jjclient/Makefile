# New ports collection makefile for:	jjclient
# Date created:				07 June 2008
# Whom:					Lucas Holt <luke@justjournal.com>
#
# $FreeBSD$
#

PORTNAME=	jjclient
PORTVERSION=	1.0.2
CATEGORIES=	deskutils
MASTER_SITES=	SF/justjournal/JustJournal%20UNIX%20Client/${PORTVERSION} \
		http://www.justjournal.com/software/unix/


MAINTAINER=	luke@justjournal.com
COMMENT=	A command line client for posting JustJournal entries

LIB_DEPENDS+=	xmlrpc.9:${PORTSDIR}/net/xmlrpc-c

PLIST_FILES=	bin/jjclient

.include <bsd.port.mk>
