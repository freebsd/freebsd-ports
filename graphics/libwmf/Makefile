# New ports collection makefile for:	libwmf
# Date Created:		22 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwmf
PORTVERSION=	0.1.17
CATEGORIES=	graphics
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/libwmf/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		png.3:${PORTSDIR}/graphics/png \
		ttf.4:${PORTSDIR}/print/freetype

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype \
		          -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}"/lib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
