# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Devel-ebug
PORTVERSION=	0.55
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple, extensible Perl debugger

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-Class-Accessor-Chained>0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Devel-StackTrace>0:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Proc-Background>0:${PORTSDIR}/devel/p5-Proc-Background \
		p5-String-Koremutake>0:${PORTSDIR}/textproc/p5-String-Koremutake
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
		p5-Test-Expect>=0:${PORTSDIR}/devel/p5-Test-Expect

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
