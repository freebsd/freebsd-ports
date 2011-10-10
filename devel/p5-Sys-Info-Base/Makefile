# New ports collection makefile for:	p5-Sys-Info-Base
# Date created:		2011-10-09
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sys-Info-Base
PORTVERSION=	0.78.02
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Base class for Sys::Info

TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	yes

MAN3=		Sys::Info::Base.3 \
		Sys::Info::Constants.3 \
		Sys::Info::Device.3 \
		Sys::Info::Device::CPU.3 \
		Sys::Info::Driver.3 \
		Sys::Info::OS.3

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
