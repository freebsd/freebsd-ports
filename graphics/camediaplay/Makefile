# New ports collection makefile for:	camediaplay
# Version required:	970703
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.1.1.1 1997/05/20 06:28:56 asami Exp $
#

DISTNAME=	camediaplay-970703
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/C-400L/unix/

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/camediaplay/build
HAS_CONFIGURE=	yes

RESTRICTED=	"Beta test period, redistribution prohibited"

DOC=	README.english README.japanese PROTOCOL

post-install:
	${MKDIR} ${PREFIX}/share/doc/camediaplay
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i \
			${PREFIX}/share/doc/camediaplay; \
	done
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
