# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Starter-PBP
PORTVERSION=	0.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Create a module as recommended in "Perl Best Practices"

BUILD_DEPENDS=	p5-Module-Starter>=0:${PORTSDIR}/devel/p5-Module-Starter \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
