# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	extace
PORTVERSION=	1.8.06
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Audio Visualization plugin for the X Window System

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_X_PREFIX=	yes
USE_GNOME=	esound imlib gnomehack gnomehier
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_LIBFFTW" \
		LDFLAGS="-L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/extace \
		${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/extace.desktop \
		${PREFIX}/share/gnome/apps/Multimedia

.include <bsd.port.mk>
