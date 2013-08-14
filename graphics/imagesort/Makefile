# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	imagesort
PORTVERSION=	2.0
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/viewers/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible X utility for managing many image files

LICENSE=	GPLv2

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11 xt
USE_GNOME=	imlib

PORTDOCS=	README imagesortrc.sample
PLIST_FILES=	bin/imagesort

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 /^LIBS/s| =.*| = `imlib-config --libs`| ; \
		 /^CFLAGS/s| =.*| += `imlib-config --cflags`|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|unsigned int argc|int argc| ; \
		 s|^#endif.*|#endif|' ${WRKSRC}/imagesort.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imagesort ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
