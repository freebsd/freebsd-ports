# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2_loaders
PORTVERSION=	1.4.6
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LICENSE=		imlib2 GPLv2
LICENSE_COMB=		multi
LICENSE_NAME_imlib2=	imlib2 license
LICENSE_FILE_imlib2=	${WRKSRC}/COPYING
LICENSE_PERMS_imlib2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig tar:bzip2

OPTIONS_DEFINE=	EET XCF
OPTIONS_DEFAULT=	EET XCF
EET_DESC=	Enable eet loader
XCF_DESC=	Enable XCF loader

CONFIGURE_ARGS=	--disable-static
MAKE_ENV+=	INSTALL_STRIP_FLAG="${STRIP}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEET}
LIB_DEPENDS+=	libefl.so:devel/efl
PLIST_SUB+=	EET=""
.else
CONFIGURE_ARGS+=	--disable-eet
PLIST_SUB+=	EET="@comment "
.endif

.if ${PORT_OPTIONS:MXCF}
PLIST_SUB+=	XCF=""
.else
CONFIGURE_ARGS+=	--disable-xcf
PLIST_SUB+=	XCF="@comment "
.endif

.include <bsd.port.mk>
