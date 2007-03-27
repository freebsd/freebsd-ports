# New ports collection makefile for:	py-qt4-qscintilla2
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	qscintilla2
PORTVERSION=	20070318
CATEGORIES=	devel
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/Snapshots/QScintilla2/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	QScintilla-1.72-gpl-2-snapshot-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for QScintilla2 (PyQt4), QSci module

LIB_DEPENDS=	qscintilla2.1:${PORTSDIR}/devel/qscintilla2
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_PYTHON=	2.3+

OPTIONS=	DEBUG		"Enable debugging in generated code" off \
		SIPFILES	"Install the Qscintilla SIP files" on \
		TRACING		"Enable tracing in generated code" off

OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
ARGS=		-c -j 2 -p 4 -d ${PYTHONPREFIX_SITELIBDIR}/PyQt4
WRKSRC=		${WRKDIR}/${DISTNAME}/Python

.include <bsd.port.pre.mk>

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
	( cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS} )

do-build:
	( cd ${WRKSRC} && ${MAKE} )

.include <bsd.port.post.mk>
