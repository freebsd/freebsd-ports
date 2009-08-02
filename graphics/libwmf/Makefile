# New ports collection makefile for:	libwmf
# Date Created:		22 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwmf
PORTVERSION=	0.2.8.4
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools and library for converting Microsoft WMF (windows metafile)

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2     # XXX
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnometarget libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sys-gd=no \
		--with-png=${LOCALBASE} --with-jpeg=${LOCALBASE} \
		--with-gsfontdir=${LOCALBASE}/share/ghostscript/fonts
USE_LDCONFIG=	yes

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--with-x=no
PLIST_SUB+=	X11='@comment '
.else
USE_XORG=	x11
PLIST_SUB+=	X11=''
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
