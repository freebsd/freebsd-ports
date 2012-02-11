# New ports collection makefile for:	Class-C3-Adopt-NEXT
# Date created:	   18 Jun 2009
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3-Adopt-NEXT
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Make NEXT suck less

RUN_DEPENDS=	p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Class::C3::Adopt::NEXT.3

.include <bsd.port.mk>
