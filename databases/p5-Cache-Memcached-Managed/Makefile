# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Cache-Memcached-Managed
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide API for managing cached information

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cache-Memcached>=0:databases/p5-Cache-Memcached
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	memcached:databases/memcached

USES=		perl5
USE_PERL5=	configure extract

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^BEGIN, .. m,^},' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
