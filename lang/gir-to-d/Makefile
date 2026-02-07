PORTNAME=	gir-to-d
PORTVERSION=	0.23.4
PORTREVISION=	1
#DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Create D bindings from GObject introspection files
WWW=		https://github.com/gtkd-developers/gir-to-d

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ldc2:lang/ldc
LIB_DEPENDS=	libphobos2-ldc-shared.so:lang/ldc \
		libdruntime-ldc-shared.so:lang/ldc

USES=		gnome meson

USE_GNOME=	introspection

USE_GITHUB=	yes
GH_ACCOUNT=	gtkd-developers

# a workaround for https://github.com/ldc-developers/ldc/issues/4000
CONFIGURE_ENV=	DFLAGS=--allinst

PLIST_FILES=	bin/girtod

.include <bsd.port.mk>
