# New ports collection makefile for:	poppler
# Date created:         03 March 2005
# Whom:                 marcus@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.23 2006/04/12 17:10:20 ahze Exp $
#

PORTNAME=	poppler
PORTVERSION=	0.5.1
PORTREVISION?=	1
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A PDF rendering library

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-xpdf-headers \
		--with-html-dir=${DOCSDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if defined(SLAVEPORT)
LIB_DEPENDS+=	poppler.1:${PORTSDIR}/graphics/poppler
.if ${SLAVEPORT}=="gtk"
CONFIGURE_ARGS+=--enable-poppler-glib
USE_GNOME+=	gtk20
BUILD_WRKSRC=	${WRKSRC}/glib
INSTALL_WRKSRC=	${WRKSRC}/glib
.elif ${SLAVEPORT}=="qt"
CONFIGURE_ARGS+=--enable-poppler-qt
USE_QT_VER+=	3
BUILD_WRKSRC=	${WRKSRC}/qt
INSTALL_WRKSRC=	${WRKSRC}/qt
# blah.. USE_QT_VER can't be defined after bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.elif ${SLAVEPORT}=="utils"
CONFIGURE_ARGS+=--enable-utils
CONFLICTS=	xpdf-[0-9]*
BUILD_WRKSRC=	${WRKSRC}/utils
INSTALL_WRKSRC=	${WRKSRC}/utils
MAN1=	pdffonts.1 pdfimages.1 pdfinfo.1 \
	pdftohtml.1  pdftops.1 pdftotext.1 pdftoppm.1
.endif
.else
CONFIGURE_ARGS+=--disable-poppler-glib --disable-poppler-qt \
		--disable-poppler-qt4 --disable-utils
.endif

post-patch:
.if defined(SLAVEPORT) && ${SLAVEPORT}=="qt"
	@${REINPLACE_CMD} -e 's|/usr/local/qt/include|${X11BASE}/include|; \
		s|/usr/local/qt/lib|${X11BASE}/lib|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$QTDIR|${X11BASE}|' ${WRKSRC}/configure
.endif

post-install:
.if defined(SLAVEPORT)
.if ${SLAVEPORT}=="gtk"
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc ${PREFIX}/libdata/pkgconfig
.elif ${SLAVEPORT}=="qt"
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc ${PREFIX}/libdata/pkgconfig
.endif
.endif

.include <bsd.port.post.mk>
