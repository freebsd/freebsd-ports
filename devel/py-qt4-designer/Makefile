# New ports collection makefile for:	py-qt4-designer
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	designer
PORTVERSION=	${PYQT4_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDesigner module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PKGNAMEPREFIX}xml>=${PYQT4_VERSION}:${PORTSDIR}/textproc/py-qt4-xml \
		${PKGNAMEPREFIX}script>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-script

HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	gui xml designer moc_build qmake_build

OPTIONS=	API		"Install QtDesigner API for QScintilla2" on \
		DEBUG		"Enable debugging in generated code" off \
		SIPFILES	"Install the QtDesigner SIP files" on \
		TRACING		"Enable tracing in generated code" off

PATCHDIR=	${PORTSDIR}/devel/py-qt4-core/files
OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt4/qsci
CONFIGURE_ENV+=	PYQT4_COMPONENT="${PORTNAME}"
ARGS=		-b ${PREFIX}/bin\
		-d ${PYTHONPREFIX_SITELIBDIR}\
		-p ${PREFIX}/${QT_PLUGINDIR_REL}\
		-q ${QMAKE}\
		--confirm-license\
		--enable QtDesigner

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build
.endif

.if defined(WITH_DEBUG)
ARGS+=		--debug
.endif
.if defined(WITHOUT_API)
ARGS+=		--no-qsci-api
PLIST_SUB+=	API="@comment "
.else
LIB_DEPENDS+=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2
ARGS+=		--qsci-api --qsci-api-destdir=${QSCIDIR}
PLIST_SUB+=	API=""
.endif
.if defined(WITHOUT_SIPFILES)
ARGS+=		--no-sip-files
PLIST_SUB+=	SIP="@comment "
.else
ARGS+=		--sipdir ${SIPDIR}
PLIST_SUB+=	SIP=""
.endif
.if defined(WITH_TRACING)
ARGS+=		--trace
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|mkspecs/freebsd-g++|share/qt4/mkspecs/freebsd-g++|'\
		-e 's|CC = cc|CC = ${CC}|'\
		-e 's|CXX = c++|CXX = ${CXX}|'\
		-e 's|LINK = c++|LINK = ${CXX}|'\
		${WRKSRC}/QtDesigner/Makefile

.include <bsd.port.post.mk>
