# New ports collection makefile for:	py-qt4
# Date created:				2009-06-30
# Whom:					Dima Panov <Fluffy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	qt4
PORTVERSION=	${PYQT4_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMEPREFIX2=	${PYTHON_PKGNAMEPREFIX}${PORTNAME}-

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	The "meta-port" for PyQt4

USE_PYTHON=	yes

NO_BUILD=	yes
.include "../../devel/py-sip/files/bsd.pyqt.mk"

RUN_DEPENDS+=	${PKGNAMEPREFIX2}core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PKGNAMEPREFIX2}gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PKGNAMEPREFIX2}network>=${PYQT4_VERSION}:${PORTSDIR}/net/py-qt4-network \
		${PKGNAMEPREFIX2}xml>=${PYQT4_VERSION}:${PORTSDIR}/textproc/py-qt4-xml \
		${PKGNAMEPREFIX2}assistant>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-assistant \
		${PKGNAMEPREFIX2}opengl>=${PYQT4_VERSION}:${PORTSDIR}/x11/py-qt4-opengl \
		${PKGNAMEPREFIX2}script>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-script \
		${PKGNAMEPREFIX2}scripttools>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-scripttools \
		${PKGNAMEPREFIX2}sql>=${PYQT4_VERSION}:${PORTSDIR}/databases/py-qt4-sql \
		${PKGNAMEPREFIX2}svg>=${PYQT4_VERSION}:${PORTSDIR}/graphics/py-qt4-svg \
		${PKGNAMEPREFIX2}test>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-test \
		${PKGNAMEPREFIX2}designer>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-designer \
		${PKGNAMEPREFIX2}designerplugin>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-designerplugin \
		${PKGNAMEPREFIX2}dbus>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-dbus \
		${PKGNAMEPREFIX2}xmlpatterns>=${PYQT4_VERSION}:${PORTSDIR}/textproc/py-qt4-xmlpatterns \
		${PKGNAMEPREFIX2}help>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-help \
		${PKGNAMEPREFIX2}webkit>=${PYQT4_VERSION}:${PORTSDIR}/www/py-qt4-webkit \
		${PKGNAMEPREFIX2}multimedia>=${PYQT4_VERSION}:${PORTSDIR}/multimedia/py-qt4-multimedia \
		${PKGNAMEPREFIX2}phonon>=${PYQT4_VERSION}:${PORTSDIR}/multimedia/py-qt4-phonon \
		${PKGNAMEPREFIX2}qscintilla2>=${QSCI2_VERSION}:${PORTSDIR}/devel/py-qt4-qscintilla2

.if !defined(NOPORTEXAMPLES)
RUN_DEPENDS+=	${PKGNAMEPREFIX2}demo>=${PYQT4_VERSION}:${PORTSDIR}/misc/py-qt4-demo
.endif

.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	${PKGNAMEPREFIX2}doc>=${PYQT4_VERSION}:${PORTSDIR}/misc/py-qt4-doc
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
