# ex:ts=8
# Ports collection makefile for:	deep_zoom
# Date created:			Aug 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	deep_zoom
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://members.rogers.com/rowley-c/deep_zoom/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate very highly zoomed fractals

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	Imlib2:${PORTSDIR}/graphics/imlib2 \
		gmp.6:${PORTSDIR}/math/libgmp4

IMLIB2_CONFIG=	${X11BASE}/bin/imlib2-config
USE_REINPLACE=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include `${IMLIB2_CONFIG} --cflags`
MAKE_ENV=	CC=${CXX} LDFLAGS="`${IMLIB2_CONFIG} --libs`"
PLIST_FILES=	bin/deep_zoom

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS=|CFLAGS+=|g" \
		-e "s|^LDFLAGS=|LDFLAGS+=|g" -e "s|imlib2||g" \
		-e "s|^CONFIG_CFLAGS|#CONFIG_CFLAGS|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deep_zoom ${PREFIX}/bin

.include <bsd.port.mk>
