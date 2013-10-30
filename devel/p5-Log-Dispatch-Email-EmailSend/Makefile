# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Email-EmailSend
DISTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subclass of Log-Dispatch-Email that uses Email-Send

BUILD_DEPENDS=	p5-Email-Send>=2.0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple>=2.100:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Log-Dispatch>=2.0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
