# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	App-CLI-Extension
PORTVERSION=	1.421
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HOLLY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension for App::CLI extension module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-CLI>=0.313:devel/p5-App-CLI \
		p5-Class-Accessor-Grouped>=0.10000:devel/p5-Class-Accessor-Grouped \
		p5-Error>=0.17000:lang/p5-Error \
		p5-MRO-Compat>=0.11:devel/p5-MRO-Compat \
		p5-UNIVERSAL-require>=0.13:devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
