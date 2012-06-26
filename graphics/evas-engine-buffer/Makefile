# New ports collection makefile for:	evas-engine-buffer
# Date created:		15 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	engine-buffer
DISTVERSION=	1.1.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${DISTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	A hardware accelerated canvas API (buffer engine)

LICENSE=	BSD

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	evas librt_hack libtool_hack
BUILD_WRKSRC=	${WRKSRC}/src/modules/engines/buffer
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-buffer

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-buffer.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
