# New ports collection makefile for:	rbldnsd
# Date created:				Fri Jun 13 05:30:12 EDT 2003
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	rbldnsd
PORTVERSION=	0.991
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/rbldnsd/:0 \
		http://www.it.ca/~paul/src/:0
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}:0

MAINTAINER=	paul+ports@it.ca
COMMENT=	Small and fast DNS daemon especially for DNSBL zones

BROKEN=		"Checksum mismatch"

.if !defined(NOPORTDOCS)
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}
MASTER_SITES+=	http://www.corpit.ru/mjt/:1 \
		http://www.it.ca/~paul/src/:1
DISTFILES+=	rbldnsd.html:1
.endif

MAN8=		rbldnsd.8

HAS_CONFIGURE=	yes

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/rbldnsd ${PREFIX}/sbin/
		@${INSTALL_MAN} ${WRKSRC}/rbldnsd.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/CHANGES-0.81 ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/rbldnsd.spec ${DOCSDIR}
		@${INSTALL_DATA} ${DISTDIR}/rbldnsd.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
