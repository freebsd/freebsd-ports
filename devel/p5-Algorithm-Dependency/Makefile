# New ports collection makefile for:	Algorithm-Dependency
# Date created:				20 Nov 2005
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Dependency
PORTVERSION=	1.106
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Base class for implementing various dependency trees

BUILD_DEPENDS=	${SITE_PERL}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/Test/ClassAPI.pm:${PORTSDIR}/devel/p5-Test-ClassAPI \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Algorithm::Dependency.3 \
	Algorithm::Dependency::Item.3 \
	Algorithm::Dependency::Ordered.3 \
	Algorithm::Dependency::Source.3 \
	Algorithm::Dependency::Source::File.3 \
	Algorithm::Dependency::Source::HoA.3 \
	Algorithm::Dependency::Weight.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
