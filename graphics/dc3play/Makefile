# New ports collection makefile for:	dc3play
# Date created:		15 Jul 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	dc3play
PORTVERSION=	19991202
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
