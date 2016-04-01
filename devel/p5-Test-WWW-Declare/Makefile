# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Test-WWW-Declare
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative testing for your web app

BUILD_DEPENDS=	p5-Test-WWW-Mechanize>=0:devel/p5-Test-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
