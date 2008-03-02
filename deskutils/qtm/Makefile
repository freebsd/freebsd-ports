# New ports collection makefile for:	qtm
# Date created:		22 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtm
PORTVERSION=	0.5.5
CATEGORIES=	deskutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=catkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog management application based on Qt 4

USE_QT_VER=	4
QT_COMPONENTS=	gui network corelib xml qmake_build uic_build moc_build
PLIST_FILES=	bin/QTM

PORTDOCS=	COPYING Changelog INSTALL README

DESKTOP_ENTRIES=	"QTM" \
			"Weblog management application" \
			"" \
			"QTM" \
			"Application;Network;" \
			"false"

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix QTM.pro

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/QTM ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
