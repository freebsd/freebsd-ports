# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Import-Base
PORTVERSION=	1.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PREACTION
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Import a set of modules into the calling module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Import-Into>=1.002005:devel/p5-Import-Into \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Dancer2-Plugin-Ajax>=0:www/p5-Dancer2-Plugin-Ajax \
		p5-Dancer2>=0:www/p5-Dancer2 \
		p5-Moo>=0:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
