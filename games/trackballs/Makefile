# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	trackballs
PORTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
		libgc.so:devel/boehm-gc

USES=		cmake desktop-file-utils gettext-runtime gl gnome pkgconfig sdl
USE_GL=		gl
USE_SDL=	image2 mixer2 sdl2 ttf2

USE_GITHUB=	yes

INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DTRACKBALLS_DOC_DIR=${DOCSDIR} \
		-DTRACKBALLS_MAN_DIR=${PREFIX}/man

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext-tools
NLS_CMAKE_ON=	-DDISABLE_NLS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS:BOOL=ON

.include <bsd.port.mk>
