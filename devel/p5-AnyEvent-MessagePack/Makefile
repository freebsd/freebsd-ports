# $FreeBSD$

PORTNAME=	AnyEvent-MessagePack
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of AnyEvent for MessagePack

RUN_DEPENDS=	\
	p5-AnyEvent>=7.02:${PORTSDIR}/devel/p5-AnyEvent \
	p5-Data-MessagePack>=0.46:${PORTSDIR}/devel/p5-Data-MessagePack \
	p5-Data-MessagePack-Stream>=0.07:${PORTSDIR}/devel/p5-Data-MessagePack-Stream
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	AnyEvent::MessagePack.3

.include <bsd.port.mk>
