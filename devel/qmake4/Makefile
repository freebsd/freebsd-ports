# New ports collection makefile for:	qmake-4
# Date created:				Tue Jul 12 16:04:29 UTC 2005
# Whom:					lofi@freebsd.org,
#					mi@aldan.algebra.com
#
# $FreeBSD$

PORTNAME=	qmake
PORTVERSION=	${QT4_VERSION}
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The build utility of the Qt project

QT_NONSTANDARD=	yes
REINPLACE_ARGS=	-i ""
WRKSRC=		${WRKDIR}/${DISTNAME}/qmake
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	FILESDIR="${FILESDIR}"
#USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	'${DISTNAME}/config.tests/unix/padstring' \
	'${DISTNAME}/mkspecs' \
	'${DISTNAME}/include/*/*' \
	'${DISTNAME}/src/*/*.h' \
	'${DISTNAME}/qmake' \
	'${DISTNAME}/src/corelib/tools' \
	'${DISTNAME}/src/corelib/io' \
	'${DISTNAME}/src/corelib/global' \
	'${DISTNAME}/src/corelib/plugin' \
	'${DISTNAME}/src/corelib/kernel' \
	'${DISTNAME}/src/script' \
	'${DISTNAME}/src/3rdparty/md4' \
	'${DISTNAME}/src/3rdparty/md5' \
	'${DISTNAME}/src/3rdparty/sha1'

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CXXFLAGS}|' \
		-e 's|gcc.*|${CC}|' \
		-e 's|g++.*|${CXX}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		-e 's|release|release thread|' \
		-e 's|-pthread -D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|uic|uic-qt4|' \
		-e 's|moc|moc-qt4|' \
		${WRKSRC}/../mkspecs/freebsd-g++/qmake.conf \
		${WRKSRC}/../mkspecs/freebsd-g++34/qmake.conf \
		${WRKSRC}/../mkspecs/freebsd-g++40/qmake.conf \
		${WRKSRC}/../mkspecs/freebsd-icc/qmake.conf
	@${REINPLACE_CMD} -e 's|include(../common/c++|include(../common/g++.conf)|' \
		${WRKSRC}/../mkspecs/freebsd-g++/qmake.conf 
	@${REINPLACE_CMD} -e 's|@QMAKE_QTOBJS@||g' ${WRKSRC}/Makefile.unix

do-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		< ${FILESDIR}/qconfig.cpp \
		> ${WRKSRC:H}/src/corelib/global/qconfig.cpp
	${ECHO} '/* empty */' > ${WRKSRC}/qconfig.h
	${LN} ${WRKSRC}/qconfig.h ${WRKSRC}/../include/QtCore/qconfig.h

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../Mk/bsd.qt.mk"

.if ${ARCH} == "alpha"
CXXFLAGS+=	-mieee
.endif

.if ${OSVERSION} < 700042 && ${ARCH} == "amd64"
CXXFLAGS+=	-fno-gcse
.endif

post-install:
	${LN} -sf ${PREFIX}/share/qt4/mkspecs/freebsd-g++ ${PREFIX}/share/qt4/mkspecs/default

.include <bsd.port.post.mk>
