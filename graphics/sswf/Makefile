# Created by: anhot
# $FreeBSD$

PORTNAME=	sswf
PORTVERSION=	1.8.4
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library and script language tool to create Flash movies

LIB_DEPENDS=	libfreetype.so:print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison iconv jpeg libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--disable-debug --disable-yydebug
.endif

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_libiconv_open=no \
		ac_cv_lib_iconv_iconv_open=no
.endif

.include <bsd.port.post.mk>
