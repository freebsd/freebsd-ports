# New ports collection makefile for:    zh-fcitx
# Date created:		26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	3.1.1
CATEGORIES=	chinese x11
MASTER_SITES=	http://www.fcitx.org/download/ \
		http://bsdchat.com/dist/dryice/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dryice@liu.com.cn
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#zh_CN.GB2312#zh_CN.eucCN#g' ${WRKSRC}/src/xim.c
	@${REINPLACE_CMD} -e 's#zh_CN.gb2312#zh_CN.eucCN#g' ${WRKSRC}/src/ui.c ${WRKSRC}/src/tools.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
