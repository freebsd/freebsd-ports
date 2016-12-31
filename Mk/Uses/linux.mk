# $FreeBSD$
#
# Ports Linux compatibility framework
#
# Feature:	linux:args
# Usage:	USES=linux or USES=linux:args
# Valid args:	c6	Depend on CentOS 6 packages (default)
#		c7	Depend on CentOS 7 packages
# Additional variables:
# USE_LINUX	List of Linux packages to depend on.
# USE_LINUX_RPM	When defined, additional variables and targets useful to Linux
#		infrastructure ports are made available.  Possible values:
#		yes	Default LIB_DISTFILES and empty BIN_DISTFILES.
#		nolib	Default BIN_DISTFILES and empty LIB_DISTFILES.
#		noarch	Like nolib but distfiles are architecture neutral.
# Additional variables when USE_LINUX_RPM is defined:
# BIN_DISTFILES	List of distfiles to install.
# LIB_DISTFILES	List of distfiles to install both the 32 and 64 bit version of.
# SRC_DISTFILES	List of source distfiles that need to be distributed with
#		binary packages to comply with some licenses.
#
# MAINTAINER: emulation@FreeBSD.org

.ifndef _INCLUDE_USES_LINUX_MK
_INCLUDE_USES_LINUX_MK=	yes
_USES_POST+=		linux

