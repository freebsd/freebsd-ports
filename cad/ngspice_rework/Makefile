# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngspice_rework
PORTVERSION=	31
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider

LICENSE=	BSD3CLAUSE BSD4CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

FLAVORS=	x11 shlib
shlib_PKGNAMESUFFIX=	-shlib
shlib_CONFLICTS_INSTALL=	ngspice_rework-2*
x11_CONFLICTS_INSTALL=		ngspice_rework-shlib-2*

USES=		gmake libtool ncurses readline

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-cider --enable-shared --enable-xspice --with-readline=yes

OPTIONS_DEFINE=	DEBUG

.if ${FLAVOR:U} ==	shlib
CONFIGURE_ARGS+=	--with-ngshared
PLIST_SUB+=		SHLIB="" X11="@comment "
.else
USES+=			xorg
USE_XORG=		ice sm x11 xaw xext xmu xt
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=		SHLIB="@comment " X11=""
.endif

DEBUG_CONFIGURE_ENABLE=	debug

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
