# New ports collection makefile for:	p5-MooseX-Attribute-ENV
# Date created:				18 November 2010
# Whom: 				alan <Alan@Wave2.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Attribute-ENV
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alan@Wave2.org
COMMENT=	Set default of an attribute to a value from %ENV

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=1.19:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Attribute::ENV.3

.include <bsd.port.mk>
