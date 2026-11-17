#-*- tab-width: 4; -*-
# ex:ts=4

# ** Please run changes to this file by eadler@ first **

Licenses_db_Include_MAINTAINER=         portmgr@FreeBSD.org

#
# bsd.licenses.db.mk - License database for bsd.licenses.mk
#
#
# Please view me with 4 column tabs!
#

# The canonical source of license names and short-name identifiers:
# - SPDX License List
#   https://spdx.org/licenses/
#
# See also:
# - Copyfree Licenses
#   http://copyfree.org/standard/licenses
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

_LICENSE_LIST= 	BSL CDDL EPL EU GFDL GMGPL \
				ISCL ODbL OFL10 OFL11 OWL PD PSFL \
				RUBY UNLICENSE WTFPL1 ZLIB ZPL21

# EU family
_LICENSE_LIST+= EUPL11 EUPL12

# GNU family
_LICENSE_LIST+= AGPLv3 GPLv1 GPLv2 GPLv3 GPLv3RLE LGPL20 LGPL21 LGPL3
_LICENSE_LIST+= AGPLv3+ GPLv1+ GPLv2+ GPLv3+ GPLv3RLE+ LGPL20+ LGPL21+ \
				LGPL3+

# BSD family
_LICENSE_LIST+= BSD BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSD4CLAUSE

# LaTeX family
_LICENSE_LIST+= LPPL10 LPPL11 LPPL12 LPPL13 LPPL13a LPPL13b LPPL13c

# Apache family
_LICENSE_LIST+= APACHE10 APACHE11 APACHE20

# Artistic family
_LICENSE_LIST+= ART10 ARTPERL10 ART20

# PHP family
_LICENSE_LIST+= PHP202 PHP30 PHP301

# MPL family
_LICENSE_LIST+= MPL10 MPL11 MPL20

# Others
_LICENSE_LIST+= NONE

# ---------------------------------------------------------------------------
# SPDX-spelled identifiers below, added via the portlicense SPDX-compliance
# audit's undefined-licenses report: SPDX ids independently detected in the
# tree with no _LICENSE_NAME_ entry to represent them.
#
# Deliberately excludes every id on that report which is itself a deprecated
# SPDX id (e.g. GPL-2.0+, GPL-3.0+, LGPL-3.0, bare GPL-1.0/GPL-3.0/AGPL-3.0,
# BSD-2-Clause-NetBSD, StandardML-NJ), only the modern replacement spelling
# is registered (e.g. GPL-2.0-or-later, LGPL-3.0-or-later), never the
# deprecated alias, so nothing here steers a new port toward a spelling SPDX
# itself no longer recommends.
#
# 3 of these are SPDX *exceptions* (used as "<license> WITH <exception>" in
# a real SPDX expression), not standalone licenses on their own;
# GCC-exception-3.1, Independent-modules-exception, cryptsetup-OpenSSL-
# exception. This framework has no WITH-expression support, so they are
# registered here as plain standalone LICENSE= tokens like everything else;
# flagged individually below so nobody mistakes one for a complete license
# grant by itself.
# ---------------------------------------------------------------------------

# Pre-existing (already SPDX-spelled before this audit's additions below;
# the entire Creative Commons family, plus CPAL-1.0/ClArtistic/MIT/NCSA/
# OpenSSL/PostgreSQL/WTFPL, were all added correctly-spelled from day one).
# Moved here, out of the legacy _LICENSE_LIST+= blocks above.
_LICENSE_SPDX_LIST= \
				CC0-1.0 CC-BY-1.0 CC-BY-2.0 CC-BY-2.5 \
				CC-BY-3.0 CC-BY-4.0 CC-BY-ND-1.0 CC-BY-ND-2.0 \
				CC-BY-ND-2.5 CC-BY-ND-3.0 CC-BY-ND-4.0 CC-BY-NC-1.0 \
				CC-BY-NC-2.0 CC-BY-NC-2.5 CC-BY-NC-3.0 CC-BY-NC-4.0 \
				CC-BY-NC-ND-1.0 CC-BY-NC-ND-2.0 CC-BY-NC-ND-2.5 CC-BY-NC-ND-3.0 \
				CC-BY-NC-ND-4.0 CC-BY-NC-SA-1.0 CC-BY-NC-SA-2.0 CC-BY-NC-SA-2.5 \
				CC-BY-NC-SA-3.0 CC-BY-NC-SA-4.0 CC-BY-SA-1.0 CC-BY-SA-2.0 \
				CC-BY-SA-2.5 CC-BY-SA-3.0 CC-BY-SA-4.0 CPAL-1.0 \
				ClArtistic MIT NCSA OpenSSL \
				PostgreSQL WTFPL

# GNU family (SPDX)
_LICENSE_SPDX_LIST+= \
				AGPL-1.0-only AGPL-3.0-only AGPL-3.0-or-later GPL-1.0-only GPL-1.0-or-later \
				GPL-2.0-only GPL-2.0-or-later GPL-3.0-only GPL-3.0-or-later LGPL-2.0-or-later \
				LGPL-2.0-only LGPL-2.1-only LGPL-2.1-or-later LGPL-3.0-only LGPL-3.0-or-later \
				GFDL-1.2-or-later GFDL-1.3-invariants-or-later GFDL-1.3-no-invariants-or-later \
				GCC-exception-3.1

