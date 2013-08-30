# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	irssi-xmpp
PORTVERSION=	0.52
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
MAKE_ARGS=	CC="${CC}"
DATADIR=	${PREFIX}/share/irssi
DOCSDIR=	${PREFIX}/share/doc/irssi

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# Try to unbreak parallel builds (-jX)
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$${MAKE})|\2 -C \1|' \
		${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
# Uphold CFLAGS
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|' ${WRKSRC}/config.mk
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|doc-install ||' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
