# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	qmake
PORTVERSION=	3.3.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	QT/archive/qt/${PORTVERSION:R:R}
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The build utility of the Qt 3 project

REINPLACE_ARGS=	-i ""
WRKSRC=		${WRKDIR}/${DISTNAME}/qmake
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	FILESDIR="${FILESDIR}"

USES=		tar:bzip2 uidfix

EXTRACT_AFTER_ARGS= \
	'${DISTNAME}/mkspecs' \
	'${DISTNAME}/src/*/*.h' '${DISTNAME}/qmake' \
	'${DISTNAME}/src/tools'

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
EXTRACT_AFTER_ARGS+='${DISTNAME}/doc/html/qmake*'
DOCSDIR=	${PREFIX}/share/doc/qt
PLIST_SUB+=	DOCSDIR="${DOCSDIR}"
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -Rp ${WRKSRC:H}/doc/html ${STAGEDIR}${DOCSDIR}
.endif

post-patch:
	@${RM} -r ${WRKSRC}/examples ${WRKSRC}/tutorial
	@${REINPLACE_CMD} -e 's|-O2|${CXXFLAGS}|' \
		-e 's|gcc|${CC}|' \
		-e 's|g++|${CXX}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		-e 's|release|release thread|' \
		${WRKSRC}/../mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e 's|@QMAKE_QTOBJS@||g' ${WRKSRC}/Makefile.unix

do-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		< ${FILESDIR}/qconfig.cpp \
		> ${WRKSRC:H}/src/tools/qconfig.cpp
	${ECHO} '/* empty */' > ${WRKSRC}/qconfig.h
	${LN} ${WRKSRC}/qconfig.h ${WRKSRC}/qmodules.h
	${LN} -s . ${WRKDIR}/${DISTNAME}/src/tools/private

.include <bsd.port.mk>
