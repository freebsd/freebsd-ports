# $FreeBSD$

PORTNAME=	Sereal
PORTVERSION=	0.260
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary (de-)serialization

RUN_DEPENDS=	\
	p5-Sereal-Decoder>=0.25:${PORTSDIR}/converters/p5-Sereal-Decoder \
	p5-Sereal-Encoder>=0.26:${PORTSDIR}/converters/p5-Sereal-Encoder
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Sereal.3

.include <bsd.port.mk>
