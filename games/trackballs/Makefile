# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trackballs
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile-2.0.so:lang/guile2 \
		libgc.so:devel/boehm-gc

USES=		cmake desktop-file-utils gettext-runtime gl gnome pkgconfig

USE_GITHUB=	yes

USE_GL=		gl
USE_SDL=	image2 mixer2 sdl2 ttf2

INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DTRACKBALLS_DOC_DIR=${DOCSDIR} \
		-DTRACKBALLS_MAN_DIR=${PREFIX}/man

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools
NLS_CMAKE_ON=	-DDISABLE_NLS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS:BOOL=ON

.include <bsd.port.mk>
