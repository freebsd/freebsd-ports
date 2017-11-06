# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2_loaders
PORTVERSION=	1.4.10
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LICENSE=		imlib2 GPLv2
LICENSE_COMB=		multi
LICENSE_NAME_imlib2=	imlib2 license
LICENSE_FILE_imlib2=	${WRKSRC}/COPYING
LICENSE_PERMS_imlib2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool localbase pathfix pkgconfig tar:bzip2
USE_XORG=	x11 xext

CONFIGURE_ARGS=	--disable-static

OPTIONS_DEFINE=	EET XCF
OPTIONS_DEFAULT=	EET XCF
OPTIONS_SUB=	yes

EET_DESC=	Enable eet loader
EET_LIB_DEPENDS=	libefl.so:devel/efl
EET_CONFIGURE_OFF=	--disable-eet

XCF_DESC=	Enable XCF loader
XCF_CONFIGURE_OFF=	--disable-xcf

.include <bsd.port.mk>
