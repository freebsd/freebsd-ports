# New ports collection makefile for:	zh-auto-cn-l10n
# Date created:		12 May 2006
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
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

OPTIONS=	WQY		"WenQuanYi Bitmap Song Font"		on \
		FIREFLYTTF	"Firefly TrueType Font"			off \
		FCITX		"GBK Chinese XIM server"		off \
		SCIM 		"Smart Common Input Method platform"	on \
		MINICHINPUT 	"A tiny version of Chinput"		off \
		RELAXCONF	"A set of utilities for FreeBSD LiveCD"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WQY)
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/wqy/wenquanyi_10pt.pcf:${PORTSDIR}/x11-fonts/wqy
.endif

.if defined(WITH_FIREFLYTTF)
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:${PORTSDIR}/chinese/fireflyttf
.endif

.if defined(WITH_FCITX)
RUN_DEPENDS+=	fcitx:${PORTSDIR}/chinese/fcitx
.endif

.if !defined(WITHOUT_SCIM)
RUN_DEPENDS+=	${LOCALBASE}/share/scim/tables/Wubi.bin:${PORTSDIR}/chinese/scim-tables
RUN_DEPENDS+=	${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/pinyin.so:${PORTSDIR}/chinese/scim-pinyin
.endif

.if defined(WITH_MINICHINPUT)
RUN_DEPENDS+=	chinput:${PORTSDIR}/chinese/miniChinput
.endif

.if !defined(WITHOUT_RELAXCONF)
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
