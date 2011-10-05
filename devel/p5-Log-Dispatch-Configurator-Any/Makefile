# New ports collection makefile for:	p5-Log-Dispatch-Configurator-Any
# Date created:		2011-10-05
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-Configurator-Any
PORTVERSION=	1.110.690
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurator implementation with Config::Any

BUILD_DEPENDS=	p5-Config-Any>=0.15:${PORTSDIR}/devel/p5-Config-Any \
		p5-Log-Dispatch>=2.23:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Config>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Config
RUN_DEPENDS=	p5-Config-Any>=0.15:${PORTSDIR}/devel/p5-Config-Any \
		p5-Log-Dispatch>=2.23:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Config>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Config

TEST_DEPENDS=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-YAML-Tiny>=0:${PORTSDIR}/textproc/p5-YAML-Tiny

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::Configurator::Any.3

.include <bsd.port.mk>