# BSD family (SPDX variants)
_LICENSE_SPDX_LIST+= \
				0BSD BSD-1-Clause BSD-2-Clause BSD-2-Clause-Darwin BSD-2-Clause-first-lines \
				BSD-2-Clause-pos-unchanged BSD-2-Clause-Views BSD-3-Clause BSD-3-Clause-Attribution \
				BSD-3-Clause-Clear BSD-3-Clause-flex BSD-3-Clause-HP BSD-3-Clause-LBNL \
				BSD-3-Clause-Modification BSD-3-Clause-No-Military-License \
				BSD-3-Clause-No-Nuclear-License-2014 BSD-3-Clause-Open-MPI BSD-3-Clause-Sun BSD-3-Clause-Tso \
				BSD-4-Clause BSD-4-Clause-UC BSD-4.3TAHOE BSD-Attribution-HPND-disclaimer BSD-Inferno-Nettverk \
				BSD-Mark-Modifications BSD-Source-beginning-file BSD-Systemics BSD-Systemics-W3Works

# MIT / X11 / HPND family
_LICENSE_SPDX_LIST+= \
				MIT-0 MIT-advertising MIT-Festival MIT-Khronos-old \
				MIT-Modern-Variant MIT-open-group MIT-STK MIT-testregex \
				X11 X11-distribute-modifications-variant X11-swapped Xdebug-1.03 \
				Xnet HPND-MIT-disclaimer HPND-Netrek HPND-sell-MIT-disclaimer-xserver \
				HPND-sell-variant HPND-UC-export-US

# Artistic family (SPDX)
_LICENSE_SPDX_LIST+= \
				Artistic-1.0 Artistic-1.0-Perl Artistic-2.0

# Apache family
_LICENSE_SPDX_LIST+= \
				Apache-1.0 Apache-1.1 Apache-2.0

# MPL family (SPDX)
_LICENSE_SPDX_LIST+= \
				MPL-1.0 MPL-1.1 MPL-2.0

# LaTeX family (SPDX)
_LICENSE_SPDX_LIST+= \
				LPPL-1.0 LPPL-1.1 LPPL-1.2 LPPL-1.3a LPPL-1.3c

# PHP family (SPDX)
_LICENSE_SPDX_LIST+= \
				PHP-3.0 PHP-3.01

# Open-source / academic license family
_LICENSE_SPDX_LIST+= \
				AFL-2.1 BSL-1.0 CDDL-1.0 CDDL-1.1 CECILL-1.1 CECILL-2.0 \
				CECILL-2.1 CECILL-B CECILL-C CPL-1.0 \
				CUA-OPL-1.0 ECL-2.0 Elastic-2.0 EPL-1.0 \
				EPL-2.0 EUPL-1.1 EUPL-1.2 ISC LPL-1.02 ODbL-1.0 \
				OFL-1.0 OFL-1.1 OSET-PL-2.1 OSL-2.1 PSF-2.0 Ruby SSPL-1.0 SUL-1.0 \
				TGPPL-1.0 TPL-1.0 Unlicense ZPL-2.1 Zlib any-OSI

# Vendor/project-specific named licenses
_LICENSE_SPDX_LIST+= \
				Adobe-Utopia Aladdin Artistic-dist bzip2-1.0.6 \
				CC-PDDC CFITSIO checkmk CMU-Mach \
				cryptsetup-OpenSSL-exception curl DocBook-XML dtoa \
				GD HDF5 Hippocratic-2.1 ICU \
				ImageMagick Independent-modules-exception Info-ZIP jove \
				JSON libpng-2.0 Linux-OpenIB mplus \
				Multics MVT-1.1 NCL NRL NTP \
				OLDAP-1.4 OSSP Pixar pkgconf \
				Python-2.0.1 python-ldap Sendmail Sendmail-8.23 \
				SHL-0.5 SHL-0.51 Sleepycat SMLNJ Spencer-94 \
				SSLeay-standalone TCL Unicode-3.0 WordNet

_LICENSE_LIST+=	${_LICENSE_SPDX_LIST}

# List of groups (only names must be present)

_LICENSE_NAME_EU=	European Union Public Licence

_LICENSE_NAME_FSF=	Free Software Foundation Approved

_LICENSE_NAME_GPL=	GPL Compatible

_LICENSE_NAME_OSI=	OSI Approved

_LICENSE_NAME_COPYFREE= Complies with Copyfree Standard Definition

_LICENSE_NAME_FONTS=	Font licenses

# --- GNU family (SPDX) ---

_LICENSE_NAME_AGPL-1.0-only= Affero General Public License v1.0 only
_LICENSE_GROUPS_AGPL-1.0-only= # empty

_LICENSE_NAME_AGPL-3.0-only= GNU Affero General Public License v3.0 only
_LICENSE_GROUPS_AGPL-3.0-only= FSF OSI

_LICENSE_NAME_AGPL-3.0-or-later= GNU Affero General Public License v3.0 or later
_LICENSE_GROUPS_AGPL-3.0-or-later= FSF OSI

_LICENSE_NAME_GPL-1.0-only= GNU General Public License v1.0 only
_LICENSE_GROUPS_GPL-1.0-only= # empty

_LICENSE_NAME_GPL-1.0-or-later= GNU General Public License v1.0 or later
_LICENSE_GROUPS_GPL-1.0-or-later= # empty

_LICENSE_NAME_GPL-2.0-only= GNU General Public License v2.0 only
_LICENSE_GROUPS_GPL-2.0-only= FSF OSI

_LICENSE_NAME_GPL-2.0-or-later= GNU General Public License v2.0 or later
_LICENSE_GROUPS_GPL-2.0-or-later= FSF OSI

