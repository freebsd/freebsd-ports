# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Parse-Perl
PORTVERSION=	0.007
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interpret string as Perl source

BUILD_DEPENDS=	p5-Devel-CallChecker>=0.003:devel/p5-Devel-CallChecker
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Declare>=0:devel/p5-Devel-Declare \
		p5-Lexical-Import>=0:devel/p5-Lexical-Import \
		p5-Sub-Identify>=0:devel/p5-Sub-Identify

BROKEN=		Fails to build with Perl >= 5.22

DEPRECATED=	does not build with Perl >= 5.22
EXPIRATION_DATE=2017-07-31

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
