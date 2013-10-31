# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Test-WWW-Declare
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative testing for your web app

BUILD_DEPENDS=	p5-Test-WWW-Mechanize>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
