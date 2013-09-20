# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	Devel-CheckLib
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl5 module to check that a library is available

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-CaptureOutput>=1.08:${PORTSDIR}/devel/p5-IO-CaptureOutput
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		use-devel-checklib.1
MAN3=		Devel::CheckLib.3

NO_STAGE=	yes
.include <bsd.port.mk>
