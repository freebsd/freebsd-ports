# New ports collection makefile for:	aube
# Date created:				09.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	aube
PORTVERSION=	0.30.3
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.metadecks.org/software/aube/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System for sound generation and processing

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_GNOME=	imlib
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		aube.1
PLIST_FILES=	bin/aube \
		%%DATADIR%%/aube_logo.ppm \
		%%DATADIR%%/aube_mini.png \
		%%DATADIR%%/gtkrc
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lgdk_imlib|@GDK_IMLIB_LIBS@|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-g -O2 -Wall|@CFLAGS@|g' ${WRKSRC}/src/modules/Makefile.in

.include <bsd.port.mk>
