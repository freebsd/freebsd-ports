# New ports collection makefile for:	p5-Text-ChaSen
# Date created:		2 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Text-ChaSen
PORTVERSION=	0.20
CATEGORIES=	japanese perl5
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/lab/nlp/tools/chasen/
DISTNAME=	chasen-sys${CHASEN_VERSION}-ipadic2.1

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	chasen.0:${PORTSDIR}/japanese/chasen

MD5_FILE=	${.CURDIR}/../chasen/distinfo

CHASEN_VERSION=	2.02

WRKSRC=		${WRKDIR}/chasen-${CHASEN_VERSION}/perl
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}"
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Text::ChaSen.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/chasen/ja/README.perl
.endif

.include <bsd.port.post.mk>
