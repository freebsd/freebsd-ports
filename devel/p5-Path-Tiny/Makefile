# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Path-Tiny
PORTVERSION=	0.027
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	File path utility

LICENSE=	AL2

BUILD_DEPENDS=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools \
		p5-autodie>=2.14:${PORTSDIR}/devel/p5-autodie
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-FailWarnings>=0:${PORTSDIR}/devel/p5-Test-FailWarnings \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Devel-Hide>=0:${PORTSDIR}/devel/p5-Devel-Hide \
		p5-File-pushd>=0:${PORTSDIR}/devel/p5-File-pushd

USES=		perl5
USE_PERL5=	configure

MAN3=	Path::Tiny.3

.include <bsd.port.mk>
