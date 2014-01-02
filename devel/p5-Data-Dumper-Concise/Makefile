# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=	Data-Dumper-Concise
PORTVERSION=	2.021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FREW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Less indentation and newlines plus sub deparsing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS =	p5-Error>=0:${PORTSDIR}/lang/p5-Error

OPTIONS_DEFINE=	ARGNAMES
OPTIONS_DEFAULT=ARGNAMES
ARGNAMES_DESC=	Enable DwarnN subroutine

ARGNAMES_BUILD_DEPENDS=	p5-Devel-ArgNames>=0.03:${PORTSDIR}/devel/p5-Devel-ArgNames
ARGNAMES_RUN_DEPENDS=	p5-Devel-ArgNames>=0.03:${PORTSDIR}/devel/p5-Devel-ArgNames

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
