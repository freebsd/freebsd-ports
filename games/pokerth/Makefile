# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	pokerth
PORTVERSION=	1.1.2
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Poker game written in C++/Qt

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libmikmod.so:audio/libmikmod \
		libgnutls.so:security/gnutls \
		libcurl.so:ftp/curl \
		libgsasl.so:security/libgsasl \
		libtinyxml.so:textproc/tinyxml \
		libprotobuf.so:devel/protobuf \
		libircclient.so:irc/libircclient
BUILD_DEPENDS=	${LOCALBASE}/include/websocketpp/client.hpp:devel/websocketpp \
		protoc:devel/protobuf

USES=		compiler:c++11-lang gl gmake iconv qmake qt:5 sdl sqlite ssl
USE_GL=		gl
USE_CXXSTD=	c++11
USE_QT=		buildtools_build core gui network sql sql-sqlite3 widgets
USE_SDL=	mixer

QMAKE_SOURCE_PATH=	pokerth.pro
QMAKE_ARGS+=	CONFIG+="client"
WRKSRC=		${WRKDIR}/${DISTNAME}-rc

PORTDOCS=	server_setup_howto.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr([a-z|/]*)|${LOCALBASE}/\1|g' \
		-e 's|(-lcurl)|\1 ${ICONV_LIB}|g' \
		-e 's|(-lcrypto) -liconv|\1 ${ICONV_LIB}|' \
		-e 's:boost_([a-z]+)-[-|a-z|0-9|_]*:boost_\1:g' \
		-e 's|LIB_DIRS =.*|LIB_DIRS = ${LOCALBASE}/lib|g' \
		-e '/.*QMAKE_CXXFLAGS.*/d' \
		${WRKSRC}/*.pro

pre-build:
	(cd ${WRKSRC} && \
		 protoc --cpp_out=src/third_party/protobuf chatcleaner.proto && \
		 protoc --cpp_out=src/third_party/protobuf pokerth.proto \
	)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pokerth
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/pokerth.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/server_setup_howto.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
