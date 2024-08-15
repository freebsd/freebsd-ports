PORTNAME=	libwmf
PORTVERSION=	0.2.13
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools and library for converting Microsoft WMF (windows metafile)
COMMENT=	Library for converting WMF files
WWW=		https://wvware.sourceforge.net/libwmf.html \
		https://github.com/caolanm/libwmf

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgd.so:graphics/gd \
		libpng.so:graphics/png

USES=		cpe gnome jpeg libtool localbase pkgconfig
USE_GNOME=	gdkpixbuf2

CONFIGURE_ARGS=	--with-fontdir=${LOCALBASE}/share/libwmf/fonts \
		--with-freetype=${LOCALBASE} \
		--with-gsfontdir=${LOCALBASE}/share/ghostscript/fonts
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
FLAVORS_SUB=	yes
nox11_PKGNAMESUFFIX=	-nox11
.if ${FLAVOR} == x11
USE_XORG=	x11
USES+=		xorg
.else
CONFIGURE_ARGS+=--with-x=no
.endif

CONFLICTS_INSTALL=	libwmf libwmf-nox11

CPE_VENDOR=	wvware

USE_GITHUB=	yes
GH_ACCOUNT=	caolanm

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/ "! -name Makefile ! -name Makefile.am ! -name Makefile.in"

.include <bsd.port.mk>