_LICENSE_NAME_GPL-3.0-only= GNU General Public License v3.0 only
_LICENSE_GROUPS_GPL-3.0-only= FSF OSI

_LICENSE_NAME_GPL-3.0-or-later= GNU General Public License v3.0 or later
_LICENSE_GROUPS_GPL-3.0-or-later= FSF OSI

_LICENSE_NAME_LGPL-2.0-only= GNU Library General Public License v2 only
_LICENSE_GROUPS_LGPL-2.0-only= OSI

_LICENSE_NAME_LGPL-2.0-or-later= GNU Library General Public License v2 or later
_LICENSE_GROUPS_LGPL-2.0-or-later= OSI

_LICENSE_NAME_LGPL-2.1-only= GNU Lesser General Public License v2.1 only
_LICENSE_GROUPS_LGPL-2.1-only= FSF OSI

_LICENSE_NAME_LGPL-2.1-or-later= GNU Lesser General Public License v2.1 or later
_LICENSE_GROUPS_LGPL-2.1-or-later= FSF OSI

_LICENSE_NAME_LGPL-3.0-only= GNU Lesser General Public License v3.0 only
_LICENSE_GROUPS_LGPL-3.0-only= FSF OSI

_LICENSE_NAME_LGPL-3.0-or-later= GNU Lesser General Public License v3.0 or later
_LICENSE_GROUPS_LGPL-3.0-or-later= FSF OSI

_LICENSE_NAME_GFDL-1.2-or-later= GNU Free Documentation License v1.2 or later
_LICENSE_GROUPS_GFDL-1.2-or-later= FSF

_LICENSE_NAME_GFDL-1.3-invariants-or-later= GNU Free Documentation License v1.3 or later - invariants
_LICENSE_GROUPS_GFDL-1.3-invariants-or-later= # empty

_LICENSE_NAME_GFDL-1.3-no-invariants-or-later= GNU Free Documentation License v1.3 or later - no invariants
_LICENSE_GROUPS_GFDL-1.3-no-invariants-or-later= # empty

_LICENSE_NAME_GCC-exception-3.1= GCC Runtime Library exception 3.1  # SPDX exception, used as "<license> WITH ${this}"
_LICENSE_GROUPS_GCC-exception-3.1= # empty

# --- BSD family (SPDX variants) ---

_LICENSE_NAME_0BSD=	BSD Zero Clause License
_LICENSE_GROUPS_0BSD=	OSI

_LICENSE_NAME_BSD-1-Clause= BSD 1-Clause License
_LICENSE_GROUPS_BSD-1-Clause= OSI

_LICENSE_NAME_BSD-2-Clause= BSD 2-Clause "Simplified" License
_LICENSE_GROUPS_BSD-2-Clause= FSF OSI

_LICENSE_NAME_BSD-2-Clause-Darwin= BSD 2-Clause - Ian Darwin variant
_LICENSE_GROUPS_BSD-2-Clause-Darwin= # empty

_LICENSE_NAME_BSD-2-Clause-first-lines= BSD 2-Clause - first lines requirement
_LICENSE_GROUPS_BSD-2-Clause-first-lines= # empty

_LICENSE_NAME_BSD-2-Clause-pos-unchanged= BSD 2-Clause - position unchanged variant
_LICENSE_GROUPS_BSD-2-Clause-pos-unchanged= # empty

_LICENSE_NAME_BSD-2-Clause-Views= BSD 2-Clause with views sentence
_LICENSE_GROUPS_BSD-2-Clause-Views= # empty

_LICENSE_NAME_BSD-3-Clause= BSD 3-clause "New" or "Revised" License
_LICENSE_GROUPS_BSD-3-Clause= FSF OSI COPYFREE

_LICENSE_NAME_BSD-3-Clause-Attribution= BSD with attribution
_LICENSE_GROUPS_BSD-3-Clause-Attribution= # empty

_LICENSE_NAME_BSD-3-Clause-Clear= BSD 3-Clause Clear License
_LICENSE_GROUPS_BSD-3-Clause-Clear= FSF

_LICENSE_NAME_BSD-3-Clause-flex= BSD 3-Clause Flex variant
_LICENSE_GROUPS_BSD-3-Clause-flex= # empty

_LICENSE_NAME_BSD-3-Clause-HP= Hewlett-Packard BSD variant license
_LICENSE_GROUPS_BSD-3-Clause-HP= # empty

_LICENSE_NAME_BSD-3-Clause-LBNL= Lawrence Berkeley National Labs BSD variant license
_LICENSE_GROUPS_BSD-3-Clause-LBNL= OSI

_LICENSE_NAME_BSD-3-Clause-Modification= BSD 3-Clause Modification
_LICENSE_GROUPS_BSD-3-Clause-Modification= # empty

_LICENSE_NAME_BSD-3-Clause-No-Military-License= BSD 3-Clause No Military License
_LICENSE_GROUPS_BSD-3-Clause-No-Military-License= # empty

_LICENSE_NAME_BSD-3-Clause-No-Nuclear-License-2014= BSD 3-Clause No Nuclear License 2014
_LICENSE_GROUPS_BSD-3-Clause-No-Nuclear-License-2014= # empty

_LICENSE_NAME_BSD-3-Clause-Open-MPI= BSD 3-Clause Open MPI variant
_LICENSE_GROUPS_BSD-3-Clause-Open-MPI= OSI

_LICENSE_NAME_BSD-3-Clause-Sun= BSD 3-Clause Sun Microsystems
_LICENSE_GROUPS_BSD-3-Clause-Sun= # empty

