# Created by: ijliao
# $FreeBSD$

PORTNAME=	VCG
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEEJAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the VCG graphing tool

BUILD_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		xvcg:${PORTSDIR}/graphics/vcg

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
