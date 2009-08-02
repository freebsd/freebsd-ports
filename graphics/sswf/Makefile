# Ports collection makefile for:	sswf
# Date created:				Oct 17, 2005
# Whom:					anhot
#
# $FreeBSD$
#

PORTNAME=	sswf
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library and script language tool to create Flash movies

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	pkgconfig
USE_BISON=	build
USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-debug --disable-yydebug
.endif

.include <bsd.port.mk>
