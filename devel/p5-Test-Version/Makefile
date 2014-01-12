# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Version
PORTVERSION=	1.002.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Check to see that version in modules are sane

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Find-Rule-Perl>=0:${PORTSDIR}/devel/p5-File-Find-Rule-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Module-Metadata>=0:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-version>=0.86:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-Module-Metadata>=0:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-version>=0.86:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
