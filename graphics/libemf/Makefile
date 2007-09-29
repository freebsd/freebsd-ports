# New ports collection makefile for:	libEMF
# Date created:		04 Oct 2003
# Whom:			NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libEMF
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/libemf/g}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Enhanced Metafile Library

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
