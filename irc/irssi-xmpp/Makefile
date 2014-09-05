# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	irssi-xmpp
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://cybione.org/~irssi-xmpp/files/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Irssi plugin to connect to Jabber network

LICENSE=	GPLv2

BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
LIB_DEPENDS=	libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
DATADIR=	${PREFIX}/share/irssi
DOCSDIR=	${PREFIX}/share/doc/irssi
CFLAGS_amd64=	-fPIC

OPTIONS_DEFINE=	DOCS

post-patch:
# Try to unbreak parallel builds (-jX)
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$${MAKE})|\2 -C \1|' \
		${WRKSRC}/Makefile ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
