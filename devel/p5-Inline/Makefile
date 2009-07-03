# New ports collection makefile for:	Inline
# Date created:		14 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Inline
PORTVERSION=	0.45
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Write Perl subroutines in other programming languages

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.8:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Inline-API.3 Inline-FAQ.3 Inline-Support.3 Inline.3 \
		Inline::C-Cookbook.3 Inline::C.3 \
		Inline::C::ParseRecDescent.3 Inline::C::ParseRegExp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.09:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
