# Created by: Evgeniy Kosov <evgeniy@kosov.su>
# $FreeBSD$

PORTNAME=	Log-Any-App
PORTVERSION=	0.43
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy way to use Log::Any in applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Log-Any-Adapter-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Any-Adapter-Log4perl \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Dir>=0.08:${PORTSDIR}/devel/p5-Log-Dispatch-Dir \
		p5-Log-Dispatch-FileRotate>=0:${PORTSDIR}/devel/p5-Log-Dispatch-FileRotate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
