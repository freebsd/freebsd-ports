# $FreeBSD$

PORTNAME=	declarative
PORTREVISION=	2
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDeclarative module

CONFIGURE_ARGS=	--enable QtDeclarative
PYQT_DIST=	yes

USES=		python pyqt:4
USE_PYQT=	sip_build core_run gui_run network_run
USE_PYTHON=	flavors
USE_QT4=	corelib declarative gui network script sql svg xmlpatterns \
		qmake_build moc_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtDeclarative API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
