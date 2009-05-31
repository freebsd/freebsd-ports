# New ports collection makefile for:	font-std
# Date created:		15 May 2009
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	font-std
PORTVERSION=	0.0.20090515
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Chinese Standard Fonts

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf:${PORTSDIR}/chinese/arphicttf \
		${LOCALBASE}/share/fonts/TrueType/gbsn00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf:${PORTSDIR}/chinese/arphicttf

NO_BUILD=	yes
PLIST_FILES=	${FONTSDIR}/std.zh_CN/STHeiti-Regular \
		${FONTSDIR}/std.zh_CN/STSong-Light \
		${FONTSDIR}/std.zh_CN/MSung-Light \
		${FONTSDIR}/std.zh_CN/MHei-Medium
PLIST_DIRS=	${FONTSDIR}/std.zh_CN
FONTSDIR=	${PREFIX}/share/fonts

do-fetch:
	@${DO_NADA}

do-install:
	${MKDIR} ${FONTSDIR}/std.zh_CN
	${LN} -s -f ${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf ${FONTSDIR}/std.zh_CN/STHeiti-Regular
	${LN} -s -f ${LOCALBASE}/share/fonts/TrueType/gbsn00lp.ttf ${FONTSDIR}/std.zh_CN/STSong-Light
	${LN} -s -f ${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf ${FONTSDIR}/std.zh_CN/MSung-Light
	${LN} -s -f ${LOCALBASE}/share/fonts/TrueType/gkai00mp.ttf ${FONTSDIR}/std.zh_CN/MHei-Medium

.include <bsd.port.mk>
