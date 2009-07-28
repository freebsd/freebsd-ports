# New ports collection makefile for:	p5-Devel-LeakGuard-Object
# Date created:		2009-07-19
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Devel-LeakGuard-Object
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Scoped checks for object leaks

BUILD_DEPENDS=	p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Devel::LeakGuard::Object.3 \
		Devel::LeakGuard::Object::State.3

.include <bsd.port.mk>
