# New ports collection makefile for:	tiled
# Date created:		03 May 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tiled
PORTVERSION=	0.8.1
CATEGORIES=	graphics editors games
MASTER_SITES=	SF/tiled/tiled-qt/${PORTVERSION}
DISTNAME=	tiled-qt-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose tile map editor

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl \
		linguist_build qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|lrelease|&-qt4|' \
		${WRKSRC}/translations/translations.pro
	@${REINPLACE_CMD} -e 's|.*\(QT += opengl\)|\1|' \
		${WRKSRC}/src/tiled/tiled.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX="${PREFIX}" tiled.pro

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}/
.endif

.include <bsd.port.mk>
