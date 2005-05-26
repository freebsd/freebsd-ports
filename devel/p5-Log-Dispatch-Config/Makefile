# New ports collection makefile for:	devel/p5-Log-Dispatch-Config
# Date created:		27 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-Config
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A log4j equivalent for Perl

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch
PM_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
PM_DEPENDS+=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig
PM_DEPENDS+=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::Config.3 \
		Log::Dispatch::Configurator.3 \
		Log::Dispatch::Configurator::AppConfig.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
PM_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
