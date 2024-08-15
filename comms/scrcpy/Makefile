PORTNAME=	scrcpy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	comms net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSIONFULL}/:server
DISTFILES=	${SERVER_FILE}:server
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Display and control your Android device
WWW=		https://github.com/Genymobile/scrcpy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	adb:devel/android-tools

USES=		compiler:c++11-lang meson pkgconfig sdl

USE_GITHUB=	yes
GH_ACCOUNT=	Genymobile

USE_SDL=	sdl2

MESON_ARGS=	-Dportable=false \
		-Dprebuilt_server=${WRKSRC}/${SERVER_FILE}

PLIST_FILES=	bin/scrcpy \
		etc/bash_completion.d/scrcpy \
		share/man/man1/scrcpy.1.gz \
		share/applications/scrcpy-console.desktop \
		share/applications/scrcpy.desktop \
		share/icons/hicolor/256x256/apps/scrcpy.png \
		${DATADIR}/scrcpy-server \
		share/zsh/site-functions/_scrcpy
PORTDOCS=	FAQ.md README.md

OPTIONS_DEFINE=	DOCS

SERVER_FILE=	${PORTNAME}-server-${DISTVERSIONFULL}

post-extract:
	${CP} ${DISTDIR}/${SERVER_FILE} ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
