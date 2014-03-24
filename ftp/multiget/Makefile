# Created by: alepulver
# $FreeBSD$

PORTNAME=	multiget
PORTVERSION=	1.1.3
PORTREVISION=	8
CATEGORIES=	ftp www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP/FTP downloader with a nice GUI

WRKSRC_SUBDIR=	src

USES=		dos2unix
USE_WX=		2.8
WX_UNICODE=	yes
MAKEFILE=	makefile
ALL_TARGET=	MultiGet

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/MultiGet.png

DESKTOP_ENTRIES="MultiGet" "" "${PREFIX}/share/pixmaps/MultiGet.png" \
		"${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(CC)|$$(CXX)| ; \
		 s|$$(CFLAGS)|$$(CXXFLAGS)| ; \
		 s|^CC =|CXX ?=| ; \
		 s|^CFLAGS =|CXXFLAGS +=| ; \
		 s| -O2 | | ; \
		 s| -s | | ; \
		 s|wx-config|$${WX_CONFIG}|' \
		 ${WRKSRC}/${MAKEFILE}

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} MultiGet \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME})
	(cd ${WRKSRC}/.. && ${INSTALL_DATA} MultiGet.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
