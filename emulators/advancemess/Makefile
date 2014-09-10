# Created by: alepulver
# $FreeBSD$

PORTNAME=	advancemess
PORTVERSION=	0.102.0.1
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL MESS port with advanced TV and monitor video support

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USE_GL=		yes
USES=		gmake
USE_SDL=	sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-idirafter ${LOCALBASE}/include

OPTIONS_DEFINE=	FREETYPE SLANG
SLANG_DESC=	Enable sLang support (for video driver)

FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_LIB_DEPENDS=		libfreetype.so:${PORTSDIR}/print/freetype2

SLANG_CONFIGURE_ENABLE=	slang
SLANG_LIB_DEPENDS=	libslang.so:${PORTSDIR}/devel/libslang2

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

post-patch:
	@${REINPLACE_CMD} -E -e '/pkgdocdir/d' \
		-e 's,(bin|man|pkg)dir),DESTDIR)$$(&,' \
		${WRKSRC}/advance/advance.mak

.include <bsd.port.post.mk>
