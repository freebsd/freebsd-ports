# New ports collection makefile for:	tuxcards
# Date created:				08 Jan 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tuxcards
PORTVERSION=	1.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.tifskom.de/tux/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for managing notes within a hierarchical tree

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

.include <bsd.port.pre.mk>

# Add this condititonal while people might still have old versions
# of qmake, living in X11BASE, installed. This should go away eventually.

.if exists(${X11BASE}/share/qt/mkspecs/freebsd-g++)
QMAKESPEC=	${X11BASE}/share/qt/mkspecs/freebsd-g++
.else
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${QMAKESPEC} tuxcards.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/en/*.* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
