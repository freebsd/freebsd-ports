# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Git-Wrapper
PORTVERSION=	0.030
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Wrap git(7) command-line interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	git>=0:${PORTSDIR}/devel/git \
		p5-Env-Path>=0:${PORTSDIR}/devel/p5-Env-Path \
		p5-File-pushd>=0:${PORTSDIR}/devel/p5-File-pushd \
		p5-Path-Class>=0.26:${PORTSDIR}/devel/p5-Path-Class \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