_LICENSE_NAME_BSD-3-Clause-Tso= BSD 3-Clause Tso variant
_LICENSE_GROUPS_BSD-3-Clause-Tso= # empty

_LICENSE_NAME_BSD-4-Clause= BSD 4-Clause "Original" or "Old" License
_LICENSE_GROUPS_BSD-4-Clause= FSF

_LICENSE_NAME_BSD-4-Clause-UC= BSD-4-Clause (University of California-Specific)
_LICENSE_GROUPS_BSD-4-Clause-UC= # empty

_LICENSE_NAME_BSD-4.3TAHOE= BSD 4.3 TAHOE License
_LICENSE_GROUPS_BSD-4.3TAHOE= # empty

_LICENSE_NAME_BSD-Attribution-HPND-disclaimer= BSD with Attribution and HPND disclaimer
_LICENSE_GROUPS_BSD-Attribution-HPND-disclaimer= # empty

_LICENSE_NAME_BSD-Inferno-Nettverk= BSD-Inferno-Nettverk
_LICENSE_GROUPS_BSD-Inferno-Nettverk= # empty

_LICENSE_NAME_BSD-Mark-Modifications= BSD Mark Modifications License
_LICENSE_GROUPS_BSD-Mark-Modifications= # empty

_LICENSE_NAME_BSD-Source-beginning-file= BSD Source Code Attribution - beginning of file variant
_LICENSE_GROUPS_BSD-Source-beginning-file= # empty

_LICENSE_NAME_BSD-Systemics= Systemics BSD variant license
_LICENSE_GROUPS_BSD-Systemics= # empty

_LICENSE_NAME_BSD-Systemics-W3Works= Systemics W3Works BSD variant license
_LICENSE_GROUPS_BSD-Systemics-W3Works= # empty

# --- MIT / X11 / HPND family ---

_LICENSE_NAME_MIT-0=	MIT No Attribution
_LICENSE_GROUPS_MIT-0=	OSI

_LICENSE_NAME_MIT-advertising= Enlightenment License (e16)
_LICENSE_GROUPS_MIT-advertising= # empty

_LICENSE_NAME_MIT-Festival= MIT Festival Variant
_LICENSE_GROUPS_MIT-Festival= # empty

_LICENSE_NAME_MIT-Khronos-old= MIT Khronos - old variant
_LICENSE_GROUPS_MIT-Khronos-old= # empty

_LICENSE_NAME_MIT-Modern-Variant= MIT License Modern Variant
_LICENSE_GROUPS_MIT-Modern-Variant= OSI

_LICENSE_NAME_MIT-open-group= MIT Open Group variant
_LICENSE_GROUPS_MIT-open-group= # empty

_LICENSE_NAME_MIT-STK=	MIT-STK License
_LICENSE_GROUPS_MIT-STK= # empty

_LICENSE_NAME_MIT-testregex= MIT testregex Variant
_LICENSE_GROUPS_MIT-testregex= # empty

_LICENSE_NAME_X11=	X11 License
_LICENSE_GROUPS_X11=	FSF

_LICENSE_NAME_X11-distribute-modifications-variant= X11 License Distribution Modification Variant
_LICENSE_GROUPS_X11-distribute-modifications-variant= # empty

_LICENSE_NAME_X11-swapped= X11 swapped final paragraphs
_LICENSE_GROUPS_X11-swapped= # empty

_LICENSE_NAME_Xdebug-1.03= Xdebug License v 1.03
_LICENSE_GROUPS_Xdebug-1.03= # empty

_LICENSE_NAME_Xnet=	X.Net License
_LICENSE_GROUPS_Xnet=	OSI

_LICENSE_NAME_HPND-MIT-disclaimer= Historical Permission Notice and Disclaimer with MIT disclaimer
_LICENSE_GROUPS_HPND-MIT-disclaimer= # empty

_LICENSE_NAME_HPND-Netrek= Historical Permission Notice and Disclaimer - Netrek variant
_LICENSE_GROUPS_HPND-Netrek= # empty

_LICENSE_NAME_HPND-sell-MIT-disclaimer-xserver= Historical Permission Notice and Disclaimer - sell xserver variant with MIT disclaimer
_LICENSE_GROUPS_HPND-sell-MIT-disclaimer-xserver= # empty

_LICENSE_NAME_HPND-sell-variant= Historical Permission Notice and Disclaimer - sell variant
_LICENSE_GROUPS_HPND-sell-variant= # empty

_LICENSE_NAME_HPND-UC-export-US= Historical Permission Notice and Disclaimer - University of California, US export warning
_LICENSE_GROUPS_HPND-UC-export-US= # empty

# --- Artistic family (SPDX) ---

_LICENSE_NAME_Artistic-1.0=	Artistic License 1.0
_LICENSE_GROUPS_Artistic-1.0=	OSI

_LICENSE_NAME_Artistic-1.0-Perl=	Artistic License 1.0 (Perl)
_LICENSE_GROUPS_Artistic-1.0-Perl=	OSI

_LICENSE_NAME_Artistic-2.0=	Artistic License 2.0
_LICENSE_GROUPS_Artistic-2.0=	FSF OSI

# --- Open-source / academic license family ---

_LICENSE_NAME_AFL-2.1=	Academic Free License v2.1
_LICENSE_GROUPS_AFL-2.1= FSF OSI

_LICENSE_NAME_Apache-1.0=	Apache License 1.0
_LICENSE_GROUPS_Apache-1.0= FSF

_LICENSE_NAME_Apache-1.1=	Apache License 1.1
_LICENSE_GROUPS_Apache-1.1= FSF OSI

