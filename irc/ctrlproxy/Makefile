# ex:ts=8
# Ports collection makefile for:	ctrlproxy
# Date created:			Oct 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ctrlproxy
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://jelmer.vernstok.nl/ctrlproxy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		pcre.0:${PORTSDIR}/devel/pcre \
		tdb.1:${PORTSDIR}/databases/tdb

USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_GNOME=	libxml2 glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	ctrlproxy.1
MAN5=	ctrlproxyrc.5
MAN7=	admin.7ctrlproxy antiflood.7ctrlproxy auto-away.7ctrlproxy \
	ctcp.7ctrlproxy linestack_file.7ctrlproxy linestack_memory.7ctrlproxy \
	log_custom.7ctrlproxy log_irssi.7ctrlproxy motd-file.7ctrlproxy \
	nickserv.7ctrlproxy noticelog.7ctrlproxy repl_command.7ctrlproxy \
	repl_highlight.7ctrlproxy repl_none.7ctrlproxy repl_simple.7ctrlproxy \
	socket.7ctrlproxy stats.7ctrlproxy strip.7ctrlproxy

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${GREP} -lR "malloc\.h" | \
		${XARGS} ${REINPLACE_CMD} -e "s@malloc.h@stdlib.h@g"

.include <bsd.port.mk>
