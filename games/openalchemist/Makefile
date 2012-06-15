# New ports collection makefile for:    openalchemist
# Date created:     Sat Oct 01 09:30:00 UTC 2003
# Whom:         Ganael LAPLANCHE <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	openalchemist
PORTVERSION=	0.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tetris-like game

LICENSE=	GPLv2 CCbySA
LICENSE_COMB=	multi
LICENSE_NAME_CCbySA=	Creative Commons Attribution-ShareAlike
LICENSE_FILE_CCbySA=	${WRKSRC}/GRAPHICS-LICENSE
LICENSE_PERMS_CCbySA=	${_LICENSE_PERMS_DEFAULT}

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	clanCore:${PORTSDIR}/devel/clanlib \
	jpeg:${PORTSDIR}/graphics/jpeg \
	png15:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	aclocal automake autoconf
# Necessary to find pkg.m4 (PKG_CHECK_MODULES)
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig pygtk2
USE_XORG=	xxf86vm xi x11 xmu xext xdamage xfixes xau xdmcp xt sm ice
USE_GL=		gl glu
USE_SDL=	sdl gfx
USE_ICONV=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E -e 's|^%|#|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E -e 's|^dist_pkgdata_DATA =.*|dist_pkgdata_DATA = data/* skins/aqua.zip skins/brushed.zip skins/vectoriel.zip|g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -E -e 's|^#!/usr/bin/python|#!${LOCALBASE}/bin/python|g' ${WRKSRC}/openalchemist-config

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
