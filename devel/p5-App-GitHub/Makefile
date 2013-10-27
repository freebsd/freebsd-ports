# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	App-GitHub
PORTVERSION=	1.0.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	App
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GitHub Command Tools

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-XS>=2.3:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Net-GitHub>=0.12:${PORTSDIR}/net/p5-Net-GitHub
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
