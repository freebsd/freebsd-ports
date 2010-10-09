# New ports collection makefile for:	POEx::Types
# Date created:		09 Oct 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POEx-Types
PORTVERSION=	1.100910
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NP/NPEREZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to provide MooseX::Types types for modern POE

RUN_DEPENDS=	\
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-Structured>0:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
	p5-POE>0:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POEx::Types.3

.include <bsd.port.mk>
