# New ports collection makefile for:   xmms-wma
# Date created:        26 Feb 2004
# Whom:            Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	xmms-wma
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://mcmcc.bat.ru/xmms-wma/

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	WMA plugin for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-fPIC -DPIC
ONLY_FOR_ARCHS=	i386 amd64 sparc64
USE_XORG=	xi xext x11

PLIST_FILES=	lib/xmms/Input/libwma.so
USE_LDCONFIG=	yes

.if defined(WITH_ICONV)
CFLAGS+=	-DUSE_ICONV
USE_ICONV=	yes
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_ICONV)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "WITH_ICONV=yes	Enable tag recoding support using iconv"
	@${ECHO_MSG} " "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/ffmpeg-strip-wma/config.mak
	@${REINPLACE_CMD} -e 's|CFLAGS :=|CFLAGS := ${CFLAGS}|g' ${WRKSRC}/Makefile.inc
.if ${ARCH}=="sparc64"
	@${REINPLACE_CMD} -e 's|X86|SPARC64|' ${WRKSRC}/ffmpeg-strip-wma/config.mak
	@${REINPLACE_CMD} -e 's|#define ARCH_X86 1|#define ARCH_SPARC64 1|' ${WRKSRC}/ffmpeg-strip-wma/config.h
.endif

.include <bsd.port.post.mk>
