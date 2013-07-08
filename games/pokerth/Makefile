# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	pokerth
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0
DISTNAME=	PokerTH-${PORTVERSION}-src

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	A poker game written in C++/QT4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		mikmod:${PORTSDIR}/audio/libmikmod \
		gnutls:${PORTSDIR}/security/gnutls \
		curl:${PORTSDIR}/ftp/curl \
		gsasl:${PORTSDIR}/security/gsasl \
		tinyxml:${PORTSDIR}/textproc/tinyxml \
		protobuf:${PORTSDIR}/devel/protobuf
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:${PORTSDIR}/irc/libircclient

USES=		iconv gmake
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
USE_QT4=	gui corelib network sql sql-sqlite3 qmake_build \
		moc_build rcc_build uic_build
USE_SDL=	mixer
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	PREFIX=${PREFIX}

PORTDOCS=	server_setup_howto.txt
MAN1=		pokerth.1

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr([a-z|/]*)|${LOCALBASE}/\1|g' \
		-e 's|(-lcurl)|\1 -liconv|g' \
		-e 's:boost_([a-z]+)-[-|a-z|0-9|_]*:boost_\1:g' \
		-e 's|LIB_DIRS =.*|LIB_DIRS = ${LOCALBASE}/lib|g' \
		-e '/.*QMAKE_CXXFLAGS.*/d' \
		${WRKSRC}/*.pro

do-configure:
	@cd ${CONFIGURE_WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS} pokerth.pro

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pokerth ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/server_setup_howto.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
