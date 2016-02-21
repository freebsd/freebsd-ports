#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$

# ** Please run changes to this file by eadler@ first **

Licenses_db_Include_MAINTAINER=         portmgr@FreeBSD.org

#
# bsd.licenses.db.mk - License database for bsd.licenses.mk
#
# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
#
# Please view me with 4 column tabs!
#

# The canonical source of license names and short-name identifiers:
# - SPDX License List
#   https://spdx.org/licenses/
#
# See also:
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
# _LICENSE_LIST		- List of defined licenses
# _LICENSE_LIST_GROUPS	- List of defined license groups
#

_LICENSE_LIST= 	BSL CC0-1.0 CDDL CPAL-1.0 ClArtistic EPL GFDL GMGPL \
				ISCL MIT MPL NCSA OFL10 OFL11 OWL OpenSSL PD PSFL PostgreSQL \
				RUBY ZLIB ZPL21

# GNU family
_LICENSE_LIST+= AGPLv3 GPLv1 GPLv2 GPLv3 GPLv3RLE LGPL20 LGPL21 LGPL3
_LICENSE_LIST+= AGPLv3+ GPLv1+ GPLv2+ GPLv3+ GPLv3RLE+ LGPL20+ LGPL21+ \
				LGPL3+

# BSD family
_LICENSE_LIST+= BSD BSD2CLAUSE BSD3CLAUSE BSD4CLAUSE

# LaTeX family
_LICENSE_LIST+= LPPL10 LPPL11 LPPL12 LPPL13 LPPL13a LPPL13b LPPL13c

# Apache family
_LICENSE_LIST+= APACHE10 APACHE11 APACHE20

# Artistic family
_LICENSE_LIST+= ART10 ARTPERL10 ART20

# PHP family
_LICENSE_LIST+= PHP202 PHP30 PHP301

# List of groups (only names must be present)

_LICENSE_NAME_FSF=	Free Software Foundation Approved

_LICENSE_NAME_GPL=	GPL Compatible

_LICENSE_NAME_OSI=	OSI Approved

_LICENSE_NAME_COPYFREE= Complies with Copyfree Standard Definition

_LICENSE_NAME_FONTS=	Font licenses

# Default permissions for licenses here, if not defined

_LICENSE_PERMS_DEFAULT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# Properties of license "xxx" (similar to port variables, but single)
#
# _LICENSE_NAME_xxx	- Full name/description of license/group
# _LICENSE_PERMS_xxx	- Permissions (if not defined defaults to
# 						  ${_LICENSE_PERMS_DEFAULT}.
# _LICENSE_GROUPS_xxx	- Groups (optional)
#
# Notes:
# - General permissions from groups are added to each license, if not defined.
#

_LICENSE_NAME_AGPLv3=	GNU Affero General Public License version 3
_LICENSE_GROUPS_AGPLv3=	FSF GPL OSI

# Note that though plus is allowed in a variable (and this license) name it
# needs an extra space before following equals sign for them not to be parsed
# as a single += operator
_LICENSE_NAME_AGPLv3+ =	${_LICENSE_NAME_AGPLv3} (or later)
_LICENSE_GROUPS_AGPLv3+ =	${_LICENSE_GROUPS_AGPLv3}

_LICENSE_NAME_APACHE10=	Apache License 1.0
_LICENSE_GROUPS_APACHE10=	FSF

_LICENSE_NAME_APACHE11=	Apache License 1.1
_LICENSE_GROUPS_APACHE11=	FSF OSI

_LICENSE_NAME_APACHE20=	Apache License 2.0
_LICENSE_GROUPS_APACHE20=	FSF OSI

_LICENSE_NAME_ART10=	Artistic License version 1.0
_LICENSE_GROUPS_ART10=	OSI

_LICENSE_NAME_ARTPERL10=Artistic License (perl) version 1.0
_LICENSE_GROUPS_ARTPERL10=	OSI

_LICENSE_NAME_ART20=	Artistic License version 2.0
_LICENSE_GROUPS_ART20=	FSF GPL OSI

_LICENSE_NAME_BSD=	BSD license Generic Version (deprecated)
_LICENSE_GROUPS_BSD=	FSF OSI COPYFREE

_LICENSE_NAME_BSD2CLAUSE=	BSD 2-clause "Simplified" License
_LICENSE_GROUPS_BSD2CLAUSE=	FSF OSI COPYFREE

