# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	guile
PORTVERSION=	2.0.11
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	GNU
#MASTER_SITES=	${MASTER_SITE_GNU}
#MASTER_SITE_SUBDIR=	guile
PKGNAMESUFFIX=	2

MAINTAINER=	5u623l20@gmail.com
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

LICENSE=	LGPL21

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libunistring.so:${PORTSDIR}/devel/libunistring \
		libffi.so.6:${PORTSDIR}/devel/libffi

CONFLICTS_INSTALL=	guile-[0-9]*

USE_AUTOTOOLS=	aclocal automake libltdl
USES=		gmake ncurses pkgconfig readline
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_GCC=	any

PLIST_SUB=	GUILE_VER=${PORTVERSION:R}

OPTIONS_DEFINE=	NLS THREADS
OPTIONS_DEFAULT=THREADS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
THREADS_CONFIGURE_WITH=	threads
THREADS_LIB_DEPENDS=	libgc.so:${PORTSDIR}/devel/boehm-gc-threaded
THREADS_LIB_DEPENDS_OFF=	libgc.so:${PORTSDIR}/devel/boehm-gc

REINPLACE_FILES=	libguile/smob.c libguile/filesys.c libguile/gc.c \
			libguile/mallocs.c libguile/eval.c libguile/gc-malloc.c \
			libguile/ports.c

INFO=		guile r5rs

.include <bsd.port.options.mk>

post-patch:
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES}
	@${REINPLACE_CMD} -e 's|2.63|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
	      ${WRKSRC}/meta/Makefile.in ${WRKSRC}/meta/Makefile.am
	@${REINPLACE_CMD} -e 's|libdir}/pkgconfig|prefix}/libdata/pkgconfig|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|sys/time.h sys/timeb.h|sys/time.h |g' ${WRKSRC}/configure.ac \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|install-exec-local: install-exec-localcharset|install-exec-local:|g' \
	       	${WRKSRC}/lib/Makefile.am
.if ${PORT_OPTIONS:MTHREADS}
	@${REINPLACE_CMD} -e 's|bdw-gc|bdw-gc-threaded|g' ${WRKSRC}/configure.ac
.endif

.include <bsd.port.mk>
