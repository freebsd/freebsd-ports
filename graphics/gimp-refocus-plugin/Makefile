# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	refocus
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP plugin to "refocus" images through FIR Wiener filtering

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app

OPTIONS_DEFINE=	ATLAS DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

ATLAS_DESC=	Build with optimized math/atlas instead of builtin

USES=		autoreconf gettext gmake pathfix pkgconfig

# GCC required due to fortran dependency, e.g., math/atlas
USE_GCC=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GIMPTOOL=${LOCALBASE}/bin/gimptool-2.0

GIMP_PLUGIN_DIR=	libexec/gimp/2.2/plug-ins

# installed files
PLIST_FILES=	${GIMP_PLUGIN_DIR}/${PORTNAME}

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am \
		-exec ${REINPLACE_CMD} -e "s|; make|; ${MAKE_CMD}|" {} \;
	@${REINPLACE_CMD} -e "s|%%WRKSRC%%|${WRKSRC}|" \
		${WRKSRC}/configure.in

.include <bsd.port.options.mk>

# math/atlas library
.if ${PORT_OPTIONS:MATLAS}
BUILD_DEPENDS+=	\
		${LOCALBASE}/include/f2c.h:lang/f2c \
		${LOCALBASE}/include/clapack.h:math/atlas
RUN_DEPENDS+=	\
		${LOCALBASE}/include/clapack.h:math/atlas

CONFIGURE_ARGS+=	--with-lapack-libs="-L${LOCALBASE}/lib -latlas -lblas -lcblas -llapack" \
			--with-lapack-includes="-I${LOCALBASE}/include"
.endif

# optimized CFLAGS
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3
.endif

# documentation
PORTDOCS=	*

do-install:
# plugin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}/
# docs
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
