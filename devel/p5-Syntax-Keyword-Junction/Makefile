# $FreeBSD$

PORTNAME=	Syntax-Keyword-Junction
PORTVERSION=	0.003006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl6 style Junction operators in Perl5

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	p5-syntax>=0:${PORTSDIR}/devel/p5-syntax \
		p5-Sub-Exporter-Progressive>=0.001.006:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Syntax::Feature::Junction.3 \
		Syntax::Keyword::Junction.3 \
		Syntax::Keyword::Junction::All.3 \
		Syntax::Keyword::Junction::Any.3 \
		Syntax::Keyword::Junction::Base.3 \
		Syntax::Keyword::Junction::None.3 \
		Syntax::Keyword::Junction::One.3

.include <bsd.port.mk>
