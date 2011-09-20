# New ports collection makefile for:	devel/p5-Log-Dispatchouli
# Date created:				2011-09-19
# Whom:					Geraud CONTINSOUZAS <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatchouli
PORTVERSION=	2.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Log events to an array (reference)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Array>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Array \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Sub-Exporter-GlobExporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter-GlobExporter \
		p5-String-Flogger>=0:${PORTSDIR}/textproc/p5-String-Flogger
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Log::Dispatchouli.3 \
	Log::Dispatchouli::Global.3 \
	Log::Dispatchouli::Proxy.3

.include <bsd.port.mk>
