# New ports collection makefile for:	qmake-4
# Date created:				Tue Jul 12 16:04:29 UTC 2005
# Whom:					lofi@freebsd.org,
#					mi@aldan.algebra.com
#
# $FreeBSD$

PORTNAME=	qmake
PORTVERSION=	4.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE
LATEST_LINK=	qmake4

MAINTAINER=	kde@freebsd.org
COMMENT=	The build utility of the Qt project

REINPLACE_ARGS=	-i ""
WRKSRC=		${WRKDIR}/${DISTNAME}/qmake
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	FILESDIR="${FILESDIR}"
#USE_BZIP2=	yes

EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	'${DISTNAME}/config.tests/unix/padstring' \
	'${DISTNAME}/mkspecs' \
	'${DISTNAME}/include/*/*' \
	'${DISTNAME}/src/*/*.h' '${DISTNAME}/qmake' \
	'${DISTNAME}/src/corelib/tools' \
	'${DISTNAME}/src/corelib/io' \
	'${DISTNAME}/src/corelib/global' \
	'${DISTNAME}/src/corelib/plugin' \
	'${DISTNAME}/src/corelib/kernel' \
	'${DISTNAME}/src/3rdparty/md5'

.if !defined(NOPORTDOCS)
EXTRACT_AFTER_ARGS+='${DISTNAME}/doc/html/qmake*'
DOCSDIR=${PREFIX}/share/doc/qt4
post-install:
	${MKDIR} '${DOCSDIR}'
	${CP} -Rp '${WRKSRC:H}/doc/html' '${DOCSDIR}'
.endif

post-patch:
	@${RM} -fr ${WRKSRC}/examples ${WRKSRC}/tutorial
	@${REINPLACE_CMD} -e 's|-O2|${CXXFLAGS}|' \
		-e 's|gcc.*|${CC}|' \
		-e 's|g++.*|${CXX}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${X11BASE}|' \
		-e 's|release|release thread|' \
		-e 's|-pthread -D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|uic|uic4|' \
		-e 's|moc|moc4|' \
		${WRKSRC}/../mkspecs/freebsd-g++/qmake.conf \
		${WRKSRC}/../mkspecs/freebsd-g++34/qmake.conf
	@${REINPLACE_CMD} -e 's|@QMAKE_QTOBJS@||g' ${WRKSRC}/Makefile.unix

do-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		< ${FILESDIR}/qconfig.cpp \
		> ${WRKSRC:H}/src/corelib/global/qconfig.cpp
	${ECHO} '/* empty */' > ${WRKSRC}/qconfig.h
	${LN} ${WRKSRC}/qconfig.h ${WRKSRC}/../include/QtCore/qconfig.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
USE_GCC=	3.4+
.endif

.if ${ARCH} == "alpha"
CXXFLAGS+=	-mieee
.endif

.include <bsd.port.post.mk>
