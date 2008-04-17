# New ports collection makefile for:	Encode::EUCJPMS
# Date created:		25 August 2006
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Encode-EUCJPMS
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	japanese converters perl5
MASTER_SITES=	CPAN

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Perl5 module defining Microsoft compatible encodings for Japanese

PERL_CONFIGURE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
