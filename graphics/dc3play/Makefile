# New ports collection makefile for:	dc3play
# Version required:	980321
# Date created:		15 Jul 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.3 1997/09/11 09:51:58 itojun Exp $
#

DISTNAME=	dc3play-980321
PKGNAME=	dc3play-19980321
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.itojun.org/pub/digi-cam/DC-3/unix/ \
		ftp://ftp.digipri.co.jp/pub/free-software/Ricoh/DC-3/unix/

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/dc3play/build
HAS_CONFIGURE=	yes

RESTRICTED=	"Beta test period, redistribution prohibited"

DOC=	README.english README.japanese PROTOCOL

post-install:
	${MKDIR} ${PREFIX}/share/doc/dc3play
	for i in ${DOC}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i \
			${PREFIX}/share/doc/dc3play; \
	done
	${SED} -e 's@\/usr\/local@${PREFIX}@' < ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
