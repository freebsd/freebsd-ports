# New ports collection makefile for:	snooper
# Date created:		4 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	snooper
PORTVERSION=	1999.12.02
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/
DISTNAME=	snooper-19991202

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/snooper/build
HAS_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
