# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goom
PORTVERSION=	2k4.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2k4/0
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual effects library

LICENSE=	LGPL20

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S|.|-|}
USES=		pathfix libtool localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-sdltest --enable-static
CONFIGURE_ENV=	ac_cv_path_SDL_CONFIG="no"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

BROKEN_powerpc=	Does not build

.include <bsd.port.mk>