_LICENSE_NAME_BSD3CLAUSE=	BSD 3-clause "New" or "Revised" License
_LICENSE_GROUPS_BSD3CLAUSE=	FSF OSI COPYFREE

_LICENSE_NAME_BSD4CLAUSE=	BSD 4-clause "Original" or "Old" License
_LICENSE_GROUPS_BSD4CLAUSE=	FSF

_LICENSE_NAME_BSL=	Boost Software License
_LICENSE_GROUPS_BSL=	FSF OSI COPYFREE

_LICENSE_NAME_CC0-1.0=		Creative Commons Zero v1.0 Universal
_LICENSE_GROUPS_CC0-1.0=	FSF GPL COPYFREE

_LICENSE_NAME_CDDL=	Common Development and Distribution License
_LICENSE_GROUPS_CDDL=	FSF OSI

_LICENSE_NAME_ClArtistic=	Clarified Artistic License
_LICENSE_GROUPS_ClArtistic=	FSF GPL OSI

_LICENSE_NAME_CPAL-1.0=		Common Public Attribution License
_LICENSE_GROUPS_CPAL-1.0=	FSF OSI

_LICENSE_NAME_EPL=	Eclipse Public License
_LICENSE_GROUPS_EPL=	FSF OSI

_LICENSE_NAME_GFDL=	GNU Free Documentation License
_LICENSE_GROUPS_GFDL=	FSF

_LICENSE_NAME_GMGPL=	GNAT Modified General Public License
_LICENSE_GROUPS_GMGPL=	FSF GPL OSI

_LICENSE_NAME_GPLv1=	GNU General Public License version 1
_LICENSE_GROUPS_GPLv1=	FSF GPL OSI

_LICENSE_NAME_GPLv1+ =	${_LICENSE_NAME_GPLv1} (or later)
_LICENSE_GROUPS_GPLv1+ =	${_LICENSE_GROUPS_GPLv1}

_LICENSE_NAME_GPLv2=	GNU General Public License version 2
_LICENSE_GROUPS_GPLv2=	FSF GPL OSI

_LICENSE_NAME_GPLv2+ =	${_LICENSE_NAME_GPLv2} (or later)
_LICENSE_GROUPS_GPLv2+ =	${_LICENSE_GROUPS_GPLv2}

_LICENSE_NAME_GPLv3=	GNU General Public License version 3
_LICENSE_GROUPS_GPLv3=	FSF GPL OSI

_LICENSE_NAME_GPLv3+ =	${_LICENSE_NAME_GPLv3} (or later)
_LICENSE_GROUPS_GPLv3+ =	${_LICENSE_GROUPS_GPLv3}

_LICENSE_NAME_GPLv3RLE=	GNU GPL version 3 Runtime Library Exception
_LICENSE_GROUPS_GPLv3RLE=	FSF GPL OSI

_LICENSE_NAME_GPLv3RLE+ =	${_LICENSE_NAME_GPLv3RLE} (or later)
_LICENSE_GROUPS_GPLv3RLE+ =	${_LICENSE_GROUPS_GPLv3RLE}

_LICENSE_NAME_ISCL=	Internet Systems Consortium License
_LICENSE_GROUPS_ISCL=	FSF GPL OSI COPYFREE

_LICENSE_NAME_LGPL20=	GNU Library General Public License version 2.0
_LICENSE_GROUPS_LGPL20=	FSF GPL OSI

_LICENSE_NAME_LGPL20+ =	${_LICENSE_NAME_LGPL20} (or later)
_LICENSE_GROUPS_LGPL20+ =	${_LICENSE_GROUPS_LGPL20}

_LICENSE_NAME_LGPL21=	GNU Lesser General Public License version 2.1
_LICENSE_GROUPS_LGPL21=	FSF GPL OSI

_LICENSE_NAME_LGPL21+ =	${_LICENSE_NAME_LGPL21} (or later)
_LICENSE_GROUPS_LGPL21+ =	${_LICENSE_GROUPS_LGPL21}

_LICENSE_NAME_LGPL3=	GNU Lesser General Public License version 3
_LICENSE_GROUPS_LGPL3=	FSF GPL OSI

_LICENSE_NAME_LGPL3+ =	${_LICENSE_NAME_LGPL3} (or later)
_LICENSE_GROUPS_LGPL3+ =	${_LICENSE_GROUPS_LGPL3}

