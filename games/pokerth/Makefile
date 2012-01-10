# New ports collection makefile for:	pokerth
# Date created:		24 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pokerth
PORTVERSION=	0.9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9
DISTNAME=	PokerTH-${PORTVERSION}-src

MAINTAINER=	mad@madpilot.net
COMMENT=	A poker game written in C++/QT4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		mikmod.2:${PORTSDIR}/audio/libmikmod \
		gnutls.47:${PORTSDIR}/security/gnutls \
		curl.6:${PORTSDIR}/ftp/curl \
		gsasl.15:${PORTSDIR}/security/gsasl \
		tinyxml:${PORTSDIR}/textproc/tinyxml
BUILD_DEPENDS=	${LOCALBASE}/include/libircclient.h:${PORTSDIR}/irc/libircclient

USE_ICONV=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib network sql sql-sqlite3 qmake_build \
		moc_build rcc_build uic_build
USE_SDL=	mixer
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix PREFIX=${PREFIX}

PORTDOCS=	server_setup_howto.txt
MAN1=		pokerth.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr([a-z|/]*)|${LOCALBASE}/\1|g' \
		-e 's|(-lcurl)|\1 -liconv|g' \
		-e 's:boost_([a-z]+)-[-|a-z|0-9|_]*:boost_\1:g' \
		-e 's|LIB_DIRS =.*|LIB_DIRS = ${LOCALBASE}/lib|g' \
		-e '/^QMAKE_CXXFLAGS.*/d' \
		${WRKSRC}/*.pro

do-configure:
	@cd ${CONFIGURE_WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS} pokerth.pro

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pokerth ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/server_setup_howto.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
