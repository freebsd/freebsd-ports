# New ports collection makefile for:   xmms-wma
# Date created:        26 Feb 2004
# Whom:            Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	xmms-wma
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://mcmcc.bat.ru/xmms-wma/

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	WMA plugin for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386

PLIST_FILES=	lib/xmms/Input/libwma.so

.include <bsd.port.mk>
