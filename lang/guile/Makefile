# Created by: jseger@FreeBSD.org
# $FreeBSD$
#    $MCom: ports/lang/guile/Makefile,v 1.1 2006/09/12 14:57:06 ahze Exp $

PORTNAME=	guile
PORTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libffi.so:devel/libffi \
		libgmp.so:math/gmp \
		libltdl.so:devel/libltdl \
		libunistring.so:devel/libunistring

USES=		charsetfix compiler:c11 gmake iconv libtool makeinfo pathfix pkgconfig \
	readline tar:lz
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	guile1-[0-9]* guile2-[0-9]*

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		guile r5rs

PLIST_SUB=	GUILE_VER=${PORTVERSION:R}

OPTIONS_DEFINE=	NLS THREADS
OPTIONS_DEFAULT=NLS THREADS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

THREADS_CONFIGURE_WITH=	threads
THREADS_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
THREADS_LIB_DEPENDS_OFF=	libgc.so:devel/boehm-gc

post-patch:
	@${REINPLACE_CMD} -e 's|sys/time.h sys/timeb.h|sys/time.h |g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-i -e|-i.bak -e|' \
		${WRKSRC}/libguile/Makefile.in

post-patch-THREADS-on:
	@${REINPLACE_CMD} -e 's|bdw-gc|bdw-gc-threaded|g' ${WRKSRC}/configure

.include <bsd.port.mk>
