# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	guile
PORTVERSION=	2.2.6
CATEGORIES=	lang scheme
MASTER_SITES=	GNU
PKGNAMESUFFIX=	2

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libltdl.so:devel/libltdl \
		libunistring.so:devel/libunistring \
		libffi.so:devel/libffi

USES=		charsetfix compiler:c11 gmake iconv libtool makeinfo ncurses pathfix \
		pkgconfig readline tar:lz
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	guile-[0-9]*

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

INFO=		guile r5rs

PLIST_SUB=	GUILE_VER=${PORTVERSION:R}

OPTIONS_DEFINE=	NLS THREADS
OPTIONS_DEFAULT=THREADS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

THREADS_CONFIGURE_WITH=	threads
THREADS_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
THREADS_LIB_DEPENDS_OFF=	libgc.so:devel/boehm-gc

REINPLACE_FILES=	libguile/smob.c libguile/filesys.c libguile/gc.c \
			libguile/mallocs.c libguile/eval.c \
			libguile/gc-malloc.c libguile/ports.c

post-patch:
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES}
	@${REINPLACE_CMD} -e 's|sys/time.h sys/timeb.h|sys/time.h |g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-i -e|-i.bak -e|' \
		${WRKSRC}/libguile/Makefile.in

post-patch-THREADS-on:
	@${REINPLACE_CMD} -e 's|bdw-gc|bdw-gc-threaded|g' ${WRKSRC}/configure

.include <bsd.port.mk>
