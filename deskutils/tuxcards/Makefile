# New ports collection makefile for:	tuxcards
# Date created:				08 Jan 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tuxcards
PORTVERSION=	1.1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.tifskom.de/tux/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for managing notes within a hierarchical tree

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_REINPLACE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"

post-patch:
	@${REINPLACE_CMD} -e 's|warn_on|warn_on thread|g' ${WRKSRC}/tuxcards.pro

.include <bsd.port.pre.mk>

# Add this condititonal while people might still have old versions
# of qmake, living in X11BASE, installed. This should go away eventually.

.if exists(${X11BASE}/share/qt/mkspecs/freebsd-g++)
do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${X11BASE}/share/qt/mkspecs/freebsd-g++ tuxcards.pro
.else
do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ tuxcards.pro
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/en/*.* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
