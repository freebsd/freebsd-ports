# Created by: Shinya Esu <esu@yk.rim.or.jp>
# $FreeBSD$

PORTNAME=	macopix
PORTVERSION=	1.7.4
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://rosegray.sakura.ne.jp/macopix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${RESTRICTED_FILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window sitter for X11

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		dumps core: Assertion failed: (!NodePtr->isKnownSentinel()), function operator*, file ilist_iterator.h
BROKEN_armv7=		dumps core: Assertion failed: (!NodePtr->isKnownSentinel()), function operator*, file ilist_iterator.h

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

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

USES=		gettext gmake iconv jpeg libtool pkgconfig
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11 ${ICONV_LIB}

OPTIONS_DEFINE=	DOCS GNUTLS GTK1

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-gnutls

GTK1_USE=		GNOME=gtk12,gdkpixbuf
GTK1_CONFIGURE_ON=	--with-gtk1

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGNUTLS}
USES+=	ssl
.endif

.if ${PORT_OPTIONS:MGTK1}
PKGNAMESUFFIX=	-gtk1
.else
USE_GNOME+=	gtk20
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/_MAIL } MailStatus/_MAIL } MailStatus2/' ${WRKSRC}/src/main.h
.if ${PORT_OPTIONS:MGTK1}
	@${REINPLACE_CMD} 's|png_ptr->jmpbuf|png_jmpbuf(png_ptr)|' \
		${WRKSRC}/src/nokkari.c
.endif

post-install:
# install mascot file
	@${MKDIR} ${STAGEDIR}${DATADIR}/pixmap
	cd ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.comipa.jp
	cd ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.cosmos.jp
	cd ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.kanon.jp
	cd ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.mizuiro.jp
	cd ${WRKDIR}/macopix-mascot-one-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.one.jp
	cd ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.pia2.jp
	cd ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.trh.jp
	cd ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.tsuki.jp
	cd ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.marimite.jp
	cd ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30 \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${STAGEDIR}${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${STAGEDIR}${DATADIR}/README.HxB.jp
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NKR.README.ja README README.ja \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
