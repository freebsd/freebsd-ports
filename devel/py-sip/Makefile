# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.3
PORTREVISION=	
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sip-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python to C and C++ bindings generator

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_PYTHON=	yes

OPTIONS=	DEBUG "Build with debugging symbols" off \
		DOCS "Install documentation" on \
		QT "Enable Qt support" on

DATADIR=	${PREFIX}/share/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

SPEC=		${LOCALBASE}/share/qt/mkspecs/freebsd-g++
ARGS=		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-e ${PYTHON_INCLUDEDIR} -v ${DATADIR}

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif
.if defined(WITH_DEBUG)
ARGS+=		-u
.endif
.if defined(WITHOUT_QT)
ARGS+=		-x
.else
BUILD_DEPENDS+=	moc:${PORTSDIR}/x11-toolkits/qt33
RUN_DEPENDS+=	moc:${PORTSDIR}/x11-toolkits/qt33
.endif

do-configure:
	( cd ${WRKSRC} && ${SETENV} QTDIR=${X11BASE} QMAKESPEC=${SPEC} \
		${PYTHON_CMD} configure.py ${ARGS} )

post-install:
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( ${MKDIR} -m 0755 ${DOCSDIR} && cd ${WRKSRC} && ${INSTALL_DATA} \
		doc/default.css doc/sipref.txt NEWS LICENSE ${DOCSDIR} )
.endif
	( ${MKDIR} -m 0755 ${DATADIR} && \
		${PYTHON_CMD} -c "import sipconfig" && \
		${PYTHON_CMD} -O -c "import sipconfig" )

.include <bsd.port.post.mk>
