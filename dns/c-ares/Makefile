# New ports collection makefile for:	ares
# Date created:		8 September 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	c-ares
PORTVERSION=	1.6.0
CATEGORIES=	dns
MASTER_SITES=	http://c-ares.haxx.se/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An asynchronous DNS resolver library

OPTIONS=	CONFIG_INFO	"Add the ares_config_info patch" ON \
		DEBUG		"Build with debug information" OFF \
		OPTIMIZED_CFLAGS	"Build with compiler optimizations" OFF

CONFLICTS=	ares-1.*

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_CONFIG_INFO)
EXTRA_PATCHES+=	${FILESDIR}/ares-config-info.patch
PKGNAMESUFFIX=	-config
.endif
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
.if defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--enable-optimize
.else
CONFIGURE_ARGS+=	--disable-optimize
.endif

USE_LDCONFIG=	yes
SHLIB_VER=	2

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

MAN3=	ares_cancel.3 \
	ares_destroy.3 ares_dup.3 \
	ares_expand_name.3 ares_expand_string.3 \
	ares_fds.3 \
	ares_free_hostent.3 ares_free_string.3 \
	ares_gethostbyaddr.3 ares_gethostbyname.3 ares_gethostbyname_file.3 \
	ares_getnameinfo.3 \
	ares_getsock.3 \
	ares_init.3 ares_init_options.3 \
	ares_mkquery.3 \
	ares_parse_a_reply.3 ares_parse_aaaa_reply.3 ares_parse_ptr_reply.3 \
	ares_process.3 \
	ares_query.3 \
	ares_search.3 \
	ares_send.3 ares_set_socket_callback.3 \
	ares_strerror.3 \
	ares_timeout.3 \
	ares_version.3 \
	ares_parse_ns_reply.3 \
	ares_destroy_options.3 \
	ares_save_options.3

.include <bsd.port.post.mk>
