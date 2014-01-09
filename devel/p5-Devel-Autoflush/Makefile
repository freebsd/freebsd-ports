# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-Autoflush
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Set autoflush from the command line

BUILD_DEPENDS=	p5-IO-CaptureOutput>0:${PORTSDIR}/devel/p5-IO-CaptureOutput
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
