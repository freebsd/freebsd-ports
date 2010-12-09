# New ports collection makefile for:	p5-Memcached-libmemcached
# Date created:				2008-01-24
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Memcached-libmemcached
PORTVERSION=	0.21.01
CATEGORIES=	databases devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TI/TIMB
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Report on and update an SQLite database

LIB_DEPENDS=	memcached:${PORTSDIR}/databases/libmemcached

PERL_CONFIGURE=	yes
USE_PERL5=	5.8+
USE_LDCONFIG=	yes

MAN3=		Memcached::libmemcached.3 \
		Memcached::libmemcached::API.3 \
		Memcached::libmemcached::constants.3 \
		Memcached::libmemcached::memcached_auto.3 \
		Memcached::libmemcached::memcached_behavior.3 \
		Memcached::libmemcached::memcached_callback.3 \
		Memcached::libmemcached::memcached_create.3 \
		Memcached::libmemcached::memcached_delete.3 \
		Memcached::libmemcached::memcached_flush.3 \
		Memcached::libmemcached::memcached_get.3 \
		Memcached::libmemcached::memcached_quit.3 \
		Memcached::libmemcached::memcached_server_st.3 \
		Memcached::libmemcached::memcached_servers.3 \
		Memcached::libmemcached::memcached_set.3 \
		Memcached::libmemcached::memcached_stats.3 \
		Memcached::libmemcached::memcached_strerror.3 \
		Memcached::libmemcached::memcached_verbosity.3 \
		Memcached::libmemcached::memcached_version.3

.include <bsd.port.mk>
