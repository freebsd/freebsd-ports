PORTNAME=	cliamp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	audio

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Retro terminal music player inspired by Winamp 2.x
WWW=		https://github.com/bjarneo/cliamp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libFLAC.so:audio/flac \
		libmpg123.so:audio/mpg123 \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		ffmpeg:multimedia/ffmpeg \
		yt-dlp:www/yt-dlp

USES=		go:1.26+,modules pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bjarneo

GO_MOD_DIST=	github
GO_MODULE=	github.com/bjarneo/cliamp
GO_BUILDFLAGS=	-ldflags "-s -w -X main.version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/cliamp \
		share/applications/cliamp.desktop \
		share/icons/hicolor/512x512/apps/cliamp.png \
		share/pixmaps/cliamp.png

# The MPRIS D-Bus service and the URL scheme handler registration are
# portable, but upstream only builds them from *_linux.go files, which Go
# restricts to GOOS=linux by file name.  Reuse them on FreeBSD.
post-patch:
.for f in cmd/protocol mediactl/service
	${SED} -e '1s|^//go:build linux$$|//go:build freebsd|' \
		${WRKSRC}/${f}_linux.go > ${WRKSRC}/${f}_freebsd.go
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/cliamp.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Cliamp.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/cliamp.png
	${INSTALL_DATA} ${WRKSRC}/Cliamp.png ${STAGEDIR}${PREFIX}/share/pixmaps/cliamp.png

.include <bsd.port.mk>
