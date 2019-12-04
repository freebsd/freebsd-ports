# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	auto-cn-l10n
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	chinese
#MASTER_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
MASTER_SITES=	LOCAL/delphij
DISTNAME=	zh-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The automatic localization for Simplified Chinese zh_CN.eucCN locale

NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		WQY FIREFLYTTF FCITX SCIM MINICHINPUT RELAXCONF
OPTIONS_DEFAULT=	WQY SCIM RELAXCONF
WQY_DESC=		WenQuanYi Bitmap Song Font
FIREFLYTTF_DESC=	Firefly TrueType Font
FCITX_DESC=		GBK Chinese XIM server
SCIM_DESC=		Smart Common Input Method platform
MINICHINPUT_DESC=	A tiny version of Chinput
RELAXCONF_DESC=		A set of utilities for FreeBSD LiveCD

WQY_RUN_DEPENDS=	${LOCALBASE}/share/fonts/wqy/wenquanyi_10pt.pcf:x11-fonts/wqy
FIREFLYTTF_RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:chinese/fireflyttf
FCITX_RUN_DEPENDS=	fcitx:chinese/fcitx
SCIM_RUN_DEPENDS=	${LOCALBASE}/share/scim/tables/Wubi.bin:chinese/scim-tables \
			${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/pinyin.so:chinese/scim-pinyin
MINICHINPUT_RUN_DEPENDS=chinput:chinese/miniChinput
RELAXCONF_RUN_DEPENDS=	relaxconf:sysutils/relaxconf

post-patch:
	@${REINPLACE_CMD} -e "s|%%X11BASE%%|${LOCALBASE}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dot.xselector ${WRKSRC}/dot.xinitrc
	@${RM} ${WRKSRC}/dot.xselector.bak ${WRKSRC}/dot.xinitrc.bak

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/skel/zh_CN.eucCN
	${CP} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/skel/zh_CN.eucCN

.include <bsd.port.mk>
