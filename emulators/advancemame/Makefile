# New ports collection makefile for:	advancemame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	advancemame
PORTVERSION=	0.106.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL MAME port with advanced TV and monitor video support

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -idirafter ${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	FREETYPE "Enable FreeType2 support" off \
		SLANG "Enable sLang support (for video driver)" off

MAN1=		advdev.1 advj.1 advk.1 advm.1 advmame.1 advs.1

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
	@${REINPLACE_CMD} -Ee 's|^(pkg.*)/advance|\1/${PORTNAME}|' \
		${WRKSRC}/advance/advance.mak
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/pkgdocdir/d' ${WRKSRC}/advance/advance.mak
.endif

.include <bsd.port.post.mk>
