# New ports collection makefile for:	evas-engine-sdl
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	engine-sdl
DISTVERSION=	1.0.1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (SDL engine)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	evas librt_hack libtool_hack
USE_SDL=	sdl
BUILD_WRKSRC=	${WRKSRC}/src/modules/engines/software_sdl
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-software-sdl

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-sdl.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
