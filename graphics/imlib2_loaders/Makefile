# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	imlib2_loaders
PORTVERSION=	1.4.5
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment/imlib2-src/${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=	pathfix
USE_EFL=	imlib2 libtool_hack

OPTIONS_DEFINE=	EDB EET XCF
OPTIONS_DEFAULT=	EDB EET XCF
EDB_DESC=	Enable edb loader
EET_DESC=	Enable eet loader
XCF_DESC=	Enable XCF loader

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEDB}
USE_EFL+=	edb
PLIST_SUB+=	EDB=""
.else
CONFIGURE_ARGS+=	--disable-edb
PLIST_SUB+=	EDB="@comment "
.endif

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
