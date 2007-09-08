# New ports collection makefile for:	p5-Algorithm-Dependency-Objects
# Date created:				21 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Dependency-Objects
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An implementation of an Object Dependency Algorithm

BUILD_DEPENDS=	p5-Scalar-List-Utils>1.10:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Set-Object>0:${PORTSDIR}/devel/p5-Set-Object \
		p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Algorithm::Dependency::Objects.3 \
	Algorithm::Dependency::Objects::Ordered.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
