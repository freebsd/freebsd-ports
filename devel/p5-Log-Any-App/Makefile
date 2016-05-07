# Created by: Evgeniy Kosov <evgeniy@kosov.su>
# $FreeBSD$

PORTNAME=	Log-Any-App
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy way to use Log::Any in applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-File-Write-Rotate>=0.29:devel/p5-File-Write-Rotate \
		p5-IO-Socket-UNIX-Util>=0:net/p5-IO-Socket-UNIX-Util \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-Any-Adapter-Log4perl>=0:devel/p5-Log-Any-Adapter-Log4perl \
		p5-Log-Any-IfLOG>=0.07:devel/p5-Log-Any-IfLOG \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Log-Dispatch-ArrayWithLimits>=0:devel/p5-Log-Dispatch-ArrayWithLimits \
		p5-Log-Dispatch-Dir>=0.08:devel/p5-Log-Dispatch-Dir \
		p5-Log-Dispatch-FileWriteRotate>=0.04:devel/p5-Log-Dispatch-FileWriteRotate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
