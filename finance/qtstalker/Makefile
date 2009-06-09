# New ports collection makefile for:	qtstalker
# Date created:		Thu Jan 19 03:18:59 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qtstalker
PORTVERSION=	0.36
CATEGORIES=	finance kde
MASTER_SITES=	SF

MAINTAINER=	corky1951@comcast.net
COMMENT=	Commodity and stock market charting and technical analysis

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	db-4.3:${PORTSDIR}/databases/db43 \
		ta_lib:${PORTSDIR}/devel/ta-lib

MAKE_JOBS_UNSAFE=yes

USE_QT_VER=3
USE_LDCONFIG=	yes

MAKE_ENV=	QTDIR="${QT_PREFIX}"

#WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

QMAKE?=		${LOCALBASE}/bin/qmake
# XXX - this test is too simple but it is a good start
.if defined(CXX) && ${CXX:M*icc}
QMAKESPEC?=	freebsd-icc
.else
QMAKESPEC?=	freebsd-g++
.endif

VERSION_PLUGIN=	0.36

# docs
DOC_FILES=	\
		BUGS \
		CHANGELOG-${PORTVERSION} \
		TODO

.ifndef(NOPORTDOCS)
PORTDOCS+=	\
		*
.endif

.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES+=	\
		*
.endif

PORTDATA+=	\
		*

PLIST_SUB+=	\
		VERSION_PLUGIN="${VERSION_PLUGIN}"

post-patch:
# NB: LOCALBASE and PREFIX should NOT be used instead of "/usr/local" in the
# following post-patch substitutions since the point is to fix some hardcoded
# path info in the distfile content.
#
# where to find header files and libs
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/include|${LOCALBASE}/include|' \
		${WRKSRC}/src/src.pro \
		${WRKSRC}/lib/lib.pro \
		${WRKSRC}/plugin.config
	@${REINPLACE_CMD} -E \
		-e 's|/usr/X11R6/include|${LOCALBASE}/include|' \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/lib|${LOCALBASE}/lib|' \
		${WRKSRC}/src/src.pro \
		${WRKSRC}/lib/lib.pro \
		${WRKSRC}/plugin.config
# where to find data files (at run-time)
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/share/qtstalker|${DATADIR}|' \
		${WRKSRC}/src/Qtstalker.cpp \
		${WRKSRC}/lib/Config.cpp \
		${WRKSRC}/docs/docs.pro
# where to install plugins
	@${FIND} ${WRKSRC} -type f -name "*pro" | \
		${XARGS} -x -n 5 \
		${REINPLACE_CMD} -E \
		-e 's|/usr/local/lib/qtstalker/|${PREFIX}/lib/${PORTNAME}/|'
# where to find plugins (at run-time)
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/lib/qtstalker/|${PREFIX}/lib/${PORTNAME}/|' \
		${WRKSRC}/lib/Config.cpp \
		${WRKSRC}/lib/RcFile.cpp
# where to both find (at run-time) and install docs
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/share/doc/qtstalker/html|${DOCSDIR}/html|' \
		${WRKSRC}/lib/Config.cpp \
		${WRKSRC}/lib/RcFile.cpp \
		${WRKSRC}/docs/docs.pro
	@${SED} -E \
		-e 's|/usr/local/share/doc/qtstalker/html|${DOCSDIR}/html|' \
		${FILESDIR}/qtstalkerrc > ${WRKDIR}/qtstalkerrc
# where to install program
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/src.pro
# where to install libs
	@${REINPLACE_CMD} -E \
		-e 's|/usr/local/lib|${PREFIX}/lib|' \
		${WRKSRC}/lib/lib.pro
# correctly use database/db43
	@${REINPLACE_CMD} -E \
		-e 's|<db.h>|<db43/db.h>|' \
		${WRKSRC}/lib/DbPlugin.h
	@${REINPLACE_CMD} -E \
		-e 's|-ldb$$|-ldb-4.3|' \
		${WRKSRC}/lib/lib.pro

# Use of LOCALBASE is OK from this point on
do-configure:
	@cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} \
		"INCLUDEPATH += ${QT_PREFIX}/include ${LOCALBASE}/include" \
		"LIBS += -L${LOCALBASE}/lib " \
		"QMAKE_CFLAGS_SHLIB += -fPIC" \
		"QMAKE_CXXFLAGS_SHLIB += -fPIC" \
		"DEFINES += QT_NO_COMPAT PIC" -o ${MAKEFILE} qtstalker.pro

pre-install:
# install with proper permissions
	@${FIND} ${WRKSRC}/docs ${WRKSRC}/lib ${WRKSRC}/plugins -type f -name "${MAKEFILE}" | \
		${XARGS} -x -n 5 \
		${REINPLACE_CMD} -E \
		-e 's|\(INSTALL_FILE\)|(BSD_INSTALL_DATA)|'
	@${REINPLACE_CMD} -E \
		-e 's|\(INSTALL_FILE\)|(BSD_INSTALL_PROGRAM)|' \
		${WRKSRC}/src/${MAKEFILE}
.if defined(NOPORTDOCS)
# disable docs installation
	@${REINPLACE_CMD} -E \
		-e 's|^.+cd[[:space:]]+docs[[:space:]]+.+$$|#|' \
		${WRKSRC}/Makefile
.endif

post-install:
# install minimal rcfile with helpfiles path needed by help window
	@${MKDIR} ${PREFIX}/share/qt/etc
	@${INSTALL_DATA} ${WRKDIR}/qtstalkerrc ${PREFIX}/share/qt/etc
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
# additional docs
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${DOCSDIR}
.endfor
.endif
# examples
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/CUS_examples
	@(cd ${WRKSRC}/misc/CUS_examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/CUS_examples)
.endif

.include <bsd.port.mk>
