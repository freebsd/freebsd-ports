# New ports collection makefile for:	Blackened IRC client
# Version required:	1.7.0
# Date created:		11 Jun 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $Id: Makefile,v 1.4 1999/08/01 00:46:36 cpiazza Exp $
#

DISTNAME=	blackened-${VERSION}
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.blackened.com/pub/irc/blackened/ \
		http://www.psn.net/~andrews/blackened/

MAINTAINER=	andrews@technologist.com

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
VERSION=	1.7.0
PLIST_SUB=	VERSION=${VERSION}

MAKE_ENV=	prefix=${PREFIX}

.include <bsd.port.mk>
