# New ports collection makefile for:	p5-ORBit
# Date created:				11 March 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	ORBit
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/H/HR/HROGERS
PKGNAMEPREFIX=	p5-
DISTNAME=	CORBA-ORBit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The perl binding for ORBit

BUILD_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit

PERL_CONFIGURE=	yes

MAN3=		CORBA::ORBit.3 \
		CORBA::ORBit::Fixed.3 \
		CORBA::ORBit::LongDouble.3 \
		CORBA::ORBit::LongLong.3 \
		CORBA::ORBit::ULongLong.3 \
		CORBA::ORBit::mapping.3

.include <bsd.port.mk>
