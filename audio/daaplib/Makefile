# New ports collection makefile for:	daaplib
# Date created:				19 October 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	daaplib
PORTVERSION=	0.1.1a
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.deleet.de/projekte/daap/daaplib/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A C++ library for DAAP memory streams

DEPRECATED=	Development stalled for years, outdated. Does not support newer versions of DAAP protocol.
EXPIRATION_DATE=	2007-11-04

USE_GCC=	3.4+
USE_ZIP=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/daaplib/src
MAKEFILE=	makefile
ALL_TARGET=

post-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g' \
		-e 's|CC = c\+\+||' \
		${WRKSRC}/${MAKEFILE}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.x
.endif

.include <bsd.port.post.mk>
