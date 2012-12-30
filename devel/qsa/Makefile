# New ports collection makefile for:	qsa
# Date created:				Thu 02 Sep 2004 18:00:00 CEST
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	qsa
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_QT}
MASTER_SITE_SUBDIR=../../${PORTNAME}/source
DISTNAME=	${PORTNAME}-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform scripting toolkit for Qt applications

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_QT_VER=	3
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=-prefix ${PREFIX}
CONFIGURE_ENV?=	QTDIR=${QT_PREFIX} QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		LD_LIBRARY_PATH=${WRKSRC}/qsa:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH
ALL_TARGET=	sub-src

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	IDE
OPTIONS_DEFAULT=	IDE
IDE_DESC=	Enable the QSA Workbench (embedded scripting IDE)

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIDE)
CONFIGURE_ARGS+=-no-ide
.endif

pre-configure:
# Adjust installation directories for the documentation and the qmake feature extension
	@${REINPLACE_CMD} -e 's|$$$$QSA_INSTALL_PREFIX/doc/html|$$$$QSA_INSTALL_PREFIX/share/doc/qsa/html|g' \
			  -e 's|$$$$QSA_INSTALL_PREFIX/mkspecs/features|$$$$QSA_INSTALL_PREFIX/share/qt/mkspecs/features|g' \
		${WRKSRC}/src/qsa/qsa.pro
# Yank the docs-installation from the configure script, qt does not handle
# global removal of docs from assistant.
	@${REINPLACE_CMD} -e 's|installDocs();||g' ${WRKSRC}/configure2/main.cpp

# Disconnect a broken example from the build
	@${REINPLACE_CMD} -e 's|enums||g' ${WRKSRC}/examples/examples.pro

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	Makefile.qsa ${INSTALL_TARGET})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
