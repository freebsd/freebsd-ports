# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Install-XSUtil
PORTVERSION=	0.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility functions for XS modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Install>=0.91:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-B-Hooks-OP-Annotation>=0.43:${PORTSDIR}/devel/p5-B-Hooks-OP-Annotation

USE_PERL5=	configure
USES=		perl5

MAN3=		Module::Install::XSUtil.3

.include <bsd.port.mk>
