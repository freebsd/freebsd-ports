# New ports collection makefile for:	darktable
# Date created:				11 March 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darktable
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A virtual lighttable and darkroom for photographers

LIB_DEPENDS=	gegl-0.1.101:${PORTSDIR}/graphics/gegl \
		exiv2.7:${PORTSDIR}/graphics/exiv2 \
		lensfun.0:${PORTSDIR}/graphics/lensfun \
		lcms.1:${PORTSDIR}/graphics/lcms

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2 libglade2
GCONF_SCHEMAS=	${PORTNAME}.schemas
USE_SQLITE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
# Bandaid for log2f(3), which FreeBSD lacks
	@${REINPLACE_CMD} -E 's,log2f\(([^)]*),logf(\1)/logf(2.0f,' \
		${WRKSRC}/src/iop/exposure.c \
		${WRKSRC}/src/iop/equalizer.c
# Better respect for CFLAGS
	@${REINPLACE_CMD} -e 's,-Werror -g,@CFLAGS@,' \
		${WRKSRC}/src/iop/Makefile.in \
		${WRKSRC}/src/views/Makefile.in \
		${WRKSRC}/src/libs/Makefile.in
# FreeBSD 6.X does not have posix_memalign(3)
	@${REINPLACE_CMD} -e 's,__APPLE__),& || __FreeBSD_version < 700013,' \
		${WRKSRC}/src/common/darktable.c
# libpng 1.4
	@${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|g' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/src/common/imageio_png.c
	@${REINPLACE_CMD} -e 's|libpng12|libpng14|g' ${WRKSRC}/configure

.include <bsd.port.mk>
