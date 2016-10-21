# Created by: lofi@FreeBSD.org, mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	qmake
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Makefile generator

USE_QT4=	# empty
QT_DIST=	yes
REINPLACE_ARGS=	-i ""
WRKSRC_SUBDIR=	${PORTNAME}
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	FILESDIR="${FILESDIR}" \
		QMAKE_COMPILER="${QMAKE_COMPILER}" \
		QMAKE="${QMAKE}" \
		QT_BINDIR_REL="${QT_BINDIR_REL}" \
		QT_MKSPECDIR_REL="${QT_MKSPECDIR_REL}"
TODAY_CMD=	/bin/date +%Y-%m-%d

SUB_FILES=	qconfig.cpp
SUB_LIST=	TODAY="$$(${TODAY_CMD})" \
		${PLIST_SUB:NPREFIX=*}

EXTRACT_AFTER_ARGS= \
	'${DISTNAME}/mkspecs' \
	'${DISTNAME}/include/*/*' \
	'${DISTNAME}/src/*/*.h' \
	'${DISTNAME}/qmake' \
	'${DISTNAME}/src/corelib/tools' \
	'${DISTNAME}/src/corelib/io' \
	'${DISTNAME}/src/corelib/global' \
	'${DISTNAME}/src/corelib/plugin' \
	'${DISTNAME}/src/corelib/kernel' \
	'${DISTNAME}/src/corelib/codecs' \
	'${DISTNAME}/src/corelib/xml' \
	'${DISTNAME}/src/3rdparty/md4' \
	'${DISTNAME}/src/3rdparty/md5' \
	'${DISTNAME}/src/3rdparty/sha1' \
	'${DISTNAME}/tools/shared/symbian' \
	'${DISTNAME}/tools/shared/windows'

EXTRA_PATCHES=	# empty

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|release|release thread|' \
		-e 's|uic|${UIC:T}|' \
		-e 's|moc|${MOC:T}|' \
		${WRKSRC:H}/mkspecs/common/freebsd.conf
	@${REINPLACE_CMD} -e 's|@QMAKE_QTOBJS@||g' ${WRKSRC}/Makefile.unix
	@${REINPLACE_CMD} -e 's|unix.conf|freebsd.conf|' \
		${WRKSRC:H}/mkspecs/freebsd-icc/qmake.conf
	@${RM} -R ${WRKSRC:H}/mkspecs/freebsd-g++46

# Add mkspec for clang
	@${CP} -a ${WRKSRC:H}/mkspecs/freebsd-g++ \
		${WRKSRC:H}/mkspecs/freebsd-clang
	@${REINPLACE_CMD} -e 's|g++|clang|g' \
		-e '/gcc-base-unix.conf/d' \
		${WRKSRC:H}/mkspecs/freebsd-clang/qmake.conf

	@${RM} ${WRKSRC:H}/mkspecs/*/*.orig

do-configure: apply-slist
	${MV} ${WRKDIR}/qconfig.cpp \
		${WRKSRC:H}/src/corelib/global/qconfig.cpp
	${ECHO} '/* empty */' > ${WRKSRC}/qconfig.h
	${LN} ${WRKSRC}/qconfig.h ${WRKSRC:H}/src/corelib/global/qconfig.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${QMAKE:T} ${STAGEDIR}${PREFIX}/${QT_BINDIR_REL}
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_MKSPECDIR_REL:H} && \
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} mkspecs ${STAGEDIR}${PREFIX}/${QT_MKSPECDIR_REL:H}
	${LN} -sf freebsd-${QMAKE_COMPILER} ${STAGEDIR}${PREFIX}/share/qt4/mkspecs/default

.include <bsd.port.mk>
