# Created by: anhot
# $FreeBSD$

PORTNAME=	sswf
PORTVERSION=	1.8.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library and script language tool to create Flash movies

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison pkgconfig iconv
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-debug --disable-yydebug
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
