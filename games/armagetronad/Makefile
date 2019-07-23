# $FreeBSD$

PORTNAME=	armagetronad
DISTVERSION=	0.2.8.3.4
DISTVERSIONSUFFIX=	.src
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/stable/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tron clone in 3D

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpng16.so:graphics/png

USES=		autoreconf gl gmake gnome jpeg sdl
GNU_CONFIGURE=	yes
USE_SDL=	image mixer sdl
USE_GL=		gl glu
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CONFIGURE_ARGS=	--disable-etc --disable-games --enable-music

BINARY_ALIAS=	sdl11-config=sdl-config

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
