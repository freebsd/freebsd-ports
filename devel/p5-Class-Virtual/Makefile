# New ports collection makefile for:	Class-Virtual
# Date created:		28 Jul 2004
# Whom:			Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Virtual
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for virtual base classes in Perl

BUILD_DEPENDS=	${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Virtual.3 Class::Virtually::Abstract.3

.include <bsd.port.mk>
