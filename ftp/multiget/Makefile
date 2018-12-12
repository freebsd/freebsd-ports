# Created by: alepulver
# $FreeBSD$

PORTNAME=	multiget
PORTVERSION=	1.1.3
PORTREVISION=	11
CATEGORIES=	ftp www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP/FTP downloader with a nice GUI

LICENSE=	GPLv2+

WRKSRC_SUBDIR=	src

USES=		alias compiler:c++11-lang dos2unix
USE_WX=		2.8
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
	${INSTALL_PROGRAM} ${WRKSRC}/MultiGet ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/../MultiGet.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
