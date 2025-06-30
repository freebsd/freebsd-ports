PORTNAME=	libgsf
DISTVERSION=	1.14.53
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Structured file library from GNOME
WWW=		https://gitlab.gnome.org/GNOME/libgsf/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake gnome libtool localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	gdkpixbuf glib20 libxml2 introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-introspection

INSTALL_TARGET=	install-strip

PLIST_SUB+=	LIBMINORVER=${DISTVERSION:E} \
		LIBSHORTVER=${DISTVERSION:R:S/.//}

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
