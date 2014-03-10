# Created by: J.F. Dockes <jean-francois.dockes@wanadoo.fr>
# $FreeBSD$

PORTNAME=	recoll
PORTVERSION=	1.19.10
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Personal full text search package, based on Xapian

LICENSE=	GPLv2

BUILD_DEPENDS=	xapian-core>=0:${PORTSDIR}/databases/xapian-core
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		antiword:${PORTSDIR}/textproc/antiword \
		catdoc:${PORTSDIR}/textproc/catdoc \
		wpd2html:${PORTSDIR}/textproc/libwpd \
		unrtf:${PORTSDIR}/textproc/unrtf \
		unrar:${PORTSDIR}/archivers/unrar

USES=		gmake iconv shebangfix
SHEBANG_FILES=	filters/rclimg desktop/hotrecoll.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pic

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ASPELL CHM DJVU KONQUEROR LATEX IMAGE PDF PS PYTHON SOUND QT4 X11MON
CHM_DESC=	CHM via CHMLIB
IMAGE_DESC=	Store personal tags or textual descriptions in images
X11MON_DESC=	X11 session monitoring support
KONQUEROR_DESC=	Konqueror webarchive format with Python
OPTIONS_DEFAULT=ASPELL IMAGE PDF PS PYTHON SOUND QT4 X11MON

OPTIONS_SUB=	yes

ASPELL_LIB_DEPENDS=		libaspell.so:${PORTSDIR}/textproc/aspell
ASPELL_CONFIGURE_WITH=		aspell

CHM_RUN_DEPENDS=		pychm:${PORTSDIR}/textproc/pychm

DJVU_RUN_DEPENDS=		djvutxt:${PORTSDIR}/graphics/djvulibre

KONQUEROR_RUN_DEPENDS=		kwebkitpart:${PORTSDIR}/www/kwebkitpart

LATEX_RUN_DEPENDS=		detex:${PORTSDIR}/print/detex \
				dvips:${PORTSDIR}/print/dvips

IMAGE_RUN_DEPENDS=		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool-devel

PDF_RUN_DEPENDS=		xpdf:${PORTSDIR}/graphics/xpdf

PS_RUN_DEPENDS=			pstotext:${PORTSDIR}/print/pstotext

PYTHON_CONFIGURE_ENABLE=	python-module

SOUND_RUN_DEPENDS=		mutagen-pony:${PORTSDIR}/audio/py-mutagen \
				pykaraoke:${PORTSDIR}/audio/py-karaoke

QT4_CONFIGURE_ENABLE=		qtgui

X11MON_CONFIGURE_ENABLE=	x11mon

.include <bsd.port.options.mk>

VERSION=	${PORTVERSION}
PLIST_SUB+=	VERSION=${VERSION}

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	Recoll-1.0-py${PYTHON_VER}.egg-info
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines_run \
		imageformats_run corelib gui xml webkit
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}"
INSTALLS_ICONS=	yes
.endif

.if ${PORT_OPTIONS:MX11MON}
USE_XORG+=	ice sm x11
USES+=		fam
CONFIGURE_ARGS+=--with-fam
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/local/lib|${LOCALBASE}/lib|' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|= -g -O2|=|' ${WRKSRC}/mk/localdefs.in
	@${REINPLACE_CMD} \
		-e 's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/mk/${OPSYS}
	@${REINPLACE_CMD} -e 's|@NOCMDLINE@||g ; \
		s|@prefix@|${PREFIX}| ; \
		s|REALPREFIX=$$PREFIX|REALPREFIX=${STAGEDIR}$$PREFIX| ; \
		s|$${ROOTFORPYTHON}||' \
		${WRKSRC}/recollinstall.in
	@${REINPLACE_CMD} -e 's|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/python/recoll/Makefile \
		${WRKSRC}/recollinstall.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/recoll/librecoll.so.${VERSION}
.for l in recoll rclextract
	${STRIP_CMD} ${STAGEDIR}${PYTHON}${PYTHON_SITELIBDIR}/recoll/${l}.so
.endfor

.include <bsd.port.mk>
