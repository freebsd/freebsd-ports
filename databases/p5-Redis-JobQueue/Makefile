# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Redis-JobQueue
PORTVERSION=	1.19
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Job queue management implemented using Redis server

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-UUID>0:devel/p5-Data-UUID \
		p5-Digest-SHA1>0:security/p5-Digest-SHA1 \
		p5-Data-UUID>0:devel/p5-Data-UUID \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Mouse>0:devel/p5-Mouse \
		p5-Params-Util>0:devel/p5-Params-Util \
		p5-Redis>0:databases/p5-Redis \
		p5-Storable>0:devel/p5-Storable \
		p5-Try-Tiny>=0.24:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
