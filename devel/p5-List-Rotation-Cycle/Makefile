# New ports collection makefile for:	p5-List-Rotation-Cycle
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	List-Rotation-Cycle
PORTVERSION=	1.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Cycle through a list of values

WRKSRC=		${WRKDIR}/${PORTNAME}

BUILD_DEPENDS+=	${SITE_PERL}/Module/Signature.pm:${PORTSDIR}/security/p5-Module-Signature \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=		List::Rotation::Cycle.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
