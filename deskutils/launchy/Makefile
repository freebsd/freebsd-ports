# New ports collection makefile for:	Launchy
# Date created:				28 Jul 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	launchy
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Access applications, files, and bookmarks with just a few keystrokes

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/core.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils

USE_DOS2UNIX=	readme.lyx readme.txt
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build gui network
MAKEFILE=	makefile
ALL_TARGET=	release
MAKE_ARGS=	PREFIX="${PREFIX}"

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} 's,make ,g&,' ${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/?eadme.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
