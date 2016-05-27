# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Version
PORTVERSION=	1.05000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|000$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Check to see that version in modules are sane

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Find-Rule-Perl>=0:devel/p5-File-Find-Rule-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
