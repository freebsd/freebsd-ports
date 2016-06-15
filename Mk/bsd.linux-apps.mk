#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Please view me with 4 column tabs!

# This section defines possible names of linux infrastructure ports
# (components) and all information necessary for ports to use those components.
# 
# Ports can use this as follows:
#
# USE_LINUX_APPS=	esound xorglibs
#
# .include <bsd.port.mk>
#
# As a result proper RUN_DEPENDS will be added.
#
# Variables:
# LINUX_DIST_SUFFIX	- Contains the value which is added to a port's name
#					  (i.e. linux<this_variable>-port ) to get the right
#					  linux infrastructure port.
# _ALL_LINUX_APPS	- A (sorted) list of all linux infrastructure ports
#					  (components), covered here.
# OVERRIDE_LINUX_NONBASE_PORTS
#			- This specifies a none-default linux infrastructure ports to use.
#					  The valid value is "f10" to use Linux Fedora 10 ports.
#					  This is an user-only variable. Don't use it in any port,
#					  it's meant to be used in make.conf.

.if !defined(_POSTMKINCLUDED) && !defined(Linux_APPS_Pre_Include)

Linux_APPS_Include_MAINTAINER=	emulation@FreeBSD.org
Linux_APPS_Pre_Include=			bsd.linux-apps.mk

.endif

.if defined(_POSTMKINCLUDED) && !defined(Linux_APPS_Post_Include)

Linux_APPS_Post_Include=	bsd.linux-apps.mk

