# New ports collection makefile for:	MooseX-IOC
# Date created:	   23 February 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-IOC
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Moose attributes with IOC integration

BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/IOC.pm:${PORTSDIR}/devel/p5-IOC \
		${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${SITE_PERL}/IOC.pm:${PORTSDIR}/devel/p5-IOC \
		${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose

PERL_CONFIGURE=	yes

MAN3=		MooseX::IOC.3 MooseX::IOC::Meta::Attribute.3

.include <bsd.port.mk>
