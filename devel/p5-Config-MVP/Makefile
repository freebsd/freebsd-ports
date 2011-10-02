# New ports collection makefile for:	Config-MVP
# Date created: 			27 December 2009
# Whom:					andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Config-MVP
PORTVERSION=	2.200001
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multivalue-property package-oriented configuration

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.91:${PORTSDIR}/devel/p5-Moose \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-MooseX-OneArgNew>=0:${PORTSDIR}/devel/p5-MooseX-OneArgNew \
		p5-Role-HasMessage>=0:${PORTSDIR}/devel/p5-Role-HasMessage \
		p5-Role-Identifiable>=0:${PORTSDIR}/devel/p5-Role-Identifiable \
		p5-Class-Load>0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Throwable>=0:${PORTSDIR}/devel/p5-Throwable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	YES
MAN3=	Config::MVP.3\
	Config::MVP::Assembler.3\
	Config::MVP::Assembler::WithBundles.3\
	Config::MVP::Error.3\
	Config::MVP::Reader.3\
	Config::MVP::Reader::Findable.3\
	Config::MVP::Reader::Findable::ByExtension.3 \
	Config::MVP::Reader::Finder.3\
	Config::MVP::Reader::Hash.3\
	Config::MVP::Section.3\
	Config::MVP::Sequence.3

.include <bsd.port.mk>
