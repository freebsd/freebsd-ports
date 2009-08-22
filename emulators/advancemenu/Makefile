# New ports collection makefile for:	advancemenu
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	advancemenu
PORTVERSION=	2.4.14
CATEGORIES=	emulators
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	AdvanceMENU is a frontend for AdvanceMAME, MAME, MESS, RAINE

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	FREETYPE "Enable FreeType2 support" off \
		SLANG "Enable sLang support (for video driver)" off

MAN1=		advmenu.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=--disable-freetype
.endif

.if defined(WITH_SLANG)
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
.else
CONFIGURE_ARGS+=--disable-slang
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|^(pkg.*)/advance|\1/${PORTNAME}|; /pkgdir/d' \
		${WRKSRC}/advance/advance.mak
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/pkgdocdir/d' ${WRKSRC}/advance/advance.mak
.endif

.include <bsd.port.post.mk>