_LICENSE_NAME_Apache-2.0=	Apache License 2.0
_LICENSE_GROUPS_Apache-2.0= FSF OSI

# --- MPL family (SPDX) ---

_LICENSE_NAME_MPL-1.0=	Mozilla Public License 1.0
_LICENSE_GROUPS_MPL-1.0=	OSI

_LICENSE_NAME_MPL-1.1=	Mozilla Public License 1.1
_LICENSE_GROUPS_MPL-1.1=	FSF OSI

_LICENSE_NAME_MPL-2.0=	Mozilla Public License 2.0
_LICENSE_GROUPS_MPL-2.0=	FSF OSI

# --- LaTeX family (SPDX) ---

_LICENSE_NAME_LPPL-1.0=	LaTeX Project Public License v1.0
_LICENSE_GROUPS_LPPL-1.0=	# empty

_LICENSE_NAME_LPPL-1.1=	LaTeX Project Public License v1.1
_LICENSE_GROUPS_LPPL-1.1=	# empty

_LICENSE_NAME_LPPL-1.2=	LaTeX Project Public License v1.2
_LICENSE_GROUPS_LPPL-1.2=	FSF

_LICENSE_NAME_LPPL-1.3a=	LaTeX Project Public License v1.3a
_LICENSE_GROUPS_LPPL-1.3a=	FSF

_LICENSE_NAME_LPPL-1.3c=	LaTeX Project Public License v1.3c
_LICENSE_GROUPS_LPPL-1.3c=	OSI

# --- PHP family (SPDX) ---

_LICENSE_NAME_PHP-3.0=	PHP License v3.0
_LICENSE_GROUPS_PHP-3.0=	OSI

_LICENSE_NAME_PHP-3.01=	PHP License v3.01
_LICENSE_GROUPS_PHP-3.01=	FSF OSI

_LICENSE_NAME_CDDL-1.1=	Common Development and Distribution License 1.1
_LICENSE_GROUPS_CDDL-1.1= OSI

_LICENSE_NAME_CECILL-1.1= CeCILL Free Software License Agreement v1.1
_LICENSE_GROUPS_CECILL-1.1= # empty

_LICENSE_NAME_CECILL-2.0= CeCILL Free Software License Agreement v2.0
_LICENSE_GROUPS_CECILL-2.0= FSF

_LICENSE_NAME_CECILL-2.1= CeCILL Free Software License Agreement v2.1
_LICENSE_GROUPS_CECILL-2.1= OSI

_LICENSE_NAME_CECILL-B=	CeCILL-B Free Software License Agreement
_LICENSE_GROUPS_CECILL-B= FSF

_LICENSE_NAME_CECILL-C=	CeCILL-C Free Software License Agreement
_LICENSE_GROUPS_CECILL-C= FSF

_LICENSE_NAME_CPL-1.0=	Common Public License 1.0
_LICENSE_GROUPS_CPL-1.0= FSF OSI

_LICENSE_NAME_CUA-OPL-1.0= CUA Office Public License v1.0
_LICENSE_GROUPS_CUA-OPL-1.0= OSI

_LICENSE_NAME_ECL-2.0=	Educational Community License v2.0
_LICENSE_GROUPS_ECL-2.0= FSF OSI

_LICENSE_NAME_Elastic-2.0= Elastic License 2.0
_LICENSE_GROUPS_Elastic-2.0= # empty

_LICENSE_NAME_EPL-1.0=	Eclipse Public License 1.0
_LICENSE_GROUPS_EPL-1.0= FSF OSI

_LICENSE_NAME_EPL-2.0=	Eclipse Public License 2.0
_LICENSE_GROUPS_EPL-2.0= FSF OSI

_LICENSE_NAME_EUPL-1.1=	European Union Public License 1.1
_LICENSE_GROUPS_EUPL-1.1= FSF OSI

_LICENSE_NAME_EUPL-1.2=	European Union Public License 1.2
_LICENSE_GROUPS_EUPL-1.2= FSF OSI

_LICENSE_NAME_LPL-1.02=	Lucent Public License v1.02
_LICENSE_GROUPS_LPL-1.02= FSF OSI

_LICENSE_NAME_OSET-PL-2.1= OSET Public License version 2.1
_LICENSE_GROUPS_OSET-PL-2.1= OSI

_LICENSE_NAME_OSL-2.1=	Open Software License 2.1
_LICENSE_GROUPS_OSL-2.1= FSF OSI

_LICENSE_NAME_SSPL-1.0=	Server Side Public License, v 1
_LICENSE_GROUPS_SSPL-1.0= # empty

_LICENSE_NAME_SUL-1.0=	Sustainable Use License v1.0
_LICENSE_GROUPS_SUL-1.0= # empty

_LICENSE_NAME_TGPPL-1.0= Transitive Grace Period Public Licence 1.0
_LICENSE_GROUPS_TGPPL-1.0= # empty

_LICENSE_NAME_TPL-1.0=	THOR Public License 1.0
_LICENSE_GROUPS_TPL-1.0= # empty

_LICENSE_NAME_BSL-1.0=	Boost Software License 1.0
_LICENSE_GROUPS_BSL-1.0= FSF OSI

_LICENSE_NAME_CDDL-1.0=	Common Development and Distribution License 1.0
_LICENSE_GROUPS_CDDL-1.0= FSF OSI

_LICENSE_NAME_ISC=	ISC License
_LICENSE_GROUPS_ISC=	FSF OSI

