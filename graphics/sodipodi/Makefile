# New ports collection makefile for:   sodipodi
# Date created:        28 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sodipodi
PORTVERSION=	0.17
CATEGORIES=	graphics
MASTER_SITES=	http://www.ariman.ee/linux/sodipodi/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		glade.3:${PORTSDIR}/devel/libglade \
		gnomeprint.6:${PORTSDIR}/print/gnomeprint \
		gdk_pixbuf.1:${PORTSDIR}/graphics/gdk-pixbuf
BUILD_DEPENDS=	${LOCALBASE}/share/automake/install-sh:${PORTSDIR}/devel/automake

WRKSRC=		${WRKDIR}/sodipodi

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

post-extract:
		${RM} ${WRKSRC}/config.cache
		${RM} ${WRKSRC}/install-sh
		${RM} ${WRKSRC}/mkinstalldirs
		${LN} -s ${LOCALBASE}/share/automake/install-sh \
			${WRKSRC}/install-sh
		${LN} -s ${LOCALBASE}/share/automake/mkinstalldirs \
			${WRKSRC}/mkinstalldirs

.include <bsd.port.mk>
