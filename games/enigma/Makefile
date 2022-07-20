PORTNAME=	enigma
PORTVERSION=	1.30
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Reimplementation of Oxyd, a puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so.3:textproc/xerces-c3 \
		libpng.so:graphics/png \
		libenet.so:net/enet \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	convert:graphics/ImageMagick6

USE_GITHUB=	yes
GH_ACCOUNT=	Enigma-Game
GH_PROJECT=	Enigma

USES=		autoreconf:build gettext gmake iconv localbase pkgconfig sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl2 image2 mixer2 ttf2
CONFIGURE_ARGS=	--with-system-enet
LDFLAGS+=	-lintl

SUB_FILES=	pkg-message

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html

NLS_CONFIGURE_ENABLE=nls

pre-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SH} autogen.sh

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/SUBDIRS =/d' ${WRKSRC}/doc/Makefile.am

post-patch:
	@${REINPLACE_CMD} -e '/Exec=/s,enigma,${PREFIX}/bin/enigma,g' \
		${WRKSRC}/etc/enigma.desktop

.include <bsd.port.mk>
