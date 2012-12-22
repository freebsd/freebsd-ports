#
# $MBSDlabs: portmk/bsd.efl.mk,v 1.17 2006/10/02 14:57:48 stas Exp $
# $FreeBSD$
#
# bsd.efl.mk - Support for Enlightenment Foundation Libraries (EFL)
#
# Author: Stanislav Sedov <stas@FreeBSD.org>
# Inspired by bsd.sdl.mk by Edwin Groothuis <edwin@freebsd.org>
#
# You can specify EFL-related library dependency using "USE_EFL=" statement,
# e.g. "USE_EFL= ecore evas" will add x11/ecore and graphics/evas as dependency
# for your port.
# You can check existency of certain library throught "WANT_EFL/HAVE_EFL" pair.
# Note: WANT_EFL should be defined before including <bsd.port.pre.mk>, and
# HAVE_EFL variable could be tested after it. For example:
#
#	WANT_EFL=	yes
#	.include <bsd.port.pre.mk>
#	.if ${HAVE_EFL:Mevas}
#	USE_EFL+=	evas
#	.endif
#
# Currently recognized variables are:
# USE_EFL	- lists all EFL libraries which port depends on
# WANT_EFL	- the port wants to test which of EFL libraries are installed
#			on the target system
#
# The following variables could be tested after inclusion of bsd.port.pre.mk:
# HAVE_EFL	- lists all EFL libraries which are available on target system
#
# Feel free to send any comments and suggestion to maintainer.
#

EFL_Include_MAINTAINER=	gblach@FreeBSD.org

#
# Define all supported libraries
#
_USE_EFL_ALL=	ecore edbus edje eet efreet eio eina elementary embryo \
		emotion ender enesim epeg esvg etch ethumb evas imlib2

# For each library supported we define the following variables:
#	_%%LIB%%_CATEGORY	- category the port belongs to
#	_%%LIB%%_PREFIX		- where the library is installed
#	_%%LIB%%_VERSION	- version of the shared library
#	_%%LIB%%_SLIB		- name of the shared library
#

_ecore_CATEGORY=	devel
_ecore_PORTNAME=	ecore-main
_ecore_VERSION=		8

_edbus_CATEGORY=	devel
_edbus_PORTNAME=	e_dbus
_edbus_VERSION=		8

_eet_CATEGORY=		devel
_eet_VERSION=		8

_efreet_CATEGORY=	x11
_efreet_VERSION=	8

_edje_CATEGORY=		graphics
_edje_VERSION=		8

_eio_CATEGORY=		devel
_eio_VERSION=		8

_eina_CATEGORY=		devel
_eina_VERSION=		8

_elementary_CATEGORY=	x11-toolkits
_elementary_VERSION=	8

_embryo_CATEGORY=	lang
_embryo_VERSION=	8

_emotion_CATEGORY=	multimedia
_emotion_VERSION=	8

_ender_CATEGORY=	graphics
_ender_VERSION=		0

_enesim_CATEGORY=	graphics
_enesim_VERSION=	0

_epeg_CATEGORY=		graphics
_epeg_VERSION=		9

_esvg_CATEGORY=		www
_esvg_PORTNAME=		egueb
_esvg_VERSION=		0

_etch_CATEGORY=		graphics
_etch_VERSION=		0

_ethumb_CATEGORY=	graphics
_ethumb_VERSION=	8

_evas_CATEGORY=		graphics
_evas_PORTNAME=		evas-core
_evas_VERSION=		8

_imlib2_CATEGORY=	graphics
_imlib2_VERSION=	5
_imlib2_SLIB=		Imlib2

#
# Assign values for variables which were not defined explicitly
#
.for LIB in ${_USE_EFL_ALL}
. if !defined(_${LIB}_SLIB)
_${LIB}_SLIB=${LIB}
. endif
. if !defined(_${LIB}_PORTNAME)
_${LIB}_PORTNAME=${LIB}
. endif
. if !defined(_${LIB}_PREFIX)
_${LIB}_PREFIX=${LOCALBASE}
. endif
.endfor

