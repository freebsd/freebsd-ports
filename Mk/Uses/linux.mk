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
#		yes	Set default LIB_DISTNAMES.
#		nolib	Set default BIN_DISTNAMES.
#		noarch	Set default SHARE_DISTNAMES.
# Additional variables when USE_LINUX_RPM is defined:
# BIN_DISTNAMES		List of architecture dependent distnames.
# LIB_DISTNAMES		List of distnames with additional 32 bit version.
# SHARE_DISTNAMES	List of architecture independent distnames.
# SRC_DISTFILES		List of source distfiles that need to be distributed
#			with binary packages to comply with some licenses.
#
# MAINTAINER: emulation@FreeBSD.org

.ifndef _INCLUDE_USES_LINUX_MK
_INCLUDE_USES_LINUX_MK=	yes
_USES_POST+=		linux

.if empty(linux_ARGS)
.if exists(${LINUXBASE}/etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-6)
linux_ARGS=		c6
.elif exists(${LINUXBASE}/etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7)
linux_ARGS=		c7
.else
linux_ARGS=		${LINUX_DEFAULT:S/_64//}
.endif
.endif

.if ${linux_ARGS} == c6
LINUX_DIST_VER?=	6.10
.if ${ARCH} == amd64 && ${LINUX_DEFAULT} != c6
LINUX_ARCH=		x86_64
.elif ${ARCH} == amd64 || ${ARCH} == i386
LINUX_ARCH=		i386
.else
LINUX_ARCH=		${ARCH}
IGNORE=			Linux CentOS ${LINUX_DIST_VER} is unsupported on ${ARCH}
.endif
.elif ${linux_ARGS} == c7
LINUX_DIST_VER?=	7.6.1810
.if ${ARCH} == amd64
LINUX_ARCH=		x86_64
.elif ${ARCH} == i386
LINUX_ARCH=		i386
.else
LINUX_ARCH=		${ARCH}
IGNORE=			Linux CentOS ${LINUX_DIST_VER} is unsupported on ${ARCH}
.endif
.else
IGNORE=			Invalid Linux distribution: ${linux_ARGS}
.endif

linux_allegro_DEP=		linux-${linux_ARGS}-allegro>0:devel/linux-${linux_ARGS}-allegro
linux_alsa-plugins-oss_DEP=	linux-${linux_ARGS}-alsa-plugins-oss>0:audio/linux-${linux_ARGS}-alsa-plugins-oss
linux_alsa-plugins-pulseaudio_DEP=linux-${linux_ARGS}-alsa-plugins-pulseaudio>0:audio/linux-${linux_ARGS}-alsa-plugins-pulseaudio
linux_alsalib_DEP=		linux-${linux_ARGS}-alsa-lib>0:audio/linux-${linux_ARGS}-alsa-lib
linux_atk_DEP=			linux-${linux_ARGS}-atk>0:accessibility/linux-${linux_ARGS}-atk
linux_avahi-libs_DEP=		linux-${linux_ARGS}-avahi-libs>0:net/linux-${linux_ARGS}-avahi-libs
linux_base_DEP=			linux_base-${linux_ARGS}>0:emulators/linux_base-${linux_ARGS}
linux_cairo_DEP=		linux-${linux_ARGS}-cairo>0:graphics/linux-${linux_ARGS}-cairo
linux_cups-libs_DEP=		linux-${linux_ARGS}-cups-libs>0:print/linux-${linux_ARGS}-cups-libs
linux_curl_DEP=			linux-${linux_ARGS}-curl>0:ftp/linux-${linux_ARGS}-curl
linux_cyrus-sasl2_DEP=		linux-${linux_ARGS}-cyrus-sasl-lib>0:security/linux-${linux_ARGS}-cyrus-sasl2
linux_dbusglib_DEP=		linux-${linux_ARGS}-dbus-glib>0:devel/linux-${linux_ARGS}-dbus-glib
linux_dbuslibs_DEP=		linux-${linux_ARGS}-dbus-libs>0:devel/linux-${linux_ARGS}-dbus-libs
linux_devtools_DEP=		linux-${linux_ARGS}-devtools>0:devel/linux-${linux_ARGS}-devtools
linux_dri_DEP=			linux-${linux_ARGS}-dri>0:graphics/linux-${linux_ARGS}-dri
linux_expat_DEP=		linux-${linux_ARGS}-expat>0:textproc/linux-${linux_ARGS}-expat
.if ${linux_ARGS} == c6
linux_flac_DEP=			linux-${linux_ARGS}-flac>0:audio/linux-${linux_ARGS}-flac
.else
linux_flac_DEP=			linux-${linux_ARGS}-flac-libs>0:audio/linux-${linux_ARGS}-flac
.endif
linux_fontconfig_DEP=		linux-${linux_ARGS}-fontconfig>0:x11-fonts/linux-${linux_ARGS}-fontconfig
linux_freetype_DEP=		linux-${linux_ARGS}-freetype>0:print/linux-${linux_ARGS}-freetype
linux_fribidi_DEP=		linux-${linux_ARGS}-fribidi>0:converters/linux-${linux_ARGS}-fribidi
linux_gdkpixbuf2_DEP=		linux-${linux_ARGS}-gdk-pixbuf2>0:graphics/linux-${linux_ARGS}-gdk-pixbuf2
linux_gnutls_DEP=		linux-${linux_ARGS}-gnutls>0:security/linux-${linux_ARGS}-gnutls
linux_graphite2_DEP=		linux-${linux_ARGS}-graphite2>0:graphics/linux-${linux_ARGS}-graphite2
linux_gtk2_DEP=			linux-${linux_ARGS}-gtk2>0:x11-toolkits/linux-${linux_ARGS}-gtk2
linux_harfbuzz_DEP=		linux-${linux_ARGS}-harfbuzz>0:print/linux-${linux_ARGS}-harfbuzz
linux_icu_DEP=			linux-${linux_ARGS}-icu>0:devel/linux-${linux_ARGS}-icu
linux_jasper_DEP=		linux-${linux_ARGS}-jasper-libs>0:graphics/linux-${linux_ARGS}-jasper
linux_jbigkit_DEP=		linux-${linux_ARGS}-jbigkit-libs>0:graphics/linux-${linux_ARGS}-jbigkit
linux_jpeg_DEP=			linux-${linux_ARGS}-jpeg>0:graphics/linux-${linux_ARGS}-jpeg
linux_libasyncns_DEP=		linux-${linux_ARGS}-libasyncns>0:dns/linux-${linux_ARGS}-libasyncns
.if ${linux_ARGS} == c6
linux_libaudiofile_DEP=		linux-${linux_ARGS}-audiofile>0:audio/linux-${linux_ARGS}-libaudiofile
.else
linux_libaudiofile_DEP=		linux-${linux_ARGS}-audiofile>0:audio/linux-${linux_ARGS}-audiofile
.endif
linux_libelf_DEP=		linux-${linux_ARGS}-elfutils-libelf>0:devel/linux-${linux_ARGS}-libelf
linux_libgcrypt_DEP=		linux-${linux_ARGS}-libgcrypt>0:security/linux-${linux_ARGS}-libgcrypt
linux_libgfortran_DEP=		linux-${linux_ARGS}-libgfortran>0:devel/linux-${linux_ARGS}-libgfortran
linux_libglvnd_DEP=		linux-${linux_ARGS}-libglvnd>0:graphics/linux-${linux_ARGS}-libglvnd
linux_libgpg-error_DEP=		linux-${linux_ARGS}-libgpg-error>0:security/linux-${linux_ARGS}-libgpg-error
linux_libmng_DEP=		linux-${linux_ARGS}-libmng>0:graphics/linux-${linux_ARGS}-libmng
linux_libogg_DEP=		linux-${linux_ARGS}-libogg>0:audio/linux-${linux_ARGS}-libogg
linux_libpciaccess_DEP=		linux-${linux_ARGS}-libpciaccess>0:devel/linux-${linux_ARGS}-libpciaccess
linux_libsndfile_DEP=		linux-${linux_ARGS}-libsndfile>0:audio/linux-${linux_ARGS}-libsndfile
linux_libsoup_DEP=		linux-${linux_ARGS}-libsoup>0:devel/linux-${linux_ARGS}-libsoup
linux_libssh2_DEP=		linux-${linux_ARGS}-libssh2>0:security/linux-${linux_ARGS}-libssh2
linux_libtasn1_DEP=		linux-${linux_ARGS}-libtasn1>0:security/linux-${linux_ARGS}-libtasn1
linux_libthai_DEP=		linux-${linux_ARGS}-libthai>0:devel/linux-${linux_ARGS}-libthai
linux_libtheora_DEP=		linux-${linux_ARGS}-libtheora>0:multimedia/linux-${linux_ARGS}-libtheora
linux_libunwind_DEP=		linux-${linux_ARGS}-libunwind>0:devel/linux-${linux_ARGS}-libunwind
linux_libv4l_DEP=		linux-${linux_ARGS}-libv4l>0:multimedia/linux-${linux_ARGS}-libv4l
linux_libvorbis_DEP=		linux-${linux_ARGS}-libvorbis>0:audio/linux-${linux_ARGS}-libvorbis
linux_libxml2_DEP=		linux-${linux_ARGS}-libxml2>0:textproc/linux-${linux_ARGS}-libxml2
linux_lttng-ust_DEP=		linux-${linux_ARGS}-lttng-ust>0:sysutils/linux-${linux_ARGS}-lttng-ust
linux_mikmod_DEP=		linux-${linux_ARGS}-libmikmod>0:audio/linux-${linux_ARGS}-mikmod
linux_naslibs_DEP=		linux-${linux_ARGS}-nas>0:audio/linux-${linux_ARGS}-nas-libs
linux_nettle_DEP=		linux-${linux_ARGS}-nettle>0:security/linux-${linux_ARGS}-nettle
linux_nspr_DEP=			linux-${linux_ARGS}-nspr>0:devel/linux-${linux_ARGS}-nspr
linux_nss_DEP=			linux-${linux_ARGS}-nss>0:security/linux-${linux_ARGS}-nss
linux_openal_DEP=		linux-${linux_ARGS}-openal>0:audio/linux-${linux_ARGS}-openal
linux_openal-soft_DEP=		linux-${linux_ARGS}-openal-soft>0:audio/linux-${linux_ARGS}-openal-soft
linux_openldap_DEP=		linux-${linux_ARGS}-openldap>0:net/linux-${linux_ARGS}-openldap
.if ${linux_ARGS} == c6
linux_openmotif_DEP=		linux-${linux_ARGS}-openmotif>0:x11-toolkits/linux-${linux_ARGS}-openmotif
.else
linux_openmotif_DEP=		linux-${linux_ARGS}-motif>0:x11-toolkits/linux-${linux_ARGS}-openmotif
.endif
.if ${linux_ARGS} == c6
linux_openssl_DEP=		linux-${linux_ARGS}-openssl>0:security/linux-${linux_ARGS}-openssl
.else
linux_openssl_DEP=		linux-${linux_ARGS}-openssl-libs>0:security/linux-${linux_ARGS}-openssl
.endif
linux_p11-kit_DEP=		linux-${linux_ARGS}-p11-kit>0:security/linux-${linux_ARGS}-p11-kit
linux_pango_DEP=		linux-${linux_ARGS}-pango>0:x11-toolkits/linux-${linux_ARGS}-pango
linux_pixman_DEP=		linux-${linux_ARGS}-pixman>0:x11/linux-${linux_ARGS}-pixman
linux_png_DEP=			linux-${linux_ARGS}-libpng>0:graphics/linux-${linux_ARGS}-png
linux_pulseaudio-libs_DEP=	linux-${linux_ARGS}-pulseaudio-libs>0:audio/linux-${linux_ARGS}-pulseaudio-libs
.if ${linux_ARGS} == c6
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
linux_tiff_DEP=			linux-${linux_ARGS}-libtiff>0:graphics/linux-${linux_ARGS}-tiff
linux_tk85_DEP=			linux-${linux_ARGS}-tk85>0:x11-toolkits/linux-${linux_ARGS}-tk85
linux_trousers_DEP=		linux-${linux_ARGS}-trousers>0:security/linux-${linux_ARGS}-trousers
linux_ucl_DEP=			linux-${linux_ARGS}-ucl>0:archivers/linux-${linux_ARGS}-ucl
linux_userspace-rcu_DEP=	linux-${linux_ARGS}-userspace-rcu>0:sysutils/linux-${linux_ARGS}-userspace-rcu
linux_wayland_DEP=		linux-${linux_ARGS}-wayland>0:graphics/linux-${linux_ARGS}-wayland
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
.if !defined(linux_${i:C/:.*//}_DEP)
DEV_ERROR+=		"USE_LINUX=${i}: package does not exist"
.endif
.endfor

.ifdef USE_LINUX_RPM

DISTVERSIONSUFFIX?=	-${RPMVERSION}

.if ${linux_ARGS} == c6
.ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_CENTOS_LINUX}
MASTER_SITE_SUBDIR=	centos/${LINUX_DIST_VER}/os/x86_64/Packages/:DEFAULT,amd64 \
			centos/${LINUX_DIST_VER}/updates/x86_64/Packages/:DEFAULT,amd64 \
			centos/${LINUX_DIST_VER}/os/i386/Packages/:DEFAULT,i386 \
			centos/${LINUX_DIST_VER}/updates/i386/Packages/:DEFAULT,i386 \
			centos/${LINUX_DIST_VER}/os/Source/SPackages/:SOURCE \
			centos/${LINUX_DIST_VER}/updates/Source/SPackages/:SOURCE
.endif
DIST_SUBDIR?=		centos
.elif ${linux_ARGS} == c7
.ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_CENTOS_LINUX}
MASTER_SITE_SUBDIR=	centos/${LINUX_DIST_VER}/os/x86_64/Packages/:DEFAULT,amd64 \
			centos/${LINUX_DIST_VER}/updates/x86_64/Packages/:DEFAULT,amd64 \
			altarch/${LINUX_DIST_VER}/os/i386/Packages/:DEFAULT,i386 \
			altarch/${LINUX_DIST_VER}/updates/i386/Packages/:DEFAULT,i386 \
			centos/${LINUX_DIST_VER}/os/Source/SPackages/:SOURCE \
			centos/${LINUX_DIST_VER}/updates/Source/SPackages/:SOURCE
.endif
DIST_SUBDIR?=		centos
.endif # ${linux_ARGS} == *

PKGNAMEPREFIX?=		linux-${linux_ARGS}-
EXTRACT_SUFX?=		.rpm
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
EXTRACT_SUFX_i386?=	.i686${EXTRACT_SUFX}
EXTRACT_SUFX_noarch?=	.noarch${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

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
SHARE_DISTNAMES?=	${DISTNAME}
.elif ${USE_LINUX_RPM} == nolib
BIN_DISTNAMES?=		${DISTNAME}
.else
LIB_DISTNAMES?=		${DISTNAME}
.endif
.if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:Mamd64)) \
 && empty(NOT_FOR_ARCHS:Mamd64)
