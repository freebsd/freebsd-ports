# New ports collection makefile for:	qtm
# Date created:		22 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtm
PORTVERSION=	0.6.0.1
CATEGORIES=	deskutils
MASTER_SITES=	SF/catkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog management application based on Qt 4

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui rcc network xml moc_build qmake_build uic_build
USE_CMAKE=	yes
CMAKE_USE_PTHREAD= yes
CMAKE_ARGS+=	-DMANPAGE_DIRECTORY="${MANPREFIX}/man/man1"

MANCOMPRESSED=	yes
MAN1=		qtm.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in Changelog INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
