# New ports collection makefile for:	Test-TAP-Model
# Date created:	   08 July 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-TAP-Model
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Accessible result collector for Test::Harness::Straps runs

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Method/Alias.pm:${PORTSDIR}/devel/p5-Method-Alias
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::TAP::Model.3 Test::TAP::Model::Consolidated.3 \
		Test::TAP::Model::File.3 \
		Test::TAP::Model::File::Consolidated.3 \
		Test::TAP::Model::Subtest.3

post-patch:
	${RM} ${WRKSRC}/example.pl

.include <bsd.port.mk>
