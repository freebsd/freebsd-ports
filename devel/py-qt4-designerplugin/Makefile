# New ports collection makefile for:	py-qt4-designerplugin
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	designerplugin
PORTVERSION=	${PYQT4_VERSION}
PORTREVISION=	2
PORTEPOCH=	1

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	${PYQT_MAINTAINER}
COMMENT=	Python bindings for the Qt4 toolkit, QtDesigner plugin

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}designer>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-designer

HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	designer moc gui xml qmake

OPTIONS=	DEBUG		"Enable debugging in generated code" off \
		TRACING		"Enable tracing in generated code" off

PATCHDIR=	${PORTSDIR}/devel/py-qt4-core/files
OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
CONFIGURE_ENV+=	PYQT4_COMPONENT="${PORTNAME}"
ARGS=		-b ${PREFIX}/bin\
		-d ${PYTHON_SITELIBDIR}\
		-q ${QT_PREFIX}/bin/qmake-qt4\
		--confirm-license

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		--debug
.endif
.if defined(WITH_TRACING)
ARGS+=		--trace
.endif
ARGS+=		--enable QtDesigner

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|CC = cc|CC = ${CC}|'\
		-e 's|CXX = c++|CXX = ${CXX}|'\
		-e 's|LINK = c++|LINK = ${CXX}|'\
		${WRKSRC}/designer/Makefile

.include <bsd.port.post.mk>
