# New ports collection makefile for:	DirectFB
# Date created:				19 October 2002
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	directfb
PORTVERSION=	0.9.16
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/
DISTNAME=	DirectFB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic development lightweight API

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
USE_SDL=	sdl
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	DIRECTFB_VERSION=${PORTVERSION}

.if exists(${LOCALBASE}/lib/libfreetype.so.9)
WITH_FREETYPE2=	yes
.endif

.if defined(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--enable-freetype
PLIST_SUB+=	WITH_FREETYPE2=""
.else
CONFIGURE_ARGS+=	--disable-freetype
PLIST_SUB+=	WITH_FREETYPE2="@comment "
.endif

MAN1=		directfb-csource.1 dfbg.1
MAN5=		directfbrc.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
BROKEN=		"Does not compile on alpha 5.x"
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Hard-codes references to libc_r"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

.include <bsd.port.post.mk>
