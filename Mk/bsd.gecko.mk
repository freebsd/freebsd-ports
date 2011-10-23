#-*- mode: Fundamental; tab-width: 4; -*-
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
# WITH_GECKO= libxul libxul-devel
#  Use libxul whenever a port supports it, falling back on libxul-devel.
#  Note: libxul-devel does not exist at the moment!
# WITH_GECKO= libxul
#  Sets your preferred backend. With this example, libxul will always
#  be chosen, unless the port doesn't support a libxul backend. In that
#  case, you get whatever the porter chose as the default. Better to use
#  the first example.
#
#
# Ports should use the following:
#
# USE_GECKO= libxul libxul-devel
#  The list of gecko backends that the port supports. Unless the user
#  overrides it with WITH_GECKO, the first gecko listed in USE_GECKO
#  will be the default. In the above example, www/libxul will be used
#  as a gecko backend unless WITH_GECKO=libxul-devel is defined by the
#  user. Note: libxul-devel does not exist at the moment!
#
# USE_GECKO= libxul-devel<->libxul
#  This will sed -e 's/libxul/libxul-devel/' on Makefile.in's and configure 
#  if ${GECKO}=="libxul-devel"
#
#  Example:
#  USE_GECKO= libxul libxul-devel
#  Note: libxul-devel does not exist at the moment!
# 
#  post-patch:
#	@${REINPALCE_CMD} -e 's|mozilla-|${GECKO}-|' \
#		${MOZSRC}/configure
#
#  If you want your port to check the ${GECKO} variable to see which backend
#  has been chosen.
#
#  Example:
#  USE_GECKO= libxul libxul-devel
#  Note: libxul-devel does not exist at the moment!
#  
#  post-patch:
#  .if ${GECKO}=="libxul-devel"
#	@${REINPLACE_CMD} -e 's|mozilla-|libxul-|' \
#		${MOZSRC}/configure
#  .endif

_GECKO_ALL=	libxul

libxul_PLIST=		${LOCALBASE}/lib/libxul/libxul.so

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
#                         Available values: yes 70+ 36+ 70 36
#                         NOTE:
#                         default value 70 is used in case of USE_FIREFOX=yes
#
# USE_FIREFOX_BUILD       Add buildtime dependency on Firefox.
#                         Available values: see USE_FIREFOX
#
# USE_SEAMONKEY           Add runtime dependency on SeaMonkey. If no
#                         version is given by the maintainer via the port 
#                         or by the user via defined variable try to find
#                         the highest stable installed version.
#                         Available values: yes 24+ 24
#                         NOTE:
#                         default value 24 is used in case of USE_SEAMONKEY=yes
#
# USE_SEAMONKEY_BUILD     Add buildtime dependency on SeaMonkey.
#                         Available values: see USE_SEAMONKEY
#
# USE_THUNDERBIRD         Add runtime dependency on Thunderbird. If no 
#                         version is given by the maintainer via the port 
#                         or by the user via defined variable try to find 
#                         the highest stable installed version.
#                         Available values: yes 70+ 31+ 70 31
#                         NOTE:
#                         default value 70 is used in case of USE_THUNDERBIRD=yes
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

_FIREFOX_DEFAULT_VERSION=	70
_FIREFOX_VERSIONS=			70 36
_FIREFOX_RANGE_VERSIONS=	70+ 36+

# For specifying [36, ..]+
_FIREFOX_36P=	36 ${_FIREFOX_70P}
_FIREFOX_70P=	70

# Set the default Firefox version and check if USE_FIREFOX=yes was given
.if ${USE_FIREFOX} == "yes"
USE_FIREFOX=	${_FIREFOX_DEFAULT_VERSION}
.endif

# Setting/finding Firefox version we want.
.if exists(${LOCALBASE}/bin/firefox)
_FIREFOX_VER!=	${LOCALBASE}/bin/firefox --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/Mozilla Firefox \([0-9]\)\.\([0-9]*\).*/\1\2/'
.elif exists(${LOCALBASE}/bin/firefox3)
_FIREFOX_VER!=	${LOCALBASE}/bin/firefox3 --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/Mozilla Firefox \([0-9]\)\.\([0-9]*\).*/\1\2/'
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
IGNORE=			cannot install: Firefox versions mismatch: firefox-${_FIREFOX_VER:C/([0-9])([0-9])/\1.\2/} is installed and wanted version is firefox-${USE_FIREFOX:C/([0-9])([0-9])/\1.\2/}
.endif
.endif