_LICENSE_NAME_LPPL10=	LaTeX Project Public License version 1.0
_LICENSE_GROUPS_LPPL10=	FSF OSI
_LICENSE_PERMS_LPPL10=	dist-mirror dist-sell

_LICENSE_NAME_LPPL11=	LaTeX Project Public License version 1.1
_LICENSE_GROUPS_LPPL11=	FSF OSI
_LICENSE_PERMS_LPPL11= dist-mirror dist-sell

_LICENSE_NAME_LPPL12=	LaTeX Project Public License version 1.2
_LICENSE_GROUPS_LPPL12=	FSF OSI
_LICENSE_PERMS_LPPL12=	dist-mirror dist-sell

_LICENSE_NAME_LPPL13=	LaTeX Project Public License version 1.3
_LICENSE_GROUPS_LPPL13=	FSF OSI
_LICENSE_PERMS_LPPL13=	dist-mirror dist-sell

_LICENSE_NAME_LPPL13a=	LaTeX Project Public License version 1.3a
_LICENSE_GROUPS_LPPL13a=	FSF OSI
_LICENSE_PERMS_LPPL13a=	dist-mirror dist-sell

_LICENSE_NAME_LPPL13b=	LaTeX Project Public License version 1.3b
_LICENSE_GROUPS_LPPL13b=	FSF OSI
_LICENSE_PERMS_LPPL13b=	dist-mirror dist-sell

_LICENSE_NAME_LPPL13c=	LaTeX Project Public License version 1.3c
_LICENSE_GROUPS_LPPL13c=	FSF OSI
_LICENSE_PERMS_LPPL13c=	dist-mirror dist-sell

_LICENSE_NAME_MIT=	MIT license / X11 license
_LICENSE_GROUPS_MIT=	COPYFREE FSF GPL OSI

_LICENSE_NAME_MPL=	Mozilla Public License
_LICENSE_GROUPS_MPL=	FSF OSI

_LICENSE_NAME_NCSA=	University of Illinois/NCSA Open Source License
_LICENSE_GROUPS_NCSA=	COPYFREE FSF GPL OSI

_LICENSE_NAME_OFL10=	SIL Open Font License version 1.0 (http://scripts.sil.org/OFL)
_LICENSE_GROUPS_OFL10=	FONTS

_LICENSE_NAME_OFL11=	SIL Open Font License version 1.1 (http://scripts.sil.org/OFL)
_LICENSE_GROUPS_OFL11=	FONTS

_LICENSE_NAME_OpenSSL=	OpenSSL License
_LICENSE_GROUPS_OpenSSL=	FSF

_LICENSE_NAME_OWL=	Open Works License (owl.apotheon.org)
_LICENSE_GROUPS_OWL=	COPYFREE

_LICENSE_NAME_PostgreSQL=	PostgreSQL Licence
_LICENSE_GROUPS_PostgreSQL=	FSF GPL OSI COPYFREE

_LICENSE_NAME_PD=		Public Domain
_LICENSE_GROUPS_PD=		GPL COPYFREE

_LICENSE_NAME_PHP202=	PHP License version 2.02
_LICENSE_GROUPS_PHP202=	FSF OSI

_LICENSE_NAME_PHP30=	PHP License version 3.0
_LICENSE_GROUPS_PHP30=	FSF OSI

_LICENSE_NAME_PHP301=	PHP License version 3.01
_LICENSE_GROUPS_PHP301=	FSF OSI

_LICENSE_NAME_PSFL=	Python Software Foundation License
_LICENSE_GROUPS_PSFL=	FSF GPL OSI

_LICENSE_NAME_RUBY=	Ruby License
_LICENSE_GROUPS_RUBY=	FSF

_LICENSE_NAME_ZLIB=		zlib License
_LICENSE_GROUPS_ZLIB=	GPL FSF OSI

_LICENSE_NAME_ZPL21=	Zope Public License version 2.1
_LICENSE_GROUPS_ZPL21=	GPL OSI

# Set default permissions if not defined

.for lic in ${_LICENSE_LIST}
.	if !defined(_LICENSE_PERMS_${lic})
# note that space before = is needed to correctly handle licenses
# ending with a plus sign
_LICENSE_PERMS_${lic} =	${_LICENSE_PERMS_DEFAULT}
.	endif
.endfor
