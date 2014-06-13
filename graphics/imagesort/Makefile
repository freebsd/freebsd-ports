# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	imagesort
PORTVERSION=	2.0
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/viewers/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible X utility for managing many image files

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11 xt
USE_GNOME=	imlib

PORTDOCS=	README imagesortrc.sample
PLIST_FILES=	bin/imagesort

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 /^LIBS/s| =.*| = `imlib-config --libs`| ; \
		 /^CFLAGS/s| =.*| += `imlib-config --cflags`|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|unsigned int argc|int argc| ; \
		 s|^#endif.*|#endif|' ${WRKSRC}/imagesort.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imagesort ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
