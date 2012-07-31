# New ports collection makefile for:	calibre
# Date created:		10/11/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	calibre
PORTVERSION=	0.8.61
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Ebook management application

LIB_DEPENDS=	MagickWand.5:${PORTSDIR}/graphics/ImageMagick \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		wmflite:${PORTSDIR}/graphics/libwmf \
		chm.0:${PORTSDIR}/misc/chmlib \
		icudata.48:${PORTSDIR}/devel/icu
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}sip>=0:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.9:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>=0:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0:${PORTSDIR}/www/py-mechanize \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus \
		pdftohtml:${PORTSDIR}/graphics/poppler-utils \
		lshal:${PORTSDIR}/sysutils/hal

OPTIONS_DEFINE=	PODOFO
PODOFO_DESC=	PDF support via PoDoFo library
OPTIONS_DEFAULT=PODOFO

USE_XZ=		yes
USE_PYTHON=	2.7
USE_QT4=	qmake_build moc_build
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
MAKE_ENV+=	FC_INC_DIR="${LOCALBASE}/include/fontconfig" \
		FC_LIB_DIR="${LOCALBASE}/lib" \
		OVERRIDE_CFLAGS="${CFLAGS}" \
		OVERRIDE_LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
MAKE_ENV+=	WITH_USB=no
PLIST_SUB+=	USB="@comment "
.else
MAKE_ENV+=	WITH_USB=yes
PLIST_SUB+=	USB=""
.endif
.if !defined(WITHOUT_PODOFO) || exists(${LOCALBASE}/lib/libpodofo.so)
LIB_DEPENDS+=	podofo:${PORTSDIR}/graphics/podofo
MAKE_ENV+=	PODOFO_LIB_DIR="${LOCALBASE}/lib" \
		PODOFO_INC_DIR="${LOCALBASE}/include/podofo"
PLIST_SUB+=	PODOFO=""
.else
PLIST_SUB+=	PODOFO="@comment "
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
.for dir in desktop-directories applications  gnome/apps mime/packages icons/hicolor/128x128/apps
	${MKDIR} ${PREFIX}/share/${dir}
.endfor
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} ${INSTALL} --prefix ${PREFIX})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
