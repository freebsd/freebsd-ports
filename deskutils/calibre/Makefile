# New ports collection makefile for:	calibre
# Date created:		10/11/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	calibre
PORTVERSION=	0.6.27
PORTREVISION=	6
CATEGORIES=	deskutils python
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		http://calibre-ebook.googlecode.com/files/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ebook management application

LIB_DEPENDS=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		wmflite:${PORTSDIR}/graphics/libwmf
BUILD_DEPENDS=	py*-setuptools>=0:${PORTSDIR}/devel/py-setuptools \
		py*-sip>=0:${PORTSDIR}/devel/py-sip \
		py*-qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		py*-dnspython>=0:${PORTSDIR}/dns/py-dnspython \
		py*-dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		py*-beautifulsoup>=0:${PORTSDIR}/www/py-beautifulsoup \
		py*-imaging>=0:${PORTSDIR}/graphics/py-imaging \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		py*-mechanize>=0:${PORTSDIR}/www/py-mechanize \
		py*-sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		py*-qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		py*-qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		py*-qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		py*-qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		py*-qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml

OPTIONS=	PODOFO "PDF support via PoDoFo library" on \
		MOUNTHELPER_SUID "Install mount helper as suid binary" off

USE_GETTEXT=	yes
USE_PYTHON=	2.6+
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build
WRKSRC=		${WRKDIR}/${PORTNAME}
PYSETUP=	setup.py
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
MAKE_ENV+=	LDFLAGS="${LDFLAGS}" \
		FC_INC_DIR="${LOCALBASE}/include/fontconfig" \
		FC_LIB_DIR="${LOCALBASE}/lib" \
		OVERRIDE_CFLAGS="${CFLAGS}" \
		OVERRIDE_LDFLAGS="${LDFLAGS}"

MAN1=	calibre-customize.1 calibre-debug.1 calibre-server.1 calibre-smtp.1 \
	calibredb.1 ebook-convert.1 ebook-meta.1 fetch-ebook-metadata.1 \
	librarything.1 lrf2lrs.1 lrs2lrf.1 pdfmanipulate.1 web2disk.1
MANCOMPRESSED=	no

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
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install --prefix ${PREFIX})

post-install:
.if defined(WITH_MOUNTHELPER_SUID)
	${CHOWN} ${BINOWN}:operator ${PREFIX}/bin/calibre-mount-helper
	${CHMOD} g+s ${PREFIX}/bin/calibre-mount-helper
.endif

.include <bsd.port.post.mk>
