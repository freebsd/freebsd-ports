# New ports collection makefile for:	py-qt4-dbus
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	20070318
CATEGORIES=	devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/PyQt4/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-4-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, D-BUS module

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtCore.so:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_PYTHON=	2.3+
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake moc

OPTIONS=	DEBUG	"Enable debugging in generated code" off \
		TRACING	"Enable tracing in generated code" off

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
ARGS=		-b ${PREFIX}/bin -c -j 2 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4 \
		-q ${QT_PREFIX}/bin/qmake-qt4 -s ${LOCALBASE}/include/dbus-1.0/dbus/

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITH_TRACING)
ARGS+=		-r
.endif

do-configure:
	( cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${ARGS} )

.include <bsd.port.post.mk>
