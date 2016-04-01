# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autodie
PORTVERSION=	2.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PJF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Replace functions with ones that succeed or die with lexical scope

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-BSD-Resource>=0:devel/p5-BSD-Resource \
		p5-IPC-System-Simple>=0.12:devel/p5-IPC-System-Simple \
		p5-Import-Into>=1.002004:devel/p5-Import-Into \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Sub-Identify>=0:devel/p5-Sub-Identify

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
