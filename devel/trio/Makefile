# ex:ts=8
# New ports collection makefile for:	trio
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	trio
PORTVERSION=	1.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ctrio

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A fully matured and stable set of printf and string functions

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOCSDIR}/doc
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/*.* ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
