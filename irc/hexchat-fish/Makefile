# $FreeBSD$

PORTNAME=	fishlim
PORTVERSION=	0.0.19
CATEGORIES=	irc security
MASTER_SITES=	http://git.fishlim.kodafritt.se/fishlim/snapshot/
PKGNAMEPREFIX=	hexchat-
DISTNAME=	fishlim-f952f6f21f6b7786e10d06a5ca90749f6e9f1f40

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Encryption plugin for Hexchat

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	hexchat:irc/hexchat

USES=		tar:bz2 pkgconfig ssl
USE_GNOME=	glib20

CFLAGS+=	-I${LOCALBASE}/include/glib-2.0
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto

PLIST_FILES=	lib/hexchat/plugins/fishlim.so

post-patch:
	# base eopnssl has no libcrypto.pc
	${REINPLACE_CMD} -e 's| libcrypto||' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/hexchat/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/fishlim.so \
		${STAGEDIR}${PREFIX}/lib/hexchat/plugins/

.include <bsd.port.mk>