#
# Evas engines and loaders support.
# Values processed:
# _evas_engine_COMP_CATEGORY	- Where the port for this object is located
# _evas_engine_COMP_PORTNAME	- Object's port subdirectory
# _evas_engine_COMP_DIR		- Evas object's subdir
#

# All components that are currently supported
_EFL_EVAS_ENGINES_ALL=	buffer opengl sdl x11
_EFL_EVAS_LOADERS_ALL=	bmp edb eet generic gif ico jpeg \
			png pmaps psd svg tga tiff wbmp xpm

#
# Generic evas engines definitions
#
_EFL_EVAS_CATEGORY=		graphics
_EFL_EVAS_MODDIR=		${LOCALBASE}/lib/evas/modules/
_EFL_EVAS_ENGINES_MODDIR=	${_EFL_EVAS_MODDIR}/engines/
_EFL_EVAS_LOADERS_MODDIR=	${_EFL_EVAS_MODDIR}/loaders/

#
# Evas engine modules definitions
#

_evas_engine_buffer_DIR=	buffer
_evas_engine_opengl_DIR=	gl_x11
_evas_engine_sdl_DIR=		software_16_sdl
_evas_engine_x11_DIR=		software_x11

#
# Assign values for variables which were not defined explicitly
#
.for COMP in ${_EFL_EVAS_ENGINES_ALL}
. if !defined(_evas_engine_${COMP}_CATEGORY)
_evas_engine_${COMP}_CATEGORY=	${_EFL_EVAS_CATEGORY}
. endif
. if !defined(_evas_engine_${COMP}_PORTNAME)
_evas_engine_${COMP}_PORTNAME=	evas-engine-${COMP}
. endif
. if !defined(_evas_engine_${COMP}_DIR)
_evas_engine_${COMP}_DIR=	${COMP}
. endif
.endfor

.for COMP in ${_EFL_EVAS_LOADERS_ALL}
. if !defined(_evas_loader_${COMP}_CATEGORY)
_evas_loader_${COMP}_CATEGORY=	${_EFL_EVAS_CATEGORY}
. endif
. if !defined(_evas_loader_${COMP}_PORTNAME)
_evas_loader_${COMP}_PORTNAME=	evas-loader-${COMP}
. endif
. if !defined(_evas_loader_${COMP}_DIR)
_evas_loader_${COMP}_DIR=	${COMP}
. endif
.endfor

#
# Ecore modules support
# Values processed:
# _ecore_COMP_CATEGORY	- Where the port for this object is located
# _ecore_COMP_PORTNAME	- Object's port subdirectory
# _ecore_COMP_NAME	- Ecore library name
#

# All components that are currently supported
_EFL_ECORE_ALL=	con config desktop evas file imf imf_evas \
		input input_evas ipc job sdl txt x11

#
# Generic ecore definitions
#
_EFL_ECORE_CATEGORY=	devel
_EFL_ECORE_MODDIR=	${LOCALBASE}/lib/

#
# Ecore modules definitions
#

_ecore_con_CATEGORY=		net
_ecore_config_CATEGORY=		sysutils
_ecore_desktop_CATEGORY=	x11
_ecore_evas_CATEGORY=		graphics
_ecore_sdl_CATEGORY=		graphics
_ecore_txt_CATEGORY=		converters
_ecore_imf_CATEGORY=		x11
_ecore_imf_evas_CATEGORY=	x11
_ecore_input_CATEGORY=		x11
_ecore_input_evas_CATEGORY=	x11
_ecore_x11_CATEGORY=		x11
_ecore_x11_NAME=		ecore_x

#
# Assign values for variables which were not defined explicitly
#
.for COMP in ${_EFL_ECORE_ALL}
. if !defined(_ecore_${COMP}_CATEGORY)
_ecore_${COMP}_CATEGORY=${_EFL_ECORE_CATEGORY}
. endif
. if !defined(_ecore_${COMP}_PORTNAME)
_ecore_${COMP}_PORTNAME=ecore-${COMP}
. endif
. if !defined(_ecore_${COMP}_NAME)
_ecore_${COMP}_NAME=	ecore_${COMP}
. endif
.endfor

