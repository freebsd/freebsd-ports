# New ports collection makefile for:	astyle
# Date created:		31 Jan 1999
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	astyle
PORTVERSION=	1.15.3
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-q -aa
EXTRACT_AFTER_ARGS=	-d ${DISTNAME}

ALL_TARGET=	astyle

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/astyle ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
