# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Marpa-PP
PORTVERSION=	0.014
PORTREVISION=	1
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}000

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Perl version of Marpa

LICENSE=	LGPLv3

BUILD_DEPENDS=	p5-PPI>=1.206:${PORTSDIR}/textproc/p5-PPI \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Weaken>=3.004000:${PORTSDIR}/devel/p5-Test-Weaken

# PERL_CONFIGURE failed on Perl 5.12.4
USE_PERL5=	modbuild
USES=		perl5

MAN3=		Marpa::PP.3 \
		Marpa::PP::Advanced::Bibliography.3 \
		Marpa::PP::Advanced::Models.3 \
		Marpa::PP::Debug.3 \
		Marpa::PP::Grammar.3 \
		Marpa::PP::Recognizer.3 \
		Marpa::PP::Rewrite.3 \
		Marpa::PP::Semantics.3 \
		Marpa::PP::Semantics::Infinite.3 \
		Marpa::PP::Semantics::Null.3 \
		Marpa::PP::Semantics::Order.3 \
		Marpa::PP::Support.3 \
		Marpa::PP::Tracing.3 \
		Marpa::PP::Vocabulary.3

.include <bsd.port.mk>
