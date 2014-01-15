# $FreeBSD$

PORTNAME=	Test-Name-FromLine
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to fill test names from caller line

RUN_DEPENDS=	\
	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
