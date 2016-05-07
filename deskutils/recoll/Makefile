# Created by: J.F. Dockes <jean-francois.dockes@wanadoo.fr>
# $FreeBSD$

PORTNAME=	recoll
PORTVERSION=	1.21.6
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

USES=		bison gmake iconv shebangfix
SHEBANG_FILES=	filters/rclimg filters/rclpdf desktop/hotrecoll.py
USE_GNOME=	libxslt:run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pic

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		ASPELL CHM DJVU KONQUEROR LATEX IMAGE PDF PS PYTHON \
			SOUND QT4 X11MON
OPTIONS_DEFAULT=	ASPELL IMAGE PDF PS PYTHON SOUND QT4 X11MON
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
PYTHON_USES=		python
PYTHON_CONFIGURE_ENABLE=	python-module
PYTHON_PLIST_SUB=	PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}"
PYTHON_VARS= 		PYDISTUTILS_PKGNAME=Recoll \
			PYDISTUTILS_PKGVERSION=1.0
QT4_USE=		qt4=moc_build,qmake_build,rcc_build,uic_build \
			qt4=iconengines_run,imageformats_run \
			qt4=corelib,gui,xml,webkit
QT4_CONFIGURE_ENABLE=	qtgui
QT4_CONFIGURE_ENV=	QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" \
			QTDIR="${QT_PREFIX}"
QT4_VARS=		QT_NONSTANDARD=yes
SOUND_RUN_DEPENDS=	mutagen-pony:audio/py-mutagen \
			pykaraoke:audio/py-karaoke
X11MON_DESC=		X11 session monitoring support
X11MON_USES=		fam
X11MON_USE=		xorg=ice,sm,x11
X11MON_CONFIGURE_ENABLE=	x11mon
X11MON_CONFIGURE_WITH=	fam

post-patch:
	@${REINPLACE_CMD} -e \
		's|@QMAKE@|${TRUE}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@NOCMDLINE@|| ; \
		 s|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/recollinstall.in
	@${REINPLACE_CMD} -e \
		's|python setup.py|${PYTHON_CMD} setup.py|; s|sudo||' \
		${WRKSRC}/python/recoll/Makefile

pre-build-QT4-on:
	@(cd ${WRKSRC}/qtgui && ${SETENV} ${QMAKE_ENV} ${QMAKE} \
		${QMAKE_ARGS} recoll.pro)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/recoll/librecoll.so.[0-9].*

post-install-PYTHON-on:
.for l in recoll rclextract
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recoll/${l}.so
.endfor
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
