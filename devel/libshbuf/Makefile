PORTNAME=	libshbuf
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libshbuf/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library for Shared Buffer IPC
WWW=		https://0pointer.de/lennart/projects/libshbuf/

LICENSE=	GPLv2 # though COPYING says LGPL21

USES=		pathfix libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-lynx --disable-doxygen

INSTALL_TARGET=	install-strip

CFLAGS+=	-D_WANT_SEMUN

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
