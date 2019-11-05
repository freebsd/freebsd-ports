# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	ftgl
DISTVERSION=	2.1.3-rc5
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/FTGL%20Source/2.1.3%7Erc5

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenGL FreeType fonts rendering library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gl-inc="${LOCALBASE}/include" \
		--without-glut-inc
USES=		gl pathfix gmake libtool xorg
USE_GL=		gl glu
USE_XORG=	x11 xext xmu
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-/~/}

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS/ s|docs||; /SUBDIRS/ s|demo||' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libftgl.so

.include <bsd.port.mk>
