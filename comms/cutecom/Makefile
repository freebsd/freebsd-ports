# New ports collection makefile for:	cutecom
# Date created:			Thu Jul 15 02:07:06 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cutecom
PORTVERSION=	0.0.7
CATEGORIES=	comms
MASTER_SITES=	http://cutecom.sourceforge.net/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical serial terminal

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
MAKE_ENV+=	QTDIR="${X11BASE}"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ cutecom.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cutecom ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/applnk/Utilities
	${INSTALL_DATA} ${WRKSRC}/cutecom.desktop ${PREFIX}/share/applnk/Utilities

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${FILESDIR}/current-cutecommdlg.ui.patch
.else
EXTRA_PATCHES=	${FILESDIR}/stable-cutecommdlg.ui.patch
.endif

.include <bsd.port.post.mk>
