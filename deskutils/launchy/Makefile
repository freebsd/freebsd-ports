# New ports collection makefile for:	Launchy
# Date created:				28 Jul 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	launchy
PORTVERSION=	2.1.1
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Access applications, files, and bookmarks with just a few keystrokes

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/core.hpp:${PORTSDIR}/devel/boost

BROKEN=		does not build

USE_DOS2UNIX=	readme.lyx readme.txt
USE_QT_VER=	4
QT_COMPONENTS=	qmake gui network
MAKEFILE=	makefile
ALL_TARGET=	release

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/?eadme.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
