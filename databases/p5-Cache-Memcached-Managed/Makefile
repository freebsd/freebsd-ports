# New ports collection makefile for:	p5-Cache-Memcached-Managed
# Date created:		2006-01-02
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached-Managed
PORTVERSION=	0.20
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide API for managing cached information

RUN_DEPENDS=	p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Cache::Memcached::Managed.3 \
	Cache::Memcached::Managed::Inactive.3 \
	Cache::Memcached::Managed::Multi.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^BEGIN, .. m,^},' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
