# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	irssi-xmpp
PORTVERSION=	0.54
CATEGORIES=	irc
MASTER_SITES=	http://cybione.org/~irssi-xmpp/files/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Irssi plugin to connect to Jabber network

LICENSE=	GPLv2

BUILD_DEPENDS=	irssi:irc/irssi
LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext-runtime gnome pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
DATADIR=	${PREFIX}/share/irssi
DOCSDIR=	${PREFIX}/share/doc/irssi
CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC
CFLAGS_i386=	-fPIC
CFLAGS_powerpc64=	-fPIC

OPTIONS_DEFINE=	DOCS

post-patch:
# Try to unbreak parallel builds (-jX)
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$$\{MAKE})|\2 -C \1|' \
		${WRKSRC}/Makefile ${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/irssi/modules/*.so

.include <bsd.port.mk>
