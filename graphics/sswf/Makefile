# Created by: anhot
# $FreeBSD$

PORTNAME=	sswf
PORTVERSION=	1.8.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library and script language tool to create Flash movies

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison pkgconfig iconv
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--disable-debug --disable-yydebug
.endif

post-configure:
	@${REINPLACE_CMD} 's|ICONV_INPUT_CAST||' \
		${WRKSRC}/src/lib/libsswf_tag_header.c++ \
		${WRKSRC}/src/sswf/sswf_lexical.c++

.include <bsd.port.mk>
