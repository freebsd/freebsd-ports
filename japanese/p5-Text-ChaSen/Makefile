# New ports collection makefile for:	p5-Text-ChaSen
# Date created:		2 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Text-ChaSen
PORTVERSION=	1.03
PORTREVISION=	4
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	chasen-legacy/32224
DISTNAME=	chasen-${CHASEN_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ChaSen library module for Perl5

LIB_DEPENDS=	chasen.2:${PORTSDIR}/japanese/chasen-base

DISTINFO_FILE=	${.CURDIR}/../chasen-base/distinfo

CHASEN_VERSION=	2.4.4

WRKSRC=		${WRKDIR}/chasen-${CHASEN_VERSION}/perl
USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PREFIX="${PREFIX}"
MAN3=		Text::ChaSen.3
DOCSDIR=	${PREFIX}/share/doc/chasen

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README.perl
.endif

.include <bsd.port.post.mk>
