# New ports collection makefile for:	ares
# Date created:		8 September 2003
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ares
PORTVERSION=	1.1.1
CATEGORIES=	dns
MASTER_SITES=	http://curl.haxx.se/dev/ \
		ftp://athena-dist.mit.edu/pub/ATHENA/ares/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An asynchronous DNS resolver library

GNU_CONFIGURE=	yes

MAN3=		ares_destroy.3 ares_expand_name.3 ares_fds.3 \
		ares_free_errmem.3 ares_free_hostent.3 ares_free_string.3 \
		ares_gethostbyaddr.3 ares_gethostbyname.3 ares_init.3 \
		ares_init_options.3 ares_mkquery.3 ares_parse_a_reply.3 \
		ares_parse_ptr_reply.3 ares_process.3 ares_query.3 \
		ares_search.3 ares_send.3 ares_strerror.3 ares_timeout.3

.include <bsd.port.mk>