#new
. if defined(OVERRIDE_LINUX_NONBASE_PORTS)
.        if ${OVERRIDE_LINUX_NONBASE_PORTS} == "f10" || ${OVERRIDE_LINUX_NONBASE_PORTS} == "c6" || ${OVERRIDE_LINUX_NONBASE_PORTS} == "c6_64"
LINUX_DIST_SUFFIX=      -${OVERRIDE_LINUX_NONBASE_PORTS}
LINUX_BASEPORT_NAME=	-${OVERRIDE_LINUX_NONBASE_PORTS:S/_64//}
.        else
IGNORE=         valid values for OVERRIDE_LINUX_NONBASE_PORTS are: \"f10\", \"c6\", and \"c6_64\"
.        endif
. elif defined(USE_LINUX)
LINUX_DIST_SUFFIX=      -${USE_LINUX}
LINUX_BASEPORT_NAME=	-${USE_LINUX:S/_64//}
.  else
# default to CentOS
LINUX_DIST_SUFFIX=      -c6
LINUX_BASEPORT_NAME=	-c6
.  endif

WEB_AUTH=			nvu

# Non-version specific components
_LINUX_APPS_ALL=	allegro alsalib alsa-plugins-oss alsa-plugins-pulseaudio \
					arts aspell atk avahi-libs cairo cups-libs curl dri devtools esound expat \
					flac fontconfig freealut gdkpixbuf gdkpixbuf2 gnutls gtk2 hicontheme imlib jpeg libaudiofile \
					libasyncns libg2c libgcrypt libglade2 libglu libgpg-error libmng libogg \
					libpciaccess libsigcpp20 libsndfile libtasn1 libtheora libvorbis libxml2 mikmod \
					naslibs ncurses-base openal openmotif openssl openssl-compat pango png \
					pulseaudio-libs scimgtk scimlibs sdl12 sdlimage sdlmixer sdlttf tiff \
					tcp_wrappers-libs xorglibs ucl ungif upx webauth

# 2.6.16 components
_LINUX_26_APPS=		 blt cyrus-sasl2 dbusglib dbuslibs \
			libidn libssh2 libv4l nspr nss openal-soft \
			openldap qt45 sqlite3 tcl85 tk85 qt47 qt47-x11 qt47-webkit

_LINUX_APPS_ALL+=	${_LINUX_26_APPS}

# Component definition section
#
# component${LINUX_DIST_SUFFIX:S/-/_/}_FILE
#					- Variables are used to name a file to check,
#					  file names may differ for different LINUX_DIST_SUFFIX.
#					  The value is LINUX_DIST_SUFFIX without the leading dash.
# component_DETECT	- The resulting file to check for a dependency existence.
# component_PORT	- A port which will be used to install a missing dependency.
# component_DEPENDS	- A list of components the current component depends on.

allegro_f10_FILE=	${LINUXBASE}/usr/lib/liballeg-4.2.2.so
#FIXME: locate weird location for allegro c6 libs
allegro_DETECT=		${allegro${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
allegro_PORT=		devel/linux${LINUX_BASEPORT_NAME}-allegro
allegro_DEPENDS=	xorglibs

alsa-plugins-oss_f10_FILE=	${LINUXBASE}/usr/lib/alsa-lib/libasound_module_pcm_oss.so
alsa-plugins-oss_c6_FILE=	${LINUXBASE}/usr/lib/alsa-lib/libasound_module_pcm_oss.so
alsa-plugins-oss_c6_64_FILE=	${LINUXBASE}/usr/lib64/alsa-lib/libasound_module_pcm_oss.so
alsa-plugins-oss_DETECT=	${alsa-plugins-oss${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
alsa-plugins-oss_PORT=		audio/linux${LINUX_BASEPORT_NAME}-alsa-plugins-oss
alsa-plugins-oss_DEPENDS=	alsalib

alsa-plugins-pulseaudio_c6_FILE=	${LINUXBASE}/usr/lib/alsa-lib/libasound_module_conf_pulse.so
alsa-plugins-pulseaudio_c6_64_FILE=	${LINUXBASE}/usr/lib64/alsa-lib/libasound_module_conf_pulse.so
alsa-plugins-pulseaudio_DETECT=	${alsa-plugins-oss${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
alsa-plugins-pulseaudio_PORT=		audio/linux${LINUX_BASEPORT_NAME}-alsa-plugins-pulseaudio
alsa-plugins-pulseaudio_DEPENDS=	alsalib

alsalib_f10_FILE=	${LINUXBASE}/lib/libasound.so.2.0.0
alsalib_c6_FILE=	${LINUXBASE}/lib/libasound.so.2.0.0
alsalib_c6_64_FILE=	${LINUXBASE}/lib64/libasound.so.2.0.0
alsalib_DETECT=		${alsalib${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
alsalib_PORT=		audio/linux${LINUX_BASEPORT_NAME}-alsa-lib

arts_f10_FILE=		${LINUXBASE}/usr/lib/libartsc.so.0
arts_c6_FILE=		${LINUXBASE}/usr/lib/libartsc.so.0
arts_c6_64_FILE=	${LINUXBASE}/usr/lib64/libartsc.so.0
arts_DETECT=		${arts${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
arts_PORT=			audio/linux${LINUX_BASEPORT_NAME}-arts

aspell_f10_FILE=	${LINUXBASE}/usr/lib/libaspell.so.15.1.4
aspell_c6_FILE=		${LINUXBASE}/usr/lib/libaspell.so.15.1.4
aspell_c6_64_FILE=	${LINUXBASE}/usr/lib64/libaspell.so.15.1.4
aspell_DETECT=		${aspell${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
aspell_PORT=		textproc/linux${LINUX_BASEPORT_NAME}-aspell

atk_f10_FILE=		${LINUXBASE}/usr/lib/libatk-1.0.so.0.2409.1
atk_c6_FILE=		${LINUXBASE}/usr/lib/libatk-1.0.so.0.3009.1
atk_c6_64_FILE=		${LINUXBASE}/usr/lib64/libatk-1.0.so.0.3009.1
atk_DETECT=			${atk${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
atk_PORT=			accessibility/linux${LINUX_BASEPORT_NAME}-atk

avahi-libs_c6_FILE=	${LINUXBASE}/usr/lib/libavahi-client.so.3.2.5
avahi-libs_c6_64_FILE=	${LINUXBASE}/usr/lib64/libavahi-client.so.3.2.5
avahi-libs_DETECT=	${avahi-libs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
avahi-libs_PORT=	net/linux${LINUX_BASEPORT_NAME}-avahi-libs

blt_f10_FILE=		${LINUXBASE}/usr/lib/libBLT24.so # FIXME: deprecated, merged into tcl/tk85
blt_DETECT=		${blt${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
blt_PORT=		x11-toolkits/linux${LINUX_BASEPORT_NAME}-blt
blt_DEPENDS=		tcl85 tk85 xorglibs

cairo_f10_FILE=		${LINUXBASE}/usr/lib/libcairo.so.2.10800.0
cairo_c6_FILE=		${LINUXBASE}/usr/lib/libcairo.so.2.10800.8
cairo_c6_64_FILE=	${LINUXBASE}/usr/lib64/libcairo.so.2.10800.8
cairo_DETECT=		${cairo${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
cairo_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-cairo
cairo_DEPENDS=		fontconfig png xorglibs

cups-libs_f10_FILE=	${LINUXBASE}/usr/lib/libcups.so.2
cups-libs_c6_FILE=	${LINUXBASE}/usr/lib/libcups.so.2
cups-libs_c6_64_FILE=	${LINUXBASE}/usr/lib64/libcups.so.2
cups-libs_DETECT=	${cups-libs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
cups-libs_PORT=		print/linux${LINUX_BASEPORT_NAME}-cups-libs
cups-libs_DEPENDS=	gnutls

curl_f10_FILE=		${LINUXBASE}/usr/lib/libcurl.so.4.1.1
curl_c6_FILE=		${LINUXBASE}/usr/lib/libcurl.so.4.1.1
curl_c6_64_FILE=		${LINUXBASE}/usr/lib64/libcurl.so.4.1.1
curl_DETECT=		${curl${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
curl_PORT=		ftp/linux${LINUX_BASEPORT_NAME}-curl
curl_DEPENDS=		cyrus-sasl2 openldap

cyrus-sasl2_f10_FILE=	${LINUXBASE}/usr/lib/libsasl2.so.2.0.22
cyrus-sasl2_c6_FILE=	${LINUXBASE}/usr/lib/libsasl2.so.2.0.23
cyrus-sasl2_c6_64_FILE=	${LINUXBASE}/usr/lib64/libsasl2.so.2.0.23
cyrus-sasl2_DETECT=	${cyrus-sasl2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
cyrus-sasl2_PORT=	security/linux${LINUX_BASEPORT_NAME}-cyrus-sasl2

dbusglib_f10_FILE=	${LINUXBASE}/usr/lib/libdbus-glib-1.so.2
dbusglib_c6_FILE=	${LINUXBASE}/usr/lib/libdbus-glib-1.so.2
dbusglib_c6_64_FILE=	${LINUXBASE}/usr/lib64/libdbus-glib-1.so.2
dbusglib_DETECT=	${dbusglib${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
dbusglib_PORT=		devel/linux${LINUX_BASEPORT_NAME}-dbus-glib
dbusglib_DEPENDS=	dbuslibs expat

dbuslibs_f10_FILE=	${LINUXBASE}/lib/libdbus-1.so.3
dbuslibs_c6_FILE=	${LINUXBASE}/lib/libdbus-1.so.3
dbuslibs_c6_64_FILE=	${LINUXBASE}/lib64/libdbus-1.so.3
dbuslibs_DETECT=	${dbuslibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
dbuslibs_PORT=		devel/linux${LINUX_BASEPORT_NAME}-dbus-libs

dri_f10_FILE=		${LINUXBASE}/usr/lib/libGL.so.1.2
dri_c6_FILE=		${LINUXBASE}/usr/lib/libGL.so.1.2.0
dri_c6_64_FILE=		${LINUXBASE}/usr/lib64/libGL.so.1.2.0
dri_DETECT=			${dri${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
dri_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-dri
dri_DEPENDS=		xorglibs

devtools_f10_FILE=	${LINUXBASE}/usr/bin/i386-redhat-linux-gcc
devtools_c6_FILE=	${LINUXBASE}/usr/bin/gcc
devtools_c6_64_FILE=	${LINUXBASE}/usr/bin/gcc
devtools_DETECT=	${devtools${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
devtools_PORT=		devel/linux${LINUX_BASEPORT_NAME}-devtools

esound_f10_FILE=	${LINUXBASE}/usr/lib/libesd.so.0.2.39
esound_c6_FILE=		${LINUXBASE}/usr/lib/libesd.so.0.2.39
esound_c6_64_FILE=	${LINUXBASE}/usr/lib64/libesd.so.0.2.39
esound_DETECT=		${esound${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
esound_PORT=		audio/linux${LINUX_BASEPORT_NAME}-esound
esound_DEPENDS=		libaudiofile

expat_f10_FILE=		${LINUXBASE}/lib/libexpat.so.1
expat_c6_FILE=		${LINUXBASE}/lib/libexpat.so.1
expat_c6_64_FILE=	${LINUXBASE}/lib64/libexpat.so.1
expat_DETECT=		${expat${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
expat_PORT=			textproc/linux${LINUX_BASEPORT_NAME}-expat

fontconfig_f10_FILE=	${LINUXBASE}/usr/lib/libfontconfig.so.1.3.0
fontconfig_c6_FILE=	${LINUXBASE}/usr/lib/libfontconfig.so.1.4.4
fontconfig_c6_64_FILE=	${LINUXBASE}/usr/lib64/libfontconfig.so.1.4.4
fontconfig_DETECT=	${fontconfig${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
fontconfig_PORT=	x11-fonts/linux${LINUX_BASEPORT_NAME}-fontconfig
fontconfig_DEPENDS=	expat

flac_c6_FILE=		${LINUXBASE}/usr/lib/libFLAC.so.8.2.0
flac_c6_64_FILE=	${LINUXBASE}/usr/lib64/libFLAC.so.8.2.0
flac_DETECT=		${flac${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
flac_PORT=			audio/linux${LINUX_BASEPORT_NAME}-flac

freealut_f10_FILE=	${LINUXBASE}/usr/lib/libalut.so.0.1.0
freealut_DETECT=	${freealut${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
freealut_PORT=		audio/linux${LINUX_BASEPORT_NAME}-freealut
freealut_DEPENDS=	openal

gdkpixbuf_f10_FILE=	${LINUXBASE}/usr/lib/libgdk_pixbuf.so.2
gdkpixbuf_DETECT=	${gdkpixbuf${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gdkpixbuf_PORT=		graphics/linux${LINUX_BASEPORT_NAME}-gdk-pixbuf

gdkpixbuf2_f10_FILE=	${LINUXBASE}/usr/lib/libgdk_pixbuf-2.0.so.0
gdkpixbuf2_c6_FILE=	${LINUXBASE}/usr/lib/libgdk_pixbuf-2.0.so.0
gdkpixbuf2_c6_64_FILE=	${LINUXBASE}/usr/lib64/libgdk_pixbuf-2.0.so.0
gdkpixbuf2_DETECT=	${gdkpixbuf2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
.if ${USE_LINUX} == "f10"
gdkpixbuf2_PORT=	x11-toolkits/linux${LINUX_BASEPORT_NAME}-gtk2
.else # default to CentOS 6.
gdkpixbuf2_PORT=	graphics/linux${LINUX_BASEPORT_NAME}-gdk-pixbuf2
.endif

gnutls_f10_FILE=	${LINUXBASE}/usr/lib/libgnutls.so.26.4.6
gnutls_c6_FILE=		${LINUXBASE}/usr/lib/libgnutls.so.26.14.12
gnutls_c6_64_FILE=	${LINUXBASE}/usr/lib64/libgnutls.so.26.14.12
gnutls_DETECT=		${gnutls${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gnutls_PORT=		security/linux${LINUX_BASEPORT_NAME}-gnutls
gnutls_DEPENDS=		libtasn1 libgcrypt libgpg-error

gtk2_f10_FILE=		${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0.1400.7
gtk2_c6_FILE=		${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0.2400.23
gtk2_c6_64_FILE=	${LINUXBASE}/usr/lib64/libgtk-x11-2.0.so.0.2400.23
gtk2_DETECT=		${gtk2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gtk2_PORT=			x11-toolkits/linux${LINUX_BASEPORT_NAME}-gtk2
gtk2_DEPENDS=		atk gdkpixbuf2 jpeg png pango tiff xorglibs

hicontheme_f10_FILE=	${LINUXBASE}/usr/share/icons/hicolor
hicontheme_c6_FILE=	${LINUXBASE}/usr/share/icons/hicolor
hicontheme_c6_64_FILE=	${LINUXBASE}/usr/share/icons/hicolor
hicontheme_DETECT=	${hicontheme${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
hicontheme_PORT=	x11-themes/linux${LINUX_BASEPORT_NAME}-hicolor-icon-theme

imlib_f10_FILE=		${LINUXBASE}/usr/lib/libgdk_imlib.so.1.9.15
imlib_DETECT=		${imlib${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
imlib_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-imlib

jpeg_f10_FILE=		${LINUXBASE}/usr/lib/libjpeg.so.62.0.0
jpeg_c6_FILE=		${LINUXBASE}/usr/lib/libjpeg.so.62.0.0
jpeg_c6_64_FILE=	${LINUXBASE}/usr/lib64/libjpeg.so.62.0.0
jpeg_DETECT=		${jpeg${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
jpeg_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-jpeg

libasyncns_f10_FILE=	${LINUXBASE}/usr/lib/libasyncns.so.0.3.1
libasyncns_c6_FILE=	${LINUXBASE}/usr/lib/libasyncns.so.0.3.1
libasyncns_c6_64_FILE=	${LINUXBASE}/usr/lib64/libasyncns.so.0.3.1
libasyncns_DETECT=	${libasyncns${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libasyncns_PORT=	dns/linux${LINUX_BASEPORT_NAME}-libasyncns

libaudiofile_f10_FILE=	${LINUXBASE}/usr/lib/libaudiofile.so.0.0.2
libaudiofile_c6_FILE=	${LINUXBASE}/usr/lib/libaudiofile.so.0.0.2
libaudiofile_c6_64_FILE=${LINUXBASE}/usr/lib64/libaudiofile.so.0.0.2
libaudiofile_DETECT=	${libaudiofile${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libaudiofile_PORT=	audio/linux${LINUX_BASEPORT_NAME}-libaudiofile

libg2c_f10_FILE=	${LINUXBASE}/usr/lib/libg2c.so.0.0.0
libg2c_DETECT=		${libg2c${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libg2c_PORT=		lang/linux${LINUX_BASEPORT_NAME}-libg2c

libgcrypt_f10_FILE=	${LINUXBASE}/lib/libgcrypt.so.11.5.2
libgcrypt_c6_FILE=	${LINUXBASE}/lib/libgcrypt.so.11.5.3
libgcrypt_c6_64_FILE=	${LINUXBASE}/lib64/libgcrypt.so.11.5.3
libgcrypt_DETECT=	${libgcrypt${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libgcrypt_PORT=		security/linux${LINUX_BASEPORT_NAME}-libgcrypt

libglade2_f10_FILE=	${LINUXBASE}/usr/lib/libglade-2.0.so.0.0.7
libglade2_c6_FILE=	${LINUXBASE}/usr/lib/libglade-2.0.so.0.0.7
libglade2_c6_64_FILE=	${LINUXBASE}/usr/lib64/libglade-2.0.so.0.0.7
libglade2_DETECT=	${libglade2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libglade2_PORT=		devel/linux${LINUX_BASEPORT_NAME}-libglade2

libglu_f10_FILE=	${LINUXBASE}/usr/lib/libGLU.so.1
libglu_c6_FILE=		${LINUXBASE}/usr/lib/libGLU.so.1
libglu_c6_64_FILE=		${LINUXBASE}/usr/lib64/libGLU.so.1
libglu_DETECT=		${libglu${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libglu_PORT=		graphics/linux${LINUX_BASEPORT_NAME}-libGLU

libgpg-error_f10_FILE=	${LINUXBASE}/lib/libgpg-error.so.0.4.0
libgpg-error_c6_FILE=	${LINUXBASE}/lib/libgpg-error.so.0.5.0
libgpg-error_c6_64_FILE=${LINUXBASE}/lib64/libgpg-error.so.0.5.0
libgpg-error_DETECT=	${libgpg-error${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libgpg-error_PORT=	security/linux${LINUX_BASEPORT_NAME}-libgpg-error

# no libidn_f10_FILE (libidn is integrated into linux_base-f10 port)
libidn_DETECT=		${libidn${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libidn_PORT=		dns/linux${LINUX_BASEPORT_NAME}-libidn

libmng_f10_FILE=	${LINUXBASE}/usr/lib/libmng.so.1.0.0
libmng_DETECT=		${libmng${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libmng_PORT=		graphics/linux${LINUX_BASEPORT_NAME}-libmng
libmng_DEPENDS=		jpeg

libogg_f10_FILE=	${LINUXBASE}/usr/lib/libogg.so.0.5.3
libogg_c6_FILE=		${LINUXBASE}/usr/lib/libogg.so.0.6.0
libogg_c6_64_FILE=	${LINUXBASE}/usr/lib64/libogg.so.0.6.0
libogg_DETECT=		${libogg${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libogg_PORT=		audio/linux${LINUX_BASEPORT_NAME}-libogg

libpciaccess_c6_FILE=		${LINUXBASE}/usr/lib/libpciaccess.so.0.11.1
libpciaccess_c6_64_FILE=		${LINUXBASE}/usr/lib64/libpciaccess.so.0.11.1
libpciaccess_DETECT=		${libpciaccess${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libpciaccess_PORT=		devel/linux${LINUX_BASEPORT_NAME}-libpciaccess

libsigcpp20_f10_FILE=	${LINUXBASE}/usr/lib/libsigc-2.0.so.0
libsigcpp20_c6_FILE=	${LINUXBASE}/usr/lib/libsigc-2.0.so.0
libsigcpp20_c6_64_FILE=	${LINUXBASE}/usr/lib64/libsigc-2.0.so.0
libsigcpp20_DETECT=	${libsigcpp20${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libsigcpp20_PORT=	devel/linux${LINUX_BASEPORT_NAME}-libsigc++20

libsndfile_c6_FILE=	${LINUXBASE}/usr/lib/libsndfile.so.1.0.20
libsndfile_c6_64_FILE=	${LINUXBASE}/usr/lib64/libsndfile.so.1.0.20
libsndfile_DETECT=	${libsndfile${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libsndfile_PORT=	audio/linux${LINUX_BASEPORT_NAME}-libsndfile

libssh2_f10_FILE=	${LINUXBASE}/usr/lib/libssh2.so.1
libssh2_c6_FILE=	${LINUXBASE}/usr/lib/libssh2.so.1.0.1
libssh2_c6_64_FILE=	${LINUXBASE}/usr/lib64/libssh2.so.1.0.1
libssh2_DETECT=		${libssh2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libssh2_PORT=		security/linux${LINUX_BASEPORT_NAME}-libssh2
libssh2_DEPENDS=	openssl

libv4l_f10_FILE=	${LINUXBASE}/usr/lib/libv4l1.so.0
libv4l_c6_FILE=	${LINUXBASE}/usr/lib/libv4l1.so.0
libv4l_c6_64_FILE=	${LINUXBASE}/usr/lib64/libv4l1.so.0
libv4l_DETECT=		${libv4l${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libv4l_PORT=		multimedia/linux${LINUX_BASEPORT_NAME}-libv4l

libtasn1_f10_FILE=	${LINUXBASE}/usr/lib/libtasn1.so.3.0.16
libtasn1_c6_FILE=	${LINUXBASE}/usr/lib/libtasn1.so.3.1.6
libtasn1_c6_64_FILE=	${LINUXBASE}/usr/lib64/libtasn1.so.3.1.6
libtasn1_DETECT=	${libtasn1${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libtasn1_PORT=		security/linux${LINUX_BASEPORT_NAME}-libtasn1

libtheora_f10_FILE=	${LINUXBASE}/usr/lib/libtheora.so.0.3.3
libtheora_c6_FILE=	${LINUXBASE}/usr/lib/libtheora.so.0.3.9
libtheora_c6_64_FILE=	${LINUXBASE}/usr/lib64/libtheora.so.0.3.9
libtheora_DETECT=	${libtheora${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libtheora_PORT=		multimedia/linux${LINUX_BASEPORT_NAME}-libtheora

libvorbis_f10_FILE=	${LINUXBASE}/usr/lib/libvorbis.so.0.4.0
libvorbis_c6_FILE=	${LINUXBASE}/usr/lib/libvorbis.so.0.4.3
libvorbis_c6_64_FILE=	${LINUXBASE}/usr/lib64/libvorbis.so.0.4.3
libvorbis_DETECT=	${libvorbis${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libvorbis_PORT=		audio/linux${LINUX_BASEPORT_NAME}-libvorbis
libvorbis_DEPENDS=	libogg

libxml2_f10_FILE=	${LINUXBASE}/usr/lib/libxml2.so.2.7.3
libxml2_c6_FILE=	${LINUXBASE}/usr/lib/libxml2.so.2.7.6
libxml2_c6_64_FILE=	${LINUXBASE}/usr/lib64/libxml2.so.2.7.6
libxml2_DETECT=		${libxml2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libxml2_PORT=		textproc/linux${LINUX_BASEPORT_NAME}-libxml2

mikmod_f10_FILE=	${LINUXBASE}/usr/lib/libmikmod.so.3.0.0
mikmod_c6_FILE=	${LINUXBASE}/usr/lib/libmikmod.so.3.0.0
mikmod_c6_64_FILE=	${LINUXBASE}/usr/lib64/libmikmod.so.3.0.0
mikmod_DETECT=		${mikmod${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
mikmod_PORT=		audio/linux${LINUX_BASEPORT_NAME}-mikmod

naslibs_f10_FILE=	${LINUXBASE}/usr/lib/libaudio.so.2
naslibs_c6_FILE=	${LINUXBASE}/usr/lib/libaudio.so.2
naslibs_c6_64_FILE=	${LINUXBASE}/usr/lib64/libaudio.so.2
naslibs_DETECT=		${naslibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
naslibs_PORT=		audio/linux${LINUX_BASEPORT_NAME}-nas-libs
naslibs_DEPENDS=	xorglibs

openldap_f10_FILE=	${LINUXBASE}/usr/lib/libldap-2.4.so.2.2.0
openldap_c6_FILE=	${LINUXBASE}/lib/libldap-2.4.so.2.10.3
openldap_c6_64_FILE=	${LINUXBASE}/lib64/libldap-2.4.so.2.10.3
openldap_DETECT=	${openldap${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openldap_PORT=		net/linux${LINUX_BASEPORT_NAME}-openldap

openmotif_f10_FILE=	${LINUXBASE}/usr/lib/libXm.so.4
openmotif_c6_FILE=	${LINUXBASE}/usr/lib/libXm.so.4.0.3
openmotif_c6_64_FILE=	${LINUXBASE}/usr/lib64/libXm.so.4.0.3
openmotif_DETECT=	${openmotif${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openmotif_PORT=		x11-toolkits/linux${LINUX_BASEPORT_NAME}-openmotif
openmotif_DEPENDS=	xorglibs

ncurses-base_f10_FILE=	${LINUXBASE}/lib/terminfo/a/ansi
ncurses-base_c6_FILE=	${LINUXBASE}/lib/terminfo/a/ansi
ncurses-base_c6_64_FILE=${LINUXBASE}/lib64/terminfo/a/ansi
ncurses-base_DETECT=	${ncurses-base${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
ncurses-base_PORT=	devel/linux${LINUX_BASEPORT_NAME}-ncurses-base

nspr_f10_FILE=		${LINUXBASE}/lib/libnspr4.so
nspr_c6_FILE=		${LINUXBASE}/lib/libnspr4.so
nspr_c6_64_FILE=	${LINUXBASE}/lib64/libnspr4.so
nspr_DETECT=		${nspr${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
nspr_PORT=		devel/linux${LINUX_BASEPORT_NAME}-nspr

nss_f10_FILE=		${LINUXBASE}/lib/libnss3.so
nss_c6_FILE=		${LINUXBASE}/usr/lib/libnss3.so
nss_c6_64_FILE=		${LINUXBASE}/usr/lib64/libnss3.so
nss_DETECT=		${nss${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
nss_PORT=		security/linux${LINUX_BASEPORT_NAME}-nss
nss_DEPENDS=		nspr sqlite3

openal_f10_FILE=	${LINUXBASE}/usr/lib/libopenal.so.0.0.0
openal_DETECT=		${openal${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openal_PORT=		audio/linux${LINUX_BASEPORT_NAME}-openal
openal_DEPENDS=		alsalib arts esound libaudiofile libvorbis sdl12

openal-soft_f10_FILE=	${LINUXBASE}/usr/lib/libopenal.so.1.8.466
openal-soft_c6_FILE=	${LINUXBASE}/usr/lib/libopenal.so.1.12.854
openal-soft_c6_64_FILE=	${LINUXBASE}/usr/lib64/libopenal.so.1.12.854
openal-soft_DETECT=	${openal-soft${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openal-soft_PORT=	audio/linux${LINUX_BASEPORT_NAME}-openal-soft
openal-soft_DEPENDS=	alsalib arts esound

openssl_f10_FILE=	${LINUXBASE}/lib/libssl.so.0.9.8g
openssl_c6_FILE=	${LINUXBASE}/usr/lib/libssl.so.10
openssl_c6_64_FILE=	${LINUXBASE}/usr/lib64/libssl.so.10
openssl_DETECT=		${openssl${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openssl_PORT=		security/linux${LINUX_BASEPORT_NAME}-openssl

openssl-compat_c6_FILE=	${LINUXBASE}/usr/lib/libssl.so.0.9.8e
openssl-compat_c6_64_FILE=	${LINUXBASE}/usr/lib64/libssl.so.0.9.8e
openssl-compat_DETECT=		${openssl-compat${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openssl-compat_PORT=		security/linux${LINUX_BASEPORT_NAME}-openssl-compat

pango_f10_FILE=		${LINUXBASE}/usr/lib/libpango-1.0.so.0.2800.3
pango_c6_FILE=		${LINUXBASE}/usr/lib/libpango-1.0.so.0.2800.1
pango_c6_64_FILE=	${LINUXBASE}/usr/lib64/libpango-1.0.so.0.2800.1
pango_DETECT=		${pango${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
pango_PORT=			x11-toolkits/linux${LINUX_BASEPORT_NAME}-pango
pango_DEPENDS=		cairo expat fontconfig xorglibs

png_f10_FILE=		${LINUXBASE}/usr/lib/libpng.so.3.37.0
png_c6_FILE=		${LINUXBASE}/usr/lib/libpng.so.3.49.0
png_c6_64_FILE=		${LINUXBASE}/usr/lib64/libpng.so.3.49.0
png_DETECT=			${png${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
png_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-png

pulseaudio-libs_f10_FILE=	${LINUXBASE}/usr/lib/libpulse.so.0
pulseaudio-libs_c6_FILE=	${LINUXBASE}/usr/lib/libpulse.so.0.12.2
pulseaudio-libs_c6_64_FILE=	${LINUXBASE}/usr/lib64/libpulse.so.0.12.2
pulseaudio-libs_DETECT=		${pulseaudio-libs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
pulseaudio-libs_PORT=		audio/linux${LINUX_BASEPORT_NAME}-pulseaudio-libs

qt45_f10_FILE=		${LINUXBASE}/usr/lib/libQtCore.so.4.5.3
qt45_DETECT=		${qt45${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
qt45_DEPENDS=		fontconfig libmng png

sdl12_f10_FILE=		${LINUXBASE}/usr/lib/libSDL-1.2.so.0.11.2
sdl12_c6_FILE=		${LINUXBASE}/usr/lib/libSDL-1.2.so.0.11.3
sdl12_c6_64_FILE=	${LINUXBASE}/usr/lib64/libSDL-1.2.so.0.11.3
sdl12_DETECT=		${sdl12${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdl12_PORT=			devel/linux${LINUX_BASEPORT_NAME}-sdl12
sdl12_DEPENDS=		xorglibs

sdlimage_f10_FILE=	${LINUXBASE}/usr/lib/libSDL_image-1.2.so.0.1.5
sdlimage_c6_FILE=	${LINUXBASE}/usr/lib/libSDL_image-1.2.so.0.8.4
sdlimage_c6_64_FILE=	${LINUXBASE}/usr/lib64/libSDL_image-1.2.so.0.8.4
sdlimage_DETECT=	${sdlimage${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdlimage_PORT=		graphics/linux${LINUX_BASEPORT_NAME}-sdl_image
sdlimage_DEPENDS=	jpeg png sdl12 tiff

sdlmixer_f10_FILE=	${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0.2.6
sdlmixer_c6_FILE=	${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0.12.0
sdlmixer_c6_64_FILE=	${LINUXBASE}/usr/lib64/libSDL_mixer-1.2.so.0.12.0
sdlmixer_DETECT=	${sdlmixer${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdlmixer_PORT=		audio/linux${LINUX_BASEPORT_NAME}-sdl_mixer
sdlmixer_DEPENDS=	sdl12

sdlttf_f10_FILE=	${LINUXBASE}/usr/lib/libSDL_ttf-2.0.so.0.6.2
sdlttf_c6_FILE=	${LINUXBASE}/usr/lib/libSDL_ttf-2.0.so.0.10.1
sdlttf_c6_64_FILE=	${LINUXBASE}/usr/lib64/libSDL_ttf-2.0.so.0.10.1
sdlttf_DETECT=		${sdlttf${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdlttf_PORT=		graphics/linux${LINUX_BASEPORT_NAME}-sdl_ttf
sdlttf_DEPENDS=	sdl12

scimgtk_f10_FILE=	${LINUXBASE}/usr/lib/gtk-2.0/immodules/im-scim.so
scimgtk_DETECT=		${scimgtk${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
scimgtk_PORT=		textproc/linux${LINUX_BASEPORT_NAME}-scim-gtk
scimgtk_DEPENDS=	gtk2 scimlibs

scimlibs_f10_FILE=	${LINUXBASE}/usr/lib/libscim-1.0.so.8
scimlibs_DETECT=	${scimlibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
scimlibs_PORT=		textproc/linux${LINUX_BASEPORT_NAME}-scim-libs
scimlibs_DEPENDS=	gtk2

sqlite3_f10_FILE=	${LINUXBASE}/usr/lib/libsqlite3.so.0
sqlite3_c6_FILE=	${LINUXBASE}/usr/lib/libsqlite3.so.0
sqlite3_c6_64_FILE=	${LINUXBASE}/usr/lib64/libsqlite3.so.0
sqlite3_DETECT=		${sqlite3${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sqlite3_PORT=		databases/linux${LINUX_BASEPORT_NAME}-sqlite3

tcl85_f10_FILE=		${LINUXBASE}/usr/lib/libtcl8.5.so
tcl85_c6_FILE=		${LINUXBASE}/usr/lib/libtcl8.5.so
tcl85_c6_64_FILE=	${LINUXBASE}/usr/lib64/libtcl8.5.so
tcl85_DETECT=		${tcl85${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tcl85_PORT=		lang/linux${LINUX_BASEPORT_NAME}-tcl85

tcp_wrappers-libs_c6_FILE=	${LINUXBASE}/lib/libwrap.so.0
tcp_wrappers-libs_c6_64_FILE=	${LINUXBASE}/lib64/libwrap.so.0
tcp_wrappers-libs_DETECT=	${tcp_wrappers-libs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tcp_wrappers-libs_PORT=	net/linux${LINUX_BASEPORT_NAME}-tcp_wrappers-libs

tiff_f10_FILE=		${LINUXBASE}/usr/lib/libtiff.so.3.8.2
tiff_c6_FILE=		${LINUXBASE}/usr/lib/libtiff.so.3.9.4
tiff_c6_64_FILE=	${LINUXBASE}/usr/lib64/libtiff.so.3.9.4
tiff_DETECT=		${tiff${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tiff_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-tiff
tiff_DEPENDS=		jpeg

tk85_f10_FILE=		${LINUXBASE}/usr/lib/libtk8.5.so
tk85_c6_FILE=		${LINUXBASE}/usr/lib/libtk8.5.so
tk85_c6_64_FILE=	${LINUXBASE}/usr/lib64/libtk8.5.so
tk85_DETECT=		${tk85${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tk85_PORT=		x11-toolkits/linux${LINUX_BASEPORT_NAME}-tk85
tk85_DEPENDS=		xorglibs

xorglibs_f10_FILE=	${LINUXBASE}/usr/lib/libXrandr.so.2.1.0
xorglibs_c6_FILE=	${LINUXBASE}/usr/lib/libXrandr.so.2.2.0
xorglibs_c6_64_FILE=	${LINUXBASE}/usr/lib64/libXrandr.so.2.2.0
xorglibs_DETECT=	${xorglibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
xorglibs_PORT=		x11/linux${LINUX_BASEPORT_NAME}-xorg-libs
xorglibs_DEPENDS=	fontconfig

ucl_f10_FILE=		${LINUXBASE}/usr/lib/libucl.so.1
ucl_DETECT=		${ucl${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
ucl_PORT=		archivers/linux${LINUX_BASEPORT_NAME}-ucl

ungif_f10_FILE=		${LINUXBASE}/usr/lib/libgif.so.4.1.3
ungif_DETECT=		${ungif${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
ungif_PORT=			graphics/linux${LINUX_BASEPORT_NAME}-ungif

upx_f10_FILE=			${LINUXBASE}/usr/bin/upx
upx_DETECT=			${upx${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
upx_PORT=			archivers/linux${LINUX_BASEPORT_NAME}-upx
upx_DEPENDS=		ucl

webauth_f10_FILE=	${LOCALBASE}/bin/linux-nvu
webauth_DETECT=		${webauth${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
webauth_PORT=		www/linux-${WEB_AUTH}
webauth_DEPENDS=	gtk2 atk pango fontconfig

qt47_c6_FILE=		${LINUXBASE}/usr/lib/qt47/libQtCore.so.4.7.2
qt47_c6_64_FILE=	${LINUXBASE}/usr/lib64/qt47/libQtCore.so.4.7.2
qt47_DETECT=		${qt47${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
qt47_PORT=		devel/linux${LINUX_BASEPORT_NAME}-qt47

qt47-x11_c6_FILE=		${LINUXBASE}/usr/lib/qt47/libQtGui.so.4.7.2
qt47-x11_c6_64_FILE=		${LINUXBASE}/usr/lib64/qt47/libQtGui.so.4.7.2
qt47-x11_DETECT=		${qt47-x11${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
qt47-x11_PORT=		x11-toolkits/linux${LINUX_BASEPORT_NAME}-qt47-x11

qt47-webkit_c6_FILE=		${LINUXBASE}/usr/lib/qt47/libQtWebKit.so.4.7.2
qt47-webkit_c6_64_FILE=		${LINUXBASE}/usr/lib64/qt47/libQtWebKit.so.4.7.2
qt47-webkit_DETECT=		${qt47-webkit${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
qt47-webkit_PORT=		www/linux${LINUX_BASEPORT_NAME}-qt47-webkit

# End component definition section

# Let's check if components from USE_LINUX_APPS exist at _LINUX_APPS_ALL
.  for component in ${USE_LINUX_APPS}
.    if ${_LINUX_APPS_ALL:M${component}}==""
IGNORE=	bsd.linux-apps.mk test failed: Invalid component USE_LINUX_APPS=${component}
.    endif
.  endfor

# Let's check if components from USE_LINUX_APPS have corresponding <app>_DETECT
# i.e. if a corresponding <app>_FILE defined for given LINUX_DIST_SUFFIX
.  for component in ${USE_LINUX_APPS}
.    if ${${component}_DETECT}==""
.      if defined(${component}${LINUX_DIST_SUFFIX:S/-/_/}_FILE)
IGNORE=	bsd.linux-apps.mk test failed: The component ${component} is empty for LINUX_DIST_SUFFIX=${LINUX_DIST_SUFFIX} (the corresponding variable ${component}${LINUX_DIST_SUFFIX:S/-/_/}_FILE is empty)
.      else
IGNORE=	bsd.linux-apps.mk test failed: The component ${component} is not defined for LINUX_DIST_SUFFIX=${LINUX_DIST_SUFFIX} (the corresponding variable ${component}${LINUX_DIST_SUFFIX:S/-/_/}_FILE is not defined). This usually means that the current port should be used with non default linux base and/or infrastructure port(s)
.      endif
.    endif
.  endfor

# Recursively expand all dependencies for each app at _LINUX_APPS_ALL
.  for component in ${_LINUX_APPS_ALL}
.    for subcomponent in ${${component}_DEPENDS}
${component}_DEPENDS+=${${subcomponent}_DEPENDS}
.    endfor
.  endfor

# Use just expanded dependencies (<app>_DEPENDS) to expand USE_LINUX_APPS
.  for component in ${USE_LINUX_APPS}
_USE_LINUX_APPS+=${${component}_DEPENDS} ${component}
.  endfor

# Set dependencies for _USE_LINUX_APPS which exists at _LINUX_APPS_ALL
.  for component in ${_LINUX_APPS_ALL}
.    if ${_USE_LINUX_APPS:M${component}}!=""
.      if defined(${component}${LINUX_DIST_SUFFIX:S/-/_/}_FILE)
RUN_DEPENDS+=   ${${component}_DETECT}:${${component}_PORT}
.      endif
.    endif
.  endfor
.endif
