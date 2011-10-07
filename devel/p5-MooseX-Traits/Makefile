# New ports collection makefile for:	MooseX-Traits
# Date created:	   11 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Traits
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose eXtension to automatically apply roles at object creation time

BUILD_DEPENDS=	p5-Moose>=0.84:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=		MooseX::Traits.3

.include <bsd.port.mk>
