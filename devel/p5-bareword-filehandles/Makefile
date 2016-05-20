# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bareword-filehandles
PORTVERSION=	0.004
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ILMARI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Disables bareword filehandles

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-OP-Check>=0:devel/p5-B-Hooks-OP-Check \
		p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-Lexical-SealRequireHints>=0:devel/p5-Lexical-SealRequireHints
RUN_DEPENDS=	p5-B-Hooks-OP-Check>=0:devel/p5-B-Hooks-OP-Check \
		p5-Lexical-SealRequireHints>=0:devel/p5-Lexical-SealRequireHints

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
