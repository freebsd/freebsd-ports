PORTNAME=	ctypes.sh
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/taviso/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	ctypes-sh-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Foreign function interface for bash
WWW=		https://github.com/taviso/ctypes.sh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf libtool pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ctypes.sh lib/ctypes.so

pre-patch:
	${RM} ${WRKSRC}/include/config.h

.include <bsd.port.mk>