#
# Handle WANT_EFL feature
#
.if !defined(AFTERPORTMK)
.if !defined(EFL_Include_pre)

EFL_Include_pre=	bsd.efl.mk

HAVE_EFL?=
HAVE_EFL_ECORE?=
.if defined(WANT_EFL)
#
# General EFL components
#
. for LIB in ${_USE_EFL_ALL}
.  if exists(${_${LIB}_PREFIX}/lib/lib${_${LIB}_SLIB}.so.${_${LIB}_VERSION})
HAVE_EFL+=	${LIB}
.  endif
. endfor

#
# Ecore components
#
. for COMP in ${_EFL_ECORE_ALL}
.  if exists(${_ecore_PREFIX}/lib/lib${_ecore_${COMP}_NAME}.so.${_ecore_VERSION})
HAVE_EFL_ECORE+=	${COMP}
.  endif
. endfor
.endif

.endif #EFL_Include_pre
.endif #AFTERPORTMK

#
# Handle USE_EFL, USE_EFL_EVAS_* and USE_EFL_ECORE features
#
.if !defined(BEFOREPORTMK)
.if !defined(EFL_Include_post)

.if defined(USE_EFL_EVAS_ENGINES)

USE_EFL+=	evas

_USE_EFL_EVAS_ENGINES=	#empty
. for COMP in ${USE_EFL_EVAS_ENGINES}
.  if ${_EFL_EVAS_ENGINES_ALL:M${COMP}}==""
IGNORE=	cannot install: unknown evas engine ${COMP}
.  else
_USE_EFL_EVAS_ENGINES+=	${COMP}
.  endif
. endfor

# Get rid of duplicates
_USE_EFL_EVAS_ENGINES_UQ=	#empty
. for COMP in ${_USE_EFL_EVAS_ENGINES}
.  if ${_USE_EFL_EVAS_ENGINES_UQ:M${COMP}}==""
_USE_EFL_EVAS_ENGINES_UQ+=	${COMP}
.  endif
. endfor

. for COMP in ${_USE_EFL_EVAS_ENGINES_UQ}
BUILD_DEPENDS+=	${_EFL_EVAS_ENGINES_MODDIR}/${_evas_engine_${COMP}_DIR}/freebsd${OSREL}-${ARCH}/module.so:${PORTSDIR}/${_evas_engine_${COMP}_CATEGORY}/${_evas_engine_${COMP}_PORTNAME}
RUN_DEPENDS+=	${_EFL_EVAS_ENGINES_MODDIR}/${_evas_engine_${COMP}_DIR}/freebsd${OSREL}-${ARCH}/module.so:${PORTSDIR}/${_evas_engine_${COMP}_CATEGORY}/${_evas_engine_${COMP}_PORTNAME}
. endfor

.endif #USE_EFL_EVAS_ENGINES

.if defined(USE_EFL_EVAS_LOADERS)

USE_EFL+=	evas

_USE_EFL_EVAS_LOADERS=	#empty
. for COMP in ${USE_EFL_EVAS_LOADERS}
.  if ${_EFL_EVAS_LOADERS_ALL:M${COMP}}==""
IGNORE=	cannot install: unknown evas loader ${COMP}
.  else
_USE_EFL_EVAS_LOADERS+=	${COMP}
.  endif
. endfor

# Get rid of duplicates
_USE_EFL_EVAS_LOADERS_UQ=	#empty
. for COMP in ${_USE_EFL_EVAS_LOADERS}
.  if ${_USE_EFL_EVAS_LOADERS_UQ:M${COMP}}==""
_USE_EFL_EVAS_LOADERS_UQ+=	${COMP}
.  endif
. endfor

. for COMP in ${_USE_EFL_EVAS_LOADERS_UQ}
BUILD_DEPENDS+=	${_EFL_EVAS_LOADERS_MODDIR}/${_evas_loader_${COMP}_DIR}/freebsd${OSREL}-${ARCH}/module.so:${PORTSDIR}/${_evas_loader_${COMP}_CATEGORY}/${_evas_loader_${COMP}_PORTNAME}
RUN_DEPENDS+=	${_EFL_EVAS_LOADERS_MODDIR}/${_evas_loader_${COMP}_DIR}/freebsd${OSREL}-${ARCH}/module.so:${PORTSDIR}/${_evas_loader_${COMP}_CATEGORY}/${_evas_loader_${COMP}_PORTNAME}
. endfor