_LICENSE_NAME_ODbL-1.0=	Open Data Commons Open Database License v1.0
_LICENSE_GROUPS_ODbL-1.0= FSF

_LICENSE_NAME_OFL-1.0=	SIL Open Font License 1.0
_LICENSE_GROUPS_OFL-1.0= FSF

_LICENSE_NAME_OFL-1.1=	SIL Open Font License 1.1
_LICENSE_GROUPS_OFL-1.1= FSF OSI

_LICENSE_NAME_PSF-2.0=	Python Software Foundation License 2.0
_LICENSE_GROUPS_PSF-2.0= # empty

_LICENSE_NAME_Ruby=	Ruby License
_LICENSE_GROUPS_Ruby=	FSF

_LICENSE_NAME_Unlicense=	The Unlicense
_LICENSE_GROUPS_Unlicense= FSF OSI

_LICENSE_NAME_ZPL-2.1=	Zope Public License 2.1
_LICENSE_GROUPS_ZPL-2.1= FSF OSI

_LICENSE_NAME_Zlib=	zlib License
_LICENSE_GROUPS_Zlib=	FSF OSI

_LICENSE_NAME_any-OSI=	Any OSI License
_LICENSE_GROUPS_any-OSI= # empty

# --- Vendor/project-specific named licenses ---

_LICENSE_NAME_Adobe-Utopia= Adobe Utopia Font License
_LICENSE_GROUPS_Adobe-Utopia= # empty

_LICENSE_NAME_Aladdin=	Aladdin Free Public License
_LICENSE_GROUPS_Aladdin= # empty

_LICENSE_NAME_Artistic-dist= Artistic License 1.0 (dist)
_LICENSE_GROUPS_Artistic-dist= # empty

_LICENSE_NAME_bzip2-1.0.6= bzip2 and libbzip2 License v1.0.6
_LICENSE_GROUPS_bzip2-1.0.6= # empty

_LICENSE_NAME_CC-PDDC=	Creative Commons Public Domain Dedication and Certification
_LICENSE_GROUPS_CC-PDDC= # empty

_LICENSE_NAME_CFITSIO=	CFITSIO License
_LICENSE_GROUPS_CFITSIO= # empty

_LICENSE_NAME_checkmk=	Checkmk License
_LICENSE_GROUPS_checkmk= # empty

_LICENSE_NAME_CMU-Mach=	CMU Mach License
_LICENSE_GROUPS_CMU-Mach= # empty

_LICENSE_NAME_cryptsetup-OpenSSL-exception= cryptsetup OpenSSL exception  # SPDX exception, used as "<license> WITH ${this}"
_LICENSE_GROUPS_cryptsetup-OpenSSL-exception= # empty

_LICENSE_NAME_curl=	curl License
_LICENSE_GROUPS_curl=	OSI

_LICENSE_NAME_DocBook-XML= DocBook XML License
_LICENSE_GROUPS_DocBook-XML= # empty

_LICENSE_NAME_dtoa=	David M. Gay dtoa License
_LICENSE_GROUPS_dtoa=	# empty

_LICENSE_NAME_GD=	GD License
_LICENSE_GROUPS_GD=	# empty

_LICENSE_NAME_HDF5=	HDF5 License
_LICENSE_GROUPS_HDF5=	# empty

_LICENSE_NAME_Hippocratic-2.1= Hippocratic License 2.1
_LICENSE_GROUPS_Hippocratic-2.1= # empty

_LICENSE_NAME_ICU=	ICU License
_LICENSE_GROUPS_ICU=	OSI

_LICENSE_NAME_ImageMagick= ImageMagick License
_LICENSE_GROUPS_ImageMagick= # empty

_LICENSE_NAME_Independent-modules-exception= Independent Module Linking exception  # SPDX exception, used as "<license> WITH ${this}"
_LICENSE_GROUPS_Independent-modules-exception= # empty

_LICENSE_NAME_Info-ZIP=	Info-ZIP License
_LICENSE_GROUPS_Info-ZIP= # empty

_LICENSE_NAME_jove=	Jove License
_LICENSE_GROUPS_jove=	# empty

_LICENSE_NAME_JSON=	JSON License
_LICENSE_GROUPS_JSON=	# empty

_LICENSE_NAME_libpng-2.0= PNG Reference Library version 2
_LICENSE_GROUPS_libpng-2.0= # empty

_LICENSE_NAME_Linux-OpenIB= Linux Kernel Variant of OpenIB.org license
_LICENSE_GROUPS_Linux-OpenIB= # empty

_LICENSE_NAME_mplus=	mplus Font License
_LICENSE_GROUPS_mplus=	# empty

_LICENSE_NAME_Multics=	Multics License
_LICENSE_GROUPS_Multics=	# empty

_LICENSE_NAME_MVT-1.1=	MVT License 1.1
_LICENSE_GROUPS_MVT-1.1= # empty

_LICENSE_NAME_NCL=	NCL Source Code License
_LICENSE_GROUPS_NCL=	# empty

_LICENSE_NAME_NRL=	NRL License
_LICENSE_GROUPS_NRL=	# empty

_LICENSE_NAME_NTP=	NTP License
_LICENSE_GROUPS_NTP=	OSI

_LICENSE_NAME_OLDAP-1.4= Open LDAP Public License v1.4
_LICENSE_GROUPS_OLDAP-1.4= # empty

_LICENSE_NAME_OSSP=	OSSP License
_LICENSE_GROUPS_OSSP=	# empty

_LICENSE_NAME_Pixar=	Pixar License
_LICENSE_GROUPS_Pixar=	# empty

