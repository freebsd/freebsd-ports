# New ports collection makefile for:	libwmf
# Date Created:		22 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwmf
PORTVERSION=	0.1.21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XLIB=	yes
USE_XPM=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

pre-configure:
	(cd ${WRKSRC}; ${LN} -sf xgd-1.7.3 xgd)
	(cd ${WRKSRC}/libdib; ${LN} -sf ../bytelevel.c)

.include <bsd.port.mk>
