# New ports collection makefile for:	xpcd
# Date created:		27 October 2001
# Whom:			Juha Ylitalo
#
# $FreeBSD$
#

PORTNAME=	xpcd
PORTVERSION=	2.09
CATEGORIES+=	graphics
MASTER_SITES=	http://dl.bytesex.org/releases/xpcd/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	PhotoCD tool collection

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		pcd.2:${PORTSDIR}/graphics/libpcd

# USE_IMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
USE_X_PREFIX=	yes
MAN1=		pcdtoppm.1 pcdview.1 xpcd.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-4
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
