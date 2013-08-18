# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Marpa-XS
PORTVERSION=	1.008000
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS version of Marpa

LICENSE=	LGPLv3

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

PERL_CONFIGURE=	yes

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

.include <bsd.port.mk>
