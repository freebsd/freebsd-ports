# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-wma
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://mcmcc.bat.ru/xmms-wma/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WMA plugin for xmms

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

OPTIONS_DEFINE=	ICONV
OPTIONS_DEFAULT=ICONV

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USE_BZIP2=	yes
USES=		compiler gmake
USE_XORG=	xi xext x11
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC -DPIC

PLIST_FILES=	lib/xmms/Input/libwma.so

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CFLAGS+=	-DUSE_ICONV
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "clang"
CFLAGS+=	-D__inline__=
.endif

post-extract:
	@${REINPLACE_CMD} -e \
		's|^CC :=|CC ?=| ; \
		 s|^CFLAGS :=|CFLAGS += | ; \
		 s|-O[0-9]||' ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e \
		's|^MAKE=|MAKE?=| ; \
		 s|^CC=|CC?=| ; \
		 s|-O[0-9]||' ${WRKSRC}/ffmpeg-strip-wma/config.mak
.if ${ARCH} == "sparc64"
	@${REINPLACE_CMD} -e \
		 s|X86|SPARC64|' ${WRKSRC}/ffmpeg-strip-wma/config.mak
	@${REINPLACE_CMD} -e \
		's|#define ARCH_X86 1|#define ARCH_SPARC64 1|' \
		${WRKSRC}/ffmpeg-strip-wma/config.h
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	(cd ${WRKSRC} && ${INSTALL_LIB} libwma.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Input)

.include <bsd.port.post.mk>
