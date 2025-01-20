PORTNAME=	halloy
DISTVERSION=	2024.14
PORTREVISION=	1
CATEGORIES=	irc

MAINTAINER=	pokeysquirrel@gmail.com
COMMENT=	IRC client written in Rust, with the iced GUI library
WWW=		https://halloy.squidowl.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	squidowl

DESKTOP_ENTRIES="Halloy" \
		"IRC Client" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Network;IRCClient;" \
		false

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor
	(cd ${WRKSRC}/assets/linux/icons/hicolor && for f in \
		*/apps/org.squidowl.halloy.png; do ${MV} $${f} \
		$${f%org.squidowl.halloy.png}halloy.png; done && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/hicolor)

.include <bsd.port.mk>
