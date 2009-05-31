# New ports collection makefile for:	font-std
# Date created:		15 May 2009
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	font-std
PORTVERSION=	0.0.20090515
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese Standard Fonts

BUILD_DEPENDS=	${LOCALBASE}/share/font-ipa/ipam.otf:${PORTSDIR}/japanese/font-ipa \
		${LOCALBASE}/share/font-ipa/ipag.otf:${PORTSDIR}/japanese/font-ipa

NO_BUILD=	yes
PLIST_FILES=	${FONTSDIR}/std.ja_JP/Ryumin-Light \
		${FONTSDIR}/std.ja_JP/GothicBBB-Medium \
		${FONTSDIR}/std.ja_JP/Mincho \
		${FONTSDIR}/std.ja_JP/Gothic
PLIST_DIRS=	${FONTSDIR}/std.ja_JP
FONTSDIR=	share/fonts

STD=		Mincho Gothic Ryumin-Light GothicBBB-Medium
STD_Mincho=	${LOCALBASE}/share/font-ipa/ipam.otf
STD_Gothic=	${LOCALBASE}/share/font-ipa/ipag.otf
STD_Ryumin-Light=	${LOCALBASE}/share/font-ipa/ipam.otf
STD_GothicBBB-Medium=	${LOCALBASE}/share/font-ipa/ipag.otf

do-fetch:
	@${DO_NADA}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}/std.ja_JP
.for F in ${STD}
	${LN} -s -f ${STD_${F}} ${PREFIX}/${FONTSDIR}/std.ja_JP/${F}
.endfor

.include <bsd.port.mk>
