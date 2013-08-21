# New ports collection makefile for:	p5-Devel-PackagePath
# Date created:		2011-05-31
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-PackagePath
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Inspect and manipulate a Path based on a Package name

RUN_DEPENDS=	p5-Moose>=0.64:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types-Path-Class>=0.04:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class

USE_PERL5=	configure
USES=		perl5

MAN3=		Devel::PackagePath.3

.include <bsd.port.mk>
