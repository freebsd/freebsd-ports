# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Rose-DB-Object
PORTVERSION=	0.8080
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible, high performance RDBMS-OO mapper

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Clone>=0.29:${PORTSDIR}/devel/p5-Clone \
		p5-DBI>=1.400:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Rose-DB>=0.763,1:${PORTSDIR}/databases/p5-Rose-DB \
		p5-Rose-DateTime>=0.532,1:${PORTSDIR}/devel/p5-Rose-DateTime \
		p5-Rose-Object>=0.854:${PORTSDIR}/devel/p5-Rose-Object \
		p5-Time-Clock>=1:${PORTSDIR}/devel/p5-Time-Clock
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
