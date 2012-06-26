# New ports collection makefile for:	evas-loader-generic
# Date created:				2012-03-09
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	loader-generic
DISTVERSION=	1.1.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/
PKGNAMEPREFIX=	evas-
DISTNAME=	evas-${DISTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	A hardware accelerated canvas API (generic loader)

LICENSE=	BSD

EVAS_GENERIC_LOADERS=	gst pdf ps raw xcf

.for NODE in ${EVAS_GENERIC_LOADERS}
OPTIONS+=	${NODE:U} "Install ${NODE} evas generic loader" on
.endfor

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	evas librt_hack libtool_hack

MAKEDIRS=	${WRKSRC}/src/modules/loaders/generic

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-image-loader-generic

.include <bsd.port.options.mk>

.for NODE in ${EVAS_GENERIC_LOADERS}
. if !defined(WITHOUT_${NODE:U})
RUN_DEPENDS+=	${LOCALBASE}/lib/evas/utils/evas_image_loader.${NODE}:${PORTSDIR}/graphics/evas_generic_loaders-${NODE}
. endif
.endfor

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${MAKEDIRS:S,$,/Makefile.in,}

do-build:
	@(for DIR in ${MAKEDIRS}; do cd $${DIR}; ${SETENV} ${MAKE_ENV} ${MAKE} \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}; done)

do-install:
	@(for DIR in ${MAKEDIRS}; do cd $${DIR}; ${SETENV} ${MAKE_ENV} ${MAKE} \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}; done)

.include <bsd.port.mk>
