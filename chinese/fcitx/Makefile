# New ports collection makefile for:    zh-fcitx
# Date created:		26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	chinese x11
MASTER_SITES=	http://www.fcitx.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dryice@liu.com.cn
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_ICONV=	yes

post-extract:
	cd ${BUILD_WRKSRC}; ${MAKE} clean

pre-patch::
	@${ECHO_MSG}
.if !defined(FCITX_WITH_CTRL_RSHIFT)
	@${ECHO_MSG} "If you don't want to use CTRL+SPACE to active/deactive fcitx,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make FCITX_WITH_CTRL_RSHIFT=yes\"."
	@${ECHO_MSG} "Then you can use CTRL+RIGHT_SHIFT to active/deactive fcitx."
	@${ECHO_MSG}
.endif
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's#usr/share#${LOCALBASE}/share#g' ${WRKSRC}/Makefile ${WRKSRC}/ime.h
	@${REINPLACE_CMD} -e 's#usr/bin#${LOCALBASE}/bin#g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's#zh_CN.GB2312#zh_CN.eucCN#g' ${WRKSRC}/ui.c
	@${REINPLACE_CMD} -e 's#zh_CN.gb2312#zh_CN.eucCN#g' ${WRKSRC}/xim.c
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/IMdkit/lib/IMConn.c ${WRKSRC}/ui.c
.if defined(FCITX_WITH_CTRL_RSHIFT)
	@${REINPLACE_CMD} -e 's/XK_space/XK_Shift_R/g' ${WRKSRC}/xim.c
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in cjkvinput.txt hf_wb98.txt readme.html wb_fh.htm
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
