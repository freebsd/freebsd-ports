# New ports collection makefile for:	ipadic
# Date created:		23 Jul 2001
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.10 2001/04/13 14:54:07 kei Exp $
# $FreeBSD$
#

PORTNAME=	ipadic
PORTVERSION=	2.5.1.1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/ipadic/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Dictionary for ChaSen

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}.diff
PATCH_DIST_STRIP=	-p1

BUILD_DEPENDS=	chasen:${PORTSDIR}/japanese/chasen-base

GNU_CONFIGURE=	YES
USE_LIBTOOL_VER=13

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${PREFIX}/share/chasen/dic/ipadic/chasenrc.example

.include <bsd.port.mk>
