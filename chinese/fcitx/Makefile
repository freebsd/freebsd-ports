# New ports collection makefile for:    zh-fcitx
# Date created:		26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	chinese x11
MASTER_SITES=	http://www.fcitx.org/download/ \
		ftp://mirrors.redv.com/pub/fcitx/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
DISTNAME= fcitx-3.5-BlackFri

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_XORG=	xpm x11
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC= 	${WRKDIR}/fcitx-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's#zh_CN.GB2312#zh_CN.eucCN#g' ${WRKSRC}/src/xim.c
	@${REINPLACE_CMD} -e 's#zh_CN.gb2312#zh_CN.eucCN#g' ${WRKSRC}/src/ui.c ${WRKSRC}/src/tools.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
