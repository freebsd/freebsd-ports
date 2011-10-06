# New ports collection makefile for:	devel/p5-Log-Dispatch-Config
# Date created:		27 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-Config
PORTVERSION=	1.04
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A log4j equivalent for Perl

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-AppConfig>=1.52:${PORTSDIR}/devel/p5-AppConfig \
		p5-Log-Dispatch>=2:${PORTSDIR}/devel/p5-Log-Dispatch
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::Config.3 \
		Log::Dispatch::Configurator.3 \
		Log::Dispatch::Configurator::AppConfig.3

.include <bsd.port.mk>
