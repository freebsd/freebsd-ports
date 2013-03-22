# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libwmf
PORTVERSION=	0.2.8.4
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/wvware/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools and library for converting Microsoft WMF (windows metafile)

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2     # XXX
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_AUTOTOOLS=	libtool
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sys-gd=no \
		--with-png=${LOCALBASE} --with-jpeg=${LOCALBASE} \
		--with-gsfontdir=${LOCALBASE}/share/ghostscript/fonts
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--with-x=no
PLIST_SUB+=	X11='@comment '
CONFLICTS+=	libwmf-0.*
.else
USE_XORG=	x11
PLIST_SUB+=	X11=''
CONFLICTS+=	libwmf-nox11-0.*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|src include fonts doc|src include fonts|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@LT_CURRENT@|2|g ; \
		 s|@LIBWMF_GDK_PIXBUF_TRUE@|#|g ; \
		 s|@LIBWMF_GDK_PIXBUF_FALSE@||g ; \
		 s|-release $$(LT_RELEASE)||g ; \
		 s|: install-loaderLTLIBRARIES|:|g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGROUP} ${DOCSDIR}
.endif

.include <bsd.port.mk>

