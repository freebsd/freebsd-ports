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
# USE_LINUX_APPS=    esound xorglibs
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

# OVERRIDE_LINUX_NONBASE_PORTS may be used only with LINUX_OSRELEASE=2.6.16
.  if (${LINUX_OSRELEASE} == "2.6.16") && defined(OVERRIDE_LINUX_NONBASE_PORTS)
.    if ${OVERRIDE_LINUX_NONBASE_PORTS} == "f10"
LINUX_DIST_SUFFIX=	-f10
.    else
IGNORE=		valid values for OVERRIDE_LINUX_NONBASE_PORTS are: \"f10\"
.    endif
.  else
# default for OSVERSION >= 800076
LINUX_DIST_SUFFIX=	-f10
.  endif

WEB_AUTH=			nvu

# Non-version specific components
_LINUX_APPS_ALL=	allegro alsalib arts aspell atk cairo cups-libs curl dri esound expat fontconfig \
					freealut gdkpixbuf gnutls gtk gtk2 hicontheme imlib jpeg libaudiofile \
					libg2c libgcrypt libglade2 libglu libgpg-error libmng libogg \
					libsigcpp20 libtasn1 libtheora libvorbis libxml2 mikmod naslibs \
					ncurses-base openal openmotif openssl pango png scimgtk \
					scimlibs sdl12 sdlimage sdlmixer tiff xorglibs ucl ungif upx webauth

