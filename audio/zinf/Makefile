# New ports collection makefile for:	freeamp
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	freeamp
PORTVERSION=	2.1.rc5
CATEGORIES=	audio
MASTER_SITES=	http://www.freeamp.org/download/src/

MAINTAINER=	roman@xpert.com

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	musicbrainz.1:${PORTSDIR}/audio/musicbrainz \
		id3:${PORTSDIR}/audio/id3lib \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		ttf.4:${PORTSDIR}/print/freetype \
		ORBit.2:${PORTSDIR}/devel/ORBit

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GTK=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -D_M_IX86"
.elif ${ARCH} == "alpha"
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -D_M_ALPHA"
.endif

.include <bsd.port.post.mk>
