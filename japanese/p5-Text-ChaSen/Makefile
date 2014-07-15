# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Text-ChaSen
PORTVERSION=	1.03
PORTREVISION=	5
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	chasen-legacy/32224
DISTNAME=	chasen-${CHASEN_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ChaSen library module for Perl5

LIB_DEPENDS=	libchasen.so:${PORTSDIR}/japanese/chasen-base

DISTINFO_FILE=	${.CURDIR}/../chasen-base/distinfo

CHASEN_VERSION=	2.4.5

WRKSRC=		${WRKDIR}/chasen-${CHASEN_VERSION}/perl
USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PREFIX="${PREFIX}"
DOCSDIR=	${PREFIX}/share/doc/chasen

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README.perl
.endif

.include <bsd.port.post.mk>
