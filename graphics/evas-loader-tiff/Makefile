# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	loader-tiff
PORTVERSION=	1.7.8
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	evas-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (TIFF loader)

LICENSE=	BSD

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	evas librt_hack libtool_hack
USE_LDCONFIG=	yes

MAKEDIRS=	${WRKSRC}/src/modules/loaders/tiff \
		${WRKSRC}/src/modules/savers/tiff

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-image-loader-tiff

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${MAKEDIRS:S,$,/Makefile.in,}

do-build:
	@(for DIR in ${MAKEDIRS}; do cd $${DIR}; ${SETENV} ${MAKE_ENV} ${GMAKE} \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}; done)

do-install:
	@(for DIR in ${MAKEDIRS}; do cd $${DIR}; ${SETENV} ${MAKE_ENV} ${GMAKE} \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}; done)

.include <bsd.port.mk>
