# Created by: Russell Francis <johntabularasa@users.sf.net>
# $FreeBSD$

PORTNAME=	libgutenfetch
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	johntabularasa@users.sf.net
COMMENT=	Library that allows application developers to connect to PG

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake libtool tar:bzip2

PLIST_FILES=	include/gutenfetch.h \
		lib/libgutenfetch.a \
		lib/libgutenfetch.so \
		lib/libgutenfetch.so.0.0.0 \
		share/libgutenfetch/servers.txt \
		man/man3/gutenfetch_duplicate_server.3.gz \
		man/man3/gutenfetch_free_server.3.gz \
		man/man3/gutenfetch_free_servers.3.gz \
		man/man3/gutenfetch_get_active_server.3.gz \
		man/man3/gutenfetch_get_aussie_server.3.gz \
		man/man3/gutenfetch_init.3.gz \
		man/man3/gutenfetch_is_threadsafe.3.gz \
		man/man3/gutenfetch_list_servers.3.gz \
		man/man3/gutenfetch_new_server.3.gz \
		man/man3/gutenfetch_set_active_server.3.gz \
		man/man3/gutenfetch_set_active_server_full.3.gz \
		man/man3/gutenfetch_shutdown.3.gz \
		man/man3/gutenfetch_version.3.gz \
		man/man3/libgutenfetch.3.gz

.include <bsd.port.mk>
