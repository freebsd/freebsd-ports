# New ports collection makefile for:	p5-Parse-Perl
# Date created:		2010-11-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-Perl
PORTVERSION=	0.007
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interpret string as Perl source

BUILD_DEPENDS=	p5-Devel-CallChecker>=0.003:${PORTSDIR}/devel/p5-Devel-CallChecker
RUN_DEPENDS=	p5-Devel-CallChecker>=0.003:${PORTSDIR}/devel/p5-Devel-CallChecker

TEST_DEPENDS=	p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Lexical-Import>=0:${PORTSDIR}/devel/p5-Lexical-Import \
		p5-Sub-Identify>=0:${PORTSDIR}/devel/p5-Sub-Identify

PERL_CONFIGURE=	yes

MAN3=		Parse::Perl.3 \
		Parse::Perl::CopHintsHash.3 \
		Parse::Perl::Environment.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
