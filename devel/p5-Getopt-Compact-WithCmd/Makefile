# Created by: Kan Sasaki <sasaki@fcc.ad.jp>
# $FreeBSD$

PORTNAME=	Getopt-Compact-WithCmd
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sub-command friendly, like Getopt::Compact

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Text-Table>=0:textproc/p5-Text-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
