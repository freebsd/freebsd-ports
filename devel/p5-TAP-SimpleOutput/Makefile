# $FreeBSD$

PORTNAME=	TAP-SimpleOutput
PORTVERSION=	0.001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	TAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Simple closure-driven TAP generator

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	TAP::SimpleOutput.3

NO_STAGE=	yes
.include <bsd.port.mk>
