# New ports collection makefile for:	qtstalker
# Date created:		Thu Jan 19 03:18:59 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qtstalker
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	finance kde
MASTER_SITES=	SF

MAINTAINER=	corky1951@comcast.net
COMMENT=	Commodity and stock market charting and technical analysis

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	db2:${PORTSDIR}/databases/db2

USE_QT_VER=3
USE_LDCONFIG=	yes

MAKE_ENV=	QTDIR="${QT_PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}

QMAKE?=		${LOCALBASE}/bin/qmake
# XXX - this test is too simple but it is a good start
.if defined(CXX) && ${CXX:M*icc}
QMAKESPEC?=	freebsd-icc
.else
QMAKESPEC?=	freebsd-g++
.endif

VERSION_PLUGIN=	0.27

# docs
DOC_FILES=	\
		BUGS \
		CHANGELOG \
		TODO

.ifndef(NOPORTDOCS)
PORTDOCS+=	\
		*
.endif

PLIST_SUB+=	\
		VERSION_PLUGIN="${VERSION_PLUGIN}"

post-patch:
# tell qtstalker where to install plugins
	@${FIND} ${WRKSRC} -type f -name "*pro" | \
		${XARGS} -x -n 5 \
		${REINPLACE_CMD} -E \
		-e 's|/usr/lib/qtstalker/|${PREFIX}/lib/${PORTNAME}/|'
# where to find plugins
	@${REINPLACE_CMD} -E \
		-e 's|/usr/lib/qtstalker/|${PREFIX}/lib/${PORTNAME}/|' \
		${WRKSRC}/lib/Config.cpp \
# where to both find and install docs
	@${REINPLACE_CMD} -E \
		-e 's|/usr/share/doc/qtstalker/html|${DOCSDIR}|' \
		${WRKSRC}/lib/Config.cpp \
		${WRKSRC}/docs/docs.pro
# where to install program
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/src.pro
# where to install libs
	@${REINPLACE_CMD} -E \
		-e 's|/usr/lib|${PREFIX}/lib|' \
		${WRKSRC}/lib/lib.pro
# correctly use database/db2
	@${REINPLACE_CMD} -E \
		-e 's|<db.h>|<db2/db.h>|' \
		${WRKSRC}/lib/DbPlugin.h
	@${REINPLACE_CMD} -E \
		-e 's|-ldb$$|-ldb2|' \
		${WRKSRC}/lib/lib.pro

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
.ifdef(NOPORTDOCS)
# disable docs installation
	@${REINPLACE_CMD} -E \
		-e 's|^.+cd[[:space:]]+docs[[:space:]]+.+$$|#|' \
		${WRKSRC}/${MAKEFILE}
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
# additional docs
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
