# New ports collection makefile for:	listener
# Date created:			2004-11-24
# Whom:				lx
#
# $FreeBSD$
#

PORTNAME=	listener
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.vanheusden.com/listener/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A program to listen for and record sound activity

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

DOCS=		INSTALL

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
