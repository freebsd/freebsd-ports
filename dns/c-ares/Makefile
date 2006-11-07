# New ports collection makefile for:	ares
# Date created:		8 September 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	c-ares
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://daniel.haxx.se/projects/c-ares/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An asynchronous DNS resolver library

CONFLICTS=	ares-1.*

USE_LDCONFIG=	yes
SHLIB_VER=	1

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --enable-shared

MAN3=	ares_cancel.3 \
	ares_destroy.3 \
	ares_expand_name.3 ares_expand_string.3 \
	ares_fds.3 \
	ares_free_hostent.3 ares_free_string.3 \
	ares_gethostbyaddr.3 ares_gethostbyname.3 ares_getnameinfo.3 \
	ares_init.3 ares_init_options.3 \
	ares_mkquery.3 \
	ares_parse_a_reply.3 ares_parse_aaaa_reply.3 ares_parse_ptr_reply.3 \
	ares_process.3 \
	ares_query.3 \
	ares_search.3 \
	ares_send.3 \
	ares_strerror.3 \
	ares_timeout.3 \
	ares_version.3

.include <bsd.port.mk>
