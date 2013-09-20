# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	ares
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://mirrors.rit.edu/zi/ \
		ftp://athena-dist.mit.edu/pub/ATHENA/ares/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	An asynchronous DNS resolver library

CONFLICTS=	c-ares-1.* c-ares-config-1.*

GNU_CONFIGURE=	yes

MAN3=		ares_destroy.3 ares_expand_name.3 ares_fds.3 \
		ares_free_errmem.3 ares_free_hostent.3 ares_free_string.3 \
		ares_gethostbyaddr.3 ares_gethostbyname.3 ares_init.3 \
		ares_init_options.3 ares_mkquery.3 ares_parse_a_reply.3 \
		ares_parse_ptr_reply.3 ares_process.3 ares_query.3 \
		ares_search.3 ares_send.3 ares_strerror.3 ares_timeout.3

PLIST_FILES=	include/ares.h lib/libares.a

NO_STAGE=	yes
.include <bsd.port.mk>
