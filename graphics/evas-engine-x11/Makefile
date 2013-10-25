# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	engine-x11
PORTVERSION=	1.7.8
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	evas-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (X11 engine)

LICENSE=	BSD

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	evas librt_hack libtool_hack
USE_XORG=	x11 xext
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/modules/engines/software_x11
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-software-xlib

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-x11.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
