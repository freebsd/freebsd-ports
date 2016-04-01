# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	DBIx-Class-CustomPrefetch
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Custom prefetches for DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Load>=0:devel/p5-Module-Load \
		p5-DBIx-Class-VirtualColumns>=0:databases/p5-DBIx-Class-VirtualColumns \
		p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-DBIx-Class>=0.081:databases/p5-DBIx-Class
RUN_DEPENDS=	p5-Module-Load>=0:devel/p5-Module-Load \
		p5-DBIx-Class-VirtualColumns>=0:databases/p5-DBIx-Class-VirtualColumns \
		p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-DBIx-Class>=0.081:databases/p5-DBIx-Class

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
