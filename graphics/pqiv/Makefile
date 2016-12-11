# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pqiv
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Pretty Quick Image Viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_ACCOUNT=	phillipberndt

OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3

OPTIONS_GROUP=		BACKENDS
OPTIONS_GROUP_BACKENDS=	LIBAV PIXBUF POPPLER SPECTRE WAND
LIBAV_DESC=		Video support
SPECTRE_DESC=		PS/EPS support
WAND_DESC=		ImageMagick image processing support

OPTIONS_DEFAULT=	GTK2 PIXBUF

USES=		gettext-runtime gmake pkgconfig tar:bzip2
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2
HAS_CONFIGURE=	yes

LIBAV_CONFIGURE_WITH=	libav
LIBAV_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

PIXBUF_CONFIGURE_WITH=	gdkpixbuf

POPPLER_CONFIGURE_WITH=	poppler
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

SPECTRE_CONFIGURE_WITH=	spectre
SPECTRE_LIB_DEPENDS=	libspectre.so:print/libspectre

WAND_CONFIGURE_WITH=	wand
WAND_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick

GTK2_CONFIGURE_ON=	--gtk-version=2
GTK2_USE=		GNOME=gtk20

GTK3_CONFIGURE_ON=	--gtk-version=3
GTK3_USE=		GNOME=gtk30

MAKEFILE=	GNUmakefile

PORTDOCS=	README.markdown
PLIST_FILES=	bin/pqiv man/man1/pqiv.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pqiv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pqiv.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
