# New ports collection makefile for:	snooper
# Date created:		4 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.2 1997/05/25 18:34:39 max Exp $
#

DISTNAME=	snooper.980813
PKGNAME=	snooper-980813
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/snooper/build
HAS_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
