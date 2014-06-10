# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	String-Errf
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Simple sprintf-like dialect

RUN_DEPENDS=	p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-String-Formatter>=0.102081:${PORTSDIR}/devel/p5-String-Formatter
BUILD_DEPENDS:=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-autodie>=0:${PORTSDIR}/devel/p5-autodie \
		${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
