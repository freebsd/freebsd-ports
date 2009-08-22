# New ports collection makefile for:    openalchemist
# Date created:     Sat Oct 01 09:30:00 UTC 2003
# Whom:         Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	openalchemist
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Tetris-like game

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib \
	jpeg.10:${PORTSDIR}/graphics/jpeg \
	png.5:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262
# Necessary to find pkg.m4 (PKG_CHECK_MODULES)
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
USE_GNOME=	pkgconfig pygtk2
USE_XORG=	xxf86vm xi x11 xmu xext xdamage xfixes xau xdmcp xt sm ice
USE_GL=		gl glu
USE_SDL=	sdl gfx
USE_ICONV=	yes

PORTDOCS=	AUTHORS CODE-LICENSE COPYING ChangeLog GRAPHICS-LICENSE README TODO

post-patch:
	@${REINPLACE_CMD} -E -e 's|^%|#|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E -e 's|^dist_pkgdata_DATA =.*|dist_pkgdata_DATA = data/* skins/aqua.zip skins/brushed.zip skins/vectoriel.zip|g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -E -e 's|^#!/usr/bin/python|#!${LOCALBASE}/bin/python|g' ${WRKSRC}/openalchemist-config

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
