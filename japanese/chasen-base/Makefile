# New ports collection makefile for:	chasen-base
# Date created:		23 Jul 2001
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	2.2.9
CATEGORIES=	japanese
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/chasen/
PKGNAMESUFFIX=	-base

PATCHFILES=	chasen-${PORTVERSION}-nmz.diff
PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Japanese Morphological Analysis System

GNU_CONFIGURE=	yes
#USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-install:
	${RM} -f ${PREFIX}/lib/libchasen.la
	${MKDIR} ${PREFIX}/share/chasen/dic
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/chasen/doc
	${INSTALL_DATA} ${WRKSRC}/doc/manual* ${PREFIX}/share/chasen/doc/
.endif

.include <bsd.port.mk>
