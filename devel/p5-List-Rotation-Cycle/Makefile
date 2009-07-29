# New ports collection makefile for:	p5-List-Rotation-Cycle
# Date created:				2007/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	List-Rotation-Cycle
PORTVERSION=	1.009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN LOCAL/chinsan/CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Cycle through a list of values

PORTSCOUT=	limitw:1,even

MAN3=		List::Rotation::Cycle.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS+=	p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize
.endif

.include <bsd.port.post.mk>
