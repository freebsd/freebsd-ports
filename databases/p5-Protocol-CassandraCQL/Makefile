# Created by: Denis Shaposhnikov <dsh@bamus.cz>
# $FreeBSD$

PORTNAME=	Protocol-CassandraCQL
PORTVERSION=	0.11
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	admins@perceptyx.com
COMMENT=	Wire protocol support functions for Cassandra CQL3

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Snappy>0:${PORTSDIR}/archivers/p5-Compress-Snappy \
		p5-IO-Socket-IP>0:${PORTSDIR}/net/p5-IO-Socket-IP \
		p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-HexString>0:${PORTSDIR}/devel/p5-Test-HexString
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
