# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	pokerth
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1
DISTNAME=	PokerTH-${PORTVERSION}-src

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Poker game written in C++/Qt4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libmikmod.so:${PORTSDIR}/audio/libmikmod \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libgsasl.so:${PORTSDIR}/security/gsasl \
		libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libprotobuf.so:${PORTSDIR}/devel/protobuf
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:${PORTSDIR}/irc/libircclient

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

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/docs/pokerth.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/server_setup_howto.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
