# $FreeBSD$

PORTNAME=	Sereal-Encoder
PORTVERSION=	0.35
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary serialization

TEST_DEPENDS=	\
	p5-Test-LongString>0:${PORTSDIR}/devel/p5-Test-LongString \
	p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn \
	p5-Sereal-Decoder>0:${PORTSDIR}/converters/p5-Sereal-Decoder

PERL_CONFIGURE=	yes

MAN3=	Sereal::Encoder.3

.include <bsd.port.mk>
