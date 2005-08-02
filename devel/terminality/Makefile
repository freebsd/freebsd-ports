# ex:ts=8
# New ports collection makefile for:	terminality
# Date created:			Apr 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	terminality
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	http://freebsd.t-hosting.hu/${PORTNAME}/
DISTNAME=	tn-${PORTVERSION}

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	A cross-platform terminal manipulation library

do-install:
	@${MKDIR} ${PREFIX}/include/tn
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/tn
	${INSTALL_DATA} ${WRKSRC}/libtn.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/screenshot
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
