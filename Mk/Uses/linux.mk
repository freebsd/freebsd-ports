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
linux_ARGS=		${LINUX_DEFAULT}
.endif
.endif

.if ${linux_ARGS} == c6
LINUX_DIST_VER?=	6.10
.elif ${linux_ARGS} == c7
LINUX_DIST_VER?=	7.7.1908
.else
IGNORE=			Invalid Linux distribution: ${linux_ARGS}
.endif

.ifndef ONLY_FOR_ARCHS
ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	Linux compatibility is only available on amd64 and i386
.endif

_linux_c7_alsa-lib-devel=		linux-c7-alsa-lib-devel>0:audio/linux-c7-alsa-lib-devel
_linux_${linux_ARGS}_alsa-plugins-oss=	linux-${linux_ARGS}-alsa-plugins-oss>0:audio/linux-${linux_ARGS}-alsa-plugins-oss
_linux_${linux_ARGS}_alsa-plugins-pulseaudio=linux-${linux_ARGS}-alsa-plugins-pulseaudio>0:audio/linux-${linux_ARGS}-alsa-plugins-pulseaudio
_linux_${linux_ARGS}_alsalib=		linux-${linux_ARGS}-alsa-lib>0:audio/linux-${linux_ARGS}-alsa-lib
_linux_c7_at-spi2-atk=			linux-c7-at-spi2-atk>0:accessibility/linux-c7-at-spi2-atk
_linux_c7_at-spi2-core=			linux-c7-at-spi2-core>0:accessibility/linux-c7-at-spi2-core
_linux_${linux_ARGS}_atk=		linux-${linux_ARGS}-atk>0:accessibility/linux-${linux_ARGS}-atk
_linux_${linux_ARGS}_avahi-libs=	linux-${linux_ARGS}-avahi-libs>0:net/linux-${linux_ARGS}-avahi-libs
_linux_c6_base=				linux_base-c6>=6.10:emulators/linux_base-c6
_linux_c7_base=				linux_base-c7>=7.6.1810_7:emulators/linux_base-c7
_linux_${linux_ARGS}_cairo=		linux-${linux_ARGS}-cairo>0:graphics/linux-${linux_ARGS}-cairo
_linux_c7_cairo-gobject=		linux-c7-cairo-gobject>0:graphics/linux-c7-cairo-gobject
_linux_${linux_ARGS}_cups-libs=		linux-${linux_ARGS}-cups-libs>0:print/linux-${linux_ARGS}-cups-libs
_linux_${linux_ARGS}_curl=		linux-${linux_ARGS}-curl>0:ftp/linux-${linux_ARGS}-curl
_linux_${linux_ARGS}_cyrus-sasl2=	linux-${linux_ARGS}-cyrus-sasl-lib>0:security/linux-${linux_ARGS}-cyrus-sasl2
_linux_${linux_ARGS}_dbusglib=		linux-${linux_ARGS}-dbus-glib>0:devel/linux-${linux_ARGS}-dbus-glib
_linux_${linux_ARGS}_dbuslibs=		linux-${linux_ARGS}-dbus-libs>0:devel/linux-${linux_ARGS}-dbus-libs
_linux_${linux_ARGS}_devtools=		linux-${linux_ARGS}-devtools>0:devel/linux-${linux_ARGS}-devtools
_linux_${linux_ARGS}_dri=		linux-${linux_ARGS}-dri>0:graphics/linux-${linux_ARGS}-dri
_linux_${linux_ARGS}_elfutils-libelf=	linux-${linux_ARGS}-elfutils-libelf>0:devel/linux-${linux_ARGS}-elfutils-libelf
_linux_c7_elfutils-libs=		linux-c7-elfutils-libs>0:devel/linux-c7-elfutils-libs
_linux_${linux_ARGS}_expat=		linux-${linux_ARGS}-expat>0:textproc/linux-${linux_ARGS}-expat
_linux_c6_flac=				linux-c6-flac>0:audio/linux-c6-flac
_linux_c7_flac=				linux-c7-flac-libs>0:audio/linux-c7-flac
_linux_${linux_ARGS}_fontconfig=	linux-${linux_ARGS}-fontconfig>0:x11-fonts/linux-${linux_ARGS}-fontconfig
_linux_c7_freetype=			linux-c7-freetype>0:print/linux-c7-freetype
_linux_c7_fribidi=			linux-c7-fribidi>0:converters/linux-c7-fribidi
_linux_${linux_ARGS}_gdkpixbuf2=	linux-${linux_ARGS}-gdk-pixbuf2>0:graphics/linux-${linux_ARGS}-gdk-pixbuf2
_linux_${linux_ARGS}_gnutls=		linux-${linux_ARGS}-gnutls>0:security/linux-${linux_ARGS}-gnutls
_linux_c7_graphite2=			linux-c7-graphite2>0:graphics/linux-c7-graphite2
_linux_${linux_ARGS}_gtk2=		linux-${linux_ARGS}-gtk2>0:x11-toolkits/linux-${linux_ARGS}-gtk2
_linux_c7_gtk3=				linux-c7-gtk3>0:x11-toolkits/linux-c7-gtk3
_linux_c7_harfbuzz=			linux-c7-harfbuzz>0:print/linux-c7-harfbuzz
_linux_${linux_ARGS}_icu=		linux-${linux_ARGS}-icu>0:devel/linux-${linux_ARGS}-icu
_linux_${linux_ARGS}_jasper=		linux-${linux_ARGS}-jasper-libs>0:graphics/linux-${linux_ARGS}-jasper
_linux_c7_jbigkit=			linux-c7-jbigkit-libs>0:graphics/linux-c7-jbigkit
_linux_${linux_ARGS}_jpeg=		linux-${linux_ARGS}-jpeg>0:graphics/linux-${linux_ARGS}-jpeg
_linux_${linux_ARGS}_libasyncns=	linux-${linux_ARGS}-libasyncns>0:dns/linux-${linux_ARGS}-libasyncns
_linux_c6_libaudiofile=			linux-c6-audiofile>0:audio/linux-c6-libaudiofile
_linux_c7_libaudiofile=			linux-c7-audiofile>0:audio/linux-c7-audiofile
_linux_c7_libdrm=			linux-c7-libdrm>0:graphics/linux-c7-libdrm
_linux_c7_libepoxy=			linux-c7-libepoxy>0:graphics/linux-c7-libepoxy
_linux_${linux_ARGS}_libgcrypt=		linux-${linux_ARGS}-libgcrypt>0:security/linux-${linux_ARGS}-libgcrypt
_linux_${linux_ARGS}_libgfortran=	linux-${linux_ARGS}-libgfortran>0:devel/linux-${linux_ARGS}-libgfortran
_linux_c7_libglvnd=			linux-c7-libglvnd>0:graphics/linux-c7-libglvnd
_linux_${linux_ARGS}_libgpg-error=	linux-${linux_ARGS}-libgpg-error>0:security/linux-${linux_ARGS}-libgpg-error
_linux_${linux_ARGS}_libogg=		linux-${linux_ARGS}-libogg>0:audio/linux-${linux_ARGS}-libogg
_linux_${linux_ARGS}_libpciaccess=	linux-${linux_ARGS}-libpciaccess>0:devel/linux-${linux_ARGS}-libpciaccess
_linux_${linux_ARGS}_libsndfile=	linux-${linux_ARGS}-libsndfile>0:audio/linux-${linux_ARGS}-libsndfile
_linux_c6_libsoup=			linux-c6-libsoup>0:devel/linux-c6-libsoup
_linux_${linux_ARGS}_libssh2=		linux-${linux_ARGS}-libssh2>0:security/linux-${linux_ARGS}-libssh2
_linux_${linux_ARGS}_libtasn1=		linux-${linux_ARGS}-libtasn1>0:security/linux-${linux_ARGS}-libtasn1
_linux_${linux_ARGS}_libthai=		linux-${linux_ARGS}-libthai>0:devel/linux-${linux_ARGS}-libthai
_linux_${linux_ARGS}_libtheora=		linux-${linux_ARGS}-libtheora>0:multimedia/linux-${linux_ARGS}-libtheora
_linux_${linux_ARGS}_libunwind=		linux-${linux_ARGS}-libunwind>0:devel/linux-${linux_ARGS}-libunwind
_linux_${linux_ARGS}_libv4l=		linux-${linux_ARGS}-libv4l>0:multimedia/linux-${linux_ARGS}-libv4l
_linux_${linux_ARGS}_libvorbis=		linux-${linux_ARGS}-libvorbis>0:audio/linux-${linux_ARGS}-libvorbis
_linux_c7_libxkbcommon=			linux-c7-libxkbcommon>0:x11/linux-c7-libxkbcommon
_linux_${linux_ARGS}_libxml2=		linux-${linux_ARGS}-libxml2>0:textproc/linux-${linux_ARGS}-libxml2
_linux_${linux_ARGS}_lttng-ust=		linux-${linux_ARGS}-lttng-ust>0:sysutils/linux-${linux_ARGS}-lttng-ust
_linux_c7_lz4=				linux-c7-lz4>0:archivers/linux-c7-lz4
_linux_c7_make=				linux-c7-make>0:devel/linux-c7-make
_linux_c6_mikmod=			linux-c6-libmikmod>0:audio/linux-c6-mikmod
_linux_c6_naslibs=			linux-c6-nas>0:audio/linux-c6-nas-libs
_linux_c7_nettle=			linux-c7-nettle>0:security/linux-c7-nettle
_linux_${linux_ARGS}_nspr=		linux-${linux_ARGS}-nspr>0:devel/linux-${linux_ARGS}-nspr
_linux_${linux_ARGS}_nss=		linux-${linux_ARGS}-nss>0:security/linux-${linux_ARGS}-nss
_linux_${linux_ARGS}_openal-soft=	linux-${linux_ARGS}-openal-soft>0:audio/linux-${linux_ARGS}-openal-soft
_linux_${linux_ARGS}_openldap=		linux-${linux_ARGS}-openldap>0:net/linux-${linux_ARGS}-openldap
_linux_c6_openmotif=			linux-c6-openmotif>0:x11-toolkits/linux-c6-openmotif
_linux_c7_openmotif=			linux-c7-motif>0:x11-toolkits/linux-c7-openmotif
_linux_c6_openssl=			linux-c6-openssl>0:security/linux-c6-openssl
_linux_c7_openssl=			${_linux_c7_base}
_linux_c7_p11-kit=			linux-c7-p11-kit>0:security/linux-c7-p11-kit
_linux_${linux_ARGS}_pango=		linux-${linux_ARGS}-pango>0:x11-toolkits/linux-${linux_ARGS}-pango
_linux_${linux_ARGS}_pixman=		linux-${linux_ARGS}-pixman>0:x11/linux-${linux_ARGS}-pixman
_linux_${linux_ARGS}_png=		linux-${linux_ARGS}-libpng>0:graphics/linux-${linux_ARGS}-png
_linux_${linux_ARGS}_pulseaudio-libs=	linux-${linux_ARGS}-pulseaudio-libs>0:audio/linux-${linux_ARGS}-pulseaudio-libs
_linux_c6_qt=				linux-c6-qt47>0:devel/linux-c6-qt47
_linux_c7_qt=				linux-c7-qt>0:devel/linux-c7-qt
_linux_c6_qt-x11=			linux-c6-qt47-x11>0:x11-toolkits/linux-c6-qt47-x11
_linux_c7_qt-x11=			linux-c7-qt-x11>0:x11-toolkits/linux-c7-qt-x11
_linux_c6_qtwebkit=			linux-c6-qt47-webkit>0:www/linux-c6-qt47-webkit
_linux_c7_qtwebkit=			linux-c7-qtwebkit>0:www/linux-c7-qtwebkit
_linux_${linux_ARGS}_sdl12=		linux-${linux_ARGS}-sdl>0:devel/linux-${linux_ARGS}-sdl12
_linux_${linux_ARGS}_sdlimage=		linux-${linux_ARGS}-sdl_image>0:graphics/linux-${linux_ARGS}-sdl_image
_linux_${linux_ARGS}_sdlmixer=		linux-${linux_ARGS}-sdl_mixer>0:audio/linux-${linux_ARGS}-sdl_mixer
_linux_${linux_ARGS}_sdlttf=		linux-${linux_ARGS}-sdl_ttf>0:graphics/linux-${linux_ARGS}-sdl_ttf
_linux_${linux_ARGS}_sqlite3=		linux-${linux_ARGS}-sqlite>0:databases/linux-${linux_ARGS}-sqlite3
_linux_c7_systemd-libs=			linux-c7-systemd-libs>0:devel/linux-c7-systemd-libs
_linux_${linux_ARGS}_tcl85=		linux-${linux_ARGS}-tcl85>0:lang/linux-${linux_ARGS}-tcl85
_linux_${linux_ARGS}_tcp_wrappers-libs=	linux-${linux_ARGS}-tcp_wrappers-libs>0:net/linux-${linux_ARGS}-tcp_wrappers-libs
_linux_${linux_ARGS}_tiff=		linux-${linux_ARGS}-libtiff>0:graphics/linux-${linux_ARGS}-tiff
_linux_${linux_ARGS}_tk85=		linux-${linux_ARGS}-tk85>0:x11-toolkits/linux-${linux_ARGS}-tk85
_linux_c7_trousers=			linux-c7-trousers>0:security/linux-c7-trousers
_linux_${linux_ARGS}_userspace-rcu=	linux-${linux_ARGS}-userspace-rcu>0:sysutils/linux-${linux_ARGS}-userspace-rcu
_linux_c7_wayland=			linux-c7-wayland>0:graphics/linux-c7-wayland
_linux_c6_xorglibs=			linux-c6-xorg-libs>0:x11/linux-c6-xorg-libs
_linux_c7_xorglibs=			linux-c7-xorg-libs>=7.7_7:x11/linux-c7-xorg-libs

