# $FreeBSD$

PORTNAME=	Module-Functions
PORTVERSION=	2.1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to get function list from package

RUN_DEPENDS=	\
	p5-Sub-Identify>=0.04:${PORTSDIR}/devel/p5-Sub-Identify
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Module::Functions.3

NO_STAGE=	yes
.include <bsd.port.mk>
