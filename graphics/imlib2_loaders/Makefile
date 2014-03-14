# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2_loaders
PORTVERSION=	1.4.6
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LICENSE=		imlib2 GPLv2
LICENSE_COMB=		multi
LICENSE_NAME_imlib2=	imlib2 license
LICENSE_FILE_imlib2=	${WRKSRC}/COPYING
LICENSE_PERMS_imlib2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_EFL=	imlib2 libtool_hack

OPTIONS_DEFINE=	EET XCF
OPTIONS_DEFAULT=	EET XCF
EET_DESC=	Enable eet loader
XCF_DESC=	Enable XCF loader

MAKE_ENV+=	INSTALL_STRIP_FLAG="${STRIP}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEET}
USE_EFL+=	eet
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
