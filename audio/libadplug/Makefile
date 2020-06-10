# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	adplug
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	audio
PKGNAMEPREFIX=	lib

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib emulator library supporting many formats

LICENSE=	GPLv2

LIB_DEPENDS=	libbinio.so:devel/libbinio

USES=		autoreconf libtool makeinfo pathfix pkgconfig
USE_CSTD=	gnu89
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-maintainer-mode

INSTALL_TARGET=	install-strip

INFO=		libadplug
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
