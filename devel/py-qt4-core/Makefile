# New ports collection makefile for:	py-qt4-core
# Date created:				2007-02-19
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	core
PORTVERSION=	20070318
CATEGORIES=	devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/PyQt4/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-4-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, QtCore module

BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_PYTHON=	2.3+
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake

OPTIONS=	API		"Install QtCore API for QScintilla2" on \
		DEBUG		"Enable debugging in generated code" off \
		SIPFILES	"Install the QtCore SIP files" on \
		TRACING		"Enable tracing in generated code" off

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
APIFILE=	${QT_PREFIX}/share/qt4/qsci/api/python/QtCore.api
SIPDIR=		${PREFIX}/share/py-sip
ARGS=		-b ${PREFIX}/bin -c -j 2 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4 \
		-q ${QT_PREFIX}/bin/qmake-qt4 -a

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITHOUT_API)
PLIST_SUB+=	API="@comment "
PLIST_SUB+=	APIFILE="@comment "
.else
LIB_DEPENDS+=	qscintilla2.1:${PORTSDIR}/devel/qscintilla2
PLIST_SUB+=	API=""
PLIST_SUB+=	APIFILE="share/qt4/qsci/api/python/QtCore.api"
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
.if ${PYTHON_VER} >= 2.5
PLIST_SUB+=	ELTREE="@comment "
.else
PLIST_SUB+=	ELTREE=""
.endif

do-configure:
	( cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${ARGS} )

post-install:
	( cd ${PYTHONPREFIX_SITELIBDIR}/PyQt4 && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py \
		`ls *.py */*.py */*/*.py` && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/py_compile.py \
		`ls *.py */*.py */*/*.py`)
.if defined(WITHOUT_API)
	( ${RM} ${APIFILE} )
.endif

.include <bsd.port.post.mk>
