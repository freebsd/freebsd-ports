# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	Log-Dispatchouli
PORTVERSION=	2.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Log events to an array (reference)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Array>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Array \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-String-Flogger>=0:${PORTSDIR}/textproc/p5-String-Flogger \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Exporter-GlobExporter>=0.002:${PORTSDIR}/devel/p5-Sub-Exporter-GlobExporter \
		p5-Sys-Syslog>=0.16:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-Try-Tiny>0.04:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

MAN3=	Log::Dispatchouli.3 \
	Log::Dispatchouli::Global.3 \
	Log::Dispatchouli::Proxy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
