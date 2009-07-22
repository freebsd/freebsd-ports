# vim:ts=8
# New ports collection makefile for:	p5-Class-AutoClass
# Date created:				25 November 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Class-AutoClass
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	autoclass_v${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Automatically define simple get and set methods in an inheritance structure

RUN_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/Deep.pm:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	5.8.0+
WRKSRC=		${WRKDIR}/AutoClass

MAN3=		Class::AutoClass::Root.3 Class::AutoClass.3 Class::AutoClass::Args.3

.include <bsd.port.mk>
