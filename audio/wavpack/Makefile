# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wavpack
PORTVERSION=	5.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio codec for lossless, lossy, and hybrid compression

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ASM
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFAULT_armv6=	ASM
OPTIONS_DEFAULT_armv7=	ASM

ASM_CONFIGURE_OFF=	--disable-asm
ASM_DESC=	Optimized assembler routines (requires MMX on x86)

.include <bsd.port.options.mk>

# ASM needs clang 3.8+
# depend on llvm60 since it's more likely to be installed already than 3.8
.if ${OSVERSION} < 1100101 && ${PORT_OPTIONS:MASM}
BUILD_DEPENDS+=	clang60:devel/llvm60
CC=		clang60
.endif

.include <bsd.port.mk>
