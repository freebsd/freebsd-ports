# New ports collection makefile for:   as80
# Date created:        02 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	as80
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.tstrathmann.de/files/

MAINTAINER=	greid@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	as80

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/as80 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/as80
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/as80
.endif

.include <bsd.port.mk>
