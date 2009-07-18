# New ports collection makefile for:	poppler
# Date created:         03 March 2005
# Whom:                 marcus@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.44 2009/03/14 05:12:31 marcus Exp $
#

PORTNAME=	poppler
PORTVERSION=	0.10.6
PORTREVISION?=	1
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A PDF rendering library

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	poppler-data>0:${PORTSDIR}/graphics/poppler-data

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget libxml2 ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-xpdf-headers \
		--with-html-dir=${DOCSDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if !defined(SLAVEPORT)
OPTIONS=	CAIRO "Enable cairo output backend" on
.endif

.include <bsd.port.pre.mk>

.if defined(SLAVEPORT)
LIB_DEPENDS+=	poppler.4:${PORTSDIR}/graphics/poppler

.if ${SLAVEPORT}=="gtk"
CONFIGURE_ARGS+=--enable-poppler-glib
USE_GNOME+=	gtk20
BUILD_WRKSRC=	${WRKSRC}/glib
INSTALL_WRKSRC=	${WRKSRC}/glib
.else
CONFIGURE_ARGS+=--disable-poppler-glib \
		--disable-gdk \
		--disable-gtk-test
.endif

.if ${SLAVEPORT}=="qt"
CONFIGURE_ARGS+=--enable-poppler-qt
USE_QT_VER+=	3
BUILD_WRKSRC=	${WRKSRC}/qt
INSTALL_WRKSRC=	${WRKSRC}/qt
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.else
CONFIGURE_ARGS+=--disable-poppler-qt
.endif

.if ${SLAVEPORT}=="qt4"
CONFIGURE_ARGS+=--enable-poppler-qt4
USE_QT_VER+=	4
QT_COMPONENTS=	gui corelib xml qtestlib moc_build
# It requires poppler/splash to be built unless you disable splash backend
# support to allow you use BUILD_WRKSRC here. It seems that splash backend
# can read more PDF files than without, tested with demos's poppler_qt4viewer.
#BUILD_WRKSRC=	${WRKSRC}/qt4
INSTALL_WRKSRC=	${WRKSRC}/qt4
.else
CONFIGURE_ARGS+=--disable-poppler-qt4
.endif

.if ${SLAVEPORT}=="utils"
CONFIGURE_ARGS+=--enable-utils
CONFLICTS=	xpdf-[0-9]*
BUILD_WRKSRC=	${WRKSRC}/utils
INSTALL_WRKSRC=	${WRKSRC}/utils
MAN1=		pdffonts.1 pdfimages.1 pdfinfo.1 \
		pdftohtml.1  pdftops.1 pdftotext.1 pdftoppm.1
.else
CONFIGURE_ARGS+=--disable-utils
.endif

.else
CONFIGURE_ARGS+=--disable-poppler-glib --disable-poppler-qt \
		--disable-poppler-qt4 --disable-utils --disable-gdk \
		--disable-gtk-test

.if defined(WITHOUT_CAIRO)
CONFIGURE_ARGS+=--disable-cairo-output
PLIST_SUB+=	CAIRO="@comment "
.else
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.endif
.endif

post-patch:
.if defined(SLAVEPORT) && ${SLAVEPORT}=="qt"
	@${REINPLACE_CMD} -e 's|/usr/local/qt/include|${LOCALBASE}/include|; \
		s|/usr/local/qt/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$QTDIR|${QT_PREFIX}|' ${WRKSRC}/configure
.endif
.if defined(SLAVEPORT) && ${SLAVEPORT}=="qt4"
	@${REINPLACE_CMD} -e 's|MOCQT4=`.*|MOCQT4="${LOCALBASE}/bin/moc-qt4"|' \
		${WRKSRC}/configure
.endif

post-install:
.if defined(SLAVEPORT)
.if ${SLAVEPORT}=="gtk"
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc ${PREFIX}/libdata/pkgconfig
.elif ${SLAVEPORT}=="qt"
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc ${PREFIX}/libdata/pkgconfig
.elif ${SLAVEPORT}=="qt4"
	${INSTALL_DATA} ${WRKSRC}/poppler-qt4.pc ${PREFIX}/libdata/pkgconfig
.endif
.endif

.include <bsd.port.post.mk>
