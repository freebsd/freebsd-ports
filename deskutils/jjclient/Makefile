# Created by: Lucas Holt <luke@justjournal.com>

PORTNAME=	jjclient
PORTVERSION=	2.0.1
CATEGORIES=	deskutils

MAINTAINER=	luke@justjournal.com
COMMENT=	Command line client for posting JustJournal entries

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxmlrpc.so:net/xmlrpc-c

USE_GITHUB=     yes
GH_PROJECT=     justjournal-client-unix
GH_ACCOUNT=     laffer1
GH_TAGNAME=     ${PORTVERSION}

USE_CSTD=	c99

CFLAGS+=	-I/usr/local/include
LDFLAGS+=	-L/usr/local/lib -lxmlrpc_client -lxmlrpc -lxmlrpc_xmlparse -lxmlrpc_util

PLIST_FILES=	bin/jjclient

.include <bsd.port.mk>
