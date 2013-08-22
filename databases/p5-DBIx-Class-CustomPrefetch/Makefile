# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	DBIx-Class-CustomPrefetch
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Custom prefetches for DBIx::Class

BUILD_DEPENDS=	p5-parent>=0:${PORTSDIR}/devel/p5-parent \
		p5-Module-Load>=0:${PORTSDIR}/devel/p5-Module-Load \
		p5-DBIx-Class-VirtualColumns>=0:${PORTSDIR}/databases/p5-DBIx-Class-VirtualColumns \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-DBIx-Class>=0.081:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	p5-parent>=0:${PORTSDIR}/devel/p5-parent \
		p5-Module-Load>=0:${PORTSDIR}/devel/p5-Module-Load \
		p5-DBIx-Class-VirtualColumns>=0:${PORTSDIR}/databases/p5-DBIx-Class-VirtualColumns \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-DBIx-Class>=0.081:${PORTSDIR}/databases/p5-DBIx-Class

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Class::CustomPrefetch.3 DBIx::Class::ResultSet::CustomPrefetch.3

.include <bsd.port.mk>
