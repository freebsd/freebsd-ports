# $FreeBSD$

PORTNAME=	scrcpy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
CATEGORIES=	comms net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_TAGNAME}/:jar
DISTFILES=	${DIST_JARFILE}:jar
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@yandex.com
COMMENT=	Display and control your Android device

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	adb:devel/android-tools-adb

USES=		meson pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	Genymobile

MESON_ARGS=	-Dbuild_server=false

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md FAQ.md

DIST_JARFILE=	${PORTNAME}-server-${DISTVERSIONPREFIX}${DISTVERSION}.jar
INSTALL_JARFILE=	${DIST_JARFILE:C/(server).*/\1/}.jar
PLIST_FILES=	bin/scrcpy ${DATADIR}/${INSTALL_JARFILE}

post-extract:
	${CP} ${_DISTDIR}/${DIST_JARFILE} ${WRKSRC}/${INSTALL_JARFILE}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${INSTALL_JARFILE} ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
