# New ports collection makefile for:	libgutenfetch
# Date created:		17 July 2004
# Whom:		Russell Francis <johntabularasa@users.sf.net>
#
# $FreeBSD$
#

PORTNAME=	libgutenfetch
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libgutenfetch

MAINTAINER=	johntabularasa@users.sf.net
COMMENT=	A library that allows application developers to connect to PG

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl:install

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN3=		libgutenfetch.3 \
		gutenfetch_version.3 \
		gutenfetch_shutdown.3 \
		gutenfetch_set_active_server_full.3 \
		gutenfetch_set_active_server.3 \
		gutenfetch_new_server.3 \
		gutenfetch_list_servers.3 \
		gutenfetch_is_threadsafe.3 \
		gutenfetch_init.3 \
		gutenfetch_get_aussie_server.3 \
		gutenfetch_get_active_server.3 \
		gutenfetch_free_server.3 \
		gutenfetch_free_servers.3 \
		gutenfetch_duplicate_server.3

PLIST_FILES=	include/gutenfetch.h \
		lib/libgutenfetch.a \
		lib/libgutenfetch.la \
		lib/libgutenfetch.so \
		lib/libgutenfetch.so.0 \
		share/libgutenfetch/servers.txt

PLIST_DIRS=	share/libgutenfetch

.include <bsd.port.mk>
