PORTNAME=	libgee
PORTVERSION=	0.20.8
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GObject collection library
WWW=		https://gitlab.gnome.org/GNOME/libgee

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USES=		compiler cpe gettext gmake gnome libtool pathfix pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
