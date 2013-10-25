# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	loader-generic
PORTVERSION=	1.7.8
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	evas-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (generic loader)

LICENSE=	BSD

EVAS_GENERIC_LOADERS=	gst pdf ps raw svg xcf

#bmake compatibility
.MAKE.FreeBSD_UL= yes

.for NODE in ${EVAS_GENERIC_LOADERS}
OPTIONS_DEFINE+=	${NODE:U}
OPTIONS_DEFAULT+=	${NODE:U}
${NODE:U}_DESC=	Install ${NODE} evas generic loader
.endfor

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	evas librt_hack libtool_hack
USE_LDCONFIG=	yes

MAKEDIRS=	${WRKSRC}/src/modules/loaders/generic

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-image-loader-generic

.include <bsd.port.options.mk>

.for NODE in ${EVAS_GENERIC_LOADERS}
. if ${PORT_OPTIONS:M${NODE:U}}
RUN_DEPENDS+=	${LOCALBASE}/lib/evas/utils/evas_image_loader.${NODE}:${PORTSDIR}/graphics/evas_generic_loaders-${NODE}
. endif
.endfor

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
