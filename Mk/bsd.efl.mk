#
# $MBSDlabs: portmk/bsd.efl.mk,v 1.17 2006/10/02 14:57:48 stas Exp $
# $FreeBSD$
#
# bsd.efl.mk - Support for Enlightenment Foundation Libraries (EFL)
#
# Author: Stanislav Sedov <ssedov@mbsd.msk.ru>
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
#		  on the target system
# USE_EFL_ESMART- the ports depends on specified esmart objects (or on all
#		  esmart objects if "yes")
#
# The following variables could be tested after inclusion of bsd.port.pre.mk:
# HAVE_EFL	- lists all EFL libraries which are available on target system
# HAVE_EFL_ESMART - esmart objects available
#
# Feel free to send any comments and suggestion to maintainer.
#

EFL_Include_MAINTAINER=	ssedov@mbsd.msk.ru

#
# Define all supported libraries
#
_USE_EFL_ALL=	ecore edb edje eet embryo emotion engrave enhance epeg \
		epsilon etk etox evas evfs ewl exml imlib2

# For each library supported we define the following variables:
#	_%%LIB%%_CATEGORY	- category the port belongs to
#	_%%LIB%%_DEPENDS	- other EFL libraries the library
#		itself depends on. We'll define them explicitly
#		to handle unwanted deinstalls.
#	_%%LIB%%_PREFIX		- where the library is installed
#	_%%LIB%%_VERSION	- version of the shared library
#	_%%LIB%%_SLIB		- name of the shared library
#

_ecore_CATEGORY=	x11
_ecore_DEPENDS=		evas
_ecore_PREFIX=		${LOCALBASE}
_ecore_VERSION=		1

_edb_CATEGORY=		databases
_edb_PREFIX=		${LOCALBASE}
_edb_VERSION=		1

_eet_CATEGORY=		devel
_eet_PREFIX=		${LOCALBASE}
_eet_VERSION=		9

_edje_CATEGORY=		graphics
_edje_DEPENDS=		embryo eet imlib2 evas ecore
_edje_PREFIX=		${LOCALBASE}
_edje_VERSION=		5

_embryo_CATEGORY=	lang
_embryo_PREFIX=		${LOCALBASE}
_embryo_VERSION=	9

_emotion_CATEGORY=	multimedia
_emotion_DEPENDS=	ecore edje eet embryo evas
_emotion_PREFIX=	${LOCALBASE}
_emotion_VERSION=	0

_engrave_CATEGORY=	devel
_engrave_DEPENDS=	ecore evas
_engrave_PREFIX=	${LOCALBASE}
_engrave_VERSION=	1

_enhance_CATEGORY=	x11-toolkits
_enhance_DEPENDS=	ecore etk exml
_enhance_PREFIX=	${LOCALBASE}
_enhance_VERSION=	0

_epeg_CATEGORY=		graphics
_epeg_PREFIX=		${LOCALBASE}
_epeg_VERSION=		9

_epsilon_CATEGORY=	graphics
_epsilon_DEPENDS=	epeg edje imlib2 ecore
_epsilon_PREFIX=	${LOCALBASE}
_epsilon_VERSION=	0

_etk_CATEGORY=		x11-toolkits
_etk_DEPENDS=		evas ecore edje
_etk_PREFIX=		${LOCALBASE}
_etk_VERSION=		1

_etox_CATEGORY=		x11-toolkits
_etox_DEPENDS=		edb evas ecore
_etox_PREFIX=		${LOCALBASE}
_etox_VERSION=		0

_evas_CATEGORY=		graphics
_evas_DEPENDS=		eet edb
_evas_PREFIX=		${LOCALBASE}
_evas_VERSION=		1

_evfs_CATEGORY=		devel
_evfs_DEPENDS=		eet ecore
_evfs_PREFIX=		${LOCALBASE}
_evfs_VERSION=		0

_ewl_CATEGORY=		x11-toolkits
_ewl_DEPENDS=		evas ecore edje epsilon
_ewl_PREFIX=		${LOCALBASE}
_ewl_VERSION=		1

_exml_CATEGORY=		textproc
_exml_DEPENDS=		ecore
_exml_PREFIX=		${LOCALBASE}
_exml_VERSION=		1

_imlib2_CATEGORY=	graphics
_imlib2_PREFIX=		${LOCALBASE}
_imlib2_VERSION=	4
_imlib2_SLIB=		Imlib2

#
# Assign values for variables which were not defined explicitly
#
.for LIB in ${_USE_EFL_ALL}
. if !defined(_${LIB}_DEPENDS)
_${LIB}_DEPENDS=	#empty
. endif
. if !defined(_${LIB}_SLIB)
_${LIB}_SLIB=${LIB}
. endif
.endfor

#
# Esmart support. We'll define esmart components in the way they are
# defined for EFL.
# Values processed:
# _esmart_COMP_CATEGORY	- Where the port for this esmart object is located
# _esmart_COMP_PORTNAME	- Object's port subdirectory
# _esmart_COMP_DEPENDS	- Other components which this object depends on
# _esmart_COMP_PREFIX	- Where the shared library for this object is located
# _esmart_COMP_VERSION	- Version of the shared library
#

