# New ports collection makefile for:	ipadic
# Date created:		23 Jul 2001
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.10 2001/04/13 14:54:07 kei Exp $
# $FreeBSD$
#

PORTNAME=	ipadic
PORTVERSION=	2.7.0
CATEGORIES=	japanese textproc
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/ipadic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Dictionary for ChaSen

BUILD_DEPENDS=	chasen:${PORTSDIR}/japanese/chasen-base

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-dicdir=${PREFIX}/share/chasen/dic
USE_LIBTOOL_VER=15

post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${PREFIX}/share/chasen/dic/ipadic/chasenrc.example

.include <bsd.port.mk>
