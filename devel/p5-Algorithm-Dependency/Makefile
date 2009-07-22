# New ports collection makefile for:	Algorithm-Dependency
# Date created:				20 Nov 2005
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Dependency
PORTVERSION=	1.110
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Base class for implementing various dependency trees

RUN_DEPENDS=	p5-Params-Util>=0.31:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-ClassAPI>=0.6:${PORTSDIR}/devel/p5-Test-ClassAPI

MAN3=	Algorithm::Dependency.3 \
	Algorithm::Dependency::Item.3 \
	Algorithm::Dependency::Ordered.3 \
	Algorithm::Dependency::Source.3 \
	Algorithm::Dependency::Source::File.3 \
	Algorithm::Dependency::Source::HoA.3 \
	Algorithm::Dependency::Source::Invert.3 \
	Algorithm::Dependency::Weight.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
