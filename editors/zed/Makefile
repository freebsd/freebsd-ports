# New ports collection makefile for:	zed
# Date created:        4 June 2002
# Whom:                Sten Poldma
#
# $FreeBSD$
#

PORTNAME=	zed
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://zed.c3po.it/

MAINTAINER=	exile@chamber.ee
COMMENT=	Simple, small, fast, highly configurable text editor

DOCS=		CHANGES zed.doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zed ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cfg/zedrc ${PREFIX}/etc/zedrc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
