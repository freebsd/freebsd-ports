# $FreeBSD$

PORTNAME=	emulationstation
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
PORTREVISION=	4
CATEGORIES=	emulators

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Graphical front-end for emulators (RetroPie fork)

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/opensans_license.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_locale.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libpugixml.so:textproc/pugixml \
		libvlc.so:multimedia/vlc

USES=		cmake compiler:gcc-c++11-lib gl pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	RetroPie
GH_PROJECT=	EmulationStation
USE_GL=		gl glu
USE_SDL=	sdl2

PLIST_FILES=	bin/emulationstation
PORTDOCS=	CREDITS.md DEVNOTES.md GAMELISTS.md README.md SYSTEMS.md \
		THEMES.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
