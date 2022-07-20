PORTNAME=	libinotify
PORTVERSION=	20211018
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libinotify-kqueue/libinotify-kqueue/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Kevent based inotify compatible library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool

CONFIGURE_ARGS=	--enable-skip-subfiles=fusefs,smbfs
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
