# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$
#   $MCom: ports-stable/devel/gconfmm26/Makefile,v 1.1 2010/06/24 07:51:01 kwm Exp $

PORTNAME=	gconfmm
PORTVERSION=	2.28.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for gconf2 API library

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		${LOCALBASE}/lib/libgtkmm-2.4.so.1:${PORTSDIR}/x11-toolkits/gtkmm24

LATEST_LINK=	gconfmm26

USES=		pkgconfig
USE_BZIP2=	yes
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomehack gconf2 referencehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
