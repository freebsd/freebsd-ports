# New ports collection makefile for:	py-qt4-qscintilla2
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTREVISION=	2
PORTEPOCH=	1

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	${PYQT_MAINTAINER}
COMMENT=	Python bindings for QScintilla2 (PyQt4), QSci module

LIB_DEPENDS=	qscintilla2.3:${PORTSDIR}/devel/qscintilla2
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	gui

OPTIONS=	API		"Install binding API for QScintilla2" on \
		DEBUG		"Enable debugging in generated code" off \
		SIPFILES	"Install the Qscintilla SIP files" on \
		TRACING		"Enable tracing in generated code" off

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
ARGS=		-p 4 -d ${PYTHON_SITELIBDIR}/PyQt4
WRKSRC=		${WRKDIR}/${DISTNAME}/Python

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

PYVER=		${PYTHON_VER}

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITHOUT_API)
ARGS+=		-a /dev/null
PLIST_SUB+=	API="@comment "
PLIST_SUB+=	APIFILE="@comment "
.else
PLIST_SUB+=	API=""
PLIST_SUB+=	APIFILE="share/qt4/qsci/api/python/QScintilla2.api"
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
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile &&\
		${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g'\
			-e 's|%%QT_INCDIR%%|${QT_INCDIR}|g'\
			-e 's|%%QT_LIBDIR%%|${QT_LIBDIR}|g'\
			-e 's|%%PYVER%%|${PYVER}|g'\
			-e 's|CC = cc|CC = ${CC}|'\
			-e 's|CXX = c++|CXX = ${CXX}|'\
			-e 's|LINK = c++|LINK = ${CXX}|'\
			${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${MAKE}

.include <bsd.port.post.mk>
