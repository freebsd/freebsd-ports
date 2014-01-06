# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Log-Dispatch-File-Stamped
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Logging to date/time stamped files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Dispatch>=2.38:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Path-Tiny>0:${PORTSDIR}/devel/p5-Path-Tiny \
		p5-Test-CheckDeps>=0.002:${PORTSDIR}/devel/p5-Test-CheckDeps \
		p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-TempDir>0:${PORTSDIR}/devel/p5-Test-TempDir

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
