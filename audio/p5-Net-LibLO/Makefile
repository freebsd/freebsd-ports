# $FreeBSD$

PORTNAME=	Net-LibLO
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for liblo Lightweight OSC library

LIB_DEPENDS=	liblo.so:${PORTSDIR}/audio/liblo

USES=		pkgconfig perl5
NO_STAGE=	yes
USE_PERL5=	configure

MAN3=	\
	Net::LibLO.3 \
	Net::LibLO::Address.3 \
	Net::LibLO::Bundle.3 \
	Net::LibLO::Message.3

.include <bsd.port.mk>
