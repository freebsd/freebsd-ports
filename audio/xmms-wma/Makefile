# New ports collection makefile for:   xmms-wma
# Date created:        26 Feb 2004
# Whom:            Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	xmms-wma
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://mcmcc.bat.ru/xmms-wma/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	WMA plugin for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386

PLIST_FILES=	lib/xmms/Input/libwma.so

.if defined(WITH_ICONV)
CFLAGS+=	-DUSE_ICONV
USE_ICONV=	yes
.endif

pre-everything::
.if !defined(WITH_ICONV)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "WITH_ICONV=yes	Enable tag recoding support using iconv"
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/ffmpeg-strip-wma/config.mak

.include <bsd.port.mk>
