#-*- tab-width: 4; -*-
# ex:ts=4
#
# Date created:		12 Nov 2005
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#
# 4 column tabs prevent hair loss and tooth decay!

# ======================= USERS =================================
# To specify which gecko-based backend you prefer, use something like:
#
# WITH_GECKO=	libxul
#
# The valid backends are:
# libxul
#
# See below for more details.
# ======================= /USERS ================================

# bsd.gecko.mk abstracts the selection of gecko-based backends. It allows users
# and porters to support any available gecko backend without needing to build
# many conditional tests. ${USE_GECKO} is the list of backends that your port
# can handle, and ${GECKO} is set by bsd.gecko.mk to be the chosen backend.
# Users set ${WITH_GECKO} to the list of gecko backends they want on their
# system.

.if defined(USE_GECKO) && ${USE_GECKO}!="gecko"

.if !defined(Gecko_Pre_Include)
# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Gecko_Include_MAINTAINER=		gecko@FreeBSD.org
Gecko_Pre_Include=			bsd.gecko.mk

# Users should use the following syntax:
#
# WITH_GECKO= libxul
#  Use libxul whenever a port supports it
# WITH_GECKO= libxul
#  Sets your preferred backend. With this example, libxul will always
#  be chosen, unless the port doesn't support a libxul backend. In that
#  case, you get whatever the porter chose as the default. Better to use
#  the first example.
#
#
# Ports should use the following:
#
# USE_GECKO= libxul
#  The list of gecko backends that the port supports. Unless the user
#  overrides it with WITH_GECKO, the first gecko listed in USE_GECKO
#  will be the default.
#
# USE_GECKO= libxul19<->libxul
#  This will sed -e 's/libxul/libxul19/' on Makefile.in's and configure
#  if ${GECKO}=="libxul19"
#
#  Example:
#  USE_GECKO= libxul
#
#  post-patch:
#	@${REINPLACE_CMD} -e 's|mozilla-|${GECKO}-|' \
#		${MOZSRC}/configure
#
#  If you want your port to check the ${GECKO} variable to see which backend
#  has been chosen.
#
#  Example:
#  USE_GECKO= libxul
#
#  post-patch:
#  .if ${GECKO}=="libxul19"
#	@${REINPLACE_CMD} -e 's|mozilla-|libxul-|' \
#		${MOZSRC}/configure
#  .endif

_GECKO_ALL=	libxul

libxul_PLIST=		libxul>=24

.for gecko in ${_GECKO_ALL}
${gecko}_PORTSDIR?=	www
${gecko}_DEPENDS?=	${PORTSDIR}/${${gecko}_PORTSDIR}/${gecko}
${gecko}_PLIST?=	${LOCALBASE}/lib/${gecko}/libgtkembedmoz.so
.endfor

# Figure out which mozilla to use
# Weed out bad options in USE_GECKO
.for badgecko in ${USE_GECKO}
. if ${_GECKO_ALL:M${badgecko:C/^([^<->]+).*/\1/}}!=""
GOOD_USE_GECKO+=	${badgecko:C/^([^<->]+).*/\1/}
. endif
. if ${_GECKO_ALL:M${badgecko:C/^[^<->]+<->([^<->]+).*/\1/}}!="${badgecko:C/^([^<->]+).*/\1/}"
${badgecko:C/^([^<->]+).*/\1/}_HACK=	s:${badgecko:C/^[^<->]+<->([^<->]+).*/\1/}:${badgecko:C/^([^<->]+).*/\1/}:g
. endif
.endfor

.undef GECKO_FALLTHROUGH
.undef _FOUND_WITH_GECKO
# Figure out which gecko to use and weed out the bad ones
.if defined(WITH_GECKO) && defined(GOOD_USE_GECKO)
. for badgecko in ${WITH_GECKO}
.  if ${GOOD_USE_GECKO:M${badgecko}}!=""
GOOD_WITH_GECKO+=	${badgecko}
.  endif
. endfor
. if defined(GOOD_WITH_GECKO)
.  for gecko in ${GOOD_WITH_GECKO}
.   if !defined(GECKO_FALLTHROUGH)
GECKO=	${gecko}
GECKO_FALLTHROUGH=	${TRUE}
_FOUND_WITH_GECKO=	${TRUE}
.   endif
.  endfor
. endif
.endif

.if !defined(GECKO) && defined(GOOD_USE_GECKO)
. for gecko in ${GOOD_USE_GECKO}
.  if !defined(GECKO_FALLTRHOUGH)
GECKO=	${gecko}
GECKO_FALLTRHOUGH=	${TRUE}
.  endif
. endfor
.endif

# Generic defines
GECKO_CONFIG?=			${LOCALBASE}/bin/${GECKO}-config
XPIDL?=				${LOCALBASE}/lib/${GECKO}/xpidl
XPIDL_INCL?=			`${GECKO_CONFIG} --idlflags`

.if defined(GECKO) && ${_GECKO_ALL:M${GECKO}}!=""
BUILD_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
RUN_DEPENDS+=	${${GECKO}_PLIST}:${${GECKO}_DEPENDS}
.else
IGNORE=	Unable to find a supported gecko, please check USE_GECKO
.endif

pre-everything:: _gecko-pre-everything

_gecko-pre-everything::
	@${ECHO_CMD} ""
.if !defined(_FOUND_WITH_GECKO) && defined(WITH_GECKO)
	@${ECHO_CMD} " Warning: ${PORTNAME} does not support any gecko you"
	@${ECHO_CMD} " listed in WITH_GECKO=${WITH_GECKO}."
	@${ECHO_CMD} " \"${GECKO}\" will be used"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " for gecko support, but you can change that by using one of"
	@${ECHO_CMD} " the following values:"
.else
	@${ECHO_CMD} " ${PORTNAME} is using ${GECKO} for gecko support, but you can"
	@${ECHO_CMD} " change that by defining WITH_GECKO to the following values:"
.endif
	@${ECHO_CMD} ""
.for gecko in ${GOOD_USE_GECKO}
	@${ECHO_CMD} "   ${gecko} "
.endfor
	@${ECHO_CMD} ""

