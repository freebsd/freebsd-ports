# New ports collection makefile for:   wmrecord
# Date created:        2 April 2001
# Whom:                Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmrecord
PORTVERSION=	1.0.5
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.bruhaha.co.uk/

MAINTAINER=	kkonstan@daemon.gr

USE_XPM=	YES
USE_X_PREFIX=	YES

MAN1=		wmrecord.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmrecord ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/wmrecord.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
