# New ports collection makefile for:	p5-Marpa-XS
# Date created:		2011-10-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Marpa-XS
PORTVERSION=	1.002000
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS version of Marpa

BUILD_DEPENDS=	p5-ExtUtils-CBuilder>=0.27:${PORTSDIR}/devel/p5-ExtUtils-CBuilder \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.223:${PORTSDIR}/devel/p5-Glib2 \
		p5-PPI>=1.206:${PORTSDIR}/textproc/p5-PPI \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS=	p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.223:${PORTSDIR}/devel/p5-Glib2 \
		p5-PPI>=1.206:${PORTSDIR}/textproc/p5-PPI \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken

TEST_DEPENDS=	p5-Test-Weaken>=3.004000:${PORTSDIR}/devel/p5-Test-Weaken

PERL_CONFIGURE=	5.10.0+

MAN3=		Marpa::XS.3 \
		Marpa::XS::Advanced::Bibliography.3 \
		Marpa::XS::Advanced::Models.3 \
		Marpa::XS::Debug.3 \
		Marpa::XS::Grammar.3 \
		Marpa::XS::Recognizer.3 \
		Marpa::XS::Rewrite.3 \
		Marpa::XS::Semantics.3 \
		Marpa::XS::Semantics::Infinite.3 \
		Marpa::XS::Semantics::Null.3 \
		Marpa::XS::Semantics::Order.3 \
		Marpa::XS::Support.3 \
		Marpa::XS::Tracing.3 \
		Marpa::XS::Vocabulary.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.21:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.21:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Data-Dumper>=2.125:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS+=	p5-Data-Dumper>=2.125:${PORTSDIR}/devel/p5-Data-Dumper
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

post-patch:
	@${REINPLACE_CMD} -e '/Test::Weaken->VERSION/ s|!=|<|' ${WRKSRC}/t/weaken.t

.include <bsd.port.post.mk>
