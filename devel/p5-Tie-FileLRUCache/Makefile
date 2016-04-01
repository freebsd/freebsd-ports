# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Tie-FileLRUCache
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight but robust filesystem based persistent LRU cache

BUILD_DEPENDS=	p5-Class-NamedParms>=0:devel/p5-Class-NamedParms \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Class-ParmList>=0:devel/p5-Class-ParmList
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
