PORTNAME=	libinotify
PORTVERSION=	20211018
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libinotify-kqueue/libinotify-kqueue/releases/download/${PORTVERSION}/

PATCH_SITES=	https://github.com/libinotify-kqueue/libinotify-kqueue/commit/
PATCHFILES=	56088169f263b79daf6b32e2f7b3e020a26980be.patch:-p1

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

.include <bsd.port.mk>
