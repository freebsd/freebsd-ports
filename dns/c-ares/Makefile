# New ports collection makefile for:	ares
# Date created:		8 September 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	c-ares
PORTVERSION=	1.4.0
CATEGORIES=	dns
MASTER_SITES=	http://daniel.haxx.se/projects/c-ares/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An asynchronous DNS resolver library

OPTIONS=	CONFIG_INFO	"Add the ares_config_info patch" ON

CONFLICTS=	ares-1.*

.include <bsd.port.pre.mk>

.if defined(WITH_CONFIG_INFO)
EXTRA_PATCHES+=	${FILESDIR}/ares-config-info.patch
PKGNAMESUFFIX=	-config
.endif

USE_LDCONFIG=	yes
SHLIB_VER=	1

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shared

MAN3=	ares_cancel.3 \
	ares_destroy.3 \
	ares_expand_name.3 ares_expand_string.3 \
	ares_fds.3 \
	ares_free_hostent.3 ares_free_string.3 \
	ares_gethostbyaddr.3 ares_gethostbyname.3 ares_getnameinfo.3 \
	ares_getsock.3 \
	ares_init.3 ares_init_options.3 \
	ares_mkquery.3 \
	ares_parse_a_reply.3 ares_parse_aaaa_reply.3 ares_parse_ptr_reply.3 \
	ares_process.3 \
	ares_query.3 \
	ares_search.3 \
	ares_send.3 \
	ares_strerror.3 \
	ares_timeout.3 \
	ares_version.3 \
	ares_parse_ns_reply.3 \
	ares_destroy_options.3 \
	ares_save_options.3

.include <bsd.port.post.mk>
