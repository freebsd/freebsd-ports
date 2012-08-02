# New ports collection makefile for:	Cache-Memcached-Tie
# Whom: 			Andrey Kostenko <andrey@kostenko.name>
# Date created:		02 December 2009
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached-Tie
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use Cache::Memcached::Fast like hash

BUILD_DEPENDS=	p5-Cache-Memcached-Fast>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Fast
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Cache::Memcached::Tie.3

.include <bsd.port.mk>
