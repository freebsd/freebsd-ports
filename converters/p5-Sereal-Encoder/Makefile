# $FreeBSD$

PORTNAME=	Sereal-Encoder
PORTVERSION=	0.37
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary serialization

TEST_DEPENDS=	\
	p5-Test-LongString>0:${PORTSDIR}/devel/p5-Test-LongString \
	p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn \
	p5-Sereal-Decoder>0:${PORTSDIR}/converters/p5-Sereal-Decoder

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
