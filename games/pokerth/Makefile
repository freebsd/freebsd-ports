# New ports collection makefile for:	pokerth
# Date created:		24 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pokerth
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	PokerTH-${PORTVERSION}-1.src

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A poker game written in C++/QT4

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		mikmod.2:${PORTSDIR}/audio/libmikmod

MANUAL_PACKAGE_BUILD=	requires large memory to build

USE_ICONV=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib qmake_build moc_build rcc_build uic_build
USE_SDL=	mixer

WRKSRC=		${WRKDIR}/PokerTH-${PORTVERSION}

PLIST_FILES=	bin/pokerth %%DATADIR%%/pokerth share/pixmaps/pokerth.png

PORTDOCS=	COPYING ChangeLog INSTALL TODO

PORTDATA=	data

MAN1=		pokerth.1

DESKTOP_ENTRIES=	"PokerTH" \
			"A poker game written in C++/Qt 4" \
			"pokerth.png" \
			"pokerth" \
			"Application;Game;CardGame;" \
			"false"

MAKE_ENV+=	QTDIR="${QT_PREFIX}"

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/usr/([a-z|/]+)|${LOCALBASE}/\1|g' \
		-e 's|(-lcrypto)|\1 -liconv|g' \
		-e 's:boost_([a-z]+)-[-|a-z|0-9|_]*:boost_\1:g' \
		${WRKSRC}/*.pro

do-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix pokerth.pro

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/pokerth ${DATADIR}/pokerth
	@${CP} -R ${WRKSRC}/${PORTDATA} ${DATADIR}
	@${ECHO_CMD} "exec ${DATADIR}/pokerth" > ${WRKSRC}/pokerth.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/pokerth.sh ${PREFIX}/bin/pokerth
	@${INSTALL_DATA} ${WRKSRC}/pokerth.png ${PREFIX}/share/pixmaps/pokerth.png
	@${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
