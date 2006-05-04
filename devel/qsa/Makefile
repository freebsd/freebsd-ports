# New ports collection makefile for:	qsa
# Date created:				Thu 02 Sep 2004 18:00:00 CEST
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	qsa
PORTVERSION=	1.1.3
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_QT}
MASTER_SITE_SUBDIR=../../qsa/source
DISTNAME=	${PORTNAME}-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	Cross-platform scripting toolkit for Qt applications

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes

CONFIGURE_ARGS=-prefix ${PREFIX}
CONFIGURE_ENV?=	QTDIR=${X11BASE} QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		LD_LIBRARY_PATH=${WRKSRC}/qsa \
		PATH=${WRKSRC}/bin:$$PATH
ALL_TARGET=	sub-src

PKGMESSAGE=	${WRKDIR}/message

OPTIONS=	IDE "Enable the QSA Workbench (embedded scripting IDE)" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IDE)
CONFIGURE_ARGS+=-no-ide
.endif

.if ${OSVERSION} < 502124
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-src_engine_qsoperations.cpp
.endif

pre-configure:
# Adjust installation directories for the documentation and the qmake feature extension
	@${REINPLACE_CMD} -e 's|$$$$QSA_INSTALL_PREFIX/doc/html|$$$$QSA_INSTALL_PREFIX/share/doc/qsa/html|g' \
			  -e 's|$$$$QSA_INSTALL_PREFIX/mkspec/features|$$$$QSA_INSTALL_PREFIX/share/qt/mkspecs/features|g' \
		${WRKSRC}/src/qsa/qsa.pro
# Yank the docs-installation from the configure script, qt does not handle
# global removal of docs from assistant.
	@${REINPLACE_CMD} -e 's|installDocs();||g' ${WRKSRC}/configure2/main.cpp

# Disconnect a broken example from the build
	@${REINPLACE_CMD} -e 's|enums||g' ${WRKSRC}/examples/examples.pro

post-build:
	@${CAT} ${PKGDIR}/pkg-message \
		| ${SED} -e 's,%%PREFIX%%,${PREFIX},g' > ${PKGMESSAGE}

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	Makefile.qsa ${INSTALL_TARGET})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
