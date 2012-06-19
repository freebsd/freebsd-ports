# New ports collection makefile for:	devel/eric4
# Date created:				21 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	devel python
DISTNAME=	${PORTNAME}-${PORTVERSION}

LICENSE_FILE=	${WRKSRC}/LICENSE.GPL3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/Qsci.so:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtWebKit.so:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_SITELIBDIR}/PyQt4/QtHelp.so:${PORTSDIR}/devel/py-qt4-help \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_GNOME=	desktopfileutils
INSTALL_CMD=	install.py -c -f eric4config.freebsd
PLIST_FILES=
SUB_FILES=	eric4.desktop

do-configure:
	${SED}  -e 's,PYTHON_SITELIBDIR,${PYTHON_SITELIBDIR},' \
		-e 's,PREFIX,${PREFIX},' \
		-e 's,LOCALBASE,${LOCALBASE},' \
		-e 's,DOCSDIR,${DOCSDIR},' \
		-e 's,EXAMPLESDIR,${EXAMPLESDIR},' \
		< ${FILESDIR}/config > ${WRKSRC}/eric4config.freebsd

post-install:
	${INSTALL} -d ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/eric4.desktop ${PREFIX}/share/applications/
	${LN} ${PYTHON_SITELIBDIR}/eric4/icons/default/eric.png ${PREFIX}/share/pixmaps/
	-update-desktop-database
	-update-mime-database ${PREFIX}/share/mime

.include "${.CURDIR}/../../devel/eric4/Makefile.inc"
