# New ports collection makefile for:	zh-auto-cn-l10n
# Date created:		12 May 2006
# Whom:			Liu.Yinghong <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$

PORTNAME=	auto-cn-l10n
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
DISTNAME=	zh-${PORTNAME}-${PORTVERSION}

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	The automatic localization for Simplified Chinese zh_CN.eucCN locale

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	FIREFLYTTF	"Firefly TrueType Font"			on \
		FCITX		"GBK Chinese XIM server"		on \
		SCIM 		"Smart Common Input Method platform"	off \
		MINICHINPUT 	"A tiny version of Chinput"		off \
		RELAXCONF	"A set of utilities for FreeBSD LiveCD"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FIREFLYTTF)
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/TrueType/fireflysung.ttf:${PORTSDIR}/chinese/fireflyttf
.endif

.if !defined(WITHOUT_FCITX)
RUN_DEPENDS+=	fcitx:${PORTSDIR}/chinese/fcitx
.endif

.if defined(WITH_SCIM)
RUN_DEPENDS+=	scim:${PORTSDIR}/textproc/scim
.endif

.if defined(WITH_MINICHINPUT)
RUN_DEPENDS+=	chinput:${PORTSDIR}/chinese/miniChinput
.endif

.if !defined(WITHOUT_RELAXCONF)
RUN_DEPENDS+=	relaxconf:${PORTSDIR}/sysutils/relaxconf
.endif

do-install:
	${MKDIR} ${PREFIX}/share/skel/zh_CN.eucCN
	${CP} ${WRKSRC}/* ${PREFIX}/share/skel/zh_CN.eucCN

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
