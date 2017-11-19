# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	adplug
PORTVERSION=	2.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	audio
PKGNAMEPREFIX=	lib

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib emulator library supporting many formats

LICENSE=	GPLv2

LIB_DEPENDS=	libbinio.so:devel/libbinio

USES=		autoreconf libtool makeinfo pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89

INFO=		libadplug

CONFIGURE_ARGS+=	--enable-maintainer-mode

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
