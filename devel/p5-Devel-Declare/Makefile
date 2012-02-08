# New ports collection makefile for:	Devel-Declare
# Date created:	   16 Aug 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Devel-Declare
PORTVERSION=	0.006010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Adding keywords to perl, in perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sub/Name.pm:${PORTSDIR}/devel/p5-Sub-Name \
		p5-B-Hooks-EndOfScope>=0.05:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-B-Hooks-OP-Check>=0.19:${PORTSDIR}/devel/p5-B-Hooks-OP-Check
BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.302:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}

TEST_DEPENDS=	p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=		Devel::Declare.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
