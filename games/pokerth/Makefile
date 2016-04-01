# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	pokerth
PORTVERSION=	1.1.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1
DISTNAME=	PokerTH-${PORTVERSION}-src

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Poker game written in C++/Qt4

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libmikmod.so:audio/libmikmod \
		libgnutls.so:security/gnutls \
		libcurl.so:ftp/curl \
		libgsasl.so:security/gsasl \
		libtinyxml.so:textproc/tinyxml \
		libprotobuf.so:devel/protobuf
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:irc/libircclient

USES=		iconv gmake qmake tar:bzip2
USE_QT4=	gui corelib network sql sql-sqlite3 \
		moc_build rcc_build uic_build
USE_SDL=	mixer
QMAKE_SOURCE_PATH=	pokerth.pro

PORTDOCS=	server_setup_howto.txt

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr([a-z|/]*)|${LOCALBASE}/\1|g' \
		-e 's|(-lcurl)|\1 ${ICONV_LIB}|g' \
		-e 's|(-lcrypto) -liconv|\1 ${ICONV_LIB}|' \
		-e 's:boost_([a-z]+)-[-|a-z|0-9|_]*:boost_\1:g' \
		-e 's|LIB_DIRS =.*|LIB_DIRS = ${LOCALBASE}/lib|g' \
		-e '/.*QMAKE_CXXFLAGS.*/d' \
		${WRKSRC}/*.pro
	@${FIND} ${WRKSRC} -name '*.cpp' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|[io]fstream|std::&|'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pokerth
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/pokerth.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/server_setup_howto.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
