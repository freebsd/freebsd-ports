# New ports collection makefile for:	Path-Dispatcher-Declarative
# Date created:		2011-04-05
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Path-Dispatcher-Declarative
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	sugary dispatcher for perl

PERL_CONFIGURE=	yes

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv1

BUILD_DEPENDS=	p5-Path-Dispatcher>=1.02:${PORTSDIR}/devel/p5-Path-Dispatcher \
		p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter

RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Path::Dispatcher::Declarative.3

.include <bsd.port.mk>
