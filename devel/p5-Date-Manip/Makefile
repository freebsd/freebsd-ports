# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Date-Manip
PORTVERSION=	6.43
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SBECK
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl5 module containing date manipulation routines

BUILD_DEPENDS=	p5-YAML-Syck>=1.15:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	p5-YAML-Syck>=1.15:${PORTSDIR}/textproc/p5-YAML-Syck
TEST_DEPENDS=	p5-Test-Inter>=0:${PORTSDIR}/devel/p5-Test-Inter

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
