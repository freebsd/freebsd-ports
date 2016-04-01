# Created by: Po-Chien Lin <linpc@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	syntax
PORTVERSION=	0.004
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PHAYLON
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Activate syntax extensions in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-OptList>=0.104:devel/p5-Data-OptList \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
