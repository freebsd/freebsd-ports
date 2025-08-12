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
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-libinotify.pc.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/inotify.h ${STAGEDIR}${PREFIX}/include/sys/inotify.h
.endif

.include <bsd.port.mk>
