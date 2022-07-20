PORTNAME=	libwmf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.12
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools and library for converting Microsoft WMF (windows metafile)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libexpat.so:textproc/expat2

USES=		autoreconf:build cpe jpeg libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	caolanm
USE_LDCONFIG=	yes
CPE_VENDOR=	wvware

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gsfontdir=${LOCALBASE}/share/ghostscript/fonts
INSTALL_TARGET=	install-strip

PORTDOCS=	*

CONFLICTS?=	libwmf-nox11

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=	xorg
X11_USE=	XORG=x11
X11_CONFIGURE_OFF=--with-x=no

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} AUTOHEADER="${TRUE}" \
	 ${LOCALBASE}/bin/autoreconf -vif -Ipatches)

post-configure:
	@${REINPLACE_CMD} -e 's|autoheader|autoheader -Ipatches|g' \
		${WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e \
		's|@LIBWMF_GDK_PIXBUF_TRUE@|#|g ; \
		 s|@LIBWMF_GDK_PIXBUF_FALSE@||g ; \
		 s|: install-loaderLTLIBRARIES|:|g' ${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -

.include <bsd.port.mk>
