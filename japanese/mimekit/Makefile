# New ports collection makefile for:	mimekit
# Date created:			9 April 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mimekit
PORTVERSION=	1.9
CATEGORIES=	japanese devel mail
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/
DISTNAME=	delegate8.9.6-pre11

MAINTAINER=	max@FreeBSD.org
COMMENT=	Library to handle messages with MIME-encoded headers

WRKSRC=		${WRKDIR}/${DISTNAME}/mimekit
.if !defined(NOPORTDOCS)
PORTDOCS=	README README-LIB README-PGP
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deMime ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/enMime ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libmimekit.a ${PREFIX}/lib
	${RANLIB} ${PREFIX}/lib/libmimekit.a

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
