# Created by: J.F. Dockes <jean-francois.dockes@wanadoo.fr>
# $FreeBSD$

PORTNAME=	recoll
DISTVERSION=	1.25.22
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	https://www.lesbonscomptes.com/recoll/

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Personal full text search package, based on Xapian

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
LIB_DEPENDS=	libxapian.so:databases/xapian-core
RUN_DEPENDS=	unrar:archivers/unrar \
		antiword:textproc/antiword \
		catdoc:textproc/catdoc \
		wpd2html:textproc/libwpd010 \
		unrtf:textproc/unrtf

USES=		bison compiler:c++11-lang gmake gnome iconv libtool localbase \
		python:2.7 shebangfix
USE_GNOME=	libxslt
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist

SHEBANG_FILES=	filters/*.py filters/rcl7z filters/rclaudio \
		filters/rclchm filters/rcldia filters/rclepub \
		filters/rclepub1 filters/rclics filters/rclimg \
		filters/rclinfo filters/rclkar filters/rclpython \
		filters/rclrar filters/rcltar filters/rclwar \
		filters/rclzip desktop/hotrecoll.py
GNU_CONFIGURE=	yes
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_PKGNAME=	Recoll
PYDISTUTILS_PKGVERSION=	1.0

PLIST_SUB=		VERSION="${PORTVERSION}" \
			PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}"

OPTIONS_DEFINE=		ASPELL CHM DJVU LATEX IMAGE PDF PS \
			SOUND QT5 X11MON
OPTIONS_DEFAULT=	ASPELL IMAGE PDF PS SOUND
OPTIONS_SUB=		yes

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_WITH=	aspell
CHM_DESC=		CHM via CHMLIB
CHM_CONFIGURE_ENABLE=	python-chm
CHM_LIB_DEPENDS=	libchm.so:misc/chmlib
CHM_RUN_DEPENDS=	pychm>0:textproc/pychm
DJVU_RUN_DEPENDS=	djvutxt:graphics/djvulibre
IMAGE_DESC=		Store personal tags or textual descriptions in images
IMAGE_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
LATEX_USE=		tex=dvipsk:run,latex:run
PDF_RUN_DEPENDS=	pdftotext:graphics/poppler-utils
PS_RUN_DEPENDS=		pstotext:print/pstotext
USE_QT=			core gui network printsupport widgets webkit xml buildtools_build qmake_build
QT5_USES=		qt:5 gl
QT5_USE=		GL=gl
QT5_CONFIGURE_ENABLE=	qtgui
QT5_CONFIGURE_ENV=	QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" \
			QTDIR="${PREFIX}"
SOUND_RUN_DEPENDS=	mutagen-pony-${PYTHON_VER}:audio/py-mutagen@${PY_FLAVOR} \
			pykaraoke:audio/py-karaoke@${PY_FLAVOR}
X11MON_DESC=		X11 session monitoring support
X11MON_USES=		fam xorg
X11MON_USE=		xorg=ice,sm,x11
X11MON_CONFIGURE_ENABLE=	x11mon
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
		${WRKSRC}/python/recoll/Makefile
	@${REINPLACE_CMD} -e \
		's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/Makefile.in

pre-build-QT5-on:
	@cd ${WRKSRC}/qtgui && ${SETENV} ${QMAKE_ENV} ${QMAKE} \
		${QMAKE_ARGS} recoll.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recoll/*.so \
		${STAGEDIR}${PREFIX}/lib/recoll/*.so

post-install-CHM-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recollchm/*.so

.include <bsd.port.mk>
