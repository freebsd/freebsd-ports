# $FreeBSD$

PORTNAME=	Devel-StackTrace-WithLexicals
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Devel::StackTrace + PadWalker

RUN_DEPENDS=	\
	p5-Devel-StackTrace>=1.25:${PORTSDIR}/devel/p5-Devel-StackTrace \
	p5-PadWalker>=1.92:${PORTSDIR}/devel/p5-PadWalker
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Devel::StackTrace::WithLexicals.3

NO_STAGE=	yes
.include <bsd.port.mk>
