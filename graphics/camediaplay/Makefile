# New ports collection makefile for:	camediaplay
# Version required:	971009
# Date created:		2 May 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.8 1997/10/09 16:10:51 itojun Exp $
#

DISTNAME=	camediaplay-971231-beta
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.itojun.org/pub/digi-cam/C-400L/unix/ \
		ftp://ftp.digipri.co.jp/pub/free-software/Olympus/C-400L/unix/ 

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/camediaplay/build
HAS_CONFIGURE=	yes

DOC=	README.english README.japanese PROTOCOL

# Work-around not being able to apply patches with locked RCS files present.
pre-patch:
	${RM} -rf ${WRKSRC}/../src/RCS

post-install:
	${MKDIR} ${PREFIX}/share/doc/camediaplay
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i \
			${PREFIX}/share/doc/camediaplay; \
	done
	${SED} -e 's@\/usr\/local@${PREFIX}@' < ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
