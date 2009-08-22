# New ports collection makefile for: ftgl
# Date created:		16 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ftgl
DISTVERSION=	2.1.3-rc5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/FTGL%20Source/2.1.3%7Erc5

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An OpenGL FreeType fonts rendering library

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_GL=		gl glu
USE_XORG=	x11 xext xmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gl-inc="${LOCALBASE}/include" \
		--without-glut-inc
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-/~/}

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS/ s|docs||; /SUBDIRS/ s|demo||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