# 2.6.16 components
_LINUX_26_APPS=		alsa-plugins-oss blt cyrus-sasl2 dbusglib dbuslibs \
			libasyncns libidn libssh2 libv4l nspr nss openal-soft \
			openldap pulseaudio-libs qt45 sqlite3 tcl84 tk84

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
allegro_DETECT=		${allegro${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
allegro_PORT=		${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-allegro
allegro_DEPENDS=	xorglibs

alsa-plugins-oss_f10_FILE=	${LINUXBASE}/usr/lib/alsa-lib/libasound_module_pcm_oss.so
alsa-plugins-oss_DETECT=	${alsa-plugins-oss${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
alsa-plugins-oss_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-alsa-plugins-oss
alsa-plugins-oss_DEPENDS=	alsalib

alsalib_f10_FILE=	${LINUXBASE}/lib/libasound.so.2.0.0
alsalib_DETECT=		${alsalib${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
alsalib_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-alsa-lib

arts_f10_FILE=		${LINUXBASE}/usr/lib/libartsc.so.0
arts_DETECT=		${arts${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
arts_PORT=			${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-arts

aspell_f10_FILE=	${LINUXBASE}/usr/lib/libaspell.so.15.1.4
aspell_DETECT=		${aspell${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
aspell_PORT=		${PORTSDIR}/textproc/linux${LINUX_DIST_SUFFIX}-aspell

atk_f10_FILE=		${LINUXBASE}/usr/lib/libatk-1.0.so.0.2409.1
atk_DETECT=			${atk${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
atk_PORT=			${PORTSDIR}/accessibility/linux${LINUX_DIST_SUFFIX}-atk

blt_f10_FILE=		${LINUXBASE}/usr/lib/libBLT24.so
blt_DETECT=		${blt${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
blt_PORT=		${PORTSDIR}/x11-toolkits/linux${LINUX_DIST_SUFFIX}-blt
blt_DEPENDS=		tcl84 tk84 xorglibs

cairo_f10_FILE=		${LINUXBASE}/usr/lib/libcairo.so.2.10800.0
cairo_DETECT=		${cairo${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
cairo_PORT=			${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-cairo
cairo_DEPENDS=		fontconfig png xorglibs

cups-libs_f10_FILE=	${LINUXBASE}/usr/lib/libcups.so.2
cups-libs_DETECT=	${cups-libs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
cups-libs_PORT=		${PORTSDIR}/print/linux${LINUX_DIST_SUFFIX}-cups-libs
cups-libs_DEPENDS=	gnutls

curl_f10_FILE=		${LINUXBASE}/usr/lib/libcurl.so.4.1.1
curl_DETECT=		${curl${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
curl_PORT=		${PORTSDIR}/ftp/linux${LINUX_DIST_SUFFIX}-curl
.  if ${LINUX_DIST_SUFFIX} == "-f10"
curl_DEPENDS=		cyrus-sasl2 openldap
.  endif

cyrus-sasl2_f10_FILE=	${LINUXBASE}/usr/lib/libsasl2.so.2.0.22
cyrus-sasl2_DETECT=	${cyrus-sasl2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
cyrus-sasl2_PORT=	${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-cyrus-sasl2

dbusglib_f10_FILE=	${LINUXBASE}/usr/lib/libdbus-glib-1.so.2
dbusglib_DETECT=	${dbusglib${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
dbusglib_PORT=		${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-dbus-glib
dbusglib_DEPENDS=	dbuslibs expat

dbuslibs_f10_FILE=	${LINUXBASE}/lib/libdbus-1.so.3
dbuslibs_DETECT=	${dbuslibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
dbuslibs_PORT=		${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-dbus-libs

dri_f10_FILE=		${LINUXBASE}/usr/lib/libGL.so.1.2
dri_DETECT=		${dri${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
dri_PORT=		${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-dri
dri_DEPENDS=		xorglibs

esound_f10_FILE=	${LINUXBASE}/usr/lib/libesd.so.0.2.39
esound_DETECT=		${esound${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
esound_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-esound
esound_DEPENDS=		libaudiofile

expat_f10_FILE=		${LINUXBASE}/lib/libexpat.so.1
expat_DETECT=		${expat${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
expat_PORT=			${PORTSDIR}/textproc/linux${LINUX_DIST_SUFFIX}-expat

fontconfig_f10_FILE=	${LINUXBASE}/usr/lib/libfontconfig.so.1.3.0
fontconfig_DETECT=	${fontconfig${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
fontconfig_PORT=	${PORTSDIR}/x11-fonts/linux${LINUX_DIST_SUFFIX}-fontconfig
fontconfig_DEPENDS=	expat

freealut_f10_FILE=	${LINUXBASE}/usr/lib/libalut.so.0.1.0
freealut_DETECT=	${freealut${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
freealut_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-freealut
freealut_DEPENDS=	openal

gdkpixbuf_f10_FILE=	${LINUXBASE}/usr/lib/libgdk_pixbuf.so.2
gdkpixbuf_DETECT=	${gdkpixbuf${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gdkpixbuf_PORT=		${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-gdk-pixbuf

gtk_f10_FILE=		${LINUXBASE}/usr/lib/libgtk-1.2.so.0.9.1
gtk_DETECT=			${gtk${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gtk_PORT=			${PORTSDIR}/x11-toolkits/linux${LINUX_DIST_SUFFIX}-gtk
gtk_DEPENDS=		xorglibs

gnutls_f10_FILE=	${LINUXBASE}/usr/lib/libgnutls.so.26.4.6
gnutls_DETECT=		${gnutls${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gnutls_PORT=		${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-gnutls
gnutls_DEPENDS=		libtasn1 libgcrypt libgpg-error

gtk2_f10_FILE=		${LINUXBASE}/usr/lib/libgtk-x11-2.0.so.0.1400.7
gtk2_DETECT=		${gtk2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
gtk2_PORT=			${PORTSDIR}/x11-toolkits/linux${LINUX_DIST_SUFFIX}-gtk2
gtk2_DEPENDS=		atk jpeg png pango tiff xorglibs

hicontheme_f10_FILE=	${LINUXBASE}/usr/share/icons/hicolor
hicontheme_DETECT=	${hicontheme${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
hicontheme_PORT=	${PORTSDIR}/x11-themes/linux${LINUX_DIST_SUFFIX}-hicolor-icon-theme

imlib_f10_FILE=		${LINUXBASE}/usr/lib/libgdk_imlib.so.1.9.15
imlib_DETECT=		${imlib${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
imlib_PORT=			${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-imlib

jpeg_f10_FILE=		${LINUXBASE}/usr/lib/libjpeg.so.62.0.0
jpeg_DETECT=		${jpeg${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
jpeg_PORT=			${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-jpeg

libasyncns_f10_FILE=	${LINUXBASE}/usr/lib/libasyncns.so.0.3.1
libasyncns_DETECT=	${libasyncns${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libasyncns_PORT=	${PORTSDIR}/dns/linux${LINUX_DIST_SUFFIX}-libasyncns

libaudiofile_f10_FILE=	${LINUXBASE}/usr/lib/libaudiofile.so.0.0.2
libaudiofile_DETECT=	${libaudiofile${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libaudiofile_PORT=	${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-libaudiofile

libg2c_f10_FILE=	${LINUXBASE}/usr/lib/libg2c.so.0.0.0
libg2c_DETECT=		${libg2c${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libg2c_PORT=		${PORTSDIR}/lang/linux${LINUX_DIST_SUFFIX}-libg2c

libgcrypt_f10_FILE=	${LINUXBASE}/lib/libgcrypt.so.11.5.2
libgcrypt_DETECT=	${libgcrypt${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libgcrypt_PORT=		${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-libgcrypt

libglade2_f10_FILE=	${LINUXBASE}/usr/lib/libglade-2.0.so.0.0.7
libglade2_DETECT=	${libglade2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libglade2_PORT=		${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-libglade2

libglu_f10_FILE=	${LINUXBASE}/usr/lib/libGLU.so.1
libglu_DETECT=		${libglu${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libglu_PORT=		${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-libGLU

libgpg-error_f10_FILE=	${LINUXBASE}/lib/libgpg-error.so.0.4.0
libgpg-error_DETECT=	${libgpg-error${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libgpg-error_PORT=	${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-libgpg-error

# no libidn_f10_FILE (libidn is integrated into linux_base-f10 port)
libidn_DETECT=		${libidn${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libidn_PORT=		${PORTSDIR}/dns/linux${LINUX_DIST_SUFFIX}-libidn

libmng_f10_FILE=	${LINUXBASE}/usr/lib/libmng.so.1.0.0
libmng_DETECT=		${libmng${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libmng_PORT=		${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-libmng
libmng_DEPENDS=		jpeg

libogg_f10_FILE=	${LINUXBASE}/usr/lib/libogg.so.0.5.3
libogg_DETECT=		${libogg${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libogg_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-libogg

libsigcpp20_f10_FILE=	${LINUXBASE}/usr/lib/libsigc-2.0.so.0
libsigcpp20_DETECT=	${libsigcpp20${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libsigcpp20_PORT=	${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-libsigc++20

libssh2_f10_FILE=	${LINUXBASE}/usr/lib/libssh2.so.1
libssh2_DETECT=		${libssh2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libssh2_PORT=		${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-libssh2
libssh2_DEPENDS=	openssl

libv4l_f10_FILE=	${LINUXBASE}/usr/lib/libv4l1.so.0
libv4l_DETECT=		${libv4l${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libv4l_PORT=		${PORTSDIR}/multimedia/linux${LINUX_DIST_SUFFIX}-libv4l

libtasn1_f10_FILE=	${LINUXBASE}/usr/lib/libtasn1.so.3.0.16
libtasn1_DETECT=	${libtasn1${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libtasn1_PORT=		${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-libtasn1

libtheora_f10_FILE=	${LINUXBASE}/usr/lib/libtheora.so.0.3.3
libtheora_DETECT=	${libtheora${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libtheora_PORT=		${PORTSDIR}/multimedia/linux${LINUX_DIST_SUFFIX}-libtheora

libvorbis_f10_FILE=	${LINUXBASE}/usr/lib/libvorbis.so.0.4.0
libvorbis_DETECT=	${libvorbis${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libvorbis_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-libvorbis
libvorbis_DEPENDS=	libogg

libxml2_f10_FILE=	${LINUXBASE}/usr/lib/libxml2.so.2.7.3
libxml2_DETECT=		${libxml2${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
libxml2_PORT=		${PORTSDIR}/textproc/linux${LINUX_DIST_SUFFIX}-libxml2

mikmod_f10_FILE=	${LINUXBASE}/usr/lib/libmikmod.so.3.0.0
mikmod_DETECT=		${mikmod${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
mikmod_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-mikmod

naslibs_f10_FILE=	${LINUXBASE}/usr/lib/libaudio.so.2
naslibs_DETECT=		${naslibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
naslibs_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-nas-libs
naslibs_DEPENDS=	xorglibs

openldap_f10_FILE=	${LINUXBASE}/usr/lib/libldap-2.4.so.2.2.0
openldap_DETECT=	${openldap${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openldap_PORT=		${PORTSDIR}/net/linux${LINUX_DIST_SUFFIX}-openldap

openmotif_f10_FILE=	${LINUXBASE}/usr/lib/libXm.so.4
openmotif_DETECT=	${openmotif${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openmotif_PORT=		${PORTSDIR}/x11-toolkits/linux${LINUX_DIST_SUFFIX}-openmotif
openmotif_DEPENDS=	xorglibs

ncurses-base_f10_FILE=	${LINUXBASE}/lib/terminfo/a/ansi
ncurses-base_DETECT=	${ncurses-base${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
ncurses-base_PORT=	${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-ncurses-base

nspr_f10_FILE=		${LINUXBASE}/lib/libnspr4.so
nspr_DETECT=		${nspr${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
nspr_PORT=		${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-nspr

nss_f10_FILE=		${LINUXBASE}/lib/libnss3.so
nss_DETECT=		${nss${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
nss_PORT=		${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-nss
nss_DEPENDS=		nspr sqlite3

openal_f10_FILE=	${LINUXBASE}/usr/lib/libopenal.so.0.0.0
openal_DETECT=		${openal${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openal_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-openal
openal_DEPENDS=		alsalib arts esound libaudiofile libvorbis sdl12

openal-soft_f10_FILE=	${LINUXBASE}/usr/lib/libopenal.so.1.8.466
openal-soft_DETECT=	${openal-soft${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openal-soft_PORT=	${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-openal-soft
openal-soft_DEPENDS=	alsalib arts esound

openssl_f10_FILE=	${LINUXBASE}/lib/libssl.so.0.9.8g
openssl_DETECT=		${openssl${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
openssl_PORT=		${PORTSDIR}/security/linux${LINUX_DIST_SUFFIX}-openssl

pango_f10_FILE=		${LINUXBASE}/usr/lib/libpango-1.0.so.0.2800.3
pango_DETECT=		${pango${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
pango_PORT=			${PORTSDIR}/x11-toolkits/linux${LINUX_DIST_SUFFIX}-pango
pango_DEPENDS=		cairo expat fontconfig xorglibs

png_f10_FILE=		${LINUXBASE}/usr/lib/libpng.so.3.37.0
png_DETECT=			${png${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
png_PORT=			${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-png

pulseaudio-libs_f10_FILE=	${LINUXBASE}/usr/lib/libpulse.so.0
pulseaudio-libs_DETECT=		${pulseaudio-libs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
pulseaudio-libs_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-pulseaudio-libs

qt45_f10_FILE=		${LINUXBASE}/usr/lib/libQtCore.so.4.5.3
qt45_DETECT=		${qt45${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
qt45_DEPENDS=		fontconfig libmng png

sdl12_f10_FILE=		${LINUXBASE}/usr/lib/libSDL-1.2.so.0.11.2
sdl12_DETECT=		${sdl12${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdl12_PORT=			${PORTSDIR}/devel/linux${LINUX_DIST_SUFFIX}-sdl12
sdl12_DEPENDS=		xorglibs

sdlimage_f10_FILE=	${LINUXBASE}/usr/lib/libSDL_image-1.2.so.0.1.5
sdlimage_DETECT=	${sdlimage${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdlimage_PORT=		${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-sdl_image
sdlimage_DEPENDS=	jpeg png sdl12 tiff

sdlmixer_f10_FILE=	${LINUXBASE}/usr/lib/libSDL_mixer-1.2.so.0.2.6
sdlmixer_DETECT=	${sdlmixer${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sdlmixer_PORT=		${PORTSDIR}/audio/linux${LINUX_DIST_SUFFIX}-sdl_mixer
sdlmixer_DEPENDS=	sdl12

scimgtk_f10_FILE=	${LINUXBASE}/usr/lib/gtk-2.0/immodules/im-scim.so
scimgtk_DETECT=		${scimgtk${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
scimgtk_PORT=		${PORTSDIR}/textproc/linux${LINUX_DIST_SUFFIX}-scim-gtk
scimgtk_DEPENDS=	gtk2 scimlibs

scimlibs_f10_FILE=	${LINUXBASE}/usr/lib/libscim-1.0.so.8
scimlibs_DETECT=	${scimlibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
scimlibs_PORT=		${PORTSDIR}/textproc/linux${LINUX_DIST_SUFFIX}-scim-libs
scimlibs_DEPENDS=	gtk2

sqlite3_f10_FILE=	${LINUXBASE}/usr/lib/libsqlite3.so.0
sqlite3_DETECT=		${sqlite3${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
sqlite3_PORT=		${PORTSDIR}/databases/linux${LINUX_DIST_SUFFIX}-sqlite3

# XXX: tcl85!!!
tcl84_f10_FILE=		${LINUXBASE}/usr/lib/libtcl8.5.so
tcl84_DETECT=		${tcl84${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tcl84_PORT=		${PORTSDIR}/lang/linux${LINUX_DIST_SUFFIX}-tcl85

tiff_f10_FILE=		${LINUXBASE}/usr/lib/libtiff.so.3.8.2
tiff_DETECT=		${tiff${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tiff_PORT=			${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-tiff
tiff_DEPENDS=		jpeg

# XXX: tk85!!!
tk84_f10_FILE=		${LINUXBASE}/usr/lib/libtk8.5.so
tk84_DETECT=		${tk84${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
tk84_PORT=		${PORTSDIR}/x11-toolkits/linux${LINUX_DIST_SUFFIX}-tk85
tk84_DEPENDS=		xorglibs

xorglibs_f10_FILE=	${LINUXBASE}/usr/lib/libXrandr.so.2.1.0
xorglibs_DETECT=	${xorglibs${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
xorglibs_PORT=		${PORTSDIR}/x11/linux${LINUX_DIST_SUFFIX}-xorg-libs
xorglibs_DEPENDS=	fontconfig

ucl_f10_FILE=		${LINUXBASE}/usr/lib/libucl.so.1
ucl_DETECT=		${ucl${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
ucl_PORT=		${PORTSDIR}/archivers/linux${LINUX_DIST_SUFFIX}-ucl

ungif_f10_FILE=		${LINUXBASE}/usr/lib/libgif.so.4.1.3
ungif_DETECT=		${ungif${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
ungif_PORT=			${PORTSDIR}/graphics/linux${LINUX_DIST_SUFFIX}-ungif

upx_f10_FILE=			${LINUXBASE}/usr/bin/upx
upx_DETECT=			${upx${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
upx_PORT=			${PORTSDIR}/archivers/linux${LINUX_DIST_SUFFIX}-upx
upx_DEPENDS=		ucl

webauth_f10_FILE=	${LOCALBASE}/bin/linux-nvu
webauth_DETECT=		${webauth${LINUX_DIST_SUFFIX:S/-/_/}_FILE}
webauth_PORT=		${PORTSDIR}/www/linux-${WEB_AUTH}
webauth_DEPENDS=	gtk2 atk pango fontconfig

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
