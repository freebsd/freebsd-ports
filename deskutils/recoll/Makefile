# Created by: J.F. Dockes <jean-francois.dockes@wanadoo.fr>
# $FreeBSD$

PORTNAME=	recoll
PORTVERSION=	1.19.14
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/${PORTNAME}/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Personal full text search package, based on Xapian

LICENSE=	GPLv2

BUILD_DEPENDS=	xapian-core>=0:${PORTSDIR}/databases/xapian-core
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		antiword:${PORTSDIR}/textproc/antiword \
		catdoc:${PORTSDIR}/textproc/catdoc \
		wpd2html:${PORTSDIR}/textproc/libwpd \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		unrar:${PORTSDIR}/archivers/unrar \
		unrtf:${PORTSDIR}/textproc/unrtf

USES=		gmake iconv shebangfix
SHEBANG_FILES=	filters/rclimg desktop/hotrecoll.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pic

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		ASPELL CHM DJVU KONQUEROR LATEX IMAGE PDF PS PYTHON \
			SOUND QT4 X11MON
OPTIONS_DEFAULT=	ASPELL IMAGE PDF PS PYTHON SOUND QT4 X11MON
OPTIONS_SUB=		yes

ASPELL_LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_CONFIGURE_WITH=	aspell
CHM_DESC=		CHM via CHMLIB
CHM_RUN_DEPENDS=	pychm:${PORTSDIR}/textproc/pychm
DJVU_RUN_DEPENDS=	djvutxt:${PORTSDIR}/graphics/djvulibre
IMAGE_DESC=		Store personal tags or textual descriptions in images
IMAGE_RUN_DEPENDS=	exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool-devel
KONQUEROR_DESC=		Konqueror webarchive format with Python
KONQUEROR_RUN_DEPENDS=	kwebkitpart:${PORTSDIR}/www/kwebkitpart
LATEX_RUN_DEPENDS=	detex:${PORTSDIR}/print/detex \
			dvips:${PORTSDIR}/print/tex-dvipsk
PDF_RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf
PS_RUN_DEPENDS=		pstotext:${PORTSDIR}/print/pstotext
PYTHON_USE=		python=yes
PYTHON_CONFIGURE_ENABLE=	python-module
QT4_USE=		qt4=moc_build,qmake_build,rcc_build,uic_build \
			qt4=iconengines_run,imageformats_run \
			qt4=corelib,gui,xml,webkit
QT4_CONFIGURE_ENABLE=	qtgui
SOUND_RUN_DEPENDS=	mutagen-pony:${PORTSDIR}/audio/py-mutagen \
			pykaraoke:${PORTSDIR}/audio/py-karaoke
X11MON_DESC=		X11 session monitoring support
X11MON_USES=		fam
X11MON_USE=		xorg=ice,sm,x11
X11MON_CONFIGURE_ENABLE=	x11mon
X11MON_CONFIGURE_WITH=	fam

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
PYDISTUTILS_PKGNAME=	Recoll
PYDISTUTILS_PKGVERSION=	1.0
PLIST_SUB+=	PYDISTUTILS_EGGINFO="${PYDISTUTILS_EGGINFO}"
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}"
INSTALLS_ICONS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|= -g -O2|=|' \
		${WRKSRC}/mk/localdefs.in
	@${REINPLACE_CMD} -e \
		's|@NOCMDLINE@||g ; \
	 	 s|@prefix@|${PREFIX}| ; \
		 s|REALPREFIX=$$PREFIX|REALPREFIX=$$DESTDIR$$PREFIX| ; \
		 s|python setup.py|${PYTHON_CMD} setup.py| ; \
		 s|$${ROOTFORPYTHON}||' \
		${WRKSRC}/recollinstall.in
	@${REINPLACE_CMD} -e \
		's|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/python/recoll/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/recoll/librecoll.so.[0-9].*
.if ${PORT_OPTIONS:MPYTHON}
.for l in recoll rclextract
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/recoll/${l}.so
.endfor
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
.endif

.include <bsd.port.mk>
