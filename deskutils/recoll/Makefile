# Created by: J.F. Dockes <jean-francois.dockes@wanadoo.fr>
# $FreeBSD$

PORTNAME=	recoll
DISTVERSION=	1.23.7
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Personal full text search package, based on Xapian

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core
RUN_DEPENDS=	unrar:archivers/unrar \
		antiword:textproc/antiword \
		catdoc:textproc/catdoc \
		wpd2html:textproc/libwpd010 \
		unrtf:textproc/unrtf

USES=		bison gmake iconv libtool localbase python:2.7 shebangfix
SHEBANG_FILES=	filters/*.py desktop/hotrecoll.py \
		filters/rcl7z filters/rclaudio filters/rclchm \
		filters/rcldia filters/rclepub filters/rclepub1 \
		filters/rclics filters/rclinfo filters/rclkar \
		filters/rclpython filters/rclrar filters/rcltar \
		filters/rclwar filters/rclzip
USE_PYTHON=	py3kplist
USE_GNOME=	libxslt:run
GNU_CONFIGURE=	yes
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_PKGNAME=	Recoll
PYDISTUTILS_PKGVERSION=	1.0

PLIST_SUB=		VERSION="${PORTVERSION}" \
			PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}"

OPTIONS_DEFINE=		ASPELL CHM DJVU KONQUEROR LATEX IMAGE PDF PS \
			SOUND QT4 X11MON
OPTIONS_DEFAULT=	ASPELL IMAGE PDF PS SOUND QT4
OPTIONS_SUB=		yes

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_WITH=	aspell
CHM_DESC=		CHM via CHMLIB
CHM_RUN_DEPENDS=	pychm>0:textproc/pychm
DJVU_RUN_DEPENDS=	djvutxt:graphics/djvulibre
IMAGE_DESC=		Store personal tags or textual descriptions in images
IMAGE_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
KONQUEROR_DESC=		Konqueror webarchive format with Python
KONQUEROR_RUN_DEPENDS=	kwebkitpart>0:www/kwebkitpart
LATEX_USE=		tex=dvipsk:run,latex:run
PDF_RUN_DEPENDS=	pdftotext:graphics/poppler-utils
PS_RUN_DEPENDS=		pstotext:print/pstotext
QT4_USE=		qt4=moc_build,qmake_build,rcc_build,uic_build \
			qt4=iconengines_run,imageformats_run \
			qt4=corelib,gui,xml,webkit
QT4_CONFIGURE_ENABLE=	qtgui
QT4_CONFIGURE_ENV=	QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" \
			QTDIR="${PREFIX}"
QT4_VARS=		QT_NONSTANDARD=yes
SOUND_RUN_DEPENDS=	mutagen-pony:audio/py-mutagen@${PY_FLAVOR} \
			pykaraoke:audio/py-karaoke@${PY_FLAVOR}
X11MON_DESC=		X11 session monitoring support
X11MON_USES=		fam
X11MON_USE=		xorg=ice,sm,x11
X11MON_CONFIGURE_ENABLE=x11mon
X11MON_CONFIGURE_WITH=	fam
X11MON_BROKEN=		does not build: index/rclmonrcv.cpp:(.text+0x1f13): undefined reference to `FAMOpen2'

post-patch:
	@${REINPLACE_CMD} -e \
		's|@QMAKE@|${TRUE}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|python setup.py|${PYTHON_CMD} setup.py|; s|sudo||' \
		${WRKSRC}/python/recoll/Makefile.in
	@${REINPLACE_CMD} -e \
		's|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/Makefile.in

pre-build-QT4-on:
	@(cd ${WRKSRC}/qtgui && ${SETENV} ${QMAKE_ENV} ${QMAKE} \
		${QMAKE_ARGS} recoll.pro)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recoll/*.so \
		${STAGEDIR}${PREFIX}/lib/recoll/*.so

.include <bsd.port.mk>
