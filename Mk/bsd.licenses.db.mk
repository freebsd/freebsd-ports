#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# bsd.licenses.db.mk - License database for bsd.licenses.mk
#
# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
#
# Please view me with 4 column tabs!
#

# Possible sources for information:
# - FOSSology (see "Default License Groups")
#   http://fossology.org/interpret_the_license_group_analysis_report
#
# - Wikipedia (article "Comparison of Free Software Licenses")
#   http://en.wikipedia.org/wiki/Comparison_of_free_software_licences
#
# Probably will be automatically incorporated from FOSSology's software.
#
# IMPORTANT: as this file is going to be included by most ports, we may
# consider having licenses here only as "tags" as most of them will be free,
# to remove some loops and additional variables here. This will not affect the
# rest of bsd.licenses.mk, and anyways restricted licenses that aren't used by
# many ports should be defined in each one's Makefile.

# XXX Start of editable section

# License definitions
#
# _LICENSE_LIST			- List of defined licenses
# _LICENSE_LIST_GROUPS	- List of defined license groups
#

_LICENSE_LIST=			ASL BSD BSL CDDL GFDL GPLv2 GPLv3 LGPL20 LGPL21 LGPL3 MIT MPL
_LICENSE_LIST_GROUPS=	FSF GPL OSI

# List of groups (only names must be present)

_LICENSE_NAME_FSF=		Free Software Foundation Approved

_LICENSE_NAME_GPL=		GPL Compatible

_LICENSE_NAME_OSI=		OSI Approved

# Default permissions for licenses here, if not defined

_LICENSE_PERMS_DEFAULT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# Properties of license "xxx" (similar to port variables, but single)
#
# _LICENSE_NAME_xxx		- Full name/description of license/group
# _LICENSE_PERMS_xxx	- Permissions (if not defined defaults to
# 						  ${_LICENSE_PERMS_DEFAULT}.
# _LICENSE_GROUPS_xxx	- Groups (optional)
#
# Notes:
# - General permissions from groups are added to each license, if not defined.
#

_LICENSE_NAME_ASL=		Apache License
_LICENSE_GROUPS_ASL=	FSF OSI

_LICENSE_NAME_BSD=		BSD license
_LICENSE_GROUPS_BSD=	FSF OSI

_LICENSE_NAME_BSL=		Boost Software License
_LICENSE_GROUPS_BSL=	FSF OSI

_LICENSE_NAME_CDDL=		Common Development and Distribution License
_LICENSE_GROUPS_CDDL=	FSF OSI

_LICENSE_NAME_GFDL=		GNU Free Documentation License
_LICENSE_GROUPS_GFDL=	FSF

_LICENSE_NAME_GPLv2=	GNU General Public License version 2
_LICENSE_GROUPS_GPLv2=	FSF GPL OSI

_LICENSE_NAME_GPLv3=	GNU General Public License version 3
_LICENSE_GROUPS_GPLv3=	FSF GPL OSI

_LICENSE_NAME_LGPL20=	GNU Library General Public License version 2.0
_LICENSE_GROUPS_LGPL20=	FSF GPL OSI

_LICENSE_NAME_LGPL21=	GNU Lesser General Public License version 2.1
_LICENSE_GROUPS_LGPL21=	FSF GPL OSI

_LICENSE_NAME_LGPL3=	GNU Lesser General Public License version 3
_LICENSE_GROUPS_LGPL3=	FSF GPL OSI

_LICENSE_NAME_MIT=		MIT license / X11 license
_LICENSE_GROUPS_MIT=	FSF GPL OSI

_LICENSE_NAME_MPL=		Mozilla Public License
_LICENSE_GROUPS_MPL=	FSF OSI

# Set default permissions if not defined

.for lic in ${_LICENSE_LIST}
.	if !defined(_LICENSE_PERMS_${lic})
_LICENSE_PERMS_${lic}=	${_LICENSE_PERMS_DEFAULT}
.	endif
.endfor
