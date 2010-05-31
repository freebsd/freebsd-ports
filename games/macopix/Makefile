# New ports collection makefile for:	macopix
# Date created:				15 Apr 2003
# Whom:					Shinya Esu <esu@yk.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	macopix
PORTVERSION=	1.7.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://rosegray.sakura.ne.jp/macopix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${RESTRICTED_FILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window sitter for X11

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
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

USE_GNOME=	gnometarget
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		macopix.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
USE_OPENSSL=	yes
.endif

.if defined(WITH_GTK1)
PKGNAMESUFFIX=	-gtk1
USE_GNOME+=	gtk12 gdkpixbuf
CONFIGURE_ARGS+=	--with-gtk1
.else
USE_GNOME+=	gtk20
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/_MAIL } MailStatus/_MAIL } MailStatus2/' ${WRKSRC}/src/main.h

post-install:
# install mascot file
	${MKDIR} ${DATADIR}/pixmap
	cd ${WRKDIR}/macopix-mascot-comic_party-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.comipa.jp
	cd ${WRKDIR}/macopix-mascot-cosmos-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.cosmos.jp
	cd ${WRKDIR}/macopix-mascot-kanon-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.kanon.jp
	cd ${WRKDIR}/macopix-mascot-mizuiro-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.mizuiro.jp
	cd ${WRKDIR}/macopix-mascot-one-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.one.jp
	cd ${WRKDIR}/macopix-mascot-pia2-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.pia2.jp
	cd ${WRKDIR}/macopix-mascot-triangle_heart-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.trh.jp
	cd ${WRKDIR}/macopix-mascot-tsukihime-euc-ja-1.02 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.tsuki.jp
	cd ${WRKDIR}/macopix-mascot-marimite-euc-ja-2.20 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.marimite.jp
	cd ${WRKDIR}/macopix-mascot-HxB-euc-ja-0.30 \
		&& ${INSTALL_DATA} *.png ${DATADIR}/pixmap \
		&& ${INSTALL_DATA} *.mcpx *.menu ${DATADIR} \
		&& ${INSTALL_DATA} README.jp ${DATADIR}/README.HxB.jp
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} \
		&& ${INSTALL_MAN} NKR.README.ja README README.ja ${DOCSDIR}
.endif

.include <bsd.port.mk>
