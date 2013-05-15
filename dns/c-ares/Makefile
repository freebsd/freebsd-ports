# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	c-ares
PORTVERSION=	1.10.0
CATEGORIES=	dns
MASTER_SITES=	http://c-ares.haxx.se/download/ \
		http://obsd.isc.org/pub/OpenBSD/distfiles/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	An asynchronous DNS resolver library

LICENSE=	MIT

OPTIONS_DEFINE=		CONFIG_INFO DEBUG HIDE_SYMBOLS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	CONFIG_INFO HIDE_SYMBOLS

CONFIG_INFO_DESC=	Add the ares_config_info patch
HIDE_SYMBOLS_DESC=	Hide internal library symbols
OPTIMIZED_CFLAGS_DESC=	Build with compiler optimizations

CONFLICTS=		ares-1.*

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCONFIG_INFO}
EXTRA_PATCHES+=	${FILESDIR}/ares-config-info.patch
PKGNAMESUFFIX=	-config
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MHIDE_SYMBOLS}
CONFIGURE_ARGS+=--enable-symbol-hiding
.else
CONFIGURE_ARGS+=--disable-symbol-hiding
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CONFIGURE_ARGS+=--enable-optimize
.else
CONFIGURE_ARGS+=--disable-optimize
.endif

USE_LDCONFIG=	yes
SHLIB_VER=	3

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --disable-werror

MAN3=	ares_cancel.3 \
	ares_create_query.3 \
	ares_destroy.3 ares_dup.3 \
	ares_expand_name.3 ares_expand_string.3 \
	ares_fds.3 \
	ares_free_data.3 ares_free_hostent.3 ares_free_string.3 \
	ares_get_servers.3 \
	ares_gethostbyaddr.3 ares_gethostbyname.3 ares_gethostbyname_file.3 \
	ares_getnameinfo.3 \
	ares_getsock.3 \
	ares_inet_ntop.3 ares_inet_pton.3 \
	ares_init.3 ares_init_options.3 \
	ares_library_cleanup.3 ares_library_init.3 \
	ares_mkquery.3 \
	ares_parse_a_reply.3 ares_parse_aaaa_reply.3 \
	ares_parse_mx_reply.3 \
	ares_parse_ptr_reply.3 ares_parse_soa_reply.3 \
	ares_parse_srv_reply.3 ares_parse_txt_reply.3 \
	ares_process.3 \
	ares_query.3 \
	ares_search.3 \
	ares_send.3 ares_set_socket_callback.3 \
	ares_set_servers.3 \
	ares_strerror.3 \
	ares_timeout.3 \
	ares_version.3 \
	ares_parse_naptr_reply.3 \
	ares_parse_ns_reply.3 \
	ares_destroy_options.3 \
	ares_save_options.3

PROGRAMS=	acountry adig ahost

post-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S@^@${WRKSRC}/.libs/@} ${PREFIX}/bin/

.include <bsd.port.post.mk>
