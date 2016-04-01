# Created by: Denis Shaposhnikov <dsh@bamus.cz>
# $FreeBSD$

PORTNAME=	Protocol-CassandraCQL
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	admins@perceptyx.com
COMMENT=	Wire protocol support functions for Cassandra CQL3

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Snappy>0:archivers/p5-Compress-Snappy \
		p5-IO-Socket-IP>0:net/p5-IO-Socket-IP \
		p5-Test-Fatal>0:devel/p5-Test-Fatal \
		p5-Test-HexString>0:devel/p5-Test-HexString
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
