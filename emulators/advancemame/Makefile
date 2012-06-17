# New ports collection makefile for:	advancemame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	advancemame
PORTVERSION=	0.106.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL MAME port with advanced TV and monitor video support

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-idirafter ${LOCALBASE}/include

OPTIONS_DEFINE=	FREETYPE SLANG DOCS
SLANG_DESC=	Enable sLang support (for video driver)

MAN1=		advdev.1 advj.1 advk.1 advm.1 advmame.1 advs.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif
.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
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
	@${REINPLACE_CMD} -Ee 's|^(pkg.*)/advance|\1/${PORTNAME}|' \
		${WRKSRC}/advance/advance.mak
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/pkgdocdir/d' ${WRKSRC}/advance/advance.mak
.endif

.include <bsd.port.post.mk>
