# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	auto-cn-l10n
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	chinese
#MASTER_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
MASTER_SITES=	${MASTER_SITE_LOCAL:S/%SUBDIR%/delphij/}
DISTNAME=	zh-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The automatic localization for Simplified Chinese zh_CN.eucCN locale

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
REINPLACE_ARGS=	-i ""

OPTIONS_DEFINE=	WQY FIREFLYTTF FCITX SCIM MINICHINPUT RELAXCONF
OPTIONS_DEFAULT=	WQY SCIM RELAXCONF
WQY_DESC=		WenQuanYi Bitmap Song Font
FIREFLYTTF_DESC=	Firefly TrueType Font
FCITX_DESC=		GBK Chinese XIM server
SCIM_DESC=		Smart Common Input Method platform
MINICHINPUT_DESC=	A tiny version of Chinput
RELAXCONF_DESC=		A set of utilities for FreeBSD LiveCD

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWQY}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/wqy/wenquanyi_10pt.pcf:${PORTSDIR}/x11-fonts/wqy
.endif

.if ${PORT_OPTIONS:MFIREFLYTTF}
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:${PORTSDIR}/chinese/fireflyttf
.endif

.if ${PORT_OPTIONS:MFCITX}
RUN_DEPENDS+=	fcitx:${PORTSDIR}/chinese/fcitx
.endif

.if ${PORT_OPTIONS:MSCIM}
RUN_DEPENDS+=	${LOCALBASE}/share/scim/tables/Wubi.bin:${PORTSDIR}/chinese/scim-tables
RUN_DEPENDS+=	${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/pinyin.so:${PORTSDIR}/chinese/scim-pinyin
.endif

.if ${PORT_OPTIONS:MMINICHINPUT}
RUN_DEPENDS+=	chinput:${PORTSDIR}/chinese/miniChinput
.endif

.if ${PORT_OPTIONS:MRELAXCONF}
RUN_DEPENDS+=	relaxconf:${PORTSDIR}/sysutils/relaxconf
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dot.xselector ${WRKSRC}/dot.xinitrc

do-install:
	${MKDIR} ${PREFIX}/share/skel/zh_CN.eucCN
	${CP} ${WRKSRC}/* ${PREFIX}/share/skel/zh_CN.eucCN

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
