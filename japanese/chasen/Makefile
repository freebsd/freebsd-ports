# New ports collection makefile for:	chasen
# Version required:	1.51 + 1.5
# Date created:		21 October 1998
# Whom:			kuriyama
#
# $FreeBSD$
#

DISTNAME=	chasen-sys1.51-dic1.5
PKGNAME=	ja-chasen-1.51
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/lab/nlp/tools/chasen/ \
		http://www.freebsd.org/~kuriyama/distfiles/

MAINTAINER=	kuriyama@FreeBSD.ORG

WRKSRC=		${WRKDIR}/chasen1.51

post-build:
	${ECHO_MSG} "Making dictionaries"
	(cd ${WRKSRC}; ${MAKE} dic)

.include <bsd.port.mk>