_LICENSE_NAME_pkgconf=	pkgconf License
_LICENSE_GROUPS_pkgconf= # empty

_LICENSE_NAME_Python-2.0.1= Python License 2.0.1
_LICENSE_GROUPS_Python-2.0.1= OSI

_LICENSE_NAME_python-ldap= Python ldap License
_LICENSE_GROUPS_python-ldap= # empty

_LICENSE_NAME_Sendmail=	Sendmail License
_LICENSE_GROUPS_Sendmail= # empty

_LICENSE_NAME_Sendmail-8.23=	Sendmail License 8.23
_LICENSE_GROUPS_Sendmail-8.23= # empty

_LICENSE_NAME_SHL-0.5=	Solderpad Hardware License v0.5
_LICENSE_GROUPS_SHL-0.5= # empty

_LICENSE_NAME_SHL-0.51=	Solderpad Hardware License, Version 0.51
_LICENSE_GROUPS_SHL-0.51= # empty

_LICENSE_NAME_Sleepycat= Sleepycat License
_LICENSE_GROUPS_Sleepycat= FSF OSI

_LICENSE_NAME_SMLNJ=	Standard ML of New Jersey License
_LICENSE_GROUPS_SMLNJ=	FSF

_LICENSE_NAME_Spencer-94= Spencer License 94
_LICENSE_GROUPS_Spencer-94= # empty

_LICENSE_NAME_SSLeay-standalone= SSLeay License - standalone
_LICENSE_GROUPS_SSLeay-standalone= # empty

_LICENSE_NAME_TCL=	TCL/TK License
_LICENSE_GROUPS_TCL=	# empty

_LICENSE_NAME_Unicode-3.0= Unicode License v3
_LICENSE_GROUPS_Unicode-3.0= OSI

_LICENSE_NAME_WordNet=	WordNet License
_LICENSE_GROUPS_WordNet= OSI

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

_LICENSE_NAME_BSD0CLAUSE=	BSD Zero Clause License
_LICENSE_GROUPS_BSD0CLAUSE=	OSI

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

_LICENSE_NAME_CC-BY-1.0=	Creative Commons Attribution 1.0
_LICENSE_GROUPS_CC-BY-1.0=	# empty

_LICENSE_NAME_CC-BY-2.0=	Creative Commons Attribution 2.0
_LICENSE_GROUPS_CC-BY-2.0=	# empty

_LICENSE_NAME_CC-BY-2.5=	Creative Commons Attribution 2.5
_LICENSE_GROUPS_CC-BY-2.5=	# empty

_LICENSE_NAME_CC-BY-3.0=	Creative Commons Attribution 3.0
_LICENSE_GROUPS_CC-BY-3.0=	# empty

_LICENSE_NAME_CC-BY-4.0=	Creative Commons Attribution 4.0
_LICENSE_GROUPS_CC-BY-4.0=	# empty

_LICENSE_NAME_CC-BY-ND-1.0=	Creative Commons Attribution No Derivatives 1.0
_LICENSE_GROUPS_CC-BY-ND-1.0=	# empty

_LICENSE_NAME_CC-BY-ND-2.0=	Creative Commons Attribution No Derivatives 2.0
_LICENSE_GROUPS_CC-BY-ND-2.0=	# empty

_LICENSE_NAME_CC-BY-ND-2.5=	Creative Commons Attribution No Derivatives 2.5
_LICENSE_GROUPS_CC-BY-ND-2.5=	# empty

_LICENSE_NAME_CC-BY-ND-3.0=	Creative Commons Attribution No Derivatives 3.0
_LICENSE_GROUPS_CC-BY-ND-3.0=	# empty

_LICENSE_NAME_CC-BY-ND-4.0=	Creative Commons Attribution No Derivatives 4.0
_LICENSE_GROUPS_CC-BY-ND-4.0=	# empty

