# New ports collection makefile for:	Test-TAP-HTMLMatrix
# Date created:	   08 July 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-TAP-HTMLMatrix
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Creates colorful matrix of Test::Harness test run results

BUILD_DEPENDS=	${SITE_PERL}/Test/TAP/Model.pm:${PORTSDIR}/devel/p5-Test-TAP-Model \
		${SITE_PERL}/Petal.pm:${PORTSDIR}/textproc/p5-Petal \
		${SITE_PERL}/Petal/Utils.pm:${PORTSDIR}/textproc/p5-Petal-Utils \
		${SITE_PERL}/URI/file.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::TAP::HTMLMatrix.3 Test::TAP::Model::Colorful.3 \
		Test::TAP::Model::File::Visual.3 \
		Test::TAP::Model::Subtest::Visual.3 Test::TAP::Model::Visual.3

post-patch:
	${RM} ${WRKSRC}/example.pl

.include <bsd.port.mk>