.if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:Mi386)) \
 && empty(NOT_FOR_ARCHS:Mi386)
DISTFILES_amd64?=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
			${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
			${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
			${SHARE_DISTNAMES:S/$/${EXTRACT_SUFX_noarch}/}
.else
DISTFILES_amd64?=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}/} \
			${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}/} \
			${SHARE_DISTNAMES:S/$/${EXTRACT_SUFX_noarch}/}
.endif
.endif
.if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:Mi386)) \
 && empty(NOT_FOR_ARCHS:Mi386)
DISTFILES_i386?=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
			${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:i386/} \
			${SHARE_DISTNAMES:S/$/${EXTRACT_SUFX_noarch}/}
.endif
SRC_DISTFILES?=		${DISTNAME}${SRC_SUFX}:SOURCE

.ifdef USE_LINUX_RPM_BAD_PERMS
EXTRACT_DEPENDS+=	rpm2archive:archivers/rpm4
EXTRACT_CMD=		rpm2archive
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	| ${TAR} xf - --no-same-owner --no-same-permissions
.endif

.if ${USE_LINUX_RPM} != noarch
PLIST?=			${PKGDIR}/pkg-plist.${LINUX_ARCH:S/x86_64/amd64/}
.endif

.if !target(do-install)
do-install:
	(cd ${WRKSRC} && \
		${FIND} * | ${CPIO} -dumpl --quiet ${STAGEDIR}${PREFIX})
