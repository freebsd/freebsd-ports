# New ports collection makefile for:	chasen-base
# Date created:		23 Jul 2001
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/chasen/
PKGNAMESUFFIX=	-base

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	chasen-2.3.3.20030821.patch chasen-2.3.3.20030822.patch chasen-2.3.3.20031024.patch
PATCH_DIST_STRIP=	-p0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Analysis System

BUILD_DEPENDS=	${LOCALBASE}/include/darts.h:${PORTSDIR}/devel/darts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-darts=${LOCALBASE}/include --with-libiconv=${LOCALBASE}
USE_ICONV=	yes
INSTALLS_SHLIB=	yes

post-install:
	${RM} -f ${PREFIX}/lib/libchasen.la
	${MKDIR} ${PREFIX}/share/chasen/dic
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/chasen/doc
	${INSTALL_DATA} ${WRKSRC}/doc/manual* ${PREFIX}/share/chasen/doc/
.endif

.include <bsd.port.mk>
