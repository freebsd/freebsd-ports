PORTNAME=	libgee
PORTVERSION=	0.6.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	06

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GObject collection library
WWW=		https://live.gnome.org/Libgee

DEPRECATED=     Legacy verision, unsupported upstream
EXPIRATION_DATE=2025-07-31

USES=		cpe gmake gnome libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