post-patch: gecko-post-patch

gecko-post-patch:
.if defined(${GECKO}_HACK)
	${FIND} ${WRKSRC} -name "Makefile.in" -type f -o -name "configure" -type f | \
		${XARGS} ${REINPLACE_CMD} -e ${${GECKO}_HACK}
.endif
.endif

.elif !defined(_POSTMKINCLUDED) && !defined(Gecko_Pre_Include) && (defined(USE_FIREFOX) || defined(USE_FIREFOX_BUILD) || defined(USE_SEAMONKEY) || defined(USE_SEAMONKEY_BUILD) || defined(USE_THUNDERBIRD) || defined(USE_THUNDERBIRD_BUILD))
Gecko_Pre_Include=			bsd.gecko.mk

# Ports can use the following:
#
# USE_FIREFOX             Add runtime dependency on Firefox. If no version
#                         is given by the maintainer via the port or by the
#                         user via defined variable try to find the highest
#                         stable installed version.
#                         Available values: yes 24+ 28+ 24 28
#                         NOTE:
#                         default value 24 is used in case of USE_FIREFOX=yes
#
# USE_FIREFOX_BUILD       Add buildtime dependency on Firefox.
#                         Available values: see USE_FIREFOX
#
# USE_SEAMONKEY           Add runtime dependency on SeaMonkey. If no
#                         version is given by the maintainer via the port
#                         or by the user via defined variable try to find
#                         the highest stable installed version.
#                         Available values: yes 25+ 25
#                         NOTE:
#                         default value 25 is used in case of USE_SEAMONKEY=yes
#
# USE_SEAMONKEY_BUILD     Add buildtime dependency on SeaMonkey.
#                         Available values: see USE_SEAMONKEY
#
# USE_THUNDERBIRD         Add runtime dependency on Thunderbird. If no
#                         version is given by the maintainer via the port
#                         or by the user via defined variable try to find
#                         the highest stable installed version.
#                         Available values: yes 24+ 24
#                         NOTE:
#                         default value 24 is used in case of USE_THUNDERBIRD=yes
#
# USE_THUNDERBIRD_BUILD   Add buildtime dependency on Thunderbird.
#                         Available values: see USE_THUNDERBIRD
#

#
# Firefox part
#
.if defined(USE_FIREFOX) || defined(USE_FIREFOX_BUILD)

# Process USE_FIREFOX_BUILD
.if defined(USE_FIREFOX_BUILD)
USE_FIREFOX:=				${USE_FIREFOX_BUILD}
_FIREFOX_BUILD_DEPENDS=		yes
.endif

_FIREFOX_DEFAULT_VERSION=	24
_FIREFOX_VERSIONS=			24 28
_FIREFOX_RANGE_VERSIONS=	24+ 28+

# For specifying [24, ..]+
_FIREFOX_28P=	28 ${_FIREFOX_24P}
_FIREFOX_24P=	24

# Set the default Firefox version and check if USE_FIREFOX=yes was given
.if ${USE_FIREFOX} == "yes"
USE_FIREFOX=	${_FIREFOX_DEFAULT_VERSION}
.endif

# Setting/finding Firefox version we want.
.if exists(${LOCALBASE}/bin/firefox)
_FIREFOX_VER!=	${LOCALBASE}/bin/firefox --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/Mozilla Firefox \([0-9]\{1,2\}\)\.\([0-9]*\).*/\1/'
.endif

