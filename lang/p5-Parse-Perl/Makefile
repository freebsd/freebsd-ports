# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Parse-Perl
PORTVERSION=	0.007
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interpret string as Perl source

BUILD_DEPENDS=	p5-Devel-CallChecker>=0.003:${PORTSDIR}/devel/p5-Devel-CallChecker
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Lexical-Import>=0:${PORTSDIR}/devel/p5-Lexical-Import \
		p5-Sub-Identify>=0:${PORTSDIR}/devel/p5-Sub-Identify

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
