# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Class-Accessor-Complex
PORTVERSION=	1.100880
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Arrays, hashes, booleans, integers, sets, and more

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Accessor-Installer>=0:devel/p5-Class-Accessor-Installer \
		p5-Data-Miscellany>=0:devel/p5-Data-Miscellany \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
