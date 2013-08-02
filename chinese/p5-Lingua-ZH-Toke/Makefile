# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Lingua-ZH-Toke
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Chinese Tokenizer on steroids

BUILD_DEPENDS=	p5-Lingua-ZH-TaBE>=0:${PORTSDIR}/chinese/p5-Lingua-ZH-TaBE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Lingua::ZH::Toke.3

.include <bsd.port.mk>
