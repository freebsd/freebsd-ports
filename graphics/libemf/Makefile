# New ports collection makefile for:	libEMF
# Date created:		04 Oct 2003
# Whom:			NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libEMF
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Enhanced Metafile Library

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
