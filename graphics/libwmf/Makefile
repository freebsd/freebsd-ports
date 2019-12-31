# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwmf
PORTVERSION=	0.2.8.4
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	SF/wvware/${PORTNAME}/${PORTVERSION}

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Tools and library for converting Microsoft WMF (windows metafile)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		gnome jpeg libtool
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sys-gd=no \
		--with-png=${LOCALBASE} --with-jpeg=${LOCALBASE} \
		--with-gsfontdir=${LOCALBASE}/share/ghostscript/fonts
INSTALL_TARGET=	install-strip

PORTDOCS=	*

CONFLICTS?=	libwmf-nox11-[0-9]*

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=	xorg
X11_USE=	XORG=x11
X11_CONFIGURE_OFF=--with-x=no

post-patch:
	@${REINPLACE_CMD} -e 's|src include fonts doc|src include fonts|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@LIBWMF_GDK_PIXBUF_TRUE@|#|g ; \
		 s|@LIBWMF_GDK_PIXBUF_FALSE@||g ; \
		 s|: install-loaderLTLIBRARIES|:|g' ${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -

.include <bsd.port.mk>
