# New ports collection makefile for:	MooseX::ConfigFromFile
# Date created:		20 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-ConfigFromFile
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to abstract Moose role attribute setting from file

RUN_DEPENDS=	\
	p5-Moose>=0.35:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Types-Path-Class>=0.04:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::ConfigFromFile.3

.include <bsd.port.mk>
