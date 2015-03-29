# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	irssi-otr
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	GHL

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Plugin for irssi for Off-the-Record (OTR) messaging

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/irssi/src/common.h:${PORTSDIR}/irc/irssi \
		${LOCALBASE}/bin/libgcrypt-config:${PORTSDIR}/security/libgcrypt
LIB_DEPENDS=	libotr.so:${PORTSDIR}/security/libotr \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	cryptodotis
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	f4ecd19
GH_TAGNAME=	v${PORTVERSION}

USE_AUTOTOOLS=	autoconf aclocal libtoolize automake
ACLOCAL_ARGS=	-I config
AUTOMAKE_ARGS=	--add-missing --no-force

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE} --with-libotr-inc-prefix=${LOCALBASE}/include
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/irssi/modules/libotr.so \
		share/irssi/help/otr

.include <bsd.port.mk>
