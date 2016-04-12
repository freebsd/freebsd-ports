# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MR-Tarantool
PORTVERSION=	0.0.24
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Driver for an efficient Tarantool/Box NoSQL in-memory storage

BUILD_DEPENDS=	p5-AnyEvent>=7.04:devel/p5-AnyEvent \
		p5-Class-Singleton>=1.4:devel/p5-Class-Singleton \
		p5-Mouse>=1.1:devel/p5-Mouse \
		p5-String-CRC32>=1.4:devel/p5-String-CRC32
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
