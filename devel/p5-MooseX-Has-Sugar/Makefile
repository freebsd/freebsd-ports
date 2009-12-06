# New ports collection makefile for:	devel/p5-MooseX-Has-Sugar
# Date created:				16 Nov, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Has-Sugar
PORTVERSION=	0.0405
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Sugar Syntax for moose has fields

BUILD_DEPENDS=	p5-Moose>=0.61:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Find-Lib>=0:${PORTSDIR}/devel/p5-Find-Lib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+
PERL_MODBUILD=	yes

MAN3=		MooseX::Has::Sugar.3 \
		MooseX::Has::Sugar::Saccharin.3 \
		MooseX::Has::Sugar::Minimal.3

.include <bsd.port.mk>
