# New ports collection makefile for:	py-qt4-designer
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	designer
PORTVERSION=	20070318
CATEGORIES=	devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/PyQt4/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-4-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, QtDesigner module

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_PYTHON=	2.3+
USE_QT_VER=	4
QT_COMPONENTS=	designer moc qmake

OPTIONS=	API		"Install QtDesigner API for QScintilla2" on \
		DEBUG		"Enable debugging in generated code" off \
		SIPFILES	"Install the QtDesigner SIP files" on \
		TRACING		"Enable tracing in generated code" off

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
APIFILE=	${QT_PREFIX}/share/qt4/qsci/api/python/QtDesigner.api
SIPDIR=		${PREFIX}/share/py-sip
ARGS=		-b ${PREFIX}/bin -c -j 2 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4 \
		-q ${QT_PREFIX}/bin/qmake-qt4 -a

.include <bsd.port.pre.mk>

.if defined(WITHOUT_API)
PLIST_SUB+=	API="@comment "
PLIST_SUB+=	APIFILE="@comment "
.else
LIB_DEPENDS+=	qscintilla2.1:${PORTSDIR}/devel/qscintilla2
PLIST_SUB+=	API=""
PLIST_SUB+=	APIFILE="share/qt4/qsci/api/python/QtDesigner.api"
.endif
.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITHOUT_SIPFILES)
ARGS+=		-v /dev/null
PLIST_SUB+=	SIPFILES="@comment "
PLIST_SUB+=	SIPDIR="@comment "
.else
ARGS+=		-v ${SIPDIR}
PLIST_SUB+=	SIPFILES=""
PLIST_SUB+=	SIPDIR="share/py-sip"
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

do-configure:
	( cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${ARGS} )

post-install:
.if defined(WITHOUT_API)
	( ${RM} ${APIFILE} )
.endif

.include <bsd.port.post.mk>
