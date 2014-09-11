# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	secretmaryochronicles
PORTVERSION=	1.10.git20140514
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
# it could use github.com/Quintus/SMC, but it needs to be packaged
# by hand as it uses submodules
DISTNAME=	smc-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Secret Maryo Chronicles two-dimensional platform game

BROKEN=		does not run, cegui 0.8 support still in development

LICENSE=	GPLv3

LIB_DEPENDS=	libCEGUIBase-0.so:${PORTSDIR}/graphics/cegui \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libfreeimage.so:${PORTSDIR}/graphics/freeimage \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26
BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		bison:${PORTSDIR}/devel/bison

USES=		tar:bzip2 cmake:outsource gettext pkgconfig compiler:c++11-lib
USE_SDL=	sdl image mixer ttf
USE_GL=		gl

DATADIR=	${PREFIX}/share/smc

WRKSRC=		${WRKDIR}/SMC

CMAKE_SOURCE_PATH=${WRKSRC}/smc

PLIST_FILES=	bin/smc
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${WRKSRC}/smc/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
