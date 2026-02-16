PORTNAME=	waves
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.41
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal music player with MusicBrainz tagging, and Last.fm scrobbling
WWW=		https://github.com/llehouerou/waves

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		xdg-open:devel/xdg-utils

USES=		go:modules pkgconfig

GO_MODULE=	github.com/llehouerou/waves

SUB_FILES=	pkg-message

PLIST_FILES=	bin/waves \
		share/waves/config.example.toml

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
		${MKDIR} ${STAGEDIR}${DATADIR}
	        ${INSTALL_DATA} ${WRKSRC}/config.example.toml \
		${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