# Check if installed Firefox version matches the wanted one
.if defined(_FIREFOX_VER)
_SUPFIREFOX=		no
.if ${USE_FIREFOX:C/[0-9][0-9]//} == "+"
.for ver in ${_FIREFOX_RANGE_VERSIONS}
.if ${USE_FIREFOX} == "${ver}"
_MATCHED_FIREFOX_VER:=	${ver:S/+//}
.for firefox in ${_FIREFOX_${_MATCHED_FIREFOX_VER}P}
.if ${_FIREFOX_VER} == ${firefox}
_SUPFIREFOX=		yes
USE_FIREFOX=		${_FIREFOX_VER}
.endif
.endfor
.endif
.endfor
.else
.if ${_FIREFOX_VER} == ${USE_FIREFOX}
_SUPFIREFOX=		yes
.endif
.endif
.if ${_SUPFIREFOX} == no
_DISPLAY_VERSION_HAVE= ${_FIREFOX_VER}
_DISPLAY_VERSION_WANT= ${USE_FIREFOX}

IGNORE=			cannot install: Firefox versions mismatch: firefox-${_DISPLAY_VERSION_HAVE} is installed and wanted version is firefox-${_DISPLAY_VERSION_WANT}
.endif
.endif

.if !defined(_FIREFOX_${USE_FIREFOX:S/+//}P)
IGNORE=			cannot install: unknown Firefox version: firefox-${USE_FIREFOX:C/([0-9])([0-9])/\1.\2/}
.endif

# Dependence lines for different Firefox versions
24_DEPENDS=		${LOCALBASE}/lib/firefox/firefox:${PORTSDIR}/www/firefox-esr
28_DEPENDS=		${LOCALBASE}/lib/firefox/firefox:${PORTSDIR}/www/firefox

# Add dependencies
.if defined(USE_FIREFOX)
.if defined(_FIREFOX_BUILD_DEPENDS)
BUILD_DEPENDS+= ${${USE_FIREFOX}_DEPENDS}
.endif
RUN_DEPENDS+=	${${USE_FIREFOX}_DEPENDS}
.endif

.endif # defined(USE_FIREFOX)
#
# SeaMonkey part
#
.if defined(USE_SEAMONKEY) || defined(USE_SEAMONKEY_BUILD)

# Process USE_SEAMONKEY_BUILD
.if defined(USE_SEAMONKEY_BUILD)
USE_SEAMONKEY:=				${USE_SEAMONKEY_BUILD}
_SEAMONKEY_BUILD_DEPENDS=	yes
.endif

_SEAMONKEY_DEFAULT_VERSION=	25
_SEAMONKEY_VERSIONS=		25
_SEAMONKEY_RANGE_VERSIONS=	25+

# For specifying [25, ..]+
_SEAMONKEY_25P=	25

# Set the default SeaMonkey version and check if USE_SEAMONKEY=yes was given
.if ${USE_SEAMONKEY} == "yes"
USE_SEAMONKEY=	${_SEAMONKEY_DEFAULT_VERSION}
.endif

# Setting/finding SeaMonkey version we want.
.if exists(${LOCALBASE}/bin/seamonkey)
_SEAMONKEY_VER!=	${LOCALBASE}/bin/seamonkey --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/Mozilla SeaMonkey \([0-9]\{1,2\}\)\.\([0-9]*\).*/\2/'
.endif

# Check if installed SeaMonkey version matches the wanted one
.if defined(_SEAMONKEY_VER)
_SUPSEAMONKEY=		no
.if ${USE_SEAMONKEY:C/[0-9][0-9]//} == "+"
.for ver in ${_SEAMONKEY_RANGE_VERSIONS}
.if ${USE_SEAMONKEY} == "${ver}"
_MATCHED_SEAMONKEY_VER:=	${ver:S/+//}
.for seamonkey in ${_SEAMONKEY_${_MATCHED_SEAMONKEY_VER}P}
.if ${_SEAMONKEY_VER} == ${seamonkey}
_SUPSEAMONKEY=		yes
USE_SEAMONKEY=		${_SEAMONKEY_VER}
.endif
.endfor
.endif
.endfor
.else
.if ${_SEAMONKEY_VER} == ${USE_SEAMONKEY}
_SUPSEAMONKEY=		yes
.endif
.endif
.if ${_SUPSEAMONKEY} == no
IGNORE=			cannot install: SeaMonkey versions mismatch: seamonkey-2.${_SEAMONKEY_VER} is installed and wanted version is seamonkey-2.${USE_SEAMONKEY}
.endif
.endif

.if !defined(_SEAMONKEY_${USE_SEAMONKEY:S/+//}P)
IGNORE=			cannot install: unknown SeaMonkey version: seamonkey-2.${USE_SEAMONKEY}
.endif

# Dependence lines for different SeaMonkey versions
25_DEPENDS=		${LOCALBASE}/lib/seamonkey/seamonkey:${PORTSDIR}/www/seamonkey

# Add dependencies
.if defined(USE_SEAMONKEY)
.if defined(_SEAMONKEY_BUILD_DEPENDS)
BUILD_DEPENDS+= ${${USE_SEAMONKEY}_DEPENDS}
.endif
RUN_DEPENDS+=	${${USE_SEAMONKEY}_DEPENDS}
.endif

.endif # defined(USE_SEAMONKEY)
#
# Thunderbird part
#
.if defined(USE_THUNDERBIRD) || defined(USE_THUNDERBIRD_BUILD)

# Process USE_THUNDERBIRD_BUILD
.if defined(USE_THUNDERBIRD_BUILD)
USE_THUNDERBIRD:=			${USE_THUNDERBIRD_BUILD}
_THUNDERBIRD_BUILD_DEPENDS=		yes
.endif

_THUNDERBIRD_DEFAULT_VERSION=	24
_THUNDERBIRD_VERSIONS=			24
_THUNDERBIRD_RANGE_VERSIONS=	24+

# For specifying [24, ..]+
_THUNDERBIRD_24P=	24

# Set the default Thunderbird version and check if USE_THUNDERBIRD=yes was given
.if ${USE_THUNDERBIRD} == "yes"
USE_THUNDERBIRD=	${_THUNDERBIRD_DEFAULT_VERSION}
.endif

# Setting/finding Thunderbird version we want.
.if exists(${LOCALBASE}/bin/thunderbird)
_THUNDERBIRD_VER!=	${LOCALBASE}/bin/thunderbird --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/ Thunderbird \([0-9]\{1,2\}\)\.\([0-9]*\).*/\1/'
.endif

# Check if installed Thunderbird version matches the wanted one
.if defined(_THUNDERBIRD_VER)
_SUPTHUNDERBIRD=		no
.if ${USE_THUNDERBIRD:C/[0-9][0-9]//} == "+"
.for ver in ${_THUNDERBIRD_RANGE_VERSIONS}
.if ${USE_THUNDERBIRD} == "${ver}"
_MATCHED_THUNDERBIRD_VER:=	${ver:S/+//}
.for thunderbird in ${_THUNDERBIRD_${_MATCHED_THUNDERBIRD_VER}P}
.if ${_THUNDERBIRD_VER} == ${thunderbird}
_SUPTHUNDERBIRD=		yes
USE_THUNDERBIRD=		${_THUNDERBIRD_VER}
.endif
.endfor
.endif
.endfor
.else
.if ${_THUNDERBIRD_VER} == ${USE_THUNDERBIRD}
_SUPTHUNDERBIRD=		yes
.endif
.endif
.if ${_SUPTHUNDERBIRD} != yes
_DISPLAY_VERSION_HAVE= ${_THUNDERBIRD_VER}
_DISPLAY_VERSION_WANT= ${USE_THUNDERBIRD}
IGNORE=			cannot install: Thunderbird versions mismatch: thunderbird-${_DISPLAY_VERSION_HAVE} is installed and wanted version is thunderbird-${_DISPLAY_VERSION_WANT}
.endif
.endif

.if !defined(_THUNDERBIRD_${USE_THUNDERBIRD:S/+//}P)
IGNORE=			cannot install: unknown Thunderbird version: thunderbird-${USE_THUNDERBIRD:C/([0-9])([0-9])/\1.\2/}
.endif

# Dependence lines for different Thunderbird versions
24_DEPENDS=		${LOCALBASE}/lib/thunderbird/thunderbird:${PORTSDIR}/mail/thunderbird

# Add dependencies
.if defined(USE_THUNDERBIRD)
.if defined(_THUNDERBIRD_BUILD_DEPENDS)
BUILD_DEPENDS+= ${${USE_THUNDERBIRD}_DEPENDS}
.endif
RUN_DEPENDS+=	${${USE_THUNDERBIRD}_DEPENDS}
.endif

.endif # defined(USE_THUNDERBIRD)

.else # split

.if !defined(_POSTMKINCLUDED) && !defined(Gecko_Pre_Include)
Gecko_Pre_Include=	bsd.gecko.mk

# This file contains some reusable components for mozilla ports. It's of
# use primarily to apps from the mozilla project itself (such as Firefox,
# Thunderbird, etc.), and probably won't be of use for gecko-based ports
# like epiphany, galeon, etc.
#
# You need to make sure to add USE_GECKO=gecko to for your port can uses
# one of these options below.
#
# Ports can use the following:
#
# USE_MOZILLA			By default, it enables every system dependency
# 						listed in '_ALL_DEPENDS'. If your port doesn't
# 						need one of those then you can use '-' like
# 						'USE_MOZILLA= -png -vpx' to subtract the
# 						dependencies.
#
# GECKO_PLIST_PRE_FILES	Manual add files in the plist if it needs.
#
# GECKO_PLIST_PRE_DIRS  Manual directories in the plist if it needs.
#
# MOZILLA_PLIST_DIRS	List of directories to descend into when installing
# 						and creating the plist
#
# MOZ_PIS_SCRIPTS		List of scripts residing in ${FILESDIR} to be
# 						filtered through MOZCONFIG_SED and installed along
# 						with our Pluggable Init Scripts (PIS)
#
# MOZ_SED_ARGS			sed(1) commands through which MOZ_PIS_SCRIPTS are
# 						filtered. There is a default set defined here, so
# 						you probably want to add to MOZ_SED_ARGS rather
# 						than clobber it
#
# MOZ_OPTIONS			configure arguments (added to .mozconfig). If
# 						NOMOZCONFIG is defined, you probably want to set
# 						CONFIGURE_ARGS+=${MOZ_OPTIONS}
#
# MOZ_MK_OPTIONS		The make(1) arguments (added to .mozconfig). If
# 						NOMOZCONFIG is defined, you probably want to set
# 						MAKE_ARGS+=${MOZ_MK_OPTIONS}
#
# MOZ_EXPORT			Environment variables for the build process (added
# 						to .mozconfig). If NOMOZCONFIG is defined, you
# 						probably want to set MAKE_ENV+=${MOZ_EXPORT}
#
# MOZ_CHROME			A variable for the --enable-chrome-format= in
# 						CONFIGURE_ARGS. The default is omni.
#
# MOZ_TOOLKIT			A variable for the --enable-default-toolkit= in
# 						CONFIGURE_ARGS. The default is cairo-gtk2.
#
# MOZ_EXTENSIONS		A list of extensions to build
#
# MOZ_PROTOCOLS			A list of protocols to build (http, ftp, etc.)
#
# PORT_MOZCONFIG		Defaults to ${FILESDIR}/mozconfig.in, but can be
# 						set to a generic mozconfig included with the port
#
# NOGECKO_INSTALL		Don't install the built gecko (most likely for
# 						testing)
#
# NOGECKO_PLIST			Don't create a dynamically-generated playlist
#
# NOMOZCONFIG			Don't drop a customized .mozconfig into the build
# 						directory. Options will have to be specified in
# 						CONFIGURE_ARGS instead
#

MAINTAINER?=	gecko@FreeBSD.org

MOZILLA?=	${PORTNAME}
MOZILLA_VER?=	${PORTVERSION}
MOZILLA_BIN?=	${PORTNAME}-bin
MOZILLA_EXEC_NAME?=${MOZILLA}
MOZ_RPATH?=	${MOZILLA}
USE_GNOME+=	desktopfileutils
USES+=		compiler:c++11-lib gmake iconv perl5 pkgconfig
USE_PERL5=	build
USE_XORG=	xext xrender xt

NO_STAGE=	yes

MOZILLA_SUFX?=	none
MOZSRC?=	${WRKSRC}
WRKSRC?=	${WRKDIR}/mozilla
FAKEDIR?=	${WRKDIR}/fake
PLIST?=		${WRKDIR}/plist
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files

MOZ_PIS_DIR?=		lib/${MOZILLA}/init.d

PORT_MOZCONFIG?=	${FILESDIR}/mozconfig.in
MOZCONFIG?=		${WRKSRC}/.mozconfig
MOZILLA_PLIST_DIRS?=	bin lib
PKGINSTALL?=	${WRKDIR}/pkg-install
PKGDEINSTALL?=	${WRKDIR}/pkg-deinstall
PKGINSTALL_INC?=	${.CURDIR}/../../www/firefox/files/pkg-install.in
PKGDEINSTALL_INC?=	${.CURDIR}/../../www/firefox/files/pkg-deinstall.in

EXTRACT_AFTER_ARGS?=	--exclude */CVS/*	\
			--exclude */macbuild/*			\
			--exclude */package/*			\
			--exclude mozilla*/gc/boehm

MOZ_PKGCONFIG_FILES?=	${MOZILLA}-gtkmozembed ${MOZILLA}-js \
			${MOZILLA}-xpcom ${MOZILLA}-plugin

MOZ_EXPORT+=	${CONFIGURE_ENV} \
				LIBS="${LIBS}" PERL="${PERL}"
MOZ_OPTIONS+=	--prefix="${FAKEDIR}"

CPPFLAGS+=		-isystem${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,-rpath,${PREFIX}/lib/${MOZILLA}

# use jemalloc 3.0.0 API for stats/tuning
MOZ_EXPORT+=	MOZ_JEMALLOC3=1
.if ${OSVERSION} < 1000012
MOZ_OPTIONS+=	--enable-jemalloc
.endif

# Standard depends
_ALL_DEPENDS=	cairo event ffi harfbuzz hunspell icu jpeg nspr nss opus png pixman sqlite vorbis vpx

cairo_LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo
cairo_MOZ_OPTIONS=	--enable-system-cairo
cairo_EXTRACT_AFTER_ARGS=	--exclude mozilla*/gfx/cairo/cairo

event_LIB_DEPENDS=	libevent-2.0.so:${PORTSDIR}/devel/libevent2
event_MOZ_OPTIONS=	--with-system-libevent
event_EXTRACT_AFTER_ARGS=	--exclude mozilla*/ipc/chromium/src/third_party/libevent

ffi_LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi
ffi_MOZ_OPTIONS=	--enable-system-ffi
ffi_EXTRACT_AFTER_ARGS=	--exclude mozilla*/js/src/ctypes/libffi

.if exists(${FILESDIR}/patch-bug847568) || exists(${FILESDIR}/patch-z-bug847568)
harfbuzz_LIB_DEPENDS=	libharfbuzz.so:${PORTSDIR}/print/harfbuzz
harfbuzz_MOZ_OPTIONS=	--with-system-harfbuzz --with-system-graphite2
harfbuzz_EXTRACT_AFTER_ARGS=	--exclude mozilla*/gfx/harfbuzz \
								--exclude mozilla*/gfx/graphite2
.endif

hunspell_LIB_DEPENDS=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell
hunspell_MOZ_OPTIONS=	--enable-system-hunspell

icu_LIB_DEPENDS=		libicui18n.so:${PORTSDIR}/devel/icu
icu_MOZ_OPTIONS=		--with-system-icu --with-intl-api --enable-intl-api

-jpeg_BUILD_DEPENDS=yasm:${PORTSDIR}/devel/yasm
# XXX depends on ports/180159 or package flavor support
#jpeg_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/libjpeg-turbo
jpeg_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
jpeg_MOZ_OPTIONS=	--with-system-jpeg=${LOCALBASE}
jpeg_EXTRACT_AFTER_ARGS=	--exclude mozilla*/media/libjpeg

nspr_LIB_DEPENDS=	libnspr4.so:${PORTSDIR}/devel/nspr
nspr_MOZ_OPTIONS=	--with-system-nspr

nss_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss
nss_MOZ_OPTIONS=	--with-system-nss
nss_EXTRACT_AFTER_ARGS=	--exclude mozilla*/dbm \
						--exclude mozilla*/security/coreconf \
						--exclude mozilla*/security/nss

.if exists(${FILESDIR}/patch-z-bug517422) || exists(${FILESDIR}/patch-zz-bug517422)
opus_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus
opus_MOZ_OPTIONS=	--with-system-opus
opus_EXTRACT_AFTER_ARGS=	--exclude mozilla*/media/libopus
.endif

pixman_LIB_DEPENDS=	libpixman-1.so:${PORTSDIR}/x11/pixman
pixman_MOZ_OPTIONS=	--enable-system-pixman
pixman_EXTRACT_AFTER_ARGS=	--exclude mozilla*/gfx/cairo/libpixman

png_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
png_MOZ_OPTIONS=	--with-system-png=${LOCALBASE}
png_EXTRACT_AFTER_ARGS=	--exclude mozilla*/media/libpng

sqlite_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
sqlite_MOZ_OPTIONS=	--enable-system-sqlite
sqlite_EXTRACT_AFTER_ARGS=	--exclude mozilla*/db/sqlite3

.if exists(${FILESDIR}/patch-z-bug517422) || exists(${FILESDIR}/patch-zz-bug517422)
vorbis_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
vorbis_MOZ_OPTIONS=	--with-system-vorbis --with-system-ogg
vorbis_EXTRACT_AFTER_ARGS=	--exclude mozilla*/media/libvorbis \
							--exclude mozilla*/media/libogg
.endif

-vpx_BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
vpx_LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx
vpx_MOZ_OPTIONS=	--with-system-libvpx
vpx_EXTRACT_AFTER_ARGS=	--exclude mozilla*/media/libvpx

.for use in ${USE_MOZILLA}
${use:S/-/_WITHOUT_/}=	${TRUE}
.endfor

.for dep in ${_ALL_DEPENDS}
.if !defined(_WITHOUT_${dep})
BUILD_DEPENDS+=	${${dep}_BUILD_DEPENDS}
LIB_DEPENDS+=	${${dep}_LIB_DEPENDS}
RUN_DEPENDS+=	${${dep}_RUN_DEPENDS}
MOZ_OPTIONS+=	${${dep}_MOZ_OPTIONS}
EXTRACT_AFTER_ARGS+=	${${dep}_EXTRACT_AFTER_ARGS}
.else
BUILD_DEPENDS+=	${-${dep}_BUILD_DEPENDS}
.endif
.endfor

# Standard options
MOZ_CHROME?=	omni
MOZ_TOOLKIT?=	cairo-gtk2
MOZ_OPTIONS+=	\
		--enable-chrome-format=${MOZ_CHROME} \
		--enable-default-toolkit=${MOZ_TOOLKIT} \
		--with-pthreads
# Configure options for install
.if !defined(MOZ_EXTENSIONS)
MOZ_OPTIONS+=	--enable-extensions=default
.else
MOZ_OPTIONS+=	--enable-extensions=${MOZ_EXTENSIONS}
.endif
.if !defined(MOZ_PROTOCOLS)
MOZ_OPTIONS+=	--enable-necko-protocols=default
.else
MOZ_OPTIONS+=	--enable-necko-protocols=${MOZ_PROTOCOLS}
.endif
# others
MOZ_OPTIONS+=	--with-system-zlib		\
		--with-system-bz2		\
		--enable-unified-compilation	\
		--disable-debug-symbols		\
		--disable-glibtest		\
		--disable-gtktest		\
		--disable-freetypetest		\
		--disable-installer		\
		--disable-updater		\
		--disable-pedantic

# XXX stolen from www/chromium
MOZ_EXPORT+=	MOZ_GOOGLE_API_KEY=AIzaSyBsp9n41JLW8jCokwn7vhoaMejDFRd1mp8

.if ${PORT_OPTIONS:MGTK3}
MOZ_TOOLKIT=	cairo-gtk3
.endif

.if ${MOZ_TOOLKIT:Mcairo-qt}
# don't use - transparent backgrounds (bug 521582),
USE_MOZILLA+=	-cairo # ports/169343
USE_DISPLAY=yes # install
USE_GNOME+=	pango
. if ${MOZILLA_VER:R:R} >= 30
USE_QT5+=	qmake_build buildtools_build gui network quick printsupport
. else
USE_QT4+=	qmake_build moc_build rcc_build gui network opengl
. endif
MOZ_EXPORT+=	HOST_QMAKE="${QMAKE}" HOST_MOC="${MOC}" HOST_RCC="${RCC}"
.elif ${MOZ_TOOLKIT:Mcairo-gtk3}
USE_GNOME+=	gtk30
.else # gtk2, cairo-gtk2
USE_GNOME+=	gtk20
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=		-O3
MOZ_EXPORT+=	MOZ_OPTIMIZE_FLAGS="${CFLAGS:M-O*}"
MOZ_OPTIONS+=	--enable-optimize
.else
MOZ_OPTIONS+=	--disable-optimize
.endif

.if ${PORT_OPTIONS:MDBUS}
BUILD_DEPENDS+=	libnotify>0:${PORTSDIR}/devel/libnotify
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
				libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
MOZ_OPTIONS+=	--enable-startup-notification
.else
MOZ_OPTIONS+=	--disable-dbus --disable-libnotify
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
. if ${MOZILLA_VER:R:R} >= 30 || exists(${FILESDIR}/patch-bug806917)
USE_GSTREAMER1?=good libav
MOZ_OPTIONS+=	--enable-gstreamer=1.0
. else
USE_GSTREAMER?=	good ffmpeg
MOZ_OPTIONS+=	--enable-gstreamer
. endif
.else
MOZ_OPTIONS+=	--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MGCONF}
BUILD_DEPENDS+=	${gconf2_DETECT}:${gconf2_LIB_DEPENDS:C/.*://}
USE_GNOME+=		gconf2:build
MOZ_OPTIONS+=	--enable-gconf
.else
MOZ_OPTIONS+=	--disable-gconf
.endif

.if ${PORT_OPTIONS:MGIO} && ! ${MOZ_TOOLKIT:Mcairo-qt}
MOZ_OPTIONS+=	--enable-gio
.else
MOZ_OPTIONS+=	--disable-gio
.endif

.if ${PORT_OPTIONS:MGNOMEUI}
BUILD_DEPENDS+=	${libgnomeui_DETECT}:${libgnomeui_LIB_DEPENDS:C/.*://}
USE_GNOME+=		libgnomeui:build
MOZ_OPTIONS+=	--enable-gnomeui
.else
MOZ_OPTIONS+=	--disable-gnomeui
.endif

.if ${PORT_OPTIONS:MGNOMEVFS2}
BUILD_DEPENDS+=	${gnomevfs2_DETECT}:${gnomevfs2_LIB_DEPENDS:C/.*://}
USE_GNOME+=		gnomevfs2:build
MOZ_OPTIONS+=	--enable-gnomevfs
MOZ_OPTIONS:=	${MOZ_OPTIONS:C/(extensions)=(.*)/\1=\2,gnomevfs/}
.else
MOZ_OPTIONS+=	--disable-gnomevfs
.endif

.if ${PORT_OPTIONS:MLIBPROXY}
LIB_DEPENDS+=	libproxy.so:${PORTSDIR}/net/libproxy
MOZ_OPTIONS+=	--enable-libproxy
.else
MOZ_OPTIONS+=	--disable-libproxy
.endif

.if ${PORT_OPTIONS:MPGO}
USE_GCC?=	yes
USE_DISPLAY=yes

.undef GNU_CONFIGURE
MAKEFILE=	${WRKSRC}/client.mk
ALL_TARGET=	profiledbuild
MOZ_EXPORT+=MOZ_OPTIMIZE_FLAGS="-Os" MOZ_PGO_OPTIMIZE_FLAGS="${CFLAGS:M-O*}"
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
MOZ_OPTIONS+=	--enable-alsa
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
BUILD_DEPENDS+=	pulseaudio>0:${PORTSDIR}/audio/pulseaudio
MOZ_OPTIONS+=	--enable-pulseaudio
.else
MOZ_OPTIONS+=	--disable-pulseaudio
.endif

.if ${PORT_OPTIONS:MDEBUG}
MOZ_OPTIONS+=	--enable-debug --disable-release
STRIP=	# ports/184285
.else
MOZ_OPTIONS+=	--disable-debug --enable-release
.endif

.if ${PORT_OPTIONS:MLOGGING} || ${PORT_OPTIONS:MDEBUG}
MOZ_OPTIONS+=	--enable-logging
.else
MOZ_OPTIONS+=	--disable-logging
.endif

.if ${PORT_OPTIONS:MPROFILE}
MOZ_OPTIONS+=	--enable-profiling
STRIP=
.else
MOZ_OPTIONS+=	--disable-profiling
.endif

.if ${PORT_OPTIONS:MTEST}
USE_XORG+=		xscrnsaver
MOZ_OPTIONS+=	--enable-tests
.else
MOZ_OPTIONS+=	--disable-tests
.endif

.if !defined(STRIP) || ${STRIP} == ""
MOZ_OPTIONS+=	--disable-strip --disable-install-strip
.else
MOZ_OPTIONS+=	--enable-strip --enable-install-strip
.endif

MOZ_SED_ARGS+=	-e's|@CPPFLAGS@|${CPPFLAGS}|g'		\
		-e 's|@CFLAGS@|${CFLAGS}|g'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|g'		\
		-e 's|@LIBS@|${LIBS}|g'			\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		-e 's|@FAKEDIR@|${FAKEDIR}|g'		\
		-e 's|@PERL@|${PERL5}|g'			\
		-e 's|@MOZDIR@|${PREFIX}/lib/${MOZILLA}|g'	\
		-e 's|%%PREFIX%%|${PREFIX}|g'		\
		-e 's|%%CFLAGS%%|${CFLAGS}|g'		\
		-e 's|%%LDFLAGS%%|${LDFLAGS}|g'		\
		-e 's|%%LIBS%%|${LIBS}|g'		\
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g'	\
		-e 's|%%FAKEDIR%%|${FAKEDIR}|g'		\
		-e 's|%%PERL%%|${PERL5}|g'		\
		-e 's|%%MOZILLA%%|${MOZILLA}|g'		\
		-e 's|%%MOZILLA_BIN%%|${MOZILLA_BIN}|g'	\
		-e 's|%%MOZDIR%%|${PREFIX}/lib/${MOZILLA}|g'
MOZCONFIG_SED?= ${SED} ${MOZ_SED_ARGS}

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-unknown-${OPSYS:L}${OSREL}
. if ${USE_MOZILLA:M-nss}
USE_BINUTILS=	# intel-gcm.s
CFLAGS+=	-B${LOCALBASE}/bin
LDFLAGS+=	-B${LOCALBASE}/bin
.  if ${OSVERSION} < 1000041 && exists(/usr/lib/libcxxrt.so) && \
	${CXXFLAGS:M-stdlib=libc++}
LIBS+=		-lcxxrt
.  endif
. endif
.elif ${ARCH:Mpowerpc*}
USE_GCC?=	yes
CFLAGS+=	-D__STDC_CONSTANT_MACROS
. if ${ARCH} == "powerpc64"
MOZ_EXPORT+=	UNAME_m="${ARCH}"
CFLAGS+=	-mminimal-toc
. endif
.elif ${ARCH} == "sparc64"
# Work around miscompilation/mislinkage of the sCanonicalVTable hacks.
MOZ_OPTIONS+=	--disable-v1-string-abi
.endif

.if defined(OBJDIR_BUILD)
CONFIGURE_SCRIPT=../configure

MOZ_OBJDIR=		${WRKSRC}/obj-${CONFIGURE_TARGET}
CONFIGURE_WRKSRC=${MOZ_OBJDIR}
BUILD_WRKSRC=	${MOZ_OBJDIR}
INSTALL_WRKSRC=	${MOZ_OBJDIR}
.else
MOZ_OBJDIR=		${WRKSRC}
.endif

.else # bsd.port.post.mk

pre-extract: gecko-pre-extract

gecko-pre-extract:
.if ${PORT_OPTIONS:MPGO}
	@${ECHO} "*****************************************************************"
	@${ECHO} "**************************** attention **************************"
	@${ECHO} "*****************************************************************"
	@${ECHO} "To build ${MOZILLA} with PGO support you need a running X server and"
	@${ECHO} "   build this port with an user who could access the X server!   "
	@${ECHO} ""
	@${ECHO} "During the build a ${MOZILLA} instance will start and run some test."
	@${ECHO} "      Do not interrupt or close ${MOZILLA} during this tests!       "
	@${ECHO} "*****************************************************************"
	@sleep 10
.endif

post-patch: gecko-post-patch gecko-moz-pis-patch

gecko-post-patch:
.if exists(${PKGINSTALL_INC})
	@${MOZCONFIG_SED} < ${PKGINSTALL_INC} > ${PKGINSTALL}
.endif
.if exists(${PKGDEINSTALL_INC})
	@${MOZCONFIG_SED} < ${PKGDEINSTALL_INC} > ${PKGDEINSTALL}
.endif
	@${RM} -f ${MOZCONFIG}
.if !defined(NOMOZCONFIG)
	@if [ -e ${PORT_MOZCONFIG} ] ; then \
		${MOZCONFIG_SED} < ${PORT_MOZCONFIG} >> ${MOZCONFIG} ; \
	fi
.for arg in ${MOZ_OPTIONS}
	@${ECHO_CMD} ac_add_options ${arg:Q} >> ${MOZCONFIG}
.endfor
.for arg in ${MOZ_MK_OPTIONS}
	@${ECHO_CMD} mk_add_options ${arg:Q} >> ${MOZCONFIG}
.endfor
.for var in ${MOZ_EXPORT}
	@${ECHO_CMD} export ${var:Q} >> ${MOZCONFIG}
.endfor
.endif # .if !defined(NOMOZCONFIG)
.if exists(${MOZSRC}/build/unix/mozilla-config.in)
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g ; \
		s|"%FULL_NSPR_CFLAGS%"|`nspr-config --cflags`|g ; \
		s|"%FULL_NSPR_LIBS%"|`nspr-config --libs`|g' \
			${MOZSRC}/build/unix/mozilla-config.in
.endif
.if ${USE_MOZILLA:M-nspr}
	@${ECHO_MSG} "===>  Applying NSPR patches"
	@for i in ${.CURDIR}/../../devel/nspr/files/patch-*; do \
		${PATCH} ${PATCH_ARGS} -d ${MOZSRC}/nsprpub/build < $$i; \
	done
.endif
.if ${USE_MOZILLA:M-nss}
	@${ECHO_MSG} "===>  Applying NSS patches"
	@for i in ${.CURDIR}/../../security/nss/files/patch-*; do \
		${PATCH} ${PATCH_ARGS} -d ${MOZSRC}/security/nss < $$i; \
	done
.endif
	@for f in \
			${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
			${WRKSRC}/directory/c-sdk/configure \
			${MOZSRC}/security/coreconf/FreeBSD.mk \
			${MOZSRC}/js/src/Makefile.in \
			${MOZSRC}/js/src/configure \
			${MOZSRC}/configure \
			${WRKSRC}/configure; do \
		if [ -f $$f ] ; then \
			${REINPLACE_CMD} -Ee 's|-lc_r|${PTHREAD_LIBS}|g ; \
				s|-l?pthread|${PTHREAD_LIBS}|g ; \
				s|echo aout|echo elf|g ; \
				s|/usr/X11R6|${LOCALBASE}|g' \
				$$f; \
		fi; \
	done
	@if [ -f ${WRKSRC}/config/baseconfig.mk ] ; then \
		${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
			${WRKSRC}/config/baseconfig.mk; \
	else \
		${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
			${WRKSRC}/config/autoconf.mk.in; \
	fi
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
			${MOZSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -e 's|/usr/local/netscape|${LOCALBASE}|g ; \
		s|/usr/local/lib/netscape|${LOCALBASE}/lib|g' \
		${MOZSRC}/xpcom/io/SpecialSystemDirectory.cpp
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|g' \
		${MOZSRC}/xpcom/build/nsXPCOMPrivate.h
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|mozilla/plugins|browser_plugins|g' \
		-e 's|share/mozilla/extensions|lib/xpi|g' \
		${MOZSRC}/xpcom/io/nsAppFileLocationProvider.cpp \
		${MOZSRC}/toolkit/xre/nsXREDirProvider.cpp
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${MOZSRC}/extensions/spellcheck/hunspell/src/mozHunspell.cpp

# handles mozilla pis scripts.
gecko-moz-pis-patch:
.for moz in ${MOZ_PIS_SCRIPTS}
	@${MOZCONFIG_SED} < ${FILESDIR}/${moz} > ${WRKDIR}/${moz}
.endfor

pre-configure: gecko-pre-configure

gecko-pre-configure:
.if defined(OBJDIR_BUILD)
	${MKDIR} ${MOZ_OBJDIR}
.endif

post-configure: gecko-post-configure

gecko-post-configure:
	@${ECHO_CMD} "#define JNIIMPORT" >> ${MOZSRC}/mozilla-config.h

pre-install: gecko-moz-pis-pre-install gecko-pre-install port-pre-install gecko-create-plist

.if !target(port-pre-install)
port-pre-install:
		@${DO_NADA}
.endif

gecko-pre-install:
.if !defined(NOGECKO_PLIST)
	@${RM} -rf ${FAKEDIR} ${PLIST} ${PLISTD} ${PLISTF}
	@${TOUCH} -f ${PLIST} ${PLISTD} ${PLISTF}
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} prefix=${FAKEDIR} ${INSTALL_TARGET}
.if defined(MOZILLA_SUFX) && ${MOZILLA_SUFX}!="none"
	${MV} ${FAKEDIR}/bin/${MOZILLA_EXEC_NAME:S/${MOZILLA_SUFX}//} ${FAKEDIR}/bin/${MOZILLA}
.if exists(${FAKEDIR}/bin/${MOZILLA_EXEC_NAME:S/${MOZILLA_SUFX}//}-config)
	${MV} ${FAKEDIR}/bin/${MOZILLA_EXEC_NAME:S/${MOZILLA_SUFX}//}-config ${FAKEDIR}/bin/${MOZILLA}-config
.endif
.for pc in ${MOZ_PKGCONFIG_FILES:S|${MOZILLA_SUFX}||}
	${SED} -e 's|Requires: ${MOZILLA:S/${MOZILLA_SUFX}//}|Requires: ${MOZILLA}|' \
	${FAKEDIR}/lib/pkgconfig/${pc}.pc > ${FAKEDIR}/lib/pkgconfig/${pc:S/${MOZILLA:S,${MOZILLA_SUFX},,}/${MOZILLA}/}.pc
.endfor
	@${REINPLACE_CMD} -e 's|${MOZILLA_BIN}|${MOZILLA:S/${MOZILLA_SUFX}//}|; \
		s|$${progbase}-bin|${MOZILLA:S/${MOZILLA_SUFX}//}-bin|' \
		-e 's|${FAKEDIR}|${PREFIX}|g' \
		-i '' $$(${REALPATH} ${FAKEDIR}/bin/${MOZILLA}*)
.else
	@${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
		-i '' $$(${REALPATH} ${FAKEDIR}/bin/${MOZILLA_EXEC_NAME}*)
.endif
.endif

gecko-create-plist:
.if !defined(NOGECKO_PLIST)
# Create the plist
.for f in ${GECKO_PLIST_PRE_FILES}
	${ECHO_CMD} ${f} >> ${PLISTF}
.endfor
.for f in ${GECKO_PLIST_PRE_DIRS}
	${ECHO_CMD} "@dirrm ${f}" >> ${PLISTD}
.endfor
	${MKDIR} ${FAKEDIR}/libdata
	${MV} -f ${FAKEDIR}/lib/pkgconfig ${FAKEDIR}/libdata/ || ${TRUE}
	${RM} -f ${FAKEDIR}/lib/pkgconfig
.for dir in ${MOZILLA_PLIST_DIRS}
	@cd ${FAKEDIR}/${dir} && ${FIND} -H -s * ! -type d | \
		${SED} -e 's|^|${dir}/|' >> ${PLISTF} && \
		${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${dir}/|' >> ${PLISTD}
.endfor
.for pcfile in ${MOZ_PKGCONFIG_FILES}
	${ECHO_CMD} "libdata/pkgconfig/${pcfile}.pc" >> ${PLISTF}
	@${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
		-e 's|${MOZILLA}-nspr = ${PORTVERSION}|nspr|' \
		${FAKEDIR}/libdata/pkgconfig/${pcfile}.pc
.endfor
	${CAT} ${PLISTF} | ${SORT} >> ${PLIST}
	${CAT} ${PLISTD} | ${SORT} -r >> ${PLIST}
	${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${PLIST}
.endif # !defined(NOGECKO_PLIST)

do-install: gecko-do-install

gecko-do-install:
.if !defined(NOGECKO_INSTALL)
.for dir in ${MOZILLA_PLIST_DIRS}
.if !exists(${PREFIX}/${dir})
	${MKDIR} ${PREFIX}/${dir}
.endif
	${TAR} cf - -C${FAKEDIR}/${dir} -s'|${FAKEDIR}|${PREFIX}|s' . | \
		${TAR} xof - -C${PREFIX}/${dir}
.endfor
.for pcfile in ${MOZ_PKGCONFIG_FILES}
	${INSTALL_DATA} ${FAKEDIR}/libdata/pkgconfig/${pcfile}.pc \
		${PREFIX}/libdata/pkgconfig/${pcfile}.pc
.endfor
.endif # !defined(NOGECKO_INSTALL)

gecko-moz-pis-pre-install:
.if defined(MOZ_PIS_SCRIPTS)
	${MKDIR} ${FAKEDIR}/${MOZ_PIS_DIR}
.for moz in ${MOZ_PIS_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${moz} ${FAKEDIR}/${MOZ_PIS_DIR}
.endfor
.endif

post-install: gecko-post-install

gecko-post-install:
.if !defined(PACKAGE_BUILDING) && !defined(NO_MOZPKGINSTALL)
	@if [ -e ${PKGINSTALL} ] ; then \
		${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; \
	fi
.endif
	@-update-desktop-database

.endif
.endif
# HERE THERE BE TACOS -- adamw
