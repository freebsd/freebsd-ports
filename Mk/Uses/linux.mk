# Ports Linux compatibility framework
#
# Feature:	linux:args
# Usage:	USES=linux or USES=linux:args
# Valid args:	c7	Depend on CentOS 7 packages (default)
#		rl9	Depend on Rocky Linux 9 packages
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

.  if empty(linux_ARGS)
.    if exists(${LINUXBASE}/etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7)
linux_ARGS=		c7
.    elif exists(${LINUXBASE}/etc/pki/rpm-gpg/RPM-GPG-KEY-Rocky-9)
linux_ARGS=		rl9
.    else
linux_ARGS=		${LINUX_DEFAULT}
.    endif
.  endif

.  if ${linux_ARGS} == c7
LINUX_DIST_VER?=	7.9.2009
.  elif ${linux_ARGS} == rl9
LINUX_DIST_VER?=	9.4
.  else
ERROR+=			"Invalid Linux distribution: ${linux_ARGS}"
.  endif

.  ifndef ONLY_FOR_ARCHS
.    if ${linux_ARGS} == rl9
ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Rocky Linux compatibility is only available on aarch64 and amd64
.    else
ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	CentOS Linux compatibility is only available on aarch64, amd64 and i386
.    endif
.  endif

_linux_${linux_ARGS}_alsa-lib-devel=	linux-${linux_ARGS}-alsa-lib-devel>0:audio/linux-${linux_ARGS}-alsa-lib-devel
_linux_${linux_ARGS}_alsa-plugins-oss=	linux-${linux_ARGS}-alsa-plugins-oss>0:audio/linux-${linux_ARGS}-alsa-plugins-oss
_linux_${linux_ARGS}_alsa-plugins-pulseaudio=linux-${linux_ARGS}-alsa-plugins-pulseaudio>0:audio/linux-${linux_ARGS}-alsa-plugins-pulseaudio
_linux_${linux_ARGS}_alsalib=		linux-${linux_ARGS}-alsa-lib>0:audio/linux-${linux_ARGS}-alsa-lib
_linux_${linux_ARGS}_at-spi2-atk=	linux-${linux_ARGS}-at-spi2-atk>0:accessibility/linux-${linux_ARGS}-at-spi2-atk
_linux_${linux_ARGS}_at-spi2-core=	linux-${linux_ARGS}-at-spi2-core>0:accessibility/linux-${linux_ARGS}-at-spi2-core
_linux_${linux_ARGS}_atk=		linux-${linux_ARGS}-atk>0:accessibility/linux-${linux_ARGS}-atk
_linux_${linux_ARGS}_avahi-libs=	linux-${linux_ARGS}-avahi-libs>0:net/linux-${linux_ARGS}-avahi-libs
_linux_c7_base=				linux_base-c7>=7.6.1810_7:emulators/linux_base-c7
_linux_rl9_base=			linux_base-rl9>=9.2:emulators/linux_base-rl9
_linux_rl9_brotli=			linux-rl9-brotli>0:archivers/linux-rl9-brotli
_linux_${linux_ARGS}_ca-certificates=	linux-${linux_ARGS}-ca-certificates>0:security/linux-${linux_ARGS}-ca-certificates
_linux_${linux_ARGS}_cairo=		linux-${linux_ARGS}-cairo>0:graphics/linux-${linux_ARGS}-cairo
_linux_${linux_ARGS}_cairo-gobject=	linux-${linux_ARGS}-cairo-gobject>0:graphics/linux-${linux_ARGS}-cairo-gobject
_linux_${linux_ARGS}_cups-libs=		linux-${linux_ARGS}-cups-libs>0:print/linux-${linux_ARGS}-cups-libs
_linux_${linux_ARGS}_curl=		linux-${linux_ARGS}-curl>0:ftp/linux-${linux_ARGS}-curl
_linux_${linux_ARGS}_cyrus-sasl2=	linux-${linux_ARGS}-cyrus-sasl-lib>0:security/linux-${linux_ARGS}-cyrus-sasl2
_linux_${linux_ARGS}_dbuslibs=		linux-${linux_ARGS}-dbus-libs>0:devel/linux-${linux_ARGS}-dbus-libs
_linux_${linux_ARGS}_devtools=		linux-${linux_ARGS}-devtools>0:devel/linux-${linux_ARGS}-devtools
_linux_c7_dosfstools=			linux-c7-dosfstools>0:sysutils/linux-c7-dosfstools
_linux_${linux_ARGS}_dri=		linux-${linux_ARGS}-dri>0:graphics/linux-${linux_ARGS}-dri
_linux_${linux_ARGS}_elfutils-libelf=	linux-${linux_ARGS}-elfutils-libelf>0:devel/linux-${linux_ARGS}-elfutils-libelf
_linux_${linux_ARGS}_elfutils-libs=	linux-${linux_ARGS}-elfutils-libs>0:devel/linux-${linux_ARGS}-elfutils-libs
_linux_c7_expat-devel=			linux-c7-expat-devel>0:textproc/linux-c7-expat-devel
_linux_${linux_ARGS}_expat=		linux-${linux_ARGS}-expat>0:textproc/linux-${linux_ARGS}-expat
_linux_rl9_ffmpeg-libs=			linux-rl9-ffmpeg-libs>0:multimedia/linux-rl9-ffmpeg
_linux_${linux_ARGS}_flac=		linux-${linux_ARGS}-flac-libs>0:audio/linux-${linux_ARGS}-flac
_linux_${linux_ARGS}_fontconfig=	linux-${linux_ARGS}-fontconfig>0:x11-fonts/linux-${linux_ARGS}-fontconfig
_linux_${linux_ARGS}_freetype=		linux-${linux_ARGS}-freetype>0:print/linux-${linux_ARGS}-freetype
_linux_${linux_ARGS}_fribidi=		linux-${linux_ARGS}-fribidi>0:converters/linux-${linux_ARGS}-fribidi
_linux_${linux_ARGS}_gdkpixbuf2=	linux-${linux_ARGS}-gdk-pixbuf2>0:graphics/linux-${linux_ARGS}-gdk-pixbuf2
_linux_rl9_gnupg=			linux-rl9-gnupg2>0:security/linux-rl9-gnupg
_linux_${linux_ARGS}_gnutls=		linux-${linux_ARGS}-gnutls>0:security/linux-${linux_ARGS}-gnutls
_linux_${linux_ARGS}_graphite2=		linux-${linux_ARGS}-graphite2>0:graphics/linux-${linux_ARGS}-graphite2
_linux_${linux_ARGS}_gsm=		linux-${linux_ARGS}-gsm>0:audio/linux-${linux_ARGS}-gsm
_linux_rl9_gstreamer1=			linux-rl9-gstreamer1>0:multimedia/linux-rl9-gstreamer1
_linux_rl9_gstreamer1-libav=		linux-rl9-gstreamer1-libav>0:multimedia/linux-rl9-gstreamer1-libav
_linux_${linux_ARGS}_gtk2=		linux-${linux_ARGS}-gtk2>0:x11-toolkits/linux-${linux_ARGS}-gtk2
_linux_${linux_ARGS}_gtk3=		linux-${linux_ARGS}-gtk3>0:x11-toolkits/linux-${linux_ARGS}-gtk3
_linux_${linux_ARGS}_harfbuzz=		linux-${linux_ARGS}-harfbuzz>0:print/linux-${linux_ARGS}-harfbuzz
_linux_${linux_ARGS}_icu=		linux-${linux_ARGS}-icu>0:devel/linux-${linux_ARGS}-icu
_linux_${linux_ARGS}_jasper=		linux-${linux_ARGS}-jasper-libs>0:graphics/linux-${linux_ARGS}-jasper
_linux_${linux_ARGS}_jbigkit=		linux-${linux_ARGS}-jbigkit-libs>0:graphics/linux-${linux_ARGS}-jbigkit
_linux_${linux_ARGS}_jpeg=		linux-${linux_ARGS}-jpeg>0:graphics/linux-${linux_ARGS}-jpeg
_linux_c7_libaio=			linux-c7-libaio>0:devel/linux-c7-libaio
_linux_rl9_libassuan=			linux-rl9-libassuan>0:security/linux-rl9-libassuan
_linux_${linux_ARGS}_libasyncns=	linux-${linux_ARGS}-libasyncns>0:dns/linux-${linux_ARGS}-libasyncns
_linux_c7_libaudiofile=			linux-c7-audiofile>0:audio/linux-c7-audiofile
_linux_c7_libcroco=			linux-c7-libcroco>0:textproc/linux-c7-libcroco
_linux_${linux_ARGS}_libdrm=		linux-${linux_ARGS}-libdrm>0:graphics/linux-${linux_ARGS}-libdrm
_linux_${linux_ARGS}_libepoxy=		linux-${linux_ARGS}-libepoxy>0:graphics/linux-${linux_ARGS}-libepoxy
_linux_rl9_libevent=			linux-rl9-libevent>0:devel/linux-rl9-libevent
_linux_${linux_ARGS}_libgcrypt=		linux-${linux_ARGS}-libgcrypt>0:security/linux-${linux_ARGS}-libgcrypt
_linux_${linux_ARGS}_libgfortran=	linux-${linux_ARGS}-libgfortran>0:devel/linux-${linux_ARGS}-libgfortran
_linux_${linux_ARGS}_libglvnd=		linux-${linux_ARGS}-libglvnd>0:graphics/linux-${linux_ARGS}-libglvnd
_linux_${linux_ARGS}_libgpg-error=	linux-${linux_ARGS}-libgpg-error>0:security/linux-${linux_ARGS}-libgpg-error
_linux_rl9_libidn2=			linux-${linux_ARGS}-libidn2>0:dns/linux-rl9-libidn2
_linux_rl9_libnghttp2=			linux-${linux_ARGS}-libnghttp2>0:www/linux-rl9-libnghttp2
_linux_${linux_ARGS}_libogg=		linux-${linux_ARGS}-libogg>0:audio/linux-${linux_ARGS}-libogg
_linux_${linux_ARGS}_libpciaccess=	linux-${linux_ARGS}-libpciaccess>0:devel/linux-${linux_ARGS}-libpciaccess
_linux_rl9_libproxy=			linux-rl9-libproxy>0:net/linux-rl9-libproxy
_linux_rl9_libpsl=			linux-rl9-libpsl>0:dns/linux-rl9-libpsl
_linux_${linux_ARGS}_librsvg2=		linux-${linux_ARGS}-librsvg2>0:graphics/linux-${linux_ARGS}-librsvg2
_linux_rl9_libsecret=			linux-rl9-libsecret>0:security/linux-rl9-libsecret
_linux_${linux_ARGS}_libsigc++20=	linux-${linux_ARGS}-libsigc++20>0:devel/linux-${linux_ARGS}-libsigc++20
_linux_rl9_libsigsegv=			linux-${linux_ARGS}-libsigsegv>0:devel/linux-${linux_ARGS}-libsigsegv
_linux_rl9_libsoup=			linux-${linux_ARGS}-libsoup>0:devel/linux-${linux_ARGS}-libsoup
_linux_${linux_ARGS}_libsndfile=	linux-${linux_ARGS}-libsndfile>0:audio/linux-${linux_ARGS}-libsndfile
_linux_c7_libssh2=			linux-c7-libssh2>0:security/linux-c7-libssh2
_linux_${linux_ARGS}_libtasn1=		linux-${linux_ARGS}-libtasn1>0:security/linux-${linux_ARGS}-libtasn1
_linux_${linux_ARGS}_libthai=		linux-${linux_ARGS}-libthai>0:devel/linux-${linux_ARGS}-libthai
_linux_${linux_ARGS}_libtheora=		linux-${linux_ARGS}-libtheora>0:multimedia/linux-${linux_ARGS}-libtheora
_linux_rl9_libtracker-sparql=		linux-rl9-libtracker-sparql>0:databases/linux-rl9-libtracker-sparql
_linux_rl9_libunistring=		linux-rl9-libunistring>0:devel/linux-rl9-libunistring
_linux_${linux_ARGS}_libunwind=		linux-${linux_ARGS}-libunwind>0:devel/linux-${linux_ARGS}-libunwind
_linux_${linux_ARGS}_libv4l=		linux-${linux_ARGS}-libv4l>0:multimedia/linux-${linux_ARGS}-libv4l
_linux_rl9_libva=			linux-rl9-libva>0:multimedia/linux-rl9-libva
_linux_rl9_libvdpau=			linux-rl9-libvdpau>0:multimedia/linux-rl9-libvdpau
_linux_${linux_ARGS}_libvorbis=		linux-${linux_ARGS}-libvorbis>0:audio/linux-${linux_ARGS}-libvorbis
_linux_rl9_libvpx=			linux-rl9-libvpx>0:multimedia/linux-rl9-libvpx
_linux_${linux_ARGS}_libxcrypt=		linux-${linux_ARGS}-libxcrypt>0:security/linux-${linux_ARGS}-libxcrypt
_linux_${linux_ARGS}_libxkbcommon=	linux-${linux_ARGS}-libxkbcommon>0:x11/linux-${linux_ARGS}-libxkbcommon
_linux_${linux_ARGS}_libxml2=		linux-${linux_ARGS}-libxml2>0:textproc/linux-${linux_ARGS}-libxml2
_linux_${linux_ARGS}_libxslt=		linux-${linux_ARGS}-libxslt>0:textproc/linux-${linux_ARGS}-libxslt
_linux_rl9_llvm=			linux-${linux_ARGS}-llvm>0:devel/linux-${linux_ARGS}-llvm
_linux_${linux_ARGS}_lttng-ust=		linux-${linux_ARGS}-lttng-ust>0:sysutils/linux-${linux_ARGS}-lttng-ust
_linux_${linux_ARGS}_lz4=		linux-${linux_ARGS}-lz4>0:archivers/linux-${linux_ARGS}-lz4
_linux_c7_make=				linux-c7-make>0:devel/linux-c7-make
_linux_${linux_ARGS}_nettle=		linux-${linux_ARGS}-nettle>0:security/linux-${linux_ARGS}-nettle
_linux_${linux_ARGS}_nspr=		linux-${linux_ARGS}-nspr>0:devel/linux-${linux_ARGS}-nspr
_linux_${linux_ARGS}_nss=		linux-${linux_ARGS}-nss>0:security/linux-${linux_ARGS}-nss
_linux_c7_numactl-libs=			linux-c7-numactl-libs>0:sysutils/linux-c7-numactl-libs
_linux_rl9_ocl-icd=			linux-rl9-ocl-icd>0:devel/linux-rl9-ocl-icd
_linux_${linux_ARGS}_openal-soft=	linux-${linux_ARGS}-openal-soft>0:audio/linux-${linux_ARGS}-openal-soft
_linux_rl9_openjpeg=			linux-rl9-openjpeg2>0:graphics/linux-rl9-openjpeg
_linux_${linux_ARGS}_openldap=		linux-${linux_ARGS}-openldap>0:net/linux-${linux_ARGS}-openldap
_linux_c7_openmotif=			linux-c7-motif>0:x11-toolkits/linux-c7-openmotif
_linux_c7_openssl-devel=		linux-c7-openssl-devel>0:security/linux-c7-openssl-devel
_linux_c7_openssl=			${_linux_c7_base}
_linux_rl9_opus=			linux-rl9-opus>0:audio/linux-rl9-opus
_linux_rl9_orc=				linux-rl9-orc>0:devel/linux-rl9-orc
_linux_${linux_ARGS}_p11-kit=		linux-${linux_ARGS}-p11-kit>0:security/linux-${linux_ARGS}-p11-kit
_linux_${linux_ARGS}_pango=		linux-${linux_ARGS}-pango>0:x11-toolkits/linux-${linux_ARGS}-pango
_linux_${linux_ARGS}_pixman=		linux-${linux_ARGS}-pixman>0:x11/linux-${linux_ARGS}-pixman
_linux_${linux_ARGS}_png=		linux-${linux_ARGS}-libpng>0:graphics/linux-${linux_ARGS}-png
_linux_${linux_ARGS}_pulseaudio-libs=	linux-${linux_ARGS}-pulseaudio-libs>0:audio/linux-${linux_ARGS}-pulseaudio-libs
_linux_rl9_python3=			linux-rl9-python39>0:lang/linux-rl9-python3
_linux_c7_qt=				linux-c7-qt>0:devel/linux-c7-qt
_linux_c7_qt-x11=			linux-c7-qt-x11>0:x11-toolkits/linux-c7-qt-x11
_linux_c7_qtwebkit=			linux-c7-qtwebkit>0:www/linux-c7-qtwebkit
_linux_${linux_ARGS}_sdl12=		linux-${linux_ARGS}-sdl>0:devel/linux-${linux_ARGS}-sdl12
_linux_${linux_ARGS}_sdlimage=		linux-${linux_ARGS}-sdl_image>0:graphics/linux-${linux_ARGS}-sdl_image
_linux_${linux_ARGS}_sdlmixer=		linux-${linux_ARGS}-sdl_mixer>0:audio/linux-${linux_ARGS}-sdl_mixer
_linux_${linux_ARGS}_sdlttf=		linux-${linux_ARGS}-sdl_ttf>0:graphics/linux-${linux_ARGS}-sdl_ttf
_linux_${linux_ARGS}_sqlite3=		linux-${linux_ARGS}-sqlite>0:databases/linux-${linux_ARGS}-sqlite3
_linux_${linux_ARGS}_strace=		linux-${linux_ARGS}-strace>0:devel/linux-${linux_ARGS}-strace
_linux_${linux_ARGS}_systemd-libs=	linux-${linux_ARGS}-systemd-libs>0:devel/linux-${linux_ARGS}-systemd-libs
_linux_${linux_ARGS}_tcl85=		linux-${linux_ARGS}-tcl85>0:lang/linux-${linux_ARGS}-tcl85
_linux_${linux_ARGS}_tcp_wrappers-libs=	linux-${linux_ARGS}-tcp_wrappers-libs>0:net/linux-${linux_ARGS}-tcp_wrappers-libs
_linux_${linux_ARGS}_tiff=		linux-${linux_ARGS}-libtiff>0:graphics/linux-${linux_ARGS}-tiff
_linux_${linux_ARGS}_tk85=		linux-${linux_ARGS}-tk85>0:x11-toolkits/linux-${linux_ARGS}-tk85
_linux_c7_trousers=			linux-c7-trousers>0:security/linux-c7-trousers
_linux_${linux_ARGS}_userspace-rcu=	linux-${linux_ARGS}-userspace-rcu>0:sysutils/linux-${linux_ARGS}-userspace-rcu
_linux_rl9_vulkan=			linux-rl9-vulkan-loader>0:graphics/linux-rl9-vulkan
_linux_${linux_ARGS}_wayland=		linux-${linux_ARGS}-wayland>0:graphics/linux-${linux_ARGS}-wayland
_linux_rl9_webp=			linux-rl9-libwebp>0:graphics/linux-rl9-webp
_linux_rl9_wget=			linux-rl9-wget>0:ftp/linux-rl9-wget
_linux_c7_xcb-util=			linux-c7-xcb-util>0:x11/linux-c7-xcb-util
_linux_${linux_ARGS}_xorglibs=		linux-${linux_ARGS}-xorg-libs>=7.7:x11/linux-${linux_ARGS}-xorg-libs
_linux_c7_zlib-devel=			linux-c7-zlib-devel>0:devel/linux-c7-zlib-devel
# special node for linux_libusb
_linux_${linux_ARGS}_libusb=		linux_libusb-${linux_ARGS}>0:devel/linux_libusb@${linux_ARGS}