.for d in bin lib lib64 sbin
	[ ! -e ${STAGEDIR}${PREFIX}/${d} -o -L ${STAGEDIR}${PREFIX}/${d} ] || \
		(cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${d} | ${CPIO} -dumpl --quiet usr && ${RM} -r ${d})
.endfor
	[ ! -e ${STAGEDIR}${PREFIX}/usr/share/icons -o \
		-L ${STAGEDIR}${PREFIX}/usr/share/icons ] || \
		(cd ${STAGEDIR}${PREFIX}/usr/share && ${FIND} icons | \
		${CPIO} -dumpl --quiet ${STAGEDIR}${LOCALBASE}/share && \
		${RM} -r icons)
.endif

.endif # USE_LINUX_RPM

.ifdef DISTNAME_amd64
DISTFILES_amd64?=	${DISTNAME_amd64}${EXTRACT_SUFX}
.endif
.ifdef DISTNAME_i386
DISTFILES_i386?=	${DISTNAME_i386}${EXTRACT_SUFX}
.endif
.ifndef DISTFILES
.ifdef DISTFILES_amd64 || DISTFILES_i386
.if make(makesum)
_ALL_DISTFILES=		${DISTFILES_amd64} ${DISTFILES_i386}
DISTFILES=		${_ALL_DISTFILES:O:u}
.else
DISTFILES=		${DISTFILES_${LINUX_ARCH:S/x86_64/amd64/}}
.endif
EXTRACT_ONLY?=		${DISTFILES_${LINUX_ARCH:S/x86_64/amd64/}:C/:[^:]+$//}
.endif
.endif
.if !empty(SRC_DISTFILES) && (make(makesum) || defined(PACKAGE_BUILDING))
DISTFILES+=		${SRC_DISTFILES}
.endif

# This triggers on amd64 with DEFAULT_VERSIONS+=linux=c6 (i386 Linux) and
# ports with ONLY_FOR_ARCHS=amd64 or NOT_FOR_ARCHS=i386.  It may be removed
# when c6 becomes an alias for c6_64 on amd64 (after FreeBSD 10.3 EoL).
.if (defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:M${LINUX_ARCH:S/x86_64/amd64/})) \
 || !empty(NOT_FOR_ARCHS:M${LINUX_ARCH:S/x86_64/amd64/})
IGNORE=			does not run on Linux/${LINUX_ARCH}
.endif

.endif # _POSTMKINCLUDED && ! _INCLUDE_USES_LINUX_POST_MK
