# New ports collection makefile for:	macopix
# Date created:				15 Apr 2003
# Whom:					Shinya Esu <esu@yk.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	macopix
PORTVERSION=	0.8.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://kurumi.sakura.ne.jp/~chimari/macopix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${RESTRICTED_FILES}

MAINTAINER=	esu@yk.rim.or.jp
COMMENT=	Window sitter for X11

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

RESTRICTED=	'contains commercial character data'
RESTRICTED_FILES= \
		macopix-mascot-comic_party-ja-1.00.tar.gz \
		macopix-mascot-cosmos-ja-1.00.tar.gz \
		macopix-mascot-kanon-ja-1.00.tar.gz \
		macopix-mascot-mizuiro-ja-1.00.tar.gz \
		macopix-mascot-one-ja-1.00.tar.gz \
		macopix-mascot-pia2-ja-1.00.tar.gz \
		macopix-mascot-triangle_heart-ja-1.00.tar.gz \
		macopix-mascot-tsukihime-ja-1.00.tar.gz \
		macopix-mascot-marimite-ja-0.70.tar.gz

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12 gdkpixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		macopix.1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/macopix
# install mascot file
#	for file in ${RESTRICTED_FILES}; do \
#		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
#	then \
#		exit 1; \
#	fi \
#	done
	${MKDIR} ${PREFIX}/share/macopix/
	${MKDIR} ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-ja/comipa.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-ja/README.jp ${PREFIX}/share/macopix/README.comipa.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-ja/cosmos.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-ja/README.jp ${PREFIX}/share/macopix/README.cosmos.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-ja/kanon.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-ja/README.jp ${PREFIX}/share/macopix/README.kanon.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-ja/mizuiro.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-ja/README.jp ${PREFIX}/share/macopix/README.mizuiro.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-ja/one.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-ja/README.jp ${PREFIX}/share/macopix/README.one.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-ja/pia2.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-ja/README.jp ${PREFIX}/share/macopix/README.pia2.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-ja/trh.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-ja/README.jp ${PREFIX}/share/macopix/README.trh.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-ja/tsuki.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-ja/README.jp ${PREFIX}/share/macopix/README.tsuki.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-ja/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-ja/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-ja/marimite.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-ja/README.jp ${PREFIX}/share/macopix/README.marimite.jp

.include <bsd.port.mk>
