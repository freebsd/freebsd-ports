PORTNAME=	enigma
PORTVERSION=	1.30
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Reimplementation of Oxyd, a puzzle game
WWW=		https://www.nongnu.org/enigma/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3 \
		libpng.so:graphics/png \
		libenet.so:net/enet \
		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	Enigma-Game
GH_PROJECT=	Enigma

USES=		autoreconf:build gettext gmake iconv localbase magick:build \
		pkgconfig sdl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
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
