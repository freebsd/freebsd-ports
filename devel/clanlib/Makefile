# New ports collection makefile for:	clanlib
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clanlib
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dark.x.dtu.dk/~mbn/clanlib/download/
DISTNAME=	ClanLib-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	Hermes.1:${PORTSDIR}/graphics/Hermes \
		png.5:${PORTSDIR}/graphics/png \
		vga.1:${PORTSDIR}/graphics/svgalib

.if defined(WITHOUT_GL)
CONFIGURE_ARGS+=	--disable-opengl
.else
USE_MESA=	yes
CONFIGURE_ARGS+=	--enable-opengl
PLIST=		${WRKDIR}/PLIST
.endif

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=	-fpermissive
ALL_TARGET+=	clanPNG clanGL

.if !defined(WITHOUT_GL)
pre-install:
	@cat ${PKGDIR}/pkg-plist.glx ${PKGDIR}/pkg-plist > ${PLIST}
.endif

.include <bsd.port.mk>
