# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	enigma
PORTVERSION=	1.21
CATEGORIES=	games
MASTER_SITES=	SF/enigma-game/Release%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so.3:textproc/xerces-c3 \
		libpng.so:graphics/png \
		libenet.so:net/enet \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	convert:graphics/ImageMagick

USES=		gmake localbase pkgconfig
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-enet

SUB_FILES=	pkg-message

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

post-patch:
	@${REINPLACE_CMD} -e '/Exec=/s,enigma,${PREFIX}/bin/enigma,g' \
		${WRKSRC}/etc/enigma.desktop

post-install:
	@${RM} -d ${STAGEDIR}${DOCSDIR}/COPYING

.include <bsd.port.mk>
