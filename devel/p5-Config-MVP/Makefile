# New ports collection makefile for:	Config-MVP
# Date created: 			27 December 2009
# Whom:					andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Config-MVP
PORTVERSION=	2.101650
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multivalue-property package-oriented configuration

BUILD_DEPENDS=	p5-Moose>=0.91:${PORTSDIR}/devel/p5-Moose \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	YES
MAN3=	Config::MVP.3\
	Config::MVP::Assembler.3\
	Config::MVP::Assembler::WithBundles.3\
	Config::MVP::Reader.3\
	Config::MVP::Reader::Findable.3\
	Config::MVP::Reader::Findable::ByExtension.3 \
	Config::MVP::Reader::Finder.3\
	Config::MVP::Reader::Hash.3\
	Config::MVP::Section.3\
	Config::MVP::Sequence.3

.include <bsd.port.mk>
