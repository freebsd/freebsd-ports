# New ports collection makefile for:	xdms
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	xdms
PORTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.ee.tut.fi/~o159219/xdms/
DISTNAME=	xdms

MAINTAINER=	mark@kyne.com.au

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/xdms/src
ALL_TARGET=	xdms

pre-build:
	${PERL} -pi -e "s@gcc@${CC}@g; s@-O3 -Wall@${CFLAGS} -Wall@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdms ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xdms
	${INSTALL_DATA} ${WRKDIR}/xdms/xdms.txt ${PREFIX}/share/doc/xdms
.endif

.include <bsd.port.mk>
