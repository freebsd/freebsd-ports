# New ports collection makefile for:    zh-fcitx
# Date created:		26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	1.8.5
CATEGORIES=	chinese x11
MASTER_SITES=	http://www.fcitx.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dryice@liu.com.cn
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#usr/share#${LOCALBASE}/share#g' ${WRKSRC}/Makefile ${WRKSRC}/ime.h
	@${REINPLACE_CMD} -e 's#usr/bin#${LOCALBASE}/bin#g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's#zh_CN.GB2312#zh_CN.EUC#g' ${WRKSRC}/window.c
	@${REINPLACE_CMD} -e 's#zh_CN.gb2312#zh_CN.EUC#g' ${WRKSRC}/xim.c
	@${REINPLACE_CMD} -e 's#zh_CN.GBK#zh_CN.EUC#g' ${WRKSRC}/tools.c
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/IMdkit/lib/IMConn.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
