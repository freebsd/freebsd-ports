# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	POE-Component-Hailo
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HINRIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Non-blocking wrapper around Hailo

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-Hailo>=0:${PORTSDIR}/textproc/p5-Hailo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
