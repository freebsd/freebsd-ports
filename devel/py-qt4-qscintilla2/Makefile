# New ports collection makefile for:	py-qt4-qscintilla2
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for QScintilla2 (PyQt4), QSci module

LIB_DEPENDS=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS:=	${BUILD_DEPENDS}

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
QSCIDIR=	${PREFIX}/share/qt4/qsci
ARGS=		-p 4 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4
WRKSRC=		${WRKDIR}/${DISTNAME}/Python
ALL_TARGET=	#empty

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.options.mk>

PYVER=		${PYTHON_VER}

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITHOUT_API)
ARGS+=		-a /dev/null
PLIST_SUB+=	API="@comment "
.else
ARGS+=		-a ${QSCIDIR}
PLIST_SUB+=	API=""
.endif
.if defined(WITHOUT_SIPFILES)
ARGS+=		-v /dev/null
PLIST_SUB+=	SIP="@comment "
.else
ARGS+=		-v ${SIPDIR}
PLIST_SUB+=	SIP=""
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
		${REINPLACE_CMD} \
			-e 's|CC = cc|CC = ${CC}|'\
			-e 's|CXX = c++|CXX = ${CXX}|'\
			-e 's|LINK = c++|LINK = ${CXX}|'\
			${WRKSRC}/Makefile

.include <bsd.port.mk>
