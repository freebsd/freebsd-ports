# New ports collection makefile for:	camediaplay
# Version required:	970803
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.5 1997/07/15 14:47:25 itojun Exp $
#

DISTNAME=	camediaplay-970803
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.csl.sony.co.jp/pub/C-400L/unix/

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/camediaplay/build
HAS_CONFIGURE=	yes

DOC=	README.english README.japanese PROTOCOL

post-install:
	${MKDIR} ${PREFIX}/share/doc/camediaplay
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i \
			${PREFIX}/share/doc/camediaplay; \
	done
	${SED} -e 's@\/usr\/local@${PREFIX}@' < ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
