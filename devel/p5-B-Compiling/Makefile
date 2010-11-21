# New ports collection makefile for:	B::Compiling
# Date created:		21 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Compiling
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to expose PL_compiling to perl

RUN_DEPENDS=	\
	p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	B::Compiling.3

.include <bsd.port.mk>
