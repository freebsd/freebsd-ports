# ex:ts=8
# Ports collection makefile for:	p5-Module-Pluggable-Fast
# Created by: ijliao
# $FreeBSD$

PORTNAME=	Module-Pluggable-Fast
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast plugins with instantiation

BUILD_DEPENDS=	p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Module::Pluggable::Fast.3

.include <bsd.port.mk>
