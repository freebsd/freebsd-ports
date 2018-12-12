# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	7kaa
PORTVERSION=	2.14.7
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/skfans/7KAA%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Seven Kingdoms: Ancient Adversaries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to compile: OBULLET.cpp:41:9: constant expression evaluates to -1 which cannot be narrowed to type 'char'
BROKEN_armv6=		fails to compile: OBULLET.cpp:41:9: constant expression evaluates to -1 which cannot be narrowed to type 'char'
BROKEN_armv7=		fails to compile: OBULLET.cpp:41:9: constant expression evaluates to -1 which cannot be narrowed to type 'char'

LIB_DEPENDS=	libenet.so:net/enet \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lang gmake localbase openal:al pkgconfig tar:xz
GNU_CONFIGURE=	yes
LLD_UNSAFE=	yes
CONFIGURE_ARGS=	--disable-nls # no translations ATM
USE_SDL=	sdl2
CXXFLAGS+=		-Wno-error=narrowing

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.ico
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="7KAA" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;StrategyGame;" \
		""

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/src/7k.ico ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

.include <bsd.port.mk>
