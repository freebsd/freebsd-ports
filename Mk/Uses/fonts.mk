# $FreeBSD$
#
# handle fonts
# Feature:	fonts
# Usage:	USES=fonts

.if !defined(_INCLUDE_USES_FONTS_MK)
_INCLUDE_USES_FONTS_MK=	yes

.if !empty(fonts_ARGS)
IGNORE=	USES=fonts - expecting no arguments
.endif

RUN_DEPENDS+=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTNAME?=	${PORTNAME}
FONTSDIR?=	${PREFIX}/share/fonts/${FONTNAME}
PLIST_FILES+=	"@fcfontsdir ${FONTSDIR}"
SUB_LIST+=	FONTSDIR="${FONTSDIR}"
PLIST_SUB+=	FONTSDIR="${FONTSDIR}"
.endif

