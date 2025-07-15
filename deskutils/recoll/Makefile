PORTNAME=	recoll
PORTVERSION=	1.33.1
PORTREVISION=	12
CATEGORIES=	deskutils
MASTER_SITES=	${WWW}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Personal full-text search package, based on Xapian
WWW=		https://www.recoll.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS}
LIB_DEPENDS=	libxapian.so:databases/xapian-core
RUN_DEPENDS=	antiword:textproc/antiword \
		catdoc:textproc/catdoc \
		unrar:archivers/unrar \
		unrtf:textproc/unrtf \
		wpd2html:textproc/libwpd010

USES=		bison compiler:c++11-lang fam gmake gnome iconv libtool \
		localbase pkgconfig python shebangfix
USE_GNOME=	libxslt
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
SHEBANG_FILES=	desktop/hotrecoll.py filters/*.py filters/rclimg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-recollq --enable-xadump
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}
BINARY_ALIAS=	python2=${FALSE} python3=${PYTHON_CMD}

PYDISTUTILS_PKGNAME=	Recoll
PYDISTUTILS_PKGVERSION=	1.0

PLIST_SUB=	PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}" \
		VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		ASPELL CHM DJVU IMAGE LATEX PDF PS QT5 SOUND X11MON
OPTIONS_DEFAULT=	ASPELL CHM IMAGE PDF PS QT5 SOUND X11MON
OPTIONS_SUB=		yes

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_OFF=	--without-aspell
CHM_DESC=		Python bindings for Microsoft ITSS/CHM format
CHM_LIB_DEPENDS=	libchm.so:misc/chmlib
CHM_CONFIGURE_OFF=	--disable-python-chm
DJVU_RUN_DEPENDS=	djvutxt:graphics/djvulibre
IMAGE_DESC=		Store personal tags or textual descriptions in images
IMAGE_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
LATEX_USES=		tex
LATEX_USE=		TEX=dvipsk:run,latex:run
PDF_RUN_DEPENDS=	pdftotext:graphics/poppler-utils
PS_RUN_DEPENDS=		pstotext:print/pstotext
QT5_USES=		gl qt:5
QT5_USE=		GL=gl QT=buildtools:build,qmake:build \
			QT=core,gui,printsupport,widgets,xml
QT5_CONFIGURE_ENV=	QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" \
			QTDIR="${PREFIX}"
QT5_CONFIGURE_ON=	--disable-webkit
QT5_CONFIGURE_OFF=	--disable-qtgui
SOUND_RUN_DEPENDS=	mutagen-pony-${PYTHON_VER}:audio/py-mutagen@${PY_FLAVOR}
X11MON_DESC=		X11 session monitoring support
X11MON_USES=		fam xorg
X11MON_USE=		XORG=ice,sm,x11
X11MON_CONFIGURE_OFF=	--disable-x11mon
X11MON_CONFIGURE_ON=	--with-fam

post-patch:
	@${REINPLACE_CMD} -e 's|@QMAKE@|${TRUE}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|override const|const override|' \
		${WRKSRC}/index/rclmonrcv.cpp

pre-build-QT5-on:
	@cd ${WRKSRC}/qtgui && \
		${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} recoll.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recoll/*.so \
		${STAGEDIR}${PREFIX}/lib/recoll/*.so
# Remove systemd unit files (useless on FreeBSD)
	@${RM} ${STAGEDIR}${DATADIR}/examples/recollindex*.service

post-install-CHM-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recollchm/*.so

.include <bsd.port.mk>
