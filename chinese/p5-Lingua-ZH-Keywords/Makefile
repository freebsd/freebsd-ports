# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-Keywords
# Date Created:			Oct 10, 2003
# Whom:				clsung
#
# $FreeBSD$

PORTNAME=	Lingua-ZH-Keywords
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese Keywords Extraction via Lingua::ZH::TaBE

BUILD_DEPENDS=	p5-Lingua-ZH-TaBE>=0:${PORTSDIR}/chinese/p5-Lingua-ZH-TaBE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Lingua::ZH::Keywords.3

.include <bsd.port.mk>