.if !defined(_FIREFOX_${USE_FIREFOX:S/+//}P)
IGNORE=			cannot install: unknown Firefox version: firefox-${USE_FIREFOX:C/([0-9])([0-9])/\1.\2/}
.endif

# Dependence lines for different Firefox versions
70_DEPENDS=		${LOCALBASE}/lib/firefox/firefox:${PORTSDIR}/www/firefox
36_DEPENDS=		${LOCALBASE}/lib/firefox3/firefox:${PORTSDIR}/www/firefox36

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

_SEAMONKEY_DEFAULT_VERSION=	24
_SEAMONKEY_VERSIONS=		24
_SEAMONKEY_RANGE_VERSIONS=	24+

# For specifying [24, 20, ..]+
_SEAMONKEY_24P=	24

# Set the default SeaMonkey version and check if USE_SEAMONKEY=yes was given
.if ${USE_SEAMONKEY} == "yes"
USE_SEAMONKEY=	${_SEAMONKEY_DEFAULT_VERSION}
.endif

# Setting/finding SeaMonkey version we want.
.if exists(${LOCALBASE}/bin/seamonkey)
_SEAMONKEY_VER!=	${LOCALBASE}/bin/seamonkey --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/Mozilla SeaMonkey \([0-9]\)\.\([0-9]*\).*/\1\2/'
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
IGNORE=			cannot install: SeaMonkey versions mismatch: seamonkey-${_SEAMONKEY_VER:C/([0-9])([0-9])/\1.\2/} is installed and wanted version is seamonkey-${USE_SEAMONKEY:C/([0-9])([0-9])/\1.\2/}
.endif
.endif

.if !defined(_SEAMONKEY_${USE_SEAMONKEY:S/+//}P)
IGNORE=			cannot install: unknown SeaMonkey version: seamonkey-${USE_SEAMONKEY:C/([0-9])([0-9])/\1.\2/}
.endif

# Dependence lines for different SeaMonkey versions
24_DEPENDS=		${LOCALBASE}/lib/seamonkey/seamonkey:${PORTSDIR}/www/seamonkey

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

_THUNDERBIRD_DEFAULT_VERSION=	70
_THUNDERBIRD_VERSIONS=			70 31
_THUNDERBIRD_RANGE_VERSIONS=	70+ 31+

# For specifying [31, 30, ..]+
_THUNDERBIRD_31P=	31 ${_THUNDERBIRD_31P}
_THUNDERBIRD_70P=	70

# Set the default Thunderbird version and check if USE_THUNDERBIRD=yes was given
.if ${USE_THUNDERBIRD} == "yes"
USE_THUNDERBIRD=	${_THUNDERBIRD_DEFAULT_VERSION}
.endif

# Setting/finding Thunderbird version we want.
.if exists(${LOCALBASE}/bin/thunderbird)
_THUNDERBIRD_VER!=	${LOCALBASE}/bin/thunderbird --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/ Thunderbird \([0-9]\)\.\([0-9]*\).*/\1\2/'
.elif exists(${LOCALBASE}/bin/thunderbird3)
_THUNDERBIRD_VER!=	${LOCALBASE}/bin/thunderbird3 --version 2>/dev/null | ${HEAD} -1 | ${SED} -e 's/ Thunderbird \([0-9]\)\.\([0-9]*\).*/\1\2/'
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
IGNORE=			cannot install: Thunderbird versions mismatch: thunderbird-${_THUNDERBIRD_VER:C/([0-9])([0-9])/\1.\2/} is installed and wanted version is thunderbird-${USE_THUNDERBIRD:C/([0-9])([0-9])/\1.\2/}
.endif
.endif

.if !defined(_THUNDERBIRD_${USE_THUNDERBIRD:S/+//}P)
IGNORE=			cannot install: unknown Thunderbird version: thunderbird-${USE_THUNDERBIRD:C/([0-9])([0-9])/\1.\2/}
.endif

# Dependence lines for different Thunderbird versions
70_DEPENDS=		${LOCALBASE}/lib/thunderbird/thunderbird:${PORTSDIR}/mail/thunderbird
31_DEPENDS=		${LOCALBASE}/lib/thunderbird3/thunderbird:${PORTSDIR}/mail/thunderbird3

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
# USE_MOZILLA			By default, it enables the denendencies: cairo, dbm,
# 						jpeg, nspr, nss, png, xft and zip. Search for
# 						'_ALL_DEPENDS' below to see the list. If your port
# 						doesn't need one of list then you can use '-' like
# 						'USE_MOZILLA= -png -zip' to subtract the dependencies.
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
# MOZ_TOOLKIT			A variable for the --enable-default-toolkit= in
# 						CONFIGURE_ARGS. The default is gtk2.
#
# MOZ_EXTENSIONS		A list of extensions to build
#
# MOZ_GRAPHICS			A list of image decoders to build
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
USE_GNOME+=	gtk20 libidl desktopfileutils
USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_XORG=	printproto sm xt xi xext x11 xinerama \
		ice xproto

MOZILLA_SUFX?=	none
MOZSRC?=	${WRKSRC}
WRKSRC?=	${WRKDIR}/mozilla
FAKEDIR?=	${WRKDIR}/fake
PLIST?=		${WRKDIR}/plist
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files
MASTER_DIR?=	${.CURDIR}/../../www/seamonkey

KRB5_HOME?=	/usr
MOZ_PIS_DIR?=		lib/${MOZILLA}/init.d

ESD_LIB?=	libesd.so.2
FREETYPE_LIB?=	libfreetype.so.9

GENERIC_MOZCONFIG?=	${.CURDIR}/../../www/seamonkey/files/mozconfig-generic.in
PORT_MOZCONFIG?=	${FILESDIR}/mozconfig.in
MOZCONFIG?=		${WRKSRC}/.mozconfig
MOZILLA_PLIST_DIRS?=	bin include lib share/idl
PKGINSTALL?=	${WRKDIR}/pkg-install
PKGDEINSTALL?=	${WRKDIR}/pkg-deinstall
MASTER_MOZDIR?=	${PORTSDIR}/www/seamonkey
PKGINSTALL_INC?=	${MASTER_MOZDIR}/pkg-install.in
PKGDEINSTALL_INC?=	${MASTER_MOZDIR}/pkg-deinstall.in

EXTRACT_AFTER_ARGS?=	| ${TAR} -xf - --exclude */CVS/*	\
			--exclude */macbuild/*			\
			--exclude */package/*			\
			--exclude mozilla/gc/boehm

MOZ_PKGCONFIG_FILES?=	${MOZILLA}-gtkmozembed ${MOZILLA}-js \
			${MOZILLA}-xpcom ${MOZILLA}-plugin

CFLAGS+=		${PTHREAD_CFLAGS}
LIBS+=			${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv

_USE_GECKO_OPTIONS_ALL=	java debug logging optimized_cflags

.if !defined(USE_GECKO_OPTIONS)
USE_GECKO_OPTIONS=	debug logging optimized_cflags
.endif

debug_OPTION=	"Build a debugging image" off
java_OPTION=	"Enable JAVA xpcom" off
logging_OPTION=	"Enable additional log messages" off
optimized_cflags_OPTION=	"Enable some additional optimizations" off

.for option in ${USE_GECKO_OPTIONS:L}
.if ${_USE_GECKO_OPTIONS_ALL:M${option}}!=""
OPTIONS+=	${option:U} ${${option}_OPTION}
_${option}=	${TRUE}
.endif
.endfor

# Standard depends
_ALL_DEPENDS=	cairo dbm jpeg nspr nss png xft zip

cairo_LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
cairo_MOZ_OPTIONS=	--enable-system-cairo
cairo_EXTRACT_AFTER_ARGS=	--exclude mozilla/gfx/cairo

dbm_EXTRACT_AFTER_ARGS=		--exclude mozilla/dbm

jpeg_LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
jpeg_MOZ_OPTIONS=	--with-system-jpeg=${LOCALBASE}
jpeg_EXTRACT_AFTER_ARGS=	--exclude mozilla/jpeg

nspr_LIB_DEPENDS=	nspr4:${PORTSDIR}/devel/nspr
nspr_MOZ_OPTIONS=	--with-system-nspr

nss_LIB_DEPENDS=	nss3:${PORTSDIR}/security/nss
nss_EXTRACT_AFTER_ARGS=	--exclude mozilla/security/nss
nss_MOZ_OPTIONS=	--with-system-nss
nss_CPPFLAGS+=		-I${LOCALBASE}/include/nss -I${LOCALBASE}/include/nss/nss
nss_LDFLAGS+=		-L${LOCALBASE}/lib/nss -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}


png_LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png
png_MOZ_OPTIONS=	--with-system-png=${LOCALBASE}

xft_LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
zip_DEPENDS=		zip:${PORTSDIR}/archivers/zip

.for use in ${USE_MOZILLA}
${use:S/-/_WITHOUT_/}=	${TRUE}
.endfor

.for dep in ${_ALL_DEPENDS}
.if !defined(_WITHOUT_${dep})
BUILD_DEPENDS+=	${${dep}_DEPENDS}
LIB_DEPENDS+=	${${dep}_LIB_DEPENDS}
RUN_DEPENDS+=	${${dep}_DEPENDS}
MOZ_OPTIONS+=	${${dep}_MOZ_OPTIONS}
EXTRACT_AFTER_ARGS+=	${${dep}_EXTRACT_AFTER_ARGS}
CPPFLAGS+=	${${dep}_CPPFLAGS}
LDFLAGS+=	${${dep}_LDFLAGS}
.endif
.endfor

# Standard options from README
MOZ_TOOLKIT?=	gtk2
MOZ_OPTIONS+=	--enable-crypto 	\
		--disable-tests 	\
		--enable-default-toolkit=${MOZ_TOOLKIT} \
		--enable-xft		\
		--with-pthreads
# Configure options for install
MOZ_OPTIONS+=	--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
.if !defined(MOZ_EXTENSIONS)
MOZ_OPTIONS+=	--enable-extensions=default
.else
MOZ_OPTIONS+=	--enable-extensions=${MOZ_EXTENSIONS}
.endif
.if !defined(MOZ_GRAPHICS)
MOZ_OPTIONS+=	--enable-image-decoders=default
.else
MOZ_OPTIONS+=	--enable-image-decoders=${MOZ_GRAPHICS}
.endif
.if !defined(MOZ_PROTOCOLS)
MOZ_OPTIONS+=	--enable-necko-protocols=default
.else
MOZ_OPTIONS+=	--enable-necko-protocols=${MOZ_PROTOCOLS}
.endif
# others 
MOZ_OPTIONS+=	--with-system-zlib=/usr		\
		--with-gssapi=${KRB5_HOME}	\
		--disable-auto-deps		\
		--disable-debug-symbols		\
		--enable-chrome-format=jar	\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--disable-glibtest		\
		--disable-gtktest		\
		--disable-freetypetest		\
		--enable-double-buffer		\
		--enable-mathml			\
		--disable-installer		\
		--disable-md			\
		--disable-pedantic		\
		--disable-bidi			\
		--disable-xterm-updates		\
		--disable-xprint		\
		--enable-xinerama
MOZ_MK_OPTIONS+=	XP_UNIX=1		\
			PERL=${PERL}

.if defined(WITH_OPTIMIZED_CFLAGS)
MOZ_OPTIONS+=	--enable-optimize=${WITH_OPTIMIZE}
CFLAGS:=	${CFLAGS} -O2 -fno-strict-aliasing ${EXTRA_CFLAGS}
WITH_OPTIMIZE?=	-O2
.else
MOZ_OPTIONS+=	--disable-optimize
CFLAGS:=	${CFLAGS} ${EXTRA_CFLAGS}
.endif

.if defined(WITH_SMB)
USE_GNOME+=		gnomevfs2
MOZ_OPTIONS+=	--enable-gnomevfs
.else
MOZ_OPTIONS+=	--disable-gnomevfs
.endif

.if !defined(STRIP) || ${STRIP} == ""
MOZ_OPTIONS+=	--disable-strip --disable-install-strip
.else
MOZ_OPTIONS+=	--enable-strip --enable-install-strip
.endif

.if defined(WITH_DEBUG)
MOZ_OPTIONS+=	--enable-debug
WITH_LOGGING=	yes
.else
MOZ_OPTIONS+=	--disable-debug
.endif

.if defined(WITH_JAVA) && defined(_WITH_JAVA)
USE_JAVA=	yes
JAVA_VERSION+=	1.5+
JAVA_OS+=	native
CONFIGURE_ENV+=	JAVA_HOME="${JAVA_HOME}"
MOZ_OPTIONS+=	--enable-javaxpcom
.endif

.if defined(WITH_LOGGING)
MOZ_OPTIONS+=	--enable-logging
.else
MOZ_OPTIONS+=	--disable-logging
.endif

MOZ_SED_ARGS+=	-e's|@CPPFLAGS@|${CPPFLAGS}|g'		\
		-e 's|@CFLAGS@|${CFLAGS}|g'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|g'		\
		-e 's|@LIBS@|${LIBS}|g'			\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		-e 's|@FAKEDIR@|${FAKEDIR}|g'		\
		-e 's|@PERL@|${PERL5}|g'			\
		-e 's|@KRB5_HOME@|${KRB5_HOME}|g'	\
		-e 's|@MOZDIR@|${PREFIX}/lib/${MOZILLA}|g'	\
		-e 's|%%PREFIX%%|${PREFIX}|g'		\
		-e 's|%%CFLAGS%%|${CFLAGS}|g'		\
		-e 's|%%LDFLAGS%%|${LDFLAGS}|g'		\
		-e 's|%%LIBS%%|${LIBS}|g'		\
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g'	\
		-e 's|%%FAKEDIR%%|${FAKEDIR}|g'		\
		-e 's|%%PERL%%|${PERL5}|g'		\
		-e 's|%%KRB5_HOME%%|${KRB5_HOME}|g'	\
		-e 's|%%MOZILLA%%|${MOZILLA}|g'		\
		-e 's|%%MOZILLA_BIN%%|${MOZILLA_BIN}|g'	\
		-e 's|%%MOZDIR%%|${PREFIX}/lib/${MOZILLA}|g'
MOZCONFIG_SED?= ${SED} ${MOZ_SED_ARGS}

.if ${ARCH}=="sparc64"
# Work around miscompilation/mislinkage of the sCanonicalVTable hacks.
MOZ_OPTIONS+=	--disable-v1-string-abi
.endif

.else # bsd.port.post.mk

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
.if exists(${GENERIC_MOZCONFIG})
	@${MOZCONFIG_SED} < ${GENERIC_MOZCONFIG} >> ${MOZCONFIG}
.endif
	@if [ -e ${PORT_MOZCONFIG} ] ; then \
		${MOZCONFIG_SED} < ${PORT_MOZCONFIG} >> ${MOZCONFIG} ; \
	fi
.for arg in ${MOZ_OPTIONS}
	@${ECHO_CMD} ac_add_options ${arg} >> ${MOZCONFIG}
.endfor
.for arg in ${MOZ_MK_OPTIONS}
	@${ECHO_CMD} mk_add_options ${arg} >> ${MOZCONFIG}
.endfor
.for var in ${MOZ_EXPORT}
	@${ECHO_CMD} "export ${var}" >> ${MOZCONFIG}
.endfor
.endif # .if !defined(NOMOZCONFIG)
.if exists(${MOZSRC}/build/unix/mozilla-config.in)
	@${REINPLACE_CMD} -e  's/%{idldir}/%idldir%/g ; \
		s|"%FULL_NSPR_CFLAGS%"|`nspr-config --cflags`|g ; \
		s|"%FULL_NSPR_LIBS%"|`nspr-config --libs`|g' \
			${MOZSRC}/build/unix/mozilla-config.in
.endif
	@${REINPLACE_CMD} -e 's|<iconv.h>|\"${LOCALBASE}/include/iconv.h\"|g' \
		${WRKSRC}/configure
.for subdir in config/system_wrappers nsprpub/config/system_wrappers js/src/config/system_wrappers_js
	@${MKDIR} ${MOZSRC}/${subdir}
	@${ECHO_CMD} "#pragma GCC system_header" >> ${MOZSRC}/${subdir}/iconv.h
	@${ECHO_CMD} "#pragma GCC visibility push(default)" >> ${MOZSRC}/${subdir}/iconv.h
	@${ECHO_CMD} "#include \"${LOCALBASE}/include/iconv.h\"" >> ${MOZSRC}/${subdir}/iconv.h
	@${ECHO_CMD} "#pragma GCC visibility pop" >> ${MOZSRC}/${subdir}/iconv.h
.endfor
.for subdir in "" nsprpub js/src
	@if [ -f ${MOZSRC}/${subdir}/config/system-headers ] ; then \
		${ECHO_CMD} "fenv.h" >> ${MOZSRC}/${subdir}/config/system-headers ; \
		${ECHO_CMD} "pthread_np.h" >> ${MOZSRC}/${subdir}/config/system-headers ; \
	fi
.endfor
	@${REINPLACE_CMD} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		${WRKSRC}/config/autoconf.mk.in
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; s|/usr/X11R6|${LOCALBASE}|g' \
		${MOZSRC}/security/coreconf/FreeBSD.mk \
		${MOZSRC}/js/src/Makefile.in
	@if [ -d ${WRKSRC}/directory/c-sdk ]; then \
		${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
			${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
			${WRKSRC}/directory/c-sdk/configure ; \
	fi
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
			${MOZSRC}/build/unix/run-mozilla.sh
	@${REINPLACE_CMD} -E -e 's|libesd\.so\.[0-9]+|libesd.so|g' \
		${MOZSRC}/widget/src/gtk2/nsSound.cpp
	@${REINPLACE_CMD} -E -e 's|libcups\.so\.[0-9]+|libcups.so|g' \
		${MOZSRC}/*/*/*/nsDeviceContextSpecG.cpp
	@${REINPLACE_CMD} -e 's|/usr/local/netscape|${LOCALBASE}|g ; \
		s|/usr/local/lib/netscape|${LOCALBASE}/lib|g' \
		${MOZSRC}/xpcom/*/SpecialSystemDirectory.cpp

# handles mozilla pis scripts.
gecko-moz-pis-patch:
.for moz in ${MOZ_PIS_SCRIPTS}
	@${MOZCONFIG_SED} < ${FILESDIR}/${moz} > ${WRKDIR}/${moz}
.endfor

post-configure: gecko-post-configure

gecko-post-configure:
	@${ECHO_CMD} "#define JNIIMPORT" >> ${MOZSRC}/mozilla-config.h

post-build: gecko-post-build

gecko-post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2|" \
		${MOZSRC}/build/unix/*.pc || ${TRUE}

pre-install: gecko-moz-pis-pre-install gecko-pre-install port-pre-install gecko-create-plist

.if !target(port-pre-install)
port-pre-install:
		@${DO_NADA}
.endif

gecko-pre-install:
.if !defined(NOGECKO_PLIST)
	@${RM} -rf ${FAKEDIR} ${PLIST} ${PLISTD} ${PLISTF}
	@${TOUCH} -f ${PLIST} ${PLISTD} ${PLISTF}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} prefix=${FAKEDIR} ${INSTALL_TARGET}
.if defined(MOZILLA_SUFX) && ${MOZILLA_SUFX}!="none"
	${MV} ${FAKEDIR}/bin/${MOZILLA:S/${MOZILLA_SUFX}//} ${FAKEDIR}/bin/${MOZILLA}
.if exists(${FAKEDIR}/bin/${MOZILLA:S/${MOZILLA_SUFX}//}-config)
	${MV} ${FAKEDIR}/bin/${MOZILLA:S/${MOZILLA_SUFX}//}-config ${FAKEDIR}/bin/${MOZILLA}-config
.endif
.for pc in ${MOZ_PKGCONFIG_FILES:S|${MOZILLA_SUFX}||}
	${SED} -e 's|Requires: ${MOZILLA:S/${MOZILLA_SUFX}//}|Requires: ${MOZILLA}|' \
	${FAKEDIR}/lib/pkgconfig/${pc}.pc > ${FAKEDIR}/lib/pkgconfig/${pc:S/${MOZILLA:S,${MOZILLA_SUFX},,}/${MOZILLA}/}.pc
.endfor
	@${REINPLACE_CMD} -e 's|${MOZILLA}-bin|${MOZILLA:S/${MOZILLA_SUFX}//}|; \
		s|$${progbase}-bin|${MOZILLA:S/${MOZILLA_SUFX}//}-bin|' \
		-i '' $$(${REALPATH} ${FAKEDIR}/bin/${MOZILLA_EXEC_NAME}*)
.endif
	@${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|g' \
		-i '' $$(${REALPATH} ${FAKEDIR}/bin/${MOZILLA_EXEC_NAME}*)
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
	${ECHO_CMD} "@dirrmtry share/idl" >> ${PLIST}
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
.if (${OSVERSION} < 800081 )
	# XXX: make sure bsdtar(1) corrected symlinks
	${FIND} ${FAKEDIR} -type l -exec \
		${ECHO_CMD} stat -f \'${LN} -hfs \"%Y\" \"%N\"\' {} + | \
		${SED} s'|${FAKEDIR}|${PREFIX}|g' | ${SH} | \
		${SED} -n s'|${FAKEDIR}|${PREFIX}|p' | ${SH} -x
.endif
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