USE_LINUX?=		base
.  for i in ${USE_LINUX}
_i_args:=		${i:C/^[^:]*:?//:S/,/ /g}
.    if ${_i_args:Mpatch}
PATCH_DEPENDS+=		${_linux_${linux_ARGS}_${i:C/:.*//}}
.    endif
.    if ${_i_args:Mbuild}
BUILD_DEPENDS+=		${_linux_${linux_ARGS}_${i:C/:.*//}}
.    endif
.    if ${_i_args:Mrun} || empty(_i_args)
RUN_DEPENDS+=		${_linux_${linux_ARGS}_${i:C/:.*//}}
.    endif
.    if !defined(_linux_${linux_ARGS}_${i:C/:.*//})
DEV_ERROR+=		"USE_LINUX=${i}: package does not exist"
.    endif
.  endfor

.  ifdef USE_LINUX_RPM

.    if ${linux_ARGS} == c7
.      ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_CENTOS_LINUX}
MASTER_SITE_SUBDIR=	altarch/${LINUX_DIST_VER}/os/aarch64/Packages/:DEFAULT,aarch64 \
			altarch/${LINUX_DIST_VER}/updates/aarch64/Packages/:DEFAULT,aarch64 \
			centos/${LINUX_DIST_VER}/os/x86_64/Packages/:DEFAULT,amd64 \
			centos/${LINUX_DIST_VER}/updates/x86_64/Packages/:DEFAULT,amd64 \
			altarch/${LINUX_DIST_VER}/os/i386/Packages/:DEFAULT,i386 \
			altarch/${LINUX_DIST_VER}/updates/i386/Packages/:DEFAULT,i386 \
			centos/${LINUX_DIST_VER}/os/Source/SPackages/:SOURCE \
			centos/${LINUX_DIST_VER}/updates/Source/SPackages/:SOURCE
.      endif
DIST_SUBDIR?=		centos
.    elif ${linux_ARGS} == rl9
.      ifndef MASTER_SITES
MASTER_SITES=		${MASTER_SITE_ROCKY_LINUX}
MASTER_SITE_SUBDIR=	${LINUX_DIST_VER}/BaseOS/aarch64/os/Packages/:DEFAULT,aarch64 \
			${LINUX_DIST_VER}/AppStream/aarch64/os/Packages/:DEFAULT,aarch64 \
			${LINUX_DIST_VER}/BaseOS/x86_64/os/Packages/:DEFAULT,amd64 \
			${LINUX_DIST_VER}/AppStream/x86_64/os/Packages/:DEFAULT,amd64 \
			${LINUX_DIST_VER}/BaseOS/source/tree/Packages/:SOURCE \
			${LINUX_DIST_VER}/AppStream/source/tree/Packages/:SOURCE
.      endif
DIST_SUBDIR?=		rocky
.    endif # ${linux_ARGS} == *

PKGNAMEPREFIX?=		linux-${linux_ARGS}-
EXTRACT_SUFX?=		.rpm
EXTRACT_SUFX_aarch64?=	.aarch64${EXTRACT_SUFX}
EXTRACT_SUFX_amd64?=	.x86_64${EXTRACT_SUFX}
EXTRACT_SUFX_i386?=	.i686${EXTRACT_SUFX}
EXTRACT_SUFX_noarch?=	.noarch${EXTRACT_SUFX}
SRC_SUFX?=		.src${EXTRACT_SUFX}

NO_BUILD=		yes
NO_WRKSUBDIR=		yes
USE_LINUX_PREFIX=	yes

.  endif # USE_LINUX_RPM

.endif # ! _INCLUDE_USES_LINUX_MK

.ifdef _POSTMKINCLUDED && ! _INCLUDE_USES_LINUX_POST_MK
_INCLUDE_USES_LINUX_POST_MK=	yes

.  ifdef USE_LINUX_RPM

.    if ${USE_LINUX_RPM} == noarch
NO_ARCH=		yes
SHARE_DISTNAMES?=	${DISTNAME}
.    elif ${USE_LINUX_RPM} == nolib
BIN_DISTNAMES?=		${DISTNAME}
.    else
LIB_DISTNAMES?=		${DISTNAME}
.    endif
.    if ${linux_ARGS} == rl9
.      if !empty(SHARE_DISTNAMES)
SHARE_DISTNAMES:=	${SHARE_DISTNAMES:C/^[a-z0-9]/&\/&/}
.      endif
.      if !empty(BIN_DISTNAMES)
BIN_DISTNAMES:=		${BIN_DISTNAMES:C/^[a-z0-9]/&\/&/}
.      endif
.      if !empty(LIB_DISTNAMES)
LIB_DISTNAMES:=		${LIB_DISTNAMES:C/^[a-z0-9]/&\/&/}
.      endif
.    endif
.    if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:Maarch64)) \
 && empty(NOT_FOR_ARCHS:Maarch64)
DISTFILES_aarch64?=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_aarch64}:aarch64/} \
			${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_aarch64}:aarch64/} \
			${SHARE_DISTNAMES:S/$/${EXTRACT_SUFX_noarch}/} \
			${LIB_DISTNAMES_aarch64:S/$/${EXTRACT_SUFX_aarch64}:aarch64/}
.    endif
.    if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:Mamd64)) \
 && empty(NOT_FOR_ARCHS:Mamd64)
.      ifndef DISTFILES_amd64
.        if ${linux_ARGS} == c7
DISTFILES_amd64=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
			${LIB_DISTNAMES_i386:S/$/${EXTRACT_SUFX_i386}:amd64,i386/}
.        endif
DISTFILES_amd64+=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
			${LIB_DISTNAMES_amd64:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
			${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_amd64}:amd64/} \
			${SHARE_DISTNAMES:S/$/${EXTRACT_SUFX_noarch}/}
.      endif
.    endif
.    if !(defined(ONLY_FOR_ARCHS) && empty(ONLY_FOR_ARCHS:Mi386)) \
 && empty(NOT_FOR_ARCHS:Mi386)
DISTFILES_i386?=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
			${LIB_DISTNAMES_i386:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
			${BIN_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:i386/} \
			${SHARE_DISTNAMES:S/$/${EXTRACT_SUFX_noarch}/}
.    endif
SRC_DISTFILES?=		${DISTNAME}${SRC_SUFX}:SOURCE
.    if ${linux_ARGS} == rl9
SRC_DISTFILES:=		${SRC_DISTFILES:C/^[a-z0-9]/&\/&/}
.    endif

.    ifdef USE_LINUX_RPM_BAD_PERMS
EXTRACT_DEPENDS+=	rpm2archive:archivers/rpm4
EXTRACT_CMD=		rpm2archive
EXTRACT_BEFORE_ARGS=	- <
EXTRACT_AFTER_ARGS=	| ${TAR} xf - --no-same-owner --no-same-permissions
.    endif

.    if ${USE_LINUX_RPM} != noarch
PLIST?=			${PKGDIR}/pkg-plist.${ARCH}
.    endif

.    if !target(do-install)
do-install:
	(cd ${WRKSRC} && \
		${FIND} * | ${CPIO} -dumpl --quiet ${STAGEDIR}${PREFIX})
.      for d in bin lib lib64 sbin
	[ ! -e ${STAGEDIR}${PREFIX}/${d} -o -L ${STAGEDIR}${PREFIX}/${d} ] || \
		(cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${d} | ${CPIO} -dumpl --quiet usr && ${RM} -r ${d})
.      endfor
	[ ! -e ${STAGEDIR}${PREFIX}/usr/share/icons -o \
		-L ${STAGEDIR}${PREFIX}/usr/share/icons ] || \
		(cd ${STAGEDIR}${PREFIX}/usr/share && ${FIND} icons | \
		${CPIO} -dumpl --quiet ${STAGEDIR}${LOCALBASE}/share && \
		${RM} -r icons)
.    endif

.  endif # USE_LINUX_RPM

.  ifdef DISTNAME_aarch64
DISTFILES_aarch64?=	${DISTNAME_aarch64}${EXTRACT_SUFX}
.  endif
.  ifdef DISTNAME_amd64
DISTFILES_amd64?=	${DISTNAME_amd64}${EXTRACT_SUFX}
.  endif
.  ifdef DISTNAME_i386
DISTFILES_i386?=	${DISTNAME_i386}${EXTRACT_SUFX}
.  endif

.  ifndef DISTFILES
.    ifdef DISTFILES_aarch64 || DISTFILES_amd64 || DISTFILES_i386
.      if make(makesum)
_ALL_DISTFILES=		${DISTFILES_aarch64} ${DISTFILES_amd64} ${DISTFILES_i386}
DISTFILES=		${_ALL_DISTFILES:O:u}
.      else
DISTFILES=		${DISTFILES_${ARCH}}
.      endif
EXTRACT_ONLY?=		${DISTFILES_${ARCH}:C/:[^:]+$//}
.    endif
.  endif
.  if !empty(SRC_DISTFILES) && (make(makesum) || defined(PACKAGE_BUILDING))
DISTFILES+=		${SRC_DISTFILES}
.  endif

.endif # _POSTMKINCLUDED && ! _INCLUDE_USES_LINUX_POST_MK
