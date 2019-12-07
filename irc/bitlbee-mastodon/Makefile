# $FreeBSD$

PORTNAME=	bitlbee-mastodon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
CATEGORIES=	irc

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Bitlbee plugin to communicate with Mastodon instances

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bitlbee>=3.5:irc/bitlbee \
		gsed:textproc/gsed
RUN_DEPENDS=	bitlbee>=3.5:irc/bitlbee

USES=		autoreconf gmake gnome libtool pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	kensanata

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plugindir=${PREFIX}/lib/bitlbee
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/bitlbee/mastodon.so \
		share/bitlbee/mastodon-help.txt

BINARY_ALIAS=	sed=gsed

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