# All components that are currently supported
_EFL_ESMART_ALL=	container draggies file_dialog text_entry \
			thumb trans_x11

#
# Generic stock esmart definitions
#
_EFL_ESMART_CATEGORY=	graphics
_EFL_ESMART_PORTNAME=	esmart
_EFL_ESMART_DEPENDS=	epsilon evas ecore imlib2 edje
_EFL_ESMART_PREFIX=	${LOCALBASE}
_EFL_ESMART_VERSION=	0

#
# Assign values for variables which were not defined explicitly
#
.for COMP in ${_EFL_ESMART_ALL}
. if !defined(_esmart_${COMP}_CATEGORY)
_esmart_${COMP}_CATEGORY=	${_EFL_ESMART_CATEGORY}
. endif
. if !defined(_esmart_${COMP}_PORTNAME)
_esmart_${COMP}_PORTNAME=	${_EFL_ESMART_PORTNAME}
. endif
. if !defined(_esmart_${COMP}_PREFIX)
_esmart_${COMP}_PREFIX=	${_EFL_ESMART_PREFIX}
. endif
. if !defined(_esmart_${COMP}_DEPENDS)
_esmart_${COMP}_DEPENDS=	#empty
. endif
. if !defined(_esmart_${COMP}_SLIB)
_esmart_${COMP}_SLIB=	esmart_${COMP}
. endif
. if !defined(_esmart_${COMP}_VERSION)
_esmart_${COMP}_VERSION=	${_EFL_ESMART_VERSION}
. endif
.endfor

#
# Handle WANT_EFL feature
#
.if !defined(AFTERPORTMK)
.if !defined(EFL_Include_pre)

EFL_Include_pre=	bsd.efl.mk

HAVE_EFL?=
HAVE_EFL_ESMART?=
.if defined(WANT_EFL)
. for LIB in ${_USE_EFL_ALL}
.  if exists(${_${LIB}_PREFIX}/lib/lib${_${LIB}_SLIB}.so.${_${LIB}_VERSION})
HAVE_EFL+=	${LIB}
.  endif
. endfor
. for COMP in ${_EFL_ESMART_ALL}
.  if exists(${_esmart_${COMP}_PREFIX}/lib/lib${_esmart_${COMP}_SLIB}.so.${_esmart_${COMP}_VERSION})
HAVE_EFL_ESMART+=	${COMP}
.  endif
. endfor
.endif

.endif #EFL_Include_pre
.endif #AFTERPORTMK

#
# Handle USE_EFL & USE_ESMART feature
#
.if !defined(BEFOREPORTMK)
.if !defined(EFL_Include_post)

.if defined(USE_EFL_ESMART)

USE_EFL+=	${_EFL_ESMART_DEPENDS} #we use EFL too

_USE_EFL_ESMART=	#empty
.if USE_EFL_ESMART=="yes"
_USE_EFL_ESMART=	${_EFL_ESMART_ALL}
.else
. for COMP in ${USE_EFL_ESMART}
.  if ${_EFL_ESMART_ALL:M${COMP}}==""
IGNORE=	cannot install: unknown Esmart component ${COMP}
.  else
_USE_EFL_ESMART+=	${COMP} ${_esmart_${COMP}_DEPENDS}
.  endif
. endfor
.endif

# Get rid of duplicates
#.if ${OSVERSION} > 700016
#_USE_EFL_ESMART_UQ=	${_USE_EFL_ESMART:O:u}
#.else
_USE_EFL_ESMART_UQ=	#empty
. for COMP in ${_USE_EFL_ESMART}
.  if ${_USE_EFL_ESMART_UQ:M${COMP}}==""
_USE_EFL_ESMART_UQ+=	${COMP}
.  endif
. endfor
#.endif

.for COMP in ${_USE_EFL_ESMART_UQ}
LIB_DEPENDS+=	${_esmart_${COMP}_SLIB}.${_esmart_${COMP}_VERSION}:${PORTSDIR}/${_esmart_${COMP}_CATEGORY}/${_esmart_${COMP}_PORTNAME}
.endfor

.endif #USE_EFL_ESMART

.if defined(USE_EFL)

EFL_Include_post=	bsd.efl.mk

#
# Check if we have all libraries requiested and build depends list
#
_USE_EFL=	#empty
.for LIB in ${USE_EFL}
. if ${_USE_EFL_ALL:M${LIB}}==""
IGNORE=	cannot install: unknown library ${LIB}
. endif
_USE_EFL+=	${_${LIB}_DEPENDS} ${LIB}
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
LIB_DEPENDS+=	${_${LIB}_SLIB}.${_${LIB}_VERSION}:${PORTSDIR}/${_${LIB}_CATEGORY}/${LIB}
.endfor

#
# Initialize configure enviropment
#
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		CFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${LDFLAGS}"

PLIST_SUB+=	E17_ARCH=freebsd${OSREL}-${ARCH}

.endif #USE_EFL

.endif #EFL_Include_post
.endif #BEFOREPORTMK
