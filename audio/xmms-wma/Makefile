# New ports collection makefile for:   xmms-wma
# Date created:        26 Feb 2004
# Whom:            Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	xmms-wma
PORTVERSION=	1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://mcmcc.bat.ru/xmms-wma/

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	WMA plugin for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386

PLIST_FILES=	lib/xmms/Input/libwma.so

post-extract:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/ffmpeg-strip-wma/config.mak

.include <bsd.port.mk>
