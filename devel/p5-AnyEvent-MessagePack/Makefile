# $FreeBSD$

PORTNAME=	AnyEvent-MessagePack
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of AnyEvent for MessagePack

RUN_DEPENDS=	\
	p5-AnyEvent>=7.02:devel/p5-AnyEvent \
	p5-Data-MessagePack>=0.46:devel/p5-Data-MessagePack \
	p5-Data-MessagePack-Stream>=0.07:devel/p5-Data-MessagePack-Stream
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