.if empty(linux_ARGS)
linux_ARGS=		${LINUX_DEFAULT:S/_64//}
.endif

.if ${linux_ARGS} == c6
LINUX_DIST_VER?=	6.8
.elif ${linux_ARGS} == c7
LINUX_DIST_VER?=	7.2.1511
.else
IGNORE=			Invalid Linux distribution: ${linux_ARGS}
.endif

.if ${LINUX_DEFAULT:M*_64}
LINUX_ARCH=		x86_64
LINUX_ARCH32=		i386
.if ${ARCH} != amd64 || ${OPSYS} != FreeBSD || ${OSVERSION} < 1002507 \
 || ( ${OSVERSION} >= 1100000 && ${OSVERSION} < 1100105 )
IGNORE=			Linux ${LINUX_DEFAULT} is only supported on FreeBSD/amd64 10.3 or higher
.endif
.else
LINUX_ARCH=		i386
.endif

linux_allegro_DEP=		linux-${linux_ARGS}-allegro>0:devel/linux-${linux_ARGS}-allegro
linux_alsa-plugins-oss_DEP=	linux-${linux_ARGS}-alsa-plugins-oss>0:audio/linux-${linux_ARGS}-alsa-plugins-oss
linux_alsa-plugins-pulseaudio_DEP=linux-${linux_ARGS}-alsa-plugins-pulseaudio>0:audio/linux-${linux_ARGS}-alsa-plugins-pulseaudio
linux_alsalib_DEP=		linux-${linux_ARGS}-alsa-lib>0:audio/linux-${linux_ARGS}-alsa-lib
linux_arts_DEP=			linux-${linux_ARGS}-arts>0:audio/linux-${linux_ARGS}-arts
linux_atk_DEP=			linux-${linux_ARGS}-atk>0:accessibility/linux-${linux_ARGS}-atk
linux_avahi-libs_DEP=		linux-${linux_ARGS}-avahi-libs>0:net/linux-${linux_ARGS}-avahi-libs
linux_base_DEP=			linux_base-${linux_ARGS}>0:emulators/linux_base-${linux_ARGS}
linux_cairo_DEP=		linux-${linux_ARGS}-cairo>0:graphics/linux-${linux_ARGS}-cairo
linux_cups-libs_DEP=		linux-${linux_ARGS}-cups-libs>0:print/linux-${linux_ARGS}-cups-libs
linux_curl_DEP=			linux-${linux_ARGS}-curl>0:ftp/linux-${linux_ARGS}-curl
linux_cyrus-sasl2_DEP=		linux-${linux_ARGS}-cyrus-sasl2>0:security/linux-${linux_ARGS}-cyrus-sasl2
linux_dbusglib_DEP=		linux-${linux_ARGS}-dbus-glib>0:devel/linux-${linux_ARGS}-dbus-glib
linux_dbuslibs_DEP=		linux-${linux_ARGS}-dbus-libs>0:devel/linux-${linux_ARGS}-dbus-libs
linux_devtools_DEP=		linux-${linux_ARGS}-devtools>0:devel/linux-${linux_ARGS}-devtools
linux_dri_DEP=			linux-${linux_ARGS}-dri>0:graphics/linux-${linux_ARGS}-dri
linux_esound_DEP=		linux-${linux_ARGS}-esound>0:audio/linux-${linux_ARGS}-esound
linux_expat_DEP=		linux-${linux_ARGS}-expat>0:textproc/linux-${linux_ARGS}-expat
linux_flac_DEP=			linux-${linux_ARGS}-flac>0:audio/linux-${linux_ARGS}-flac
linux_fontconfig_DEP=		linux-${linux_ARGS}-fontconfig>0:x11-fonts/linux-${linux_ARGS}-fontconfig
linux_gdkpixbuf2_DEP=		linux-${linux_ARGS}-gdk-pixbuf2>0:graphics/linux-${linux_ARGS}-gdk-pixbuf2
linux_gnutls_DEP=		linux-${linux_ARGS}-gnutls>0:security/linux-${linux_ARGS}-gnutls
linux_graphite2_DEP=		linux-${linux_ARGS}-graphite2>0:graphics/linux-${linux_ARGS}-graphite2
linux_gtk2_DEP=			linux-${linux_ARGS}-gtk2>0:x11-toolkits/linux-${linux_ARGS}-gtk2
linux_harfbuzz_DEP=		linux-${linux_ARGS}-harfbuzz>0:print/linux-${linux_ARGS}-harfbuzz
linux_hicontheme_DEP=		linux-${linux_ARGS}-hicolor-icon-theme>0:x11-themes/linux-${linux_ARGS}-hicolor-icon-theme
linux_jasper_DEP=		linux-${linux_ARGS}-jasper>0:graphics/linux-${linux_ARGS}-jasper
linux_jbigkit_DEP=		linux-${linux_ARGS}-jbigkit>0:graphics/linux-${linux_ARGS}-jbigkit
linux_jpeg_DEP=			linux-${linux_ARGS}-jpeg>0:graphics/linux-${linux_ARGS}-jpeg
linux_libasyncns_DEP=		linux-${linux_ARGS}-libasyncns>0:dns/linux-${linux_ARGS}-libasyncns
.if ${linux_ARGS:Mc6}
linux_libaudiofile_DEP=		linux-${linux_ARGS}-libaudiofile>0:audio/linux-${linux_ARGS}-libaudiofile
.else
linux_libaudiofile_DEP=		linux-${linux_ARGS}-audiofile>0:audio/linux-${linux_ARGS}-audiofile
.endif
linux_libelf_DEP=		linux-${linux_ARGS}-libelf>0:devel/linux-${linux_ARGS}-libelf
linux_libgcrypt_DEP=		linux-${linux_ARGS}-libgcrypt>0:security/linux-${linux_ARGS}-libgcrypt
linux_libgfortran_DEP=		linux-${linux_ARGS}-libgfortran>0:devel/linux-${linux_ARGS}-libgfortran
linux_libgpg-error_DEP=		linux-${linux_ARGS}-libgpg-error>0:security/linux-${linux_ARGS}-libgpg-error
linux_libmng_DEP=		linux-${linux_ARGS}-libmng>0:graphics/linux-${linux_ARGS}-libmng
linux_libogg_DEP=		linux-${linux_ARGS}-libogg>0:audio/linux-${linux_ARGS}-libogg
linux_libpciaccess_DEP=		linux-${linux_ARGS}-libpciaccess>0:devel/linux-${linux_ARGS}-libpciaccess
linux_libsndfile_DEP=		linux-${linux_ARGS}-libsndfile>0:audio/linux-${linux_ARGS}-libsndfile
linux_libssh2_DEP=		linux-${linux_ARGS}-libssh2>0:security/linux-${linux_ARGS}-libssh2
linux_libtasn1_DEP=		linux-${linux_ARGS}-libtasn1>0:security/linux-${linux_ARGS}-libtasn1
linux_libthai_DEP=		linux-${linux_ARGS}-libthai>0:devel/linux-${linux_ARGS}-libthai
linux_libtheora_DEP=		linux-${linux_ARGS}-libtheora>0:multimedia/linux-${linux_ARGS}-libtheora
linux_libv4l_DEP=		linux-${linux_ARGS}-libv4l>0:multimedia/linux-${linux_ARGS}-libv4l
linux_libvorbis_DEP=		linux-${linux_ARGS}-libvorbis>0:audio/linux-${linux_ARGS}-libvorbis
linux_libxml2_DEP=		linux-${linux_ARGS}-libxml2>0:textproc/linux-${linux_ARGS}-libxml2
linux_mikmod_DEP=		linux-${linux_ARGS}-mikmod>0:audio/linux-${linux_ARGS}-mikmod
linux_naslibs_DEP=		linux-${linux_ARGS}-nas-libs>0:audio/linux-${linux_ARGS}-nas-libs
linux_ncurses-base_DEP=		linux-${linux_ARGS}-ncurses-base>0:devel/linux-${linux_ARGS}-ncurses-base
linux_nspr_DEP=			linux-${linux_ARGS}-nspr>0:devel/linux-${linux_ARGS}-nspr
linux_nss_DEP=			linux-${linux_ARGS}-nss>0:security/linux-${linux_ARGS}-nss
linux_openal_DEP=		linux-${linux_ARGS}-openal>0:audio/linux-${linux_ARGS}-openal
linux_openal-soft_DEP=		linux-${linux_ARGS}-openal-soft>0:audio/linux-${linux_ARGS}-openal-soft
linux_openldap_DEP=		linux-${linux_ARGS}-openldap>0:net/linux-${linux_ARGS}-openldap
linux_openmotif_DEP=		linux-${linux_ARGS}-openmotif>0:x11-toolkits/linux-${linux_ARGS}-openmotif
linux_openssl_DEP=		linux-${linux_ARGS}-openssl>0:security/linux-${linux_ARGS}-openssl
linux_openssl-compat_DEP=	linux-${linux_ARGS}-openssl-compat>0:security/linux-${linux_ARGS}-openssl-compat
linux_pango_DEP=		linux-${linux_ARGS}-pango>0:x11-toolkits/linux-${linux_ARGS}-pango
linux_pixman_DEP=		linux-${linux_ARGS}-pixman>0:x11/linux-${linux_ARGS}-pixman
linux_png_DEP=			linux-${linux_ARGS}-png>0:graphics/linux-${linux_ARGS}-png
linux_pulseaudio-libs_DEP=	linux-${linux_ARGS}-pulseaudio-libs>0:audio/linux-${linux_ARGS}-pulseaudio-libs
.if ${linux_ARGS:Mc6}
linux_qt_DEP=			linux-${linux_ARGS}-qt47>0:devel/linux-${linux_ARGS}-qt47
linux_qt-x11_DEP=		linux-${linux_ARGS}-qt47-x11>0:x11-toolkits/linux-${linux_ARGS}-qt47-x11
linux_qtwebkit_DEP=		linux-${linux_ARGS}-qt47-webkit>0:www/linux-${linux_ARGS}-qt47-webkit
.else
linux_qt_DEP=			linux-${linux_ARGS}-qt>0:devel/linux-${linux_ARGS}-qt
linux_qt-x11_DEP=		linux-${linux_ARGS}-qt-x11>0:x11-toolkits/linux-${linux_ARGS}-qt-x11
linux_qtwebkit_DEP=		linux-${linux_ARGS}-qtwebkit>0:www/linux-${linux_ARGS}-qtwebkit
.endif
linux_scimlibs_DEP=		linux-${linux_ARGS}-scim-libs>0:textproc/linux-${linux_ARGS}-scim-libs
linux_sdl12_DEP=		linux-${linux_ARGS}-sdl>0:devel/linux-${linux_ARGS}-sdl12
linux_sdlimage_DEP=		linux-${linux_ARGS}-sdl_image>0:graphics/linux-${linux_ARGS}-sdl_image
linux_sdlmixer_DEP=		linux-${linux_ARGS}-sdl_mixer>0:audio/linux-${linux_ARGS}-sdl_mixer
linux_sqlite3_DEP=		linux-${linux_ARGS}-sqlite>0:databases/linux-${linux_ARGS}-sqlite3
linux_tcl85_DEP=		linux-${linux_ARGS}-tcl85>0:lang/linux-${linux_ARGS}-tcl85
linux_tcp_wrappers-libs_DEP=	linux-${linux_ARGS}-tcp_wrappers-libs>0:net/linux-${linux_ARGS}-tcp_wrappers-libs
linux_tiff_DEP=			linux-${linux_ARGS}-tiff>0:graphics/linux-${linux_ARGS}-tiff
linux_tk85_DEP=			linux-${linux_ARGS}-tk85>0:x11-toolkits/linux-${linux_ARGS}-tk85
linux_ucl_DEP=			linux-${linux_ARGS}-ucl>0:archivers/linux-${linux_ARGS}-ucl
linux_xorglibs_DEP=		linux-${linux_ARGS}-xorg-libs>0:x11/linux-${linux_ARGS}-xorg-libs

USE_LINUX?=		base
.for i in ${USE_LINUX}
_i_args:=		${i:C/^[^:]*:?//:S/,/ /g}
.if ${_i_args:Mpatch}
PATCH_DEPENDS+=		${linux_${i:C/:.*//}_DEP}
.endif
.if ${_i_args:Mbuild}
BUILD_DEPENDS+=		${linux_${i:C/:.*//}_DEP}
.endif
.if ${_i_args:Mrun} || empty(_i_args)
RUN_DEPENDS+=		${linux_${i:C/:.*//}_DEP}
.endif
.endfor

.ifdef USE_LINUX_RPM

DISTVERSIONSUFFIX?=	-${RPMVERSION}

.if ${linux_ARGS} == c6

.ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_CENTOS_LINUX}
MASTER_SITE_SUBDIR=	centos/${LINUX_DIST_VER}/os/${LINUX_ARCH}/Packages \
			centos/${LINUX_DIST_VER}/updates/${LINUX_ARCH}/Packages \
			centos/${LINUX_DIST_VER}/os/Source/SPackages/:SOURCE \
			centos/${LINUX_DIST_VER}/updates/Source/SPackages/:SOURCE
.endif
DIST_SUBDIR?=		rpm/${LINUX_RPM_ARCH}/centos/${LINUX_DIST_VER}

.if ${USE_LINUX_RPM} == noarch
LINUX_RPM_ARCH?=	noarch
.elif ${LINUX_ARCH} == x86_64
LINUX_RPM_ARCH?=	x86_64
LINUX_RPM_ARCH32?=	i686
.else
LINUX_RPM_ARCH?=	i686
.endif

.elif ${linux_ARGS} == c7

.ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_CENTOS_LINUX}
.if ${LINUX_ARCH} == x86_64
MASTER_SITE_SUBDIR=	centos/${LINUX_DIST_VER}/os/${LINUX_ARCH}/Packages \
			centos/${LINUX_DIST_VER}/updates/${LINUX_ARCH}/Packages
.else
MASTER_SITE_SUBDIR=	altarch/${LINUX_DIST_VER}/os/${LINUX_ARCH}/Packages \
			altarch/${LINUX_DIST_VER}/updates/${LINUX_ARCH}/Packages
.endif
MASTER_SITE_SUBDIR+=	centos/${LINUX_DIST_VER}/os/Source/SPackages/:SOURCE \
			centos/${LINUX_DIST_VER}/updates/Source/SPackages/:SOURCE
.endif
DIST_SUBDIR?=		rpm/centos/${LINUX_DIST_VER}/${LINUX_ARCH}

.if ${USE_LINUX_RPM} == noarch
LINUX_RPM_ARCH?=	noarch
.elif ${LINUX_ARCH} == x86_64
LINUX_RPM_ARCH?=	x86_64
LINUX_RPM_ARCH32?=	i686
.else
LINUX_RPM_ARCH?=	i686
.endif

.endif # ${linux_ARGS} == *

PKGNAMEPREFIX?=		linux-${linux_ARGS}-
EXTRACT_SUFX?=		.${LINUX_RPM_ARCH}.rpm
.ifdef LINUX_RPM_ARCH32
EXTRACT_SUFX32?=	.${LINUX_RPM_ARCH32}.rpm
.endif
SRC_SUFX?=		.src.rpm

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_LINUX_PREFIX=	yes

.endif # USE_LINUX_RPM

.endif # ! _INCLUDE_USES_LINUX_MK

.ifdef _POSTMKINCLUDED && ! _INCLUDE_USES_LINUX_POST_MK
_INCLUDE_USES_LINUX_POST_MK=	yes

.ifdef USE_LINUX_RPM

.if ${USE_LINUX_RPM} == noarch
NO_ARCH=		yes
.else
ONLY_FOR_ARCHS?=	i386 amd64
.endif

.if ${USE_LINUX_RPM} == yes
LIB_DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
.else
BIN_DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
.endif
.ifdef LINUX_ARCH32 && EXTRACT_SUFX32
.for fmakehack in ${LINUX_ARCH32}
.if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:M${fmakehack})) \
 && empty(NOT_FOR_ARCHS:M${fmakehack})
DISTFILES?=		${LIB_DISTFILES:S/${EXTRACT_SUFX}/${EXTRACT_SUFX32}/} \
			${LIB_DISTFILES} ${BIN_DISTFILES}
EXTRACT_ONLY?=		${LIB_DISTFILES:S/${EXTRACT_SUFX}/${EXTRACT_SUFX32}/} \
			${LIB_DISTFILES} ${BIN_DISTFILES}
.else
DISTFILES?=		${LIB_DISTFILES} ${BIN_DISTFILES}
EXTRACT_ONLY?=		${LIB_DISTFILES} ${BIN_DISTFILES}
.endif
.endfor
.else
DISTFILES?=		${LIB_DISTFILES} ${BIN_DISTFILES}
EXTRACT_ONLY?=		${LIB_DISTFILES} ${BIN_DISTFILES}
.endif
.ifdef PACKAGE_BUILDING
SRC_DISTFILES?=		${LIB_DISTFILES:S/${EXTRACT_SUFX}/${SRC_SUFX}:SOURCE/} \
			${BIN_DISTFILES:S/${EXTRACT_SUFX}/${SRC_SUFX}:SOURCE/}
DISTFILES+=		${SRC_DISTFILES}
ALWAYS_KEEP_DISTFILES=	yes
.endif

DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_ARCH}

.ifdef USE_LINUX_RPM_BAD_PERMS
EXTRACT_DEPENDS+=	rpm2archive:archivers/rpm4
EXTRACT_CMD=		rpm2archive
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	| ${TAR} xf - --no-same-owner --no-same-permissions
.endif

.if ${USE_LINUX_RPM} != noarch
PLIST?=			${PKGDIR}/pkg-plist.${LINUX_ARCH}
.endif

.if !target(do-install)
do-install:
	(cd ${WRKSRC} && ${FIND} * | ${CPIO} -dumpl ${STAGEDIR}${PREFIX})
.endif

.endif # USE_LINUX_RPM

.ifdef DISTNAME_i386
DISTFILES_i386?=	${DISTNAME_i386}${EXTRACT_SUFX}
.endif
.ifdef DISTNAME_x86_64
DISTFILES_x86_64?=	${DISTNAME_x86_64}${EXTRACT_SUFX}
.endif
.ifdef DISTFILES_i386 || DISTFILES_x86_64
.if make(makesum)
.if !defined(DISTFILES)
DISTFILES=		${DISTFILES_i386} ${DISTFILES_x86_64}
EXTRACT_ONLY?=		${DISTFILES_${LINUX_ARCH}}
.endif
.else
DISTFILES?=		${DISTFILES_${LINUX_ARCH}}
.endif
.endif

# With fmake :M${var} only works when ${var} is a for loop variable.
.for fmakehack in ${LINUX_ARCH:S/x86_64/amd64/}
.if (defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:M${fmakehack})) \
 || !empty(NOT_FOR_ARCHS:M${fmakehack})
IGNORE=			does not run on Linux/${LINUX_ARCH}
.endif
.endfor

.endif # _POSTMKINCLUDED && ! _INCLUDE_USES_LINUX_POST_MK
