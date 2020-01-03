# $FreeBSD$

PORTNAME=	scrcpy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.1
CATEGORIES=	comms net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_TAGNAME}/:server
DISTFILES=	${SERVER_FILE}:server
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@yandex.com
COMMENT=	Display and control your Android device

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	adb:devel/android-tools-adb

USES=		compiler:c++11-lang meson pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	Genymobile

MESON_ARGS=	-Dportable=false \
		-Dprebuilt_server=${WRKSRC}/${SERVER_FILE}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md FAQ.md

SERVER_FILE=	${PORTNAME}-server-${DISTVERSIONPREFIX}${DISTVERSION}
PLIST_FILES=	bin/scrcpy man/man1/scrcpy.1.gz ${DATADIR}/scrcpy-server

post-extract:
	${CP} ${DISTDIR}/${SERVER_FILE} ${WRKSRC}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
