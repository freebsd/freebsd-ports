# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apl
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free interpreter for APL programming language

LICENSE=	GPLv3+

BROKEN_aarch64=	Fails to link: missing sbrk

# XXX: should be optional, but no way to disable in the configure script
LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		compiler:c++11-lang gmake libtool localbase
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		apl libapl
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS GTK3 LIBAPL PCRE PGSQL SQLITE
OPTIONS_SUB=	yes

LIBAPL_DESC=	Build libapl.so instead of executable
# XXX: LIBAPL_CONFIGURE_WITH won't work for some reason
LIBAPL_CONFIGURE_ON=	--with-libapl

GTK3_USES=	pkgconfig gnome
GTK3_USE=	GNOME=gtk30
GTK3_CONFIGURE_WITH=	gtk3

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_CONFIGURE_WITH=	pcre=${LOCALBASE}

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql

SQLITE_USES=		sqlite:3
SQLITE_CONFIGURE_WITH=	sqlite3=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e '25s,^,#include <sys/socket.h>,' \
		${WRKSRC}/src/Common.hh
	@${REINPLACE_CMD} -e 's,bind(,::&,' \
		${WRKSRC}/src/emacs_mode/TcpListener.cc \
		${WRKSRC}/src/emacs_mode/UnixSocketListener.cc
	@${REINPLACE_CMD} -e 's,POLLRDHUP,POLLHUP,' \
		${WRKSRC}/src/Quad_GTK.cc
# Prevent needless C[XX]FLAGS pollution
	@${REINPLACE_CMD} -e 's,-g -O. ,,' \
		${WRKSRC}/src/APs/Makefile.in \
		${WRKSRC}/src/native/Makefile.in
# Fixes below are for GCC-based builds
	@${REINPLACE_CMD} -e '28s,^,#include <cstring>,' \
		${WRKSRC}/src/Error.hh
	@${REINPLACE_CMD} -E '/(total|used)_memory/s,uint64_t,int64_t,' \
		${WRKSRC}/src/Quad_WA.?? ${WRKSRC}/src/Value.cc

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/gnu-apl.d/preferences \
		${STAGEDIR}${PREFIX}/etc/gnu-apl.d/preferences.sample

.include <bsd.port.mk>
