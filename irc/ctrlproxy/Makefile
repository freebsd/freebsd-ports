# ex:ts=8
# Ports collection makefile for:	ctrlproxy
# Date created:			Oct 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ctrlproxy
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://jelmer.vernstok.nl/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		pcre.0:${PORTSDIR}/devel/pcre \
		tdb.1:${PORTSDIR}/databases/tdb

USE_OPENSSL=	yes
USE_GNOME=	glib20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	ctrlproxy.1
MAN5=	ctrlproxyrc.5
MAN7=	admin.7ctrlproxy antiflood.7ctrlproxy auto-away.7ctrlproxy \
	ctcp.7ctrlproxy linestack_file.7ctrlproxy linestack_memory.7ctrlproxy \
	log_custom.7ctrlproxy log_irssi.7ctrlproxy motd-file.7ctrlproxy \
	nickserv.7ctrlproxy noticelog.7ctrlproxy repl_command.7ctrlproxy \
	repl_highlight.7ctrlproxy repl_none.7ctrlproxy repl_simple.7ctrlproxy \
	socket.7ctrlproxy stats.7ctrlproxy strip.7ctrlproxy

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOC)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS TODO doc/ctrlproxy.html doc/ctrlproxy.pdf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
