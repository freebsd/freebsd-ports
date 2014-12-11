# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	blockout
PORTVERSION=	2.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/BlockOut%20${PORTVERSION}/ \
		http://www.stasyan.com/devel/distfiles/
DISTNAME=	bl24-src-linux-i586

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BlockOut II is an adaptation of the original Blockout DOS game

LICENSE=	GPLv2 # or later

ONLY_FOR_ARCHS=	i386

USE_SDL=	mixer sdl
USES=		gmake dos2unix
DOS2UNIX_FILES=	${WRKSRC}/ImageLib/src/gif/gif.c
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/bl24_lin_src
BUILD_WRKSRC=	${WRKSRC}/BlockOut

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/BlockOut/Utils.cpp

pre-build:
	cd ${WRKSRC}/ImageLib/src && ${DO_MAKE_BUILD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BlockOut/blockout ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/BlockOut && ${COPYTREE_SHARE} "images sounds" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
