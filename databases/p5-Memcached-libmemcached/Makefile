# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Memcached-libmemcached
PORTVERSION=	0.44.06
CATEGORIES=	databases devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMB
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Thin fast full interface to the libmemcached client API

USES=		perl5
USE_PERL5=	configure
USE_LDCONFIG=	yes

MAN3=		Memcached::libmemcached.3 \
		Memcached::libmemcached::API.3 \
		Memcached::libmemcached::constants.3 \
		Memcached::libmemcached::memcached_analyze.3 \
		Memcached::libmemcached::memcached_auto.3 \
		Memcached::libmemcached::memcached_behavior.3 \
		Memcached::libmemcached::memcached_callback.3 \
		Memcached::libmemcached::memcached_create.3 \
		Memcached::libmemcached::memcached_delete.3 \
		Memcached::libmemcached::memcached_dump.3 \
		Memcached::libmemcached::memcached_flush.3 \
		Memcached::libmemcached::memcached_flush_buffers.3 \
		Memcached::libmemcached::memcached_generate_hash_value.3 \
		Memcached::libmemcached::memcached_get.3 \
		Memcached::libmemcached::memcached_memory_allocators.3 \
		Memcached::libmemcached::memcached_pool.3 \
		Memcached::libmemcached::memcached_quit.3 \
		Memcached::libmemcached::memcached_result_st.3 \
		Memcached::libmemcached::memcached_sasl.3 \
		Memcached::libmemcached::memcached_server_st.3 \
		Memcached::libmemcached::memcached_servers.3 \
		Memcached::libmemcached::memcached_set.3 \
		Memcached::libmemcached::memcached_stats.3 \
		Memcached::libmemcached::memcached_strerror.3 \
		Memcached::libmemcached::memcached_user_data.3 \
		Memcached::libmemcached::memcached_verbosity.3 \
		Memcached::libmemcached::memcached_version.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/my $$configure_args/ s|--disable-shared|& --without-memcached --disable-dtrace|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
