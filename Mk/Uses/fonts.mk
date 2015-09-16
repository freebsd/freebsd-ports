# $FreeBSD$
#
# handle fonts
# Feature:	fonts
# Usage:	USES=fonts
# Valid ARGS:	fc, fontsdir, fcfontsdir, none (empty means fcfontsdir)

#  fc		Add @fc ${FONTSDIR} to PLIST_FILES
#  fontsdir	Add @fontsdir ${FONTSDIR} to PLIST_FILES
#  fcfontsdir	Add @fcfontsdir ${FONTSDIR} to PLIST_FILES
#  none		No special handling of ${FONTSDIR} in PLIST_FILES

.if !defined(_INCLUDE_USES_FONTS_MK)
_INCLUDE_USES_FONTS_MK=	yes

.if empty(fonts_ARGS)
fonts_ARGS=	fcfontsdir
.endif

.if !empty(fonts_ARGS:Nfc:Nfontsdir:Nfcfontsdir:Nnone)
IGNORE=	USES=fonts - invalid ARGS (${fonts_ARGS)
.endif

.if !empty(fonts_ARGS:Mfc) || !empty(fonts_ARGS:Mfcfontsdir)
RUN_DEPENDS+=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
.endif
.if !empty(fonts_ARGS:Mfontsdir) || !empty(fonts_ARGS:Mfcfontsdir)
RUN_DEPENDS+=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
.endif

FONTNAME?=	${PORTNAME}
FONTSDIR?=	${PREFIX}/share/fonts/${FONTNAME}
.if !empty(fonts_ARGS:Nnone)
PLIST_FILES+=	"@${fonts_ARGS} ${FONTSDIR}"
.endif
SUB_LIST+=	FONTSDIR="${FONTSDIR}"
PLIST_SUB+=	FONTSDIR="${FONTSDIR}"
.endif

