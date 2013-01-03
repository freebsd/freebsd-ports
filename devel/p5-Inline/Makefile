# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines in other programming languages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.800:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Inline-Files>=0:${PORTSDIR}/devel/p5-Inline-Files

PERL_CONFIGURE=	yes

MAN3=		Inline.3 \
		Inline-API.3 \
		Inline-FAQ.3 \
		Inline-Support.3 \
		Inline::C.3 \
		Inline::C-Cookbook.3 \
		Inline::C::ParseRecDescent.3 \
		Inline::C::ParseRegExp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
TEST_DEPENDS+=	p5-Test-Warn>=0.23:${PORTSDIR}/devel/p5-Test-Warn
.else
TEST_DEPENDS+=	p5-Test-Warn>=0.21:${PORTSDIR}/devel/p5-Test-Warn
.endif

.include <bsd.port.post.mk>
