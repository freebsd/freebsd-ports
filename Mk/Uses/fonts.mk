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

# Ports should use USES=fonts with an argument only when necessary.
# By default, @fcfontsdir ${FONTSDIR} is added and it updates font
# information cache file of fontconfig library, and XLFD entries
# in fonts.dir and fonts.scale file, which are directly used by
# X server and xfs font server.
#
# Xorg supports TrueType and OpenType via either of the two font
# subsystems.  @fcfontsdir is designed to update configuration files for
# both of them to register a font file.  Specifically, fc-cache and
# mkfontdir utilities are used, respectively.
#
# Ports to install fonts with which mkfontdir or fc-cache do not work well
# should use :fc and/or :fontsdir argument.  fc-cache and mkfontdir
# get information such as fontname, encoding, etc. from a font file.
# However, mkfontdir does not understand information in some scalable
# fonts.  Typical examples are TrueType Collection format and
# CJK (Chinese, Japanese, and Korean) TrueType font.  The former is
# a format which contains multiple fonts in a single file.
# While Xorg supports it, mkfontdir does not generate correct
# fonts.dir entries from a TTC font.  CJK fonts often require
# modifiers in a XFLD entry to enable special feature which mkfontdir
# does not support, either.
#
# Note that ports which do not want mkfontdir need to use
# a separate FONTSDIR, not shared ones such as misc or TTF.
# This is because other ports using @fcfontsdir or @fontsdir
# update fonts.dir in these font directories upon installation
# and deinstallation.  mkfontdir will overwrite manually-added entries.

.if !defined(_INCLUDE_USES_FONTS_MK)
_INCLUDE_USES_FONTS_MK=	yes

.if empty(fonts_ARGS)
fonts_ARGS=	fcfontsdir
.endif

.if !empty(fonts_ARGS:Nfc:Nfontsdir:Nfcfontsdir:Nnone)
IGNORE=	USES=fonts - invalid ARGS (${fonts_ARGS})
.endif

.if !empty(fonts_ARGS:Mfc) || !empty(fonts_ARGS:Mfcfontsdir)
RUN_DEPENDS+=	fc-cache:x11-fonts/fontconfig
.endif
.if !empty(fonts_ARGS:Mfontsdir) || !empty(fonts_ARGS:Mfcfontsdir)
RUN_DEPENDS+=	mkfontscale:x11-fonts/mkfontscale
.endif

FONTNAME?=	${PORTNAME}
FONTSDIR?=	${PREFIX}/share/fonts/${FONTNAME}
.if !empty(fonts_ARGS:Nnone)
PLIST_FILES+=	"@${fonts_ARGS} ${FONTSDIR}"
.endif
.if defined(FONTPATHSPEC) && !empty(FONTPATHSPEC)
FONTPATHD?=	${LOCALBASE}/etc/X11/fontpath.d
PLIST_FILES+=	"${FONTPATHD}/${FONTPATHSPEC}"
_USES_install+=	690:fonts-install-fontpathd
fonts-install-fontpathd:
	@${MKDIR} ${STAGEDIR}${FONTPATHD}
	${RLN} ${STAGEDIR}${FONTSDIR} ${STAGEDIR}${FONTPATHD}/${FONTPATHSPEC}
.endif
SUB_LIST+=	FONTSDIR="${FONTSDIR}"
PLIST_SUB+=	FONTSDIR="${FONTSDIR:S,^${PREFIX}/,,}"
.endif

