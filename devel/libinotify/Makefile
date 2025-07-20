PORTNAME=	libinotify
PORTVERSION=	20240724
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libinotify-kqueue/libinotify-kqueue/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kevent based inotify compatible library
WWW=		https://github.com/libinotify-kqueue/libinotify-kqueue

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pathfix

CONFIGURE_ARGS=	--enable-skip-subfiles=fusefs,smbfs
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.if exists(/usr/include/sys/inotify.h)
post-install:
	${PRINTF} '#pragma GCC system_header\n#include_next <sys/inotify.h>\n' \
		> ${STAGEDIR}${PREFIX}/include/sys/inotify.h
	${SED} -e '/Libs:/d' -e '/Cflags:/d' ${WRKSRC}/libinotify.pc \
		> ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libinotify.pc
.endif

.include <bsd.port.mk>
