# New ports collection makefile for: gd
# Date created:				19 Aug 1998
# Whom:					ichiro@ichiro.org
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.6.3
CATEGORIES=	japanese graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

PATCH_SITES=    ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/gd/${PORTVERSION}/
PATCHFILES=     ${DISTNAME}.ttf-kanji.patch.990731

MAINTAINER=	ichiro@ichiro.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

FETCH_BEFORE_ARGS=	-b
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/gd \
			--libdir=${PREFIX}/lib

CFLAGS=		-DJISX0208

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
