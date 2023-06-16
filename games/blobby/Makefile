PORTNAME=	blobby
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Official continuation of the famous Blobby Volley 1.x game
WWW=		http://blobbyvolley.de

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libphysfs.so:devel/physfs
BUILD_DEPENDS=	zip:archivers/zip \
		${LOCALBASE}/include/boost/crc.hpp:devel/boost-libs

USES=		cmake compiler:c++11-lang dos2unix gl localbase:ldflags \
		pkgconfig sdl
USE_SDL=	sdl2
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	danielknobe
GH_PROJECT=	blobbyvolley2

DOS2UNIX_REGEX=	.*\.(c|h|cpp)
CMAKE_ARGS=	-DDATADIR:PATH="${DATADIR}"

PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
