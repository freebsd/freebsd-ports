# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Tie-FileLRUCache
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight but robust filesystem based persistent LRU cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-NamedParms>=0:devel/p5-Class-NamedParms \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Class-ParmList>=0:devel/p5-Class-ParmList

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
