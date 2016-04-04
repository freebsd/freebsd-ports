# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	Log-Dispatchouli
PORTVERSION=	2.012
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Log events to an array (reference)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Array>=0:devel/p5-Log-Dispatch-Array \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-String-Flogger>=0:textproc/p5-String-Flogger \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Sub-Exporter-GlobExporter>=0.002:devel/p5-Sub-Exporter-GlobExporter \
		p5-Sys-Syslog>=0.16:sysutils/p5-Sys-Syslog \
		p5-Try-Tiny>=0.04:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
