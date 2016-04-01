# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Email-EmailSend
DISTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Subclass of Log-Dispatch-Email that uses Email-Send

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Send>=2.0:mail/p5-Email-Send \
		p5-Email-Simple>=2.100:mail/p5-Email-Simple \
		p5-Log-Dispatch>=2.0:devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
