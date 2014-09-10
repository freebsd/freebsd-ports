# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	designer
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDesigner module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PKGNAMEPREFIX}xml>=${PYQT4_VERSION}:${PORTSDIR}/textproc/py-qt4-xml \
		${PKGNAMEPREFIX}script>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-script

CONFIGURE_ARGS=	--enable QtDesigner --no-designer-plugin
PYQT4_DIST=	yes
USE_QT4=	gui xml designer moc_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtDesigner API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"
.include <bsd.port.mk>
