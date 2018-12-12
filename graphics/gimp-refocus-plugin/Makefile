# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	refocus
PORTVERSION=	0.9.0
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP plugin to "refocus" images through FIR Wiener filtering

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GIMPTOOL=${LOCALBASE}/bin/gimptool-2.0
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango

GIMP_PLUGIN_DIR=	libexec/gimp/2.2/plug-ins

PLIST_FILES=	${GIMP_PLUGIN_DIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	ATLAS DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

ATLAS_DESC=	Build with optimized math/atlas instead of builtin
ATLAS_USES=		blaslapack:atlas fortran
ATLAS_BUILD_DEPENDS=	f2c>0:lang/f2c
ATLAS_CONFIGURE_ON=	--with-lapack-libs="${LAPACKLIB} ${BLASLIB}" \
			--with-lapack-includes="-I${LOCALBASE}/include"

OPTIMIZED_CFLAGS_CFLAGS=	-O3

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am \
		-exec ${REINPLACE_CMD} -e "s|; make|; ${MAKE_CMD}|" {} \;
	@${REINPLACE_CMD} -e "s|%%WRKSRC%%|${WRKSRC}|" \
		${WRKSRC}/configure.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${GIMP_PLUGIN_DIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
