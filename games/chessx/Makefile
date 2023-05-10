PORTNAME=	chessx
DISTVERSION=	1.6.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	alexey@pentode.fi
COMMENT=	Qt 5 chess database application
WWW=		https://chessx.sourceforge.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		compiler:c++11-lang desktop-file-utils gl gmake qmake qt:5 tar:tgz
USE_GL=		gl
USE_QT=		concurrent core gui multimedia network opengl printsupport svg \
		widgets xml buildtools:build linguisttools:build speech

PLIST_FILES=	bin/chessx \
		share/applications/chessx.desktop \
		share/pixmaps/chessx.png \
		share/metainfo/io.sourceforge.ChessX.metainfo.xml \
		share/icons/hicolor/128x128/apps/chessx.png \
		share/icons/hicolor/32x32/apps/chessx-32.png \
		share/icons/hicolor/64x64/apps/chessx-64.png

OPTIONS_DEFINE=	CRAFTY STOCKFISH

CRAFTY_DESC=	Install Crafty Chess Application
STOCKFISH_DESC=	Install Stockfish Chess Engine

CRAFTY_RUN_DEPENDS=	crafty:games/crafty
STOCKFISH_RUN_DEPENDS=	stockfish:games/stockfish

post-configure:
	( cd ${BUILD_WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro )

# the FIND command works around a bug in FreeBSD 12.4 strip(1) which
# leaves junk files when attempting to strip a file of unrecognised format.
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chessx
	${FIND} ${STAGEDIR}${PREFIX} -name 'ecp.????????' -delete

.include <bsd.port.mk>
