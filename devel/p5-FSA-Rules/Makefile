# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FSA-Rules
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build simple rules-based state machines in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-GraphViz>=2:${PORTSDIR}/graphics/p5-GraphViz \
		p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		FSA::Rules.3

.include <bsd.port.mk>
