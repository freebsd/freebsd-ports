# New ports collection makefile for:	advancemenu
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	advancemenu
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A frontend for AdvanceMAME, MAME, MESS, RAINE

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	FREETYPE SLANG DOCS
SLANG_DESC=	Enable sLang support (for video driver)

MAN1=		advmenu.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=--disable-freetype
.endif

.if ${PORT_OPTIONS:MSLANG}
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
.else
CONFIGURE_ARGS+=--disable-slang
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|^(pkg.*)/advance|\1/${PORTNAME}|; /pkgdir/d' \
		${WRKSRC}/advance/advance.mak
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/pkgdocdir/d' ${WRKSRC}/advance/advance.mak
.endif

.include <bsd.port.post.mk>
