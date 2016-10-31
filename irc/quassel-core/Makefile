# $FreeBSD$

PKGNAMESUFFIX=	-core

COMMENT=	Qt 5 based distributed IRC client (core/server only)

LIB_DEPENDS=	libqca-qt5.so:devel/qca-qt5

MASTERDIR=	${.CURDIR}/../quassel

USE_QT5=	buildtools_build core network qmake_build script sql sql-sqlite3_run
CMAKE_ARGS+=	-DWITH_KDE=off \
		-DUSE_QT5=on \
		-DWANT_CORE=on \
		-DWANT_QTCLIENT=off \
		-DWANT_MONO=off

USE_RC_SUBR=	quasselcore
USERS=		quasselcore
GROUPS=		${USERS}
SUB_FILES=	pkg-message
PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	bin/quasselcore

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quasselcore

.include "${MASTERDIR}/Makefile"
