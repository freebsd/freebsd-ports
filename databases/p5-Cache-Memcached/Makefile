# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	Cache-Memcached
PORTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN \
		http://www.danga.com/memcached/dist/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl API for memcached, a distributed memory cache daemon

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-String-CRC32>0:devel/p5-String-CRC32
RUN_DEPENDS=	p5-String-CRC32>0:devel/p5-String-CRC32

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
