# New ports collection makefile for:	kakasi
# Date created:			26 Mar. 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	2.3.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://kakasi.namazu.org/pub/kakasi/

MAINTAINER=	max@FreeBSD.org

GNU_CONFIGURE=	yes

MANLANG=		ja
MAN1=			kakasi.1

post-install:
	@${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/doc/kakasi.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/kakasi
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/kakasi
.endif

.include <bsd.port.mk>
