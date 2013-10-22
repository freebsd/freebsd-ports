# Created by: gahr
# $FreeBSD$

PORTNAME=	fxite
PORTVERSION=	0.91
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An advanced cross-platform text editor

LIB_DEPENDS=	#

OPTIONS_SINGLE=		FOX
OPTIONS_SINGLE_FOX=	FOX16 FOX17
FOX16_DESC=		Use FOX 1.6
FOX17_DESC=		Use FOX 1.7
OPTIONS_DEFAULT=	FOX16

USE_GITHUB=	yes
GH_ACCOUNT=	yetanothergeek
GH_TAGNAME=	FXITE-0_91
GH_COMMIT=	c2ecac3

USES=		pkgconfig
USE_LUA=	yes
USE_AUTOTOOLS=	aclocal autoconf automake
ACLOCAL_ARGS=	--force -I m4
AUTOMAKE_ARGS=	--gnu --add-missing --copy
USE_GMAKE=	yes
CXXFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS+=--with-system-lua \
		--with-lua-pkg=lua-${LUA_VER}
CONFIGURE_ENV+=	FOX_CFLAGS="${FOX_CFLAGS}" \
		FOX_LIBS="${FOX_LIBS}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFOX16}
LIB_DEPENDS+=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16
CONFIGURE_ENV+=	RESWRAP=${LOCALBASE}/bin/reswrap
FOX_CFLAGS+=	`fox-config --cflags`
FOX_LIBS+=	`fox-config --libs`
.endif

.if ${PORT_OPTIONS:MFOX17}
LIB_DEPENDS+=	FOX-1.7:${PORTSDIR}/x11-toolkits/fox17
CONFIGURE_ENV+=	RESWRAP=${LOCALBASE}/bin/fox-1.7/reswrap
FOX_CFLAGS+=	`pkgconf fox17 --cflags`
FOX_LIBS+=	`pkgconf fox17 --libs`
.endif

PLIST_FILES=	bin/fxite \
		share/pixmaps/fxite.xpm \
		share/applications/fxite.desktop

.include <bsd.port.mk>
