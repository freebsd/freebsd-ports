# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apl
PORTVERSION=	1.8
CATEGORIES=	lang
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free interpreter for APL programming language

LICENSE=	GPLv3+

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		gmake libtool localbase
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		apl libapl
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS GTK3 LIBAPL PCRE SQLITE
OPTIONS_SUB=	yes

LIBAPL_DESC=	Build libapl.so instead of executable

GTK3_USES=	pkgconfig gnome
GTK3_USE=	GNOME=gtk30
GTK3_CONFIGURE_WITH=	gtk3

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_CONFIGURE_WITH=	pcre=${LOCALBASE}

SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
SQLITE_CONFIGURE_WITH=	sqlite3=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e '25s,^,#include <sys/socket.h>,' \
		${WRKSRC}/src/Common.hh
	@${REINPLACE_CMD} -e 's,bind(,::&,' \
		${WRKSRC}/src/emacs_mode/TcpListener.cc \
		${WRKSRC}/src/emacs_mode/UnixSocketListener.cc
	@${REINPLACE_CMD} -e 's,POLLRDHUP,POLLHUP,' \
		${WRKSRC}/src/Quad_GTK.cc

.include <bsd.port.mk>
