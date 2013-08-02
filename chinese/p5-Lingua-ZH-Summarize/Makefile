# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-Summarize
# Date Created:			Oct 10, 2003
# Whom:				clsung
#
# $FreeBSD$

PORTNAME=	Lingua-ZH-Summarize
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese Text Summarization

BUILD_DEPENDS=	p5-Lingua-ZH-Toke>=0:${PORTSDIR}/chinese/p5-Lingua-ZH-Toke \
		p5-Lingua-ZH-Wrap>=0:${PORTSDIR}/chinese/p5-Lingua-ZH-Wrap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Lingua::ZH::Summarize.3

.include <bsd.port.mk>
