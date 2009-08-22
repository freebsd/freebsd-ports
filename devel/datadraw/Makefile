# ex:ts=8
# Ports collection makefile for:	datadraw
# Date created:			Aug 31, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	datadraw
PORTVERSION=	3.1.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A feature rich persistent database generator

USE_BISON=	build
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

.if !defined(NOPORTDOCS)
PORTDOCS=	*

post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/www/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
