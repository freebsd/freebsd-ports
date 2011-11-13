# New ports collection makefile for:	p5-Marpa-PP
# Date created:		2011-10-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Marpa-PP
PORTVERSION=	0.010
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}000

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Perl version of Marpa

BUILD_DEPENDS=	p5-PPI>=1.206:${PORTSDIR}/textproc/p5-PPI \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
BUILD_DEPENDS=	p5-PPI>=1.206:${PORTSDIR}/textproc/p5-PPI \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken

TEST_DEPENDS=	p5-Test-Weaken>=3.004000:${PORTSDIR}/devel/p5-Test-Weaken

# PERL_CONFIGURE failed on Perl 5.12.4
PERL_MODBUILD=	5.10.0+

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.21:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.21:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Data-Dumper>=2.125:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Storable>=2.21:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS+=	p5-Data-Dumper>=2.125:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Storable>=2.21:${PORTSDIR}/devel/p5-Storable
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
