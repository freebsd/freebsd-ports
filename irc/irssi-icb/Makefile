PORTNAME=	irssi-icb
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	irc

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Irssi plugin for connecting to ICB network
WWW=		https://github.com/mglocker/irssi-icb

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/irssi/src/common.h:irc/irssi
RUN_DEPENDS=	irssi:irc/irssi

USES=		autoreconf gnome libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	mglocker
GH_TAGNAME=	c4e2ea8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-irssi=${LOCALBASE}/include/irssi
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/irssi/modules/libfe_icb.so \
		lib/irssi/modules/libicb_core.so

.include <bsd.port.pre.mk>

# Fixes build failure for Clang 16.0.6
.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
