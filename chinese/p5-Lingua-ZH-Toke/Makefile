# Ports collection makefile for:	p5-Lingua-ZH-Toke
# Date Created:			Oct 13th 2003
# Whom:				clsung@dragon2.net
#
# $FreeBSD$

PORTNAME=	Lingua-ZH-Toke
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Chinese Tokenizer on steroids

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Lingua/ZH/TaBE.pm:${PORTSDIR}/chinese/p5-Lingua-ZH-TaBE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::ZH::Toke.3

.include <bsd.port.mk>
