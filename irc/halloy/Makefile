PORTNAME=	halloy
DISTVERSION=	2025.6
PORTREVISION=	2
CATEGORIES=	irc

MAINTAINER=	pokeysquirrel@gmail.com
COMMENT=	IRC client written in Rust, with the iced GUI library
WWW=		https://halloy.chat/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libzstd.so:archivers/zstd

USES=		cargo desktop-file-utils ssl

USE_GITHUB=	yes
GH_ACCOUNT=	squidowl

post-install:
	${INSTALL_DATA} ${FILESDIR}/halloy.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor
	(cd ${WRKSRC}/assets/linux/icons/hicolor && for f in \
		*/apps/org.squidowl.halloy.png; do ${MV} $${f} \
		$${f%org.squidowl.halloy.png}halloy.png; done && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/icons/hicolor)

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

.include <bsd.port.post.mk>
