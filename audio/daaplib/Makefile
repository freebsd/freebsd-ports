# New ports collection makefile for:	daaplib
# Date created:				19 October 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	daaplib
PORTVERSION=	0.1.1a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.deleet.de/projekte/daap/daaplib/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A C++ library for DAAP memory streams

USE_ZIP=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/daaplib/src
MAKEFILE=	makefile
ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/${MAKEFILE}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