_LICENSE_NAME_CC-BY-NC-1.0=	Creative Commons Attribution Non Commercial 1.0
_LICENSE_GROUPS_CC-BY-NC-1.0=	# empty
_LICENSE_PERMS_CC-BY-NC-1.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-2.0=	Creative Commons Attribution Non Commercial 2.0
_LICENSE_GROUPS_CC-BY-NC-2.0=	# empty
_LICENSE_PERMS_CC-BY-NC-2.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-2.5=	Creative Commons Attribution Non Commercial 2.5
_LICENSE_GROUPS_CC-BY-NC-2.5=	# empty
_LICENSE_PERMS_CC-BY-NC-2.5=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-3.0=	Creative Commons Attribution Non Commercial 3.0
_LICENSE_GROUPS_CC-BY-NC-3.0=	# empty
_LICENSE_PERMS_CC-BY-NC-3.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-4.0=	Creative Commons Attribution Non Commercial 4.0
_LICENSE_GROUPS_CC-BY-NC-4.0=	# empty
_LICENSE_PERMS_CC-BY-NC-4.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-ND-1.0=	Creative Commons Attribution Non Commercial No Derivatives 1.0
_LICENSE_GROUPS_CC-BY-NC-ND-1.0=	# empty
_LICENSE_PERMS_CC-BY-NC-ND-1.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-ND-2.0=	Creative Commons Attribution Non Commercial No Derivatives 2.0
_LICENSE_GROUPS_CC-BY-NC-ND-2.0=	# empty
_LICENSE_PERMS_CC-BY-NC-ND-2.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-ND-2.5=	Creative Commons Attribution Non Commercial No Derivatives 2.5
_LICENSE_GROUPS_CC-BY-NC-ND-2.5=	# empty
_LICENSE_PERMS_CC-BY-NC-ND-2.5=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-ND-3.0=	Creative Commons Attribution Non Commercial No Derivatives 3.0
_LICENSE_GROUPS_CC-BY-NC-ND-3.0=	# empty
_LICENSE_PERMS_CC-BY-NC-ND-3.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-ND-4.0=	Creative Commons Attribution Non Commercial No Derivatives 4.0
_LICENSE_GROUPS_CC-BY-NC-ND-4.0=	# empty
_LICENSE_PERMS_CC-BY-NC-ND-4.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-SA-1.0=	Creative Commons Attribution Non Commercial Share Alike 1.0
_LICENSE_GROUPS_CC-BY-NC-SA-1.0=	# empty
_LICENSE_PERMS_CC-BY-NC-SA-1.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-SA-2.0=	Creative Commons Attribution Non Commercial Share Alike 2.0
_LICENSE_GROUPS_CC-BY-NC-SA-2.0=	# empty
_LICENSE_PERMS_CC-BY-NC-SA-2.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-SA-2.5=	Creative Commons Attribution Non Commercial Share Alike 2.5
_LICENSE_GROUPS_CC-BY-NC-SA-2.5=	# empty
_LICENSE_PERMS_CC-BY-NC-SA-2.5=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-SA-3.0=	Creative Commons Attribution Non Commercial Share Alike 3.0
_LICENSE_GROUPS_CC-BY-NC-SA-3.0=	# empty
_LICENSE_PERMS_CC-BY-NC-SA-3.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-NC-SA-4.0=	Creative Commons Attribution Non Commercial Share Alike 4.0
_LICENSE_GROUPS_CC-BY-NC-SA-4.0=	# empty
_LICENSE_PERMS_CC-BY-NC-SA-4.0=	dist-mirror pkg-mirror auto-accept

_LICENSE_NAME_CC-BY-SA-1.0=	Creative Commons Attribution Share Alike 1.0
_LICENSE_GROUPS_CC-BY-SA-1.0=	# empty

_LICENSE_NAME_CC-BY-SA-2.0=	Creative Commons Attribution Share Alike 2.0
_LICENSE_GROUPS_CC-BY-SA-2.0=	# empty

_LICENSE_NAME_CC-BY-SA-2.5=	Creative Commons Attribution Share Alike 2.5
_LICENSE_GROUPS_CC-BY-SA-2.5=	# empty

_LICENSE_NAME_CC-BY-SA-3.0=	Creative Commons Attribution Share Alike 3.0
_LICENSE_GROUPS_CC-BY-SA-3.0=	# empty

_LICENSE_NAME_CC-BY-SA-4.0=	Creative Commons Attribution Share Alike 4.0
_LICENSE_GROUPS_CC-BY-SA-4.0=	# empty

_LICENSE_NAME_CDDL=	Common Development and Distribution License
_LICENSE_GROUPS_CDDL=	FSF OSI

_LICENSE_NAME_ClArtistic=	Clarified Artistic License
_LICENSE_GROUPS_ClArtistic=	FSF GPL OSI

_LICENSE_NAME_CPAL-1.0=		Common Public Attribution License
_LICENSE_GROUPS_CPAL-1.0=	FSF OSI

_LICENSE_NAME_EPL=	Eclipse Public License
_LICENSE_GROUPS_EPL=	FSF OSI

_LICENSE_NAME_EUPL11=	European Union Public Licence version 1.1
_LICENSE_GROUPS_EUPL11=	EU OSI

_LICENSE_NAME_EUPL12=	European Union Public Licence version 1.2
_LICENSE_GROUPS_EUPL12=	EU OSI

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

_LICENSE_NAME_MPL10=	Mozilla Public License version 1.0
_LICENSE_GROUPS_MPL10=	FSF OSI

_LICENSE_NAME_MPL11=	Mozilla Public License version 1.1
_LICENSE_GROUPS_MPL11=	FSF OSI

_LICENSE_NAME_MPL20=	Mozilla Public License version 2.0
_LICENSE_GROUPS_MPL20=	FSF OSI

_LICENSE_NAME_NCSA=	University of Illinois/NCSA Open Source License
_LICENSE_GROUPS_NCSA=	COPYFREE FSF GPL OSI

_LICENSE_NAME_ODbL=	Open Database License

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

_LICENSE_NAME_NONE=	No license specified
_LICENSE_GROUPS_NONE=	# empty
_LICENSE_PERMS_NONE=	none

_LICENSE_NAME_UNLICENSE=	The Unlicense
_LICENSE_GROUPS_UNLICENSE=	COPYFREE FSF GPL

_LICENSE_NAME_WTFPL1=	Do What the Fuck You Want To Public License version 1
_LICENSE_GROUPS_WTFPL1=	GPL FSF COPYFREE

_LICENSE_NAME_WTFPL=	Do What the Fuck You Want To Public License version 2
_LICENSE_GROUPS_WTFPL=	GPL FSF COPYFREE

_LICENSE_NAME_ZLIB=		zlib License
_LICENSE_GROUPS_ZLIB=	GPL FSF OSI

_LICENSE_NAME_ZPL21=	Zope Public License version 2.1
_LICENSE_GROUPS_ZPL21=	GPL OSI

# Set default permissions if not defined

.for lic in ${_LICENSE_LIST}
.  if !defined(_LICENSE_PERMS_${lic})
_LICENSE_PERMS_${lic}=	${_LICENSE_PERMS_DEFAULT}
.  endif
.endfor
