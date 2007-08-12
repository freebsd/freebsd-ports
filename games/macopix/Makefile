# New ports collection makefile for:	macopix
# Date created:				15 Apr 2003
# Whom:					Shinya Esu <esu@yk.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	macopix
PORTVERSION=	1.6.4
CATEGORIES=	games
MASTER_SITES=	http://rosegray.sakura.ne.jp/macopix/
.if defined(WITH_GTK1)
PKGNAMESUFFIX=	-gtk1
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${RESTRICTED_FILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window sitter for X11

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

RESTRICTED=	'contains commercial character data'

RESTRICTED_FILES=	\
		macopix-mascot-comic_party-euc-ja-1.02.tar.gz \
		macopix-mascot-cosmos-euc-ja-1.02.tar.gz \
		macopix-mascot-kanon-euc-ja-1.02.tar.gz \
		macopix-mascot-mizuiro-euc-ja-1.02.tar.gz \
		macopix-mascot-one-euc-ja-1.02.tar.gz \
		macopix-mascot-pia2-euc-ja-1.02.tar.gz \
		macopix-mascot-triangle_heart-euc-ja-1.02.tar.gz \
		macopix-mascot-tsukihime-euc-ja-1.02.tar.gz \
		macopix-mascot-marimite-euc-ja-2.20.tar.gz \
		macopix-mascot-HxB-euc-ja-0.30.tar.gz

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
.if defined(WITH_GTK1)
USE_GNOME=	gtk12 gdkpixbuf
.else
USE_GNOME=	gtk20
.endif
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
.if defined(WITH_GTK1)
CONFIGURE_ARGS+=	--with-gtk1
.endif
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		macopix.1

post-extract:
	@${REINPLACE_CMD} -e 's/_MAIL } MailStatus/_MAIL } MailStatus2/' ${WRKSRC}/src/main.h

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
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02/comipa.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.comipa.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02/cosmos.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.cosmos.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02/kanon.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.kanon.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02/mizuiro.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.mizuiro.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-euc-ja-1.02/one.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-one-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.one.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02/pia2.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.pia2.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02/trh.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.trh.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02/tsuki.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02/README.jp ${PREFIX}/share/macopix/README.tsuki.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20/marimite.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20/README.jp ${PREFIX}/share/macopix/README.marimite.jp
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30/*.png ${PREFIX}/share/macopix/pixmap/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30/*.mcpx ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30/HxB.menu ${PREFIX}/share/macopix/
	${INSTALL_DATA} ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30/README.jp ${PREFIX}/share/macopix/README.HxB.jp
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/macopix
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/macopix
	${INSTALL_MAN} ${WRKSRC}/README.ja ${PREFIX}/share/doc/macopix
	${INSTALL_MAN} ${WRKSRC}/NKR.README.ja ${PREFIX}/share/doc/macopix
.endif

.include <bsd.port.mk>
