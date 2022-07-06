PORTNAME=	recoll
PORTVERSION=	1.31.4
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	https://www.lesbonscomptes.com/recoll/

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Personal full text search package, based on Xapian

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
LIB_DEPENDS=	libxapian.so:databases/xapian-core
RUN_DEPENDS=	antiword:textproc/antiword \
		catdoc:textproc/catdoc \
		unrar:archivers/unrar \
		unrtf:textproc/unrtf \
		wpd2html:textproc/libwpd010

USES=		bison compiler:c++11-lang gmake gnome iconv libtool localbase \
		pkgconfig python:3.5+ shebangfix
USE_GNOME=	libxslt
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
PYDISTUTILS_PKGNAME=	Recoll
PYDISTUTILS_PKGVERSION=	1.0
USE_QT=		core gui printsupport widgets xml buildtools_build qmake_build

SHEBANG_FILES=	desktop/hotrecoll.py filters/*.py filters/rcl7z \
		filters/rclaudio filters/rclchm filters/rcldia filters/rclepub \
		filters/rclepub1 filters/rclics filters/rclimg filters/rclinfo \
		filters/rclkar filters/rclrar filters/rcltar filters/rclwar \
		filters/rclzip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-recollq \
		--enable-xadump
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}
BINARY_ALIAS=	python2=${FALSE} python3=${PYTHON_CMD}

PLIST_SUB=	PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}" \
		VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		ASPELL CHM DJVU IMAGE LATEX PDF PS QT5 SOUND X11MON
OPTIONS_DEFAULT=	ASPELL CHM IMAGE PDF PS QT5 SOUND X11MON
OPTIONS_SUB=		yes

CHM_DESC=			Python bindings for Microsoft ITSS/CHM format
IMAGE_DESC=			Store personal tags or textual descriptions in images
X11MON_DESC=			X11 session monitoring support
ASPELL_LIB_DEPENDS=		libaspell.so:textproc/aspell
ASPELL_CONFIGURE_WITH=		aspell
CHM_LIB_DEPENDS=		libchm.so:misc/chmlib
CHM_CONFIGURE_OFF=		--disable-python-chm
DJVU_RUN_DEPENDS=		djvutxt:graphics/djvulibre
IMAGE_RUN_DEPENDS=		exiftool:graphics/p5-Image-ExifTool
LATEX_USE=			dvipsk:run \
				latex:run
PDF_RUN_DEPENDS=		pdftotext:graphics/poppler-utils
PS_RUN_DEPENDS=			pstotext:print/pstotext
QT5_USES=			gl qt:5
QT5_USE=			GL=gl
QT5_CONFIGURE_ON=		--disable-webkit
QT5_CONFIGURE_ENABLE=		qtgui
QT5_CONFIGURE_ENV=		QMAKE="${QMAKE}" \
				QMAKESPEC="${QMAKESPEC}" \
				QTDIR="${PREFIX}"
SOUND_RUN_DEPENDS=		mutagen-pony-${PYTHON_VER}:audio/py-mutagen@${PY_FLAVOR}
X11MON_USES=			fam xorg
X11MON_USE=			XORG=ice,sm,x11
X11MON_CONFIGURE_ENABLE=	x11mon
X11MON_CONFIGURE_WITH=		fam

post-patch:
	@${REINPLACE_CMD} -e 's|@QMAKE@|${TRUE}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/configure

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
