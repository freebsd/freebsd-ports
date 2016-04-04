# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sub-Exporter-Lexical
PORTVERSION=	0.092292
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Export lexically-available subs with Sub::Exporter

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0:devel/p5-B-Hooks-EndOfScope \
		p5-Lexical-Var>=0:devel/p5-Lexical-Var \
		p5-Sub-Exporter>=0.978:devel/p5-Sub-Exporter \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
