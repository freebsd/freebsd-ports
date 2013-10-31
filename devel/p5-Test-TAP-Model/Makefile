# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Test-TAP-Model
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Accessible result collector for Test::Harness::Straps runs

BUILD_DEPENDS=	p5-Method-Alias>=0:${PORTSDIR}/devel/p5-Method-Alias \
		p5-Test-Harness-Straps>=0.30:${PORTSDIR}/devel/p5-Test-Harness-Straps
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.53:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} ${WRKSRC}/example.pl

.include <bsd.port.mk>
