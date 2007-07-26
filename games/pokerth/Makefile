# New ports collection makefile for:	pokerth
# Date created:		24 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pokerth
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	PokerTH-${PORTVERSION}-src

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A poker game written in C++/QT4

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		mikmod.2:${PORTSDIR}/audio/libmikmod

MANUAL_PACKAGE_BUILD=	requires large memory to build

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib qmake moc rcc uic
USE_SDL=	mixer

WRKSRC=		${WRKDIR}/PokerTH-${PORTVERSION}

PLIST_FILES=	bin/pokerth share/pixmaps/pokerth.png

PORTDOCS=	COPYING ChangeLog INSTALL TODO

DESKTOP_ENTRIES=	"PokerTH" \
			"A poker game written in C++/Qt 4" \
			"pokerth.png" \
			"pokerth" \
			"Application;Game;CardGame;" \
			"false"

MAKE_ENV+=	QTDIR="${QT_PREFIX}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}|g' \
		-e 's|boost_thread-mt|boost_thread|g' \
		${WRKSRC}/pokerth.pro

do-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix pokerth.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth ${PREFIX}/bin/pokerth
	@${INSTALL_DATA} ${WRKSRC}/pokerth.png ${PREFIX}/share/pixmaps/pokerth.png
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
