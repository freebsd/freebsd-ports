# New ports collection makefile for:	chasen-base
# Date created:		23 Jul 2001
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	2.4.4
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=     chasen-legacy/32224
PKGNAMESUFFIX=	-base

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Analysis System

BUILD_DEPENDS=	${LOCALBASE}/include/darts.h:${PORTSDIR}/devel/darts

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-darts=${LOCALBASE}/include --with-libiconv=${LOCALBASE}
USE_ICONV=	yes
USE_LDCONFIG=	yes

post-install:
	${RM} -f ${PREFIX}/lib/libchasen.la
	${MKDIR} ${PREFIX}/share/chasen/dic
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual* ${DOCSDIR}
.endif

.include <bsd.port.mk>
