# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	extace
PORTVERSION=	1.9.9
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/eXtace/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Audio Visualization plugin for the X Window System

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3

USE_GNOME=	esound gnomehack gnomehier gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/extace \
		share/gnome/apps/Multimedia/extace.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^LIBS =|#LIBS =|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
