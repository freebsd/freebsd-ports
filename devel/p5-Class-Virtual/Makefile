# New ports collection makefile for:	Class-Virtual
# Date created:		28 Jul 2004
# Whom:			Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Virtual
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for virtual base classes in Perl

RUN_DEPENDS=	p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Virtual.3 Class::Virtually::Abstract.3

.include <bsd.port.mk>
