# New ports collection makefile for:    zh-fcitx
# Date created:		26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	1.8.2
CATEGORIES=	chinese
MASTER_SITES=	http://www.linuxsir.com.cn/fcitx/

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_XLIB=	yes
USE_REINPLACE=  yes

post-patch:
	@${REINPLACE_CMD} -e 's#usr/share#usr/local/share#g' ${WRKSRC}/Makefile ${WRKSRC}/ime.h
	@${REINPLACE_CMD} -e 's#usr/bin#usr/local/bin#g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's#zh_CN.GB2312#zh_CN.EUC#g' ${WRKSRC}/window.c
	@${REINPLACE_CMD} -e 's#zh_CN.gb2312#zh_CN.EUC#g' ${WRKSRC}/xim.c
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/IMdkit/lib/IMConn.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
