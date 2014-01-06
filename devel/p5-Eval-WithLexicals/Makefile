# $FreeBSD$

PORTNAME=	Eval-WithLexicals
PORTVERSION=	1.002000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for pure perl eval with persistent lexical variables

RUN_DEPENDS=	\
	p5-Moo>=0.009006:${PORTSDIR}/devel/p5-Moo
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
