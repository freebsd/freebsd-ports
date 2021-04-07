PORTNAME=	std
PORTVERSION=	0.0.20191230
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	# empty
PKGNAMEPREFIX=	ja-font-
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese Standard Fonts

LICENSE=	PD

RUN_DEPENDS=	${LOCALBASE}/share/fonts/ipa/ipam.otf:japanese/font-ipa \
		${LOCALBASE}/share/fonts/ipa/ipag.otf:japanese/font-ipa \
		${LOCALBASE}/share/fonts/mplus-ipa/fonts/ipam.ttf:japanese/font-mplus-ipa \
		${LOCALBASE}/share/fonts/mplus-ipa/fonts/ipag.ttf:japanese/font-mplus-ipa

NO_BUILD=	yes
PLIST_FILES=	${STD:S,^,${FONTSDIR}/std.ja_JP/,}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
FONTSDIR=	share/fonts

STD=		Mincho Gothic \
		Ryumin-Light GothicBBB-Medium \
		Ryumin-Light.gs7 GothicBBB-Medium.gs7
STD_Mincho=	${LOCALBASE}/share/fonts/ipa/ipam.otf
STD_Gothic=	${LOCALBASE}/share/fonts/ipa/ipag.otf
STD_Ryumin-Light=	${LOCALBASE}/share/fonts/ipa/ipam.otf
STD_GothicBBB-Medium=	${LOCALBASE}/share/fonts/ipa/ipag.otf
STD_Ryumin-Light.gs7=	${LOCALBASE}/share/fonts/mplus-ipa/fonts/ipam.ttf
STD_GothicBBB-Medium.gs7=	${LOCALBASE}/share/fonts/mplus-ipa/fonts/ipag.ttf

do-fetch:
	@${DO_NADA}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}/std.ja_JP
.for F in ${STD}
	${LN} -s -f ${STD_${F}} ${STAGEDIR}${PREFIX}/${FONTSDIR}/std.ja_JP/${F}
.endfor

.include <bsd.port.mk>