USE_LINUX?=		base
.for i in ${USE_LINUX}
_i_args:=		${i:C/^[^:]*:?//:S/,/ /g}
.if ${_i_args:Mpatch}
PATCH_DEPENDS+=		${_linux_${linux_ARGS}_${i:C/:.*//}}
.endif
.if ${_i_args:Mbuild}
BUILD_DEPENDS+=		${_linux_${linux_ARGS}_${i:C/:.*//}}
.endif
.if ${_i_args:Mrun} || empty(_i_args)
RUN_DEPENDS+=		${_linux_${linux_ARGS}_${i:C/:.*//}}
.endif
.if !defined(_linux_${linux_ARGS}_${i:C/:.*//})
DEV_ERROR+=		"USE_LINUX=${i}: package does not exist"
.endif
.endfor

.ifdef USE_LINUX_RPM

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
DEPRECATED=		Superseded by CentOS 7
EXPIRATION_DATE=	2019-12-31
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
PLIST?=			${PKGDIR}/pkg-plist.${ARCH}
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
DISTFILES=		${DISTFILES_${ARCH}}
.endif
EXTRACT_ONLY?=		${DISTFILES_${ARCH}:C/:[^:]+$//}
.endif
.endif
.if !empty(SRC_DISTFILES) && (make(makesum) || defined(PACKAGE_BUILDING))
DISTFILES+=		${SRC_DISTFILES}
.endif

.endif # _POSTMKINCLUDED && ! _INCLUDE_USES_LINUX_POST_MK
