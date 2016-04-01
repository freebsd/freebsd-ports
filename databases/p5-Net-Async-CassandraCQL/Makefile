# Created by: Denis Shaposhnikov <dsh@bamus.cz>
# $FreeBSD$

PORTNAME=	Net-Async-CassandraCQL
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	admins@perceptyx.com
COMMENT=	Use Cassandra databases with IO::Async using CQL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Compress-Snappy>0:archivers/p5-Compress-Snappy \
		p5-Devel-GlobalDestruction>=0:devel/p5-Devel-GlobalDestruction \
		p5-Future>=0.17:devel/p5-Future \
		p5-IO-Async>=0.59:devel/p5-IO-Async \
		p5-IO-Socket-IP>0:net/p5-IO-Socket-IP \
		p5-Compress-LZ4>0:archivers/p5-Compress-LZ4 \
		p5-Protocol-CassandraCQL>=0.11:databases/p5-Protocol-CassandraCQL
TEST_DEPENDS=	p5-Test-Identity>0:devel/p5-Test-Identity \
		p5-Test-Refcount>0:devel/p5-Test-Refcount
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
