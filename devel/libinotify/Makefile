PORTNAME=	libinotify
PORTVERSION=	20240724
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libinotify-kqueue/libinotify-kqueue/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kevent based inotify compatible library
WWW=		https://github.com/libinotify-kqueue/libinotify-kqueue

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool

CONFIGURE_ARGS=	--enable-skip-subfiles=fusefs,smbfs
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.if exists(/usr/include/sys/inotify.h)
post-install:
	${INSTALL_DATA} /usr/include/sys/inotify.h ${STAGEDIR}${PREFIX}/include/sys/
	${SED} -e '/Libs:/d' -e '/Cflags:/d' ${WRKSRC}/libinotify.pc \
		> ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libinotify.pc
.endif

.include <bsd.port.mk>
