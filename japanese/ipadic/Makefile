# New ports collection makefile for:	ipadic
# Date created:		23 Jul 2001
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.10 2001/04/13 14:54:07 kei Exp $
# $FreeBSD$
#

PORTNAME=	ipadic
PORTVERSION=	2.5.1
CATEGORIES=	japanese
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Japanese Morphological Dictionary for ChaSen

BUILD_DEPENDS=	chasen:${PORTSDIR}/japanese/chasen-base

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${PREFIX}/share/chasen/dic/ipadic/chasenrc.example

.include <bsd.port.mk>