.endif #USE_EFL_EVAS_LOADERS

.if defined(USE_EFL_ECORE)

USE_EFL+=	ecore

_USE_EFL_ECORE=	#empty
. for COMP in ${USE_EFL_ECORE}
.  if ${_EFL_ECORE_ALL:M${COMP}}==""
IGNORE=	cannot install: unknown ecore module ${COMP}
.  else
_USE_EFL_ECORE+=	${COMP}
.  endif
. endfor

# Get rid of duplicates
_USE_EFL_ECORE_UQ=	#empty
. for COMP in ${_USE_EFL_ECORE}
.  if ${_USE_EFL_ECORE_UQ:M${COMP}}==""
_USE_EFL_ECORE_UQ+=	${COMP}
.  endif
. endfor

. for COMP in ${_USE_EFL_ECORE_UQ}
LIB_DEPENDS+=	${_ecore_${COMP}_NAME}.${_ecore_VERSION}:${PORTSDIR}/${_ecore_${COMP}_CATEGORY}/${_ecore_${COMP}_PORTNAME}
. endfor

.endif #USE_EFL_ECORE

.if defined(USE_EFL)

EFL_Include_post=	bsd.efl.mk

#
# Check if we have all libraries requiested and build depends list
#
.if ${USE_EFL:Mlibrt_hack}
_USE_EFL_LIBRT_HACK=	yes
.endif
.if ${USE_EFL:Mmodarch_hack}
_USE_EFL_MODARCH_HACK=	yes
.endif
.if ${USE_EFL:Mlibtool_hack}
_USE_EFL_LIBTOOL_HACK=	yes
.endif
_USE_EFL=	#empty
.for LIB in ${USE_EFL:Nlibrt_hack:Nmodarch_hack:Nlibtool_hack}
. if ${_USE_EFL_ALL:M${LIB}}==""
IGNORE=	cannot install: unknown library ${LIB}
. else
_USE_EFL+=	${LIB}
. endif
.endfor

#
# Get rid of duplicates
#
_USE_EFL_UQ=	#empty
.for LIB in ${_USE_EFL}
. if ${_USE_EFL_UQ:M${LIB}}==""
_USE_EFL_UQ+=	${LIB}
. endif
.endfor

#
# define dependencies
#
.for LIB in ${_USE_EFL_UQ}
LIB_DEPENDS+=	${_${LIB}_SLIB}.${_${LIB}_VERSION}:${PORTSDIR}/${_${LIB}_CATEGORY}/${_${LIB}_PORTNAME}
.endfor

#
# Initialize configure enviropment
#
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_SUB+=	E17_ARCH=freebsd${OSREL}-${ARCH}

.if defined(_USE_EFL_LIBRT_HACK)
#
# Don't use librt
#
post-patch: efl_drop_librt
efl_drop_librt:
	@${REINPLACE_CMD} -E \
		-e '/^[[:space:]]+freebsd\*/,/^[[:space:]];;/s/-lrt//g' \
		${WRKSRC}/configure
.endif

.if defined(_USE_EFL_MODARCH_HACK)
#
# Use correct module arch path
#
post-patch: efl_patch_modarch
efl_patch_modarch:
	@${REINPLACE_CMD} -E \
		-e 's/(MODULE_ARCH="\$$host_os-\$$host_cpu)-[^"]+"/\1"/g' \
		-e 's/(MODULE_EDJE="\$$host_os-\$$host_cpu)-[^"]+"/\1"/g' \
		${WRKSRC}/configure
.endif

.if defined(_USE_EFL_LIBTOOL_HACK)
#
# Get rid of .la and static library files
#
post-configure: efl_drop_la
efl_drop_la:
	${REINPLACE_CMD} -E -e \
		'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool
.endif

.endif #USE_EFL

.endif #EFL_Include_post
.endif #BEFOREPORTMK
