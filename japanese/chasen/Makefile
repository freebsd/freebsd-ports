# New ports collection makefile for:	chasen
# Version required:	1.51 + 1.5
# Date created:		21 October 1998
# Whom:			kuriyama
#
# $Id: Makefile,v 1.1.1.1 1998/10/21 22:09:44 kuriyama Exp $
#

DISTNAME=	chasen-sys1.51-dic1.5
PKGNAME=	ja-chasen-1.51
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/nlp/tools/chasen/

MAINTAINER=	kuriyama@FreeBSD.ORG

BROKEN=		fetch

WRKSRC=		${WRKDIR}/chasen1.51

post-build:
	${ECHO_MSG} "Making dictionaries"
	(cd ${WRKSRC}; ${MAKE} dic)

.include <bsd.port.mk>
