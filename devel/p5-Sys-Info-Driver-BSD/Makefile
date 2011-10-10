# New ports collection makefile for:	p5-Sys-Info-Driver-BSD
# Date created:		2011-10-09
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sys-Info-Driver-BSD
PORTVERSION=	0.78.01
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BSD driver for Sys::Info

BUILD_DEPENDS=	p5-BSD-Sysctl>=0.08:${PORTSDIR}/sysutils/p5-BSD-Sysctl \
		p5-Sys-Info-Base>=${PORTVERSION}:${PORTSDIR}/devel/p5-Sys-Info-Base \
		p5-Unix-Processors>=0:${PORTSDIR}/sysutils/p5-Unix-Processors
RUN_DEPENDS=	p5-BSD-Sysctl>=0.08:${PORTSDIR}/sysutils/p5-BSD-Sysctl \
		p5-Sys-Info-Base>=${PORTVERSION}:${PORTSDIR}/devel/p5-Sys-Info-Base \
		p5-Unix-Processors>=0:${PORTSDIR}/sysutils/p5-Unix-Processors

TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Sys-Info>=0.20:${PORTSDIR}/devel/p5-Test-Sys-Info

PERL_CONFIGURE=	yes

MAN3=		Sys::Info::Driver::BSD.3 \
		Sys::Info::Driver::BSD::Device.3 \
		Sys::Info::Driver::BSD::Device::CPU.3 \
		Sys::Info::Driver::BSD::OS.3

.include <bsd.port.mk>
