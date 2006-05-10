# New ports collection makefile for:	Algorithm-Dependency
# Date created:				20 Nov 2005
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Dependency
PORTVERSION=	1.102
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Base class for implementing various dependency trees

BUILD_DEPENDS=	${SITE_PERL}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/Test/ClassAPI.pm:${PORTSDIR}/devel/p5-Test-ClassAPI
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Algorithm::Dependency.3 \
	Algorithm::Dependency::Item.3 \
	Algorithm::Dependency::Ordered.3 \
	Algorithm::Dependency::Source.3 \
	Algorithm::Dependency::Source::File.3 \
	Algorithm::Dependency::Source::HoA.3 \
	Algorithm::Dependency::Weight.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
IGNORE=	requires perl 5.6 or above
.endif

.include <bsd.port.post.mk>
