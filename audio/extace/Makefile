# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	extace
PORTVERSION=	1.9.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Audio Visualization plugin for the X Window System

LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3

USE_X_PREFIX=	yes
USE_GNOME=	esound imlib gnomehack gnometarget gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/extace \
		share/gnome/apps/Multimedia/extace.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 |$$CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^LIBS =|#LIBS =|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
