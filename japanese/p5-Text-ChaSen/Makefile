# New ports collection makefile for:	p5-Text-ChaSen
# Date created:		2 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Text-ChaSen
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	http://chasen.aist-nara.ac.jp/stable/chasen/
DISTNAME=	chasen-${CHASEN_VERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	ChaSen library module for Perl5

LIB_DEPENDS=	chasen.0:${PORTSDIR}/japanese/chasen-base

MD5_FILE=	${.CURDIR}/../chasen-base/distinfo

CHASEN_VERSION=	2.3.3

WRKSRC=		${WRKDIR}/chasen-${CHASEN_VERSION}/perl
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}"
MAN3=		Text::ChaSen.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/chasen/doc/README.perl
.endif

.include <bsd.port.post.mk>
