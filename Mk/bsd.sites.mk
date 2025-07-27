# bsd.sites.mk - Popular master sites.
#
# Sites_MAINTAINER=		ports@FreeBSD.org
#
# This file does not have any designated maintainer, so feel free to
# commit to it yourself.  However, it is generally a good idea to
# notify the principal maintainer in case you have a change to one of
# the software environments (KDE, GNOME, etc.).
#
# Also, this file is included from bsd.port.mk for all invocations, so
# committing a syntax error to this file is a cardinal sin, and will
# be punished accordingly.  DO NOT COMMIT SOMETHING YOU HAVEN'T TESTED.
# You have been warned. :)
#
# Note: because it is included for all invocations, please keep the size
# of this file manageable.  If a distfile is unfetchable from the first
# few dozen locations, it is unlikely to be fetchable from any past that,
# and those fetch failures will simply waste time and bandwidth.  Please
# pick a globally representative subset.
#
# Note: all entries should terminate with a slash.

# Where to put distfiles that don't have any other master site
.if !defined(IGNORE_MASTER_SITE_LOCAL)
MASTER_SITE_LOCAL+= \
	http://distcache.FreeBSD.org/local-distfiles/%SUBDIR%/ \
	http://distcache.us-east.FreeBSD.org/local-distfiles/%SUBDIR%/ \
	http://distcache.eu.FreeBSD.org/local-distfiles/%SUBDIR%/ \
	http://distcache.us-west.FreeBSD.org/local-distfiles/%SUBDIR%/

MASTER_SITE_PORTS_JP+= \
	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp4.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/ \
	ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/FreeBSD-jp/ports-jp/LOCAL_PORTS/%SUBDIR%/
.endif

##
##	KEEP THIS LIST SORTED
##

.if !defined(IGNORE_MASTER_SITE_AFTERSTEP)
MASTER_SITE_AFTERSTEP+= \
	ftp://ftp.afterstep.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE)
MASTER_SITE_APACHE+= \
	https://dlcdn.apache.org/%SUBDIR%/ \
	https://ftp.wayne.edu/apache/%SUBDIR%/ \
	https://mirror.its.dal.ca/apache/%SUBDIR%/ \
	http://mirror.cogentco.com/pub/apache/%SUBDIR%/ \
	http://mirror.navercorp.com/apache/%SUBDIR%/ \
	http://miroir.univ-lorraine.fr/apache/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_COMMONS_BINARIES)
MASTER_SITE_APACHE_COMMONS_BINARIES+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,commons/&/binaries,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_COMMONS_SOURCE)
MASTER_SITE_APACHE_COMMONS_SOURCE+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,commons/&/source,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_HTTPD)
MASTER_SITE_APACHE_HTTPD+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,httpd/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_JAKARTA)
MASTER_SITE_APACHE_JAKARTA+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,jakarta/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_TOMCAT)
MASTER_SITE_APACHE_TOMCAT+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,tomcat/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE_XML)
MASTER_SITE_APACHE_XML+= \
	${MASTER_SITE_APACHE:S,%SUBDIR%,xml/&,}
.endif

.if !defined(IGNORE_MASTER_SITE_BERLIOS)
MASTER_SITE_BERLIOS+= \
	${MASTER_SITE_SOURCEFORGE}
.endif

.if !defined(IGNORE_MASTER_SITE_COMP_SOURCES)
MASTER_SITE_COMP_SOURCES+= \
	http://ftp.isc.org/pub/usenet/comp.sources.%SUBDIR%/ \
	http://ftp.funet.fi/pub/archive/comp.sources.%SUBDIR%/ \
	http://ftp.fi.netbsd.org/pub/misc/archive/comp.sources.%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CRAN)
MASTER_SITE_CRAN+= \
	https://cloud.r-project.org/%SUBDIR%/ \
	https://stat.ethz.ch/CRAN/%SUBDIR%/ \
	http://cran.utstat.utoronto.ca/%SUBDIR%/ \
	https://cran.csiro.au/%SUBDIR%/ \
	https://mirrors.tuna.tsinghua.edu.cn/CRAN/%SUBDIR%/ \
	https://mirror.las.iastate.edu/CRAN/%SUBDIR%/ \
	https://cran.ma.imperial.ac.uk/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CRAN_ARCHIVE)
MASTER_SITE_CRAN_ARCHIVE+= ${MASTER_SITE_CRAN:S,$,Archive/${PORTNAME}/,}
.endif

.if !defined(IGNORE_MASTER_SITE_CRATESIO)
MASTER_SITE_CRATESIO+=	https://crates.io/api/v1/crates/%SUBDIR%/download?dummy=/
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN)
MASTER_SITE_DEBIAN+=	http://deb.debian.org/debian/%SUBDIR%/
.  for country in am au at by be br bg ca cl cn hr cz dk fi fr de hk hu is it \
		  jp kr lt md nl nc nz no pl pt ru sk si es se ch tw uk us
MASTER_SITE_DEBIAN+=	http://ftp.${country}.debian.org/debian/%SUBDIR%/
.  endfor
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_POOL)
MASTER_SITE_DEBIAN_POOL+= \
	${MASTER_SITE_DEBIAN:C|(/%SUBDIR%/)|/pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}/|}
.endif

.if !defined(IGNORE_MASTER_SITE_ECLIPSE)
MASTER_SITE_ECLIPSE+= \
	https://ftp-stud.hs-esslingen.de/pub/Mirrors/eclipse/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/download.eclipse.org/eclipseMirror/%SUBDIR%/
.endif

# List: https://www.exim.org/mirmon/ftp_mirrors.html
.if !defined(IGNORE_MASTER_SITE_EXIM)
MASTER_SITE_EXIM+= \
	https://exim.mirror.globo.tech/exim/%SUBDIR%/ \
	https://mirror.easyname.at/exim-ftp/exim/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.exim.org/pub/exim/%SUBDIR%/ \
	https://exim.mirror.iphh.net/ftp/exim/%SUBDIR%/ \
	http://ftp.carnet.hr/misc/exim/exim/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/exim/exim/%SUBDIR%/ \
	http://sunsite.icm.edu.pl/pub/unix/mail/exim/exim/%SUBDIR%/ \
	https://ftp.exim.org/pub/exim/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CENTOS_LINUX)
MASTER_SITE_CENTOS_LINUX+= \
	http://vault.centos.org/%SUBDIR%/:DEFAULT,aarch64,amd64,i386,SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_ROCKY_LINUX)
MASTER_SITE_ROCKY_LINUX+= \
	https://dl.rockylinux.org/pub/rocky/%SUBDIR%/:DEFAULT,aarch64,amd64,SOURCE \
	https://dl.rockylinux.org/vault/rocky/%SUBDIR%/:DEFAULT,aarch64,amd64,SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_EPEL7)
MASTER_SITE_EPEL7+= \
	https://archives.fedoraproject.org/pub/archive/epel/7/aarch64/Packages/%SUBDIR%/:DEFAULT,aarch64 \
	https://archives.fedoraproject.org/pub/archive/epel/7/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	https://archives.fedoraproject.org/pub/archive/epel/7/SRPMS/Packages/%SUBDIR%/:SOURCE \
	http://archives.fedoraproject.org/pub/archive/epel/7/aarch64/Packages/%SUBDIR%/:DEFAULT,aarch64 \
	http://archives.fedoraproject.org/pub/archive/epel/7/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	http://archives.fedoraproject.org/pub/archive/epel/7/SRPMS/Packages/%SUBDIR%/:SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_EPEL9)
MASTER_SITE_EPEL9+= \
	https://dl.fedoraproject.org/pub/epel/9/Everything/aarch64/Packages/%SUBDIR%/:DEFAULT,aarch64 \
	https://dl.fedoraproject.org/pub/epel/9/Everything/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	https://dl.fedoraproject.org/pub/epel/9/Everything/source/tree/Packages/%SUBDIR%/:SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_RPMFUSION9)
MASTER_SITE_RPMFUSION9+= \
	https://ftp.icm.edu.pl/pub/Linux/dist/rpmfusion/free/el/updates/9/aarch64/%SUBDIR%/:DEFAULT,aarch64 \
	https://ftp.icm.edu.pl/pub/Linux/dist/rpmfusion/free/el/updates/9/x86_64/%SUBDIR%/:DEFAULT,amd64 \
	https://ftp.icm.edu.pl/pub/Linux/dist/rpmfusion/free/el/updates/9/SRPMS/%SUBDIR%/:DEFAULT,SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_FARSIGHT)
MASTER_SITE_FARSIGHT+= \
	https://dl.farsightsecurity.com/dist/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FESTIVAL)
MASTER_SITE_FESTIVAL+= \
	http://www.festvox.org/packed/festival/%SUBDIR%/ \
	http://www.cstr.ed.ac.uk/downloads/festival/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FESTIVAL_OGI)
MASTER_SITE_FESTIVAL_OGI+= \
	http://www.cslu.ogi.edu/tts/download/data/
.endif

#
# FreeBSD mirror sites
#
# For the full list, see the Handbook:
#
#    https://docs.FreeBSD.org/en/books/handbook/mirrors/#mirrors-ftp
#
.if !defined(IGNORE_MASTER_SITE_FREEBSD_ORG)
MASTER_SITE_FREEBSD_ORG+= \
	https://download.FreeBSD.org/%SUBDIR%/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FRUGALWARE)
MASTER_SITE_FRUGALWARE+= \
	ftp://ftp7.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp6.frugalware.org/mirrors/linux/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp12.frugalware.org/mirrors/ftp.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GCC)
MASTER_SITE_GCC+= \
	https://mirrors.kernel.org/sourceware/gcc/%SUBDIR%/ \
	https://ftp-stud.hs-esslingen.de/pub/Mirrors/sourceware.org/gcc/%SUBDIR%/ \
	https://ftp.funet.fi/pub/mirrors/sourceware.org/pub/gcc/%SUBDIR%/ \
	https://ftp.mpi-inf.mpg.de/pub/gnu/mirror/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	https://mirrorservice.org/sites/sourceware.org/pub/gcc/%SUBDIR%/ \
	http://mirror.koddos.net/gcc/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/gnu/gcc/%SUBDIR%/ \
	http://gcc.gnu.org/pub/gcc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GENTOO)
MASTER_SITE_GENTOO+= \
	https://mirror.leaseweb.com/gentoo/%SUBDIR%/ \
	https://mirror.rackspace.com/gentoo/%SUBDIR%/ \
	https://mirror.init7.net/gentoo/%SUBDIR%/ \
	https://mirrors.rit.edu/gentoo/%SUBDIR%/ \
	http://ftp.iij.ad.jp/pub/linux/gentoo/%SUBDIR%/ \
	http://ftp.belnet.be/pub/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	http://ftp.uni-hannover.de/gentoo/%SUBDIR%/ \
	http://gentoo-mirror.flux.utah.edu/%SUBDIR%/
.endif

# Keep this before USE_GITHUB
.if !empty(MASTER_SITES:M*/github.com/*/archive/*)
DEV_WARNING+=	"MASTER_SITES contains ${MASTER_SITES:M*/github.com/*/archive/*}, please use USE_GITHUB instead."
.endif

.if !defined(IGNORE_MASTER_SITE_GITHUB)
#
# In order to use GitHub your port must define USE_GITHUB and the following
# variables:
#
# GH_ACCOUNT    - account name of the GitHub user hosting the project
#                 default: ${PORTNAME}
#
# GH_PROJECT    - name of the project on GitHub
#                 default: ${PORTNAME}
#
# GH_TAGNAME    - name of the tag to download (2.0.1, hash, ...)
#                 Using the name of a branch here is incorrect. It is
#                 possible to do GH_TAGNAME= GIT_HASH to do a snapshot.
#                 default: ${DISTVERSIONFULL}
#
# GH_SUBDIR     - directory relative to WRKSRC where to move this distfile's
#                 content after extracting.
#
# GH_TUPLE      - above shortened to account:project:tagname[:group][/subdir]
#
.  if defined(USE_GITHUB)
.    if defined(GH_TAGNAME) && ${GH_TAGNAME} == master
IGNORE?=	Using master as GH_TAGNAME is invalid. \
		Must use a tag or commit hash so the upstream does \
		not "reroll" as soon as the branch is updated
.    endif
.    if defined(GH_TUPLE)
.      for _tuple in ${GH_TUPLE}
_t_tmp=${_tuple}
.        if ${_t_tmp:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\4@:S/://:C/[a-zA-Z0-9_.+-]//g}
check-makevars::
	@${ECHO_MSG} "The ${_tuple} GH_TUPLE line has"
	@${ECHO_MSG} "a tag containing something else than [a-zA-Z0-9_.+-]"
	@${FALSE}
.        endif
.      endfor
GH_ACCOUNT+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\1\4@}
GH_PROJECT+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\2\4@}
GH_TAGNAME+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\3\4@}
GH_SUBDIR+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\6\4@:M/*:S/^\///}
.    endif
# We are cheating and using backend URLS for GitHub here. See ports/194898
# comment #15 for explanation as to why and how to deal with it if it breaks.
MASTER_SITE_GITHUB+=		https://codeload.github.com/%SUBDIR%
MASTER_SITE_GITHUB_CLOUD+=	https://cloud.github.com/downloads/%SUBDIR%

.    if ( !defined(MASTER_SITES) || !${MASTER_SITES:MGH} && !${MASTER_SITES:MGHC} ) && !${USE_GITHUB:Mnodefault}
MASTER_SITES+=	GH
.    endif
GH_ACCOUNT_DEFAULT=	${PORTNAME}
GH_ACCOUNT?=	${GH_ACCOUNT_DEFAULT}
GH_PROJECT_DEFAULT=	${PORTNAME}
GH_PROJECT?=	${GH_PROJECT_DEFAULT}
# Use full PREFIX/SUFFIX and converted DISTVERSION
GH_TAGNAME_DEFAULT=	${DISTVERSIONFULL}
GH_TAGNAME?=	${GH_TAGNAME_DEFAULT}
# Iterate over GH_ACCOUNT, GH_PROJECT, GH_TAGNAME and GH_SUBDIR to extract groups
_GITHUB_GROUPS= DEFAULT
.    for _gh_v in GH_ACCOUNT GH_PROJECT GH_TAGNAME GH_SUBDIR
.      for _v_ex in ${${_gh_v}}
_GH_GROUPS=	${_v_ex:S/^${_v_ex:C@:[^/:]+$@@}//:S/^://}
.        if !empty(_GH_GROUPS)
.          for _group in ${_GH_GROUPS:S/,/ /g}
.            if ${_group} == all || ${_group} == ALL || ${_group} == default
check-makevars::
		@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
		@${ECHO_MSG} "used in group definitions. Please fix your ${_gh_v}"
		@${FALSE}
.            endif
.            if !${_GITHUB_GROUPS:M${_group}}
_GITHUB_GROUPS+=	${_group}
.            endif
${_gh_v}_${_group}=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.          endfor
.        else
${_gh_v}_DEFAULT=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.        endif
.      endfor
.    endfor
# Put the default values back into the variables so that the *default* behavior
# is not changed.
GH_ACCOUNT:=	${GH_ACCOUNT_DEFAULT}
GH_PROJECT:=	${GH_PROJECT_DEFAULT}
GH_TAGNAME:=	${GH_TAGNAME_DEFAULT}
GH_SUBDIR:=	${GH_SUBDIR_DEFAULT}
.    if defined(GH_TAGNAME)
# If you change either of the _SANITIZED or _EXTRACT variables, please keep the
# changes in sync with the GH_TAGNAME_${_group}_* variables 50 lines below.
GH_TAGNAME_SANITIZED=	${GH_TAGNAME:S,/,-,g}
# GitHub silently converts tags starting with v to not have v in the filename
# and extraction directory.  It also replaces + with -.
GH_TAGNAME_EXTRACT=	${GH_TAGNAME_SANITIZED:C/^[vV]([0-9])/\1/:S/+/-/g:C/--*/-/g}
.    endif
# This new scheme rerolls distfiles. Also ensure they are renamed to avoid
# conflicts. Use _GITHUB_REV in case github changes their zipping or structure
# which has happened before.
_GITHUB_REV=	0
_GITHUB_EXTRACT_SUFX=	.tar.gz
# Put the DEFAULT distfile first
_GITHUB_CLONE_DIR?=	${WRKDIR}/git-clone
_PORTS_DIRECTORIES+=	${_GITHUB_CLONE_DIR}
.    if !${USE_GITHUB:Mnodefault} && empty(MASTER_SITES:MGHC)
# GH_TAGNAME defaults to DISTVERSIONFULL; Avoid adding DISTVERSIONFULL in twice
.      if ${GH_TAGNAME} != ${DISTVERSIONFULL}
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}-${GH_TAGNAME_SANITIZED}
.      else
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME_SANITIZED}
.      endif
DISTNAME_DEFAULT:=	${DISTNAME}_GH${_GITHUB_REV}
DISTFILE_DEFAULT=	${DISTNAME_DEFAULT}${_GITHUB_EXTRACT_SUFX}
DISTNAME:=	${DISTNAME_DEFAULT}
DISTFILES+=	${DISTFILE_DEFAULT}
git-clone: git-clone-DEFAULT
git-clone-DEFAULT: ${_GITHUB_CLONE_DIR}
	@git clone https://github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}.git ${_GITHUB_CLONE_DIR}/${GH_PROJECT_DEFAULT}
	@${ECHO_MSG} "Cloned the default github repository into ${_GITHUB_CLONE_DIR}/${GH_PROJECT_DEFAULT}" | ${FMT_80}
.    endif
.    if !empty(GH_SUBDIR)
_SITES_extract:=	690:post-extract-gh-DEFAULT
post-extract-gh-DEFAULT:
	@${RMDIR} ${WRKSRC}/${GH_SUBDIR_DEFAULT} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GH_SUBDIR_DEFAULT:H} 2>/dev/null || :
	@${LN} -s ${GH_SUBDIR_DEFAULT:C/[^\/]//g:C/\//..\//g:S/^$/./} ${WRKSRC}/${GH_SUBDIR_DEFAULT}
.    endif
# If there are non default groups
.    if !empty(_GITHUB_GROUPS:NDEFAULT)
# Then for each of the remaining groups, add DISTFILES and MASTER_SITES
# entries with the correct group and create {WRKSRC,DISTNAME,DISTFILES}_group
# helper variables.
.      for _group in ${_GITHUB_GROUPS:NDEFAULT}
GH_ACCOUNT_${_group}?=	${GH_ACCOUNT_DEFAULT}
GH_PROJECT_${_group}?=	${GH_PROJECT_DEFAULT}
GH_TAGNAME_${_group}?=	${GH_TAGNAME_DEFAULT}
# If you change either of the _SANITIZED or _EXTRACT variables, please keep the
# changes in sync with the GH_TAGNAME_* variables 50 lines above.
GH_TAGNAME_${_group}_SANITIZED=	${GH_TAGNAME_${_group}:S,/,-,g}
GH_TAGNAME_${_group}_EXTRACT=	${GH_TAGNAME_${_group}_SANITIZED:C/^[vV]([0-9])/\1/:S/+/-/g:C/--*/-/g}
_GH_TUPLE_OUT:=	${_GH_TUPLE_OUT} ${GH_ACCOUNT_${_group}}:${GH_PROJECT_${_group}}:${GH_TAGNAME_${_group}}:${_group}/${GH_SUBDIR_${_group}}
DISTNAME_${_group}:=	${GH_ACCOUNT_${_group}}-${GH_PROJECT_${_group}}-${GH_TAGNAME_${_group}_SANITIZED}
DISTFILE_${_group}:=	${DISTNAME_${_group}}_GH${_GITHUB_REV}${_GITHUB_EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DISTFILE_${_group}}:${_group}
MASTER_SITES:=	${MASTER_SITES} ${MASTER_SITE_GITHUB:S@%SUBDIR%@${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}/tar.gz/${GH_TAGNAME_${_group}}?dummy=/:${_group}@}
WRKSRC_${_group}:=	${WRKDIR}/${GH_PROJECT_${_group}}-${GH_TAGNAME_${_group}_EXTRACT}
.        if !empty(GH_SUBDIR_${_group})
# In order to sort the subdir extraction so that foo/bar is moved in before
# foo/bar/baz, we count the number of / in the path and use it to order the
# targets.  This handles up to 9 levels.  The max as of r463123 is 4.
_SITES_extract:=	${_SITES_extract} 69${GH_SUBDIR_${_group}:C=[^/]+= =g:[#]}:post-extract-gh-${_group}
post-extract-gh-${_group}:
	@${RMDIR} ${WRKSRC}/${GH_SUBDIR_${_group}} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GH_SUBDIR_${_group}:H} 2>/dev/null || :
	@${MV} ${WRKSRC_${_group}} ${WRKSRC}/${GH_SUBDIR_${_group}}
	@${LN} -s ${WRKSRC:T}/${GH_SUBDIR_${_group}} ${WRKSRC_${_group}}
.        endif
git-clone: git-clone-${_group}
git-clone-${_group}: ${_GITHUB_CLONE_DIR}
	@git clone https://github.com/${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}.git ${_GITHUB_CLONE_DIR}/${GH_PROJECT_${_group}}
	@${ECHO_MSG} "Cloned the ${_group} github repository into ${_GITHUB_CLONE_DIR}/${GH_PROJECT_${_group}}" | ${FMT_80}
.      endfor
.    endif
convert-to-gh-tuple:
	@${ECHO_MSG} ${GH_ACCOUNT}:${GH_PROJECT}:${GH_TAGNAME} ${_GH_TUPLE_OUT:S/\/$//}
WWW?=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/
.  endif # defined(USE_GITHUB)
.endif # !defined(IGNORE_MASTER_SITE_GITHUB)

# Keep this before USE_GITLAB
# first try to detect when fetch was called by makesum, which passes
# MASTER_SITES and would cause a bogus warning here.
.if !(make(fetch) && !empty(NO_CHECKSUM) && !empty(DISABLE_SIZE))
.  if !empty(MASTER_SITES:M*//*/*/*/-/archive/${DISTVERSIONFULL}/)
DEV_WARNING+=	"MASTER_SITES contains ${MASTER_SITES:M*//*/*/*/-/archive/${DISTVERSIONFULL}/}, please use USE_GITLAB instead."
.  endif
.endif

.if !defined(IGNORE_MASTER_SITE_GITLAB)
#
# In order to use GitLab your port must define USE_GITLAB and the following
# variables:
#
# GL_SITE       - site URL hosting GitLab and the project
#                 default: https://gitlab.com
#
# GL_ACCOUNT    - account name of the GitLab user hosting the project
#                 default: ${PORTNAME}
#
# GL_PROJECT    - name of the project on GitLab
#                 default: ${PORTNAME}
#
# GL_TAGNAME    - name of the tag to download (2.0.1, hash, ...)
#                 Using the name of a branch here is incorrect. It is
#                 possible to do GL_TAGNAME= GIT_HASH to do a snapshot.
#                 default: ${DISTVERSIONFULL}
#
# GL_SUBDIR     - directory relative to WRKSRC where to move this distfile's
#                 content after extracting.
#
# GL_TUPLE      - above shortened to [site[:port][/webroot]:]account:project:tagname:group[/subdir]
#
.  if defined(USE_GITLAB)
.    if !defined(GL_TAGNAME) && defined(GL_COMMIT)
GL_TAGNAME=	${GL_COMMIT}
DEV_WARNING+=	"GL_COMMIT is deprecated, please use GL_TAGNAME instead"
.    endif
.    if defined(GL_TUPLE)
.      for _tuple in ${GL_TUPLE}
.        if ${_tuple:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\7@:S/^://:C/[a-zA-Z0-9_.+-]//g}
check-makevars::
	@${ECHO_MSG} "The ${_tuple}"
	@${ECHO_MSG} "GL_TUPLE is improperly formatted or, the tagname"
	@${ECHO_MSG} "section contains something other than [a-zA-Z0-9_.+-]"
	@${FALSE}
.        endif
.      endfor
GL_SITE+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\1\8@:S@::@:@}
GL_ACCOUNT+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\5\8@}
GL_PROJECT+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\6\8@}
GL_TAGNAME+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\7\8@}
GL_SUBDIR+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\9\8@:M/*:S/^\///}
.    endif

.    if empty(USE_GITLAB:Mnodefault)
MASTER_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/archive/${GL_TAGNAME:C@^[a-f0-9]{40}$@\0.tar.gz?dummy=@}/
.    endif
GL_SITE_DEFAULT=	https://gitlab.com
GL_SITE?=	${GL_SITE_DEFAULT}
GL_ACCOUNT_DEFAULT=	${PORTNAME}
GL_ACCOUNT?=	${GL_ACCOUNT_DEFAULT}
GL_PROJECT_DEFAULT=	${PORTNAME}
GL_PROJECT?=	${GL_PROJECT_DEFAULT}
GL_TAGNAME_DEFAULT=	${DISTVERSIONFULL}
GL_TAGNAME?=	${GL_TAGNAME_DEFAULT}
_GITLAB_GROUPS=	DEFAULT
.    for _gl_v in GL_SITE GL_ACCOUNT GL_PROJECT GL_TAGNAME GL_SUBDIR
.      for _v_ex in ${${_gl_v}}
_GL_GROUPS=	${_v_ex:S/^${_v_ex:C@:[^/:]+$@@}//:S/^://}
.        if !empty(_GL_GROUPS)
.          for _group in ${_GL_GROUPS:S/,/ /g}
.            if ${_group} == all || ${_group} == ALL || ${_group} == default
check-makevars::
		@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
		@${ECHO_MSG} "used in group definitions. Please fix your ${_gl_v}"
		@${FALSE}
.            endif
.            if !${_GITLAB_GROUPS:M${_group}}
_GITLAB_GROUPS+=	${_group}
.            endif
${_gl_v}_${_group}=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.          endfor
.        else
${_gl_v}_DEFAULT=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.        endif
.      endfor
.    endfor
GL_SITE:=	${GL_SITE_DEFAULT}
GL_ACCOUNT:=	${GL_ACCOUNT_DEFAULT}
GL_PROJECT:=	${GL_PROJECT_DEFAULT}
GL_TAGNAME:=	${GL_TAGNAME_DEFAULT}
GL_SUBDIR:=	${GL_SUBDIR_DEFAULT}

_GITLAB_REV=	0

_GITLAB_EXTRACT_SUFX=		.tar.gz
_GITLAB_TAG_EXTRACT_SUFX=	.tar.bz2

_GITLAB_CLONE_DIR?=	${WRKDIR}/git-clone
_PORTS_DIRECTORIES+=	${_GITLAB_CLONE_DIR}
.    if !${USE_GITLAB:Mnodefault}
.      if ${GL_TAGNAME:C/^[a-f0-9]{40}$//}
DISTNAME:=	${GL_PROJECT}-${GL_TAGNAME}
DISTFILES+=	${DISTNAME}${_GITLAB_TAG_EXTRACT_SUFX}
.      else
DISTNAME:=	${GL_ACCOUNT}-${GL_PROJECT}-${GL_TAGNAME}_GL${_GITLAB_REV}
DISTFILES+=	${DISTNAME}${_GITLAB_EXTRACT_SUFX}
.      endif
git-clone: git-clone-DEFAULT
git-clone-DEFAULT: ${_GITLAB_CLONE_DIR}
	@git clone ${GL_SITE_DEFAULT}/${GL_ACCOUNT_DEFAULT}/${GL_PROJECT_DEFAULT}.git ${_GITLAB_CLONE_DIR}/${GL_PROJECT_DEFAULT}
	@${ECHO_MSG} "Cloned the default GitLab repository into ${_GITLAB_CLONE_DIR}/${GL_PROJECT_DEFAULT}" | ${FMT_80}
.    endif
.    if !empty(GL_SUBDIR)
_SITES_extract:=	69${GL_SUBDIR_${_group}:C=[^/]+= =g:[#]}:post-extract-gl-DEFAULT
post-extract-gl-DEFAULT:
	@${RMDIR} ${WRKSRC}/${GL_SUBDIR_DEFAULT} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GL_SUBDIR_DEFAULT:H} 2>/dev/null || :
	@${LN} -s ${GL_SUBDIR_DEFAULT:C/[^\/]//g:C/\//..\//g:S/^$/./} ${WRKSRC}/${GL_SUBDIR_DEFAULT}
.    endif
.    if !empty(_GITLAB_GROUPS:NDEFAULT)
.      for _group in ${_GITLAB_GROUPS:NDEFAULT}
# We set GL_SITE earlier, we need to verify it's not empty
.        if empty(GL_SITE_${_group})
GL_SITE_${_group}=	${GL_SITE_DEFAULT}
.        endif
GL_ACCOUNT_${_group}?=	${GL_ACCOUNT_DEFAULT}
GL_PROJECT_${_group}?=	${GL_PROJECT_DEFAULT}

_GL_TUPLE_OUT:=	${_GL_TUPLE_OUT} ${GL_SITE_${_group}}:${GL_ACCOUNT_${_group}}:${GL_PROJECT_${_group}}:${GL_TAGNAME_${_group}}:${_group}/${GL_SUBDIR_${_group}}
.        if ${GL_TAGNAME_${_group}:C/^[a-f0-9]{40}$//}
DISTNAME_${_group}:=	${GL_PROJECT_${_group}}-${GL_TAGNAME_${_group}}
DISTFILE_${_group}:=	${DISTNAME_${_group}}${_GITLAB_TAG_EXTRACT_SUFX}
MASTER_SITES:=	${MASTER_SITES} ${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}/-/archive/${GL_TAGNAME_${_group}}/:${_group}
.        else
DISTNAME_${_group}:=	${GL_ACCOUNT_${_group}}-${GL_PROJECT_${_group}}-${GL_TAGNAME_${_group}}_GL${_GITLAB_REV}
DISTFILE_${_group}:=	${DISTNAME_${_group}}${_GITLAB_EXTRACT_SUFX}
MASTER_SITES:=	${MASTER_SITES} ${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}/-/archive/${GL_TAGNAME_${_group}}.tar.gz?dummy=/:${_group}
.        endif
DISTFILES:=	${DISTFILES} ${DISTFILE_${_group}}:${_group}
WRKSRC_${_group}:=	${WRKDIR}/${GL_PROJECT_${_group}}-${GL_TAGNAME_${_group}}
.        if !empty(GL_SUBDIR_${_group})
_SITES_extract:=	${_SITES_extract} 690:post-extract-gl-${_group}
post-extract-gl-${_group}:
	@${RMDIR} ${WRKSRC}/${GL_SUBDIR_${_group}} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GL_SUBDIR_${_group}:H} 2>/dev/null || :
	@${MV} ${WRKSRC_${_group}} ${WRKSRC}/${GL_SUBDIR_${_group}}
	@${LN} -s ${WRKSRC:T}/${GL_SUBDIR_${_group}} ${WRKSRC_${_group}}
.        endif
git-clone: git-clone-${_group}
git-clone-${_group}: ${_GITLAB_CLONE_DIR}
	@git clone ${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}.git ${_GITLAB_CLONE_DIR}/${GL_PROJECT_${_group}}
	@${ECHO_MSG} "Cloned the ${_group} GitLab repository into ${_GITLAB_CLONE_DIR}/${GL_PROJECT_${_group}}" | ${FMT_80}
.      endfor
.    endif
WWW?=	https://gitlab.com/${GL_ACCOUNT}/${GL_PROJECT}/
.  endif # defined(USE_GITLAB)
.endif # !defined(IGNORE_MASTER_SITE_GITLAB)

.if !defined(IGNORE_MASTER_SITE_GNOME)
.  if defined(DISTVERSION) && ${DISTVERSION:M[0-9]*}
_version_major=	${DISTVERSION:C|^([0-9]+).*|\1|}
_version_minor=	${DISTVERSION:C|^([0-9]+)\.([0-9]+).*|\2|}

.    if ${_version_major} >= 10
_gnome_ver=	${_version_major}
.    else
_gnome_ver=	${_version_major}.${_version_minor}
.    endif
.  endif

_GNOME_PATH=	%SUBDIR%/${_gnome_ver}

MASTER_SITE_GNOME+= \
	https://download.gnome.org/${_GNOME_PATH}/
.endif

.if !defined(IGNORE_MASTER_SITE_GIMP)
MASTER_SITE_GIMP+= \
	https://ftp.gwdg.de/pub/misc/grafik/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
	https://download.gimp.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU)
MASTER_SITE_GNU+= \
	https://ftpmirror.gnu.org/%SUBDIR%/ \
	https://mirrors.kernel.org/gnu/%SUBDIR%/ \
	https://mirror.netcologne.de/gnu/%SUBDIR%/ \
	https://www.nic.funet.fi/pub/gnu/gnu/%SUBDIR%/ \
	http://mirror.navercorp.com/gnu/%SUBDIR%/ \
	http://ftp.halifax.rwth-aachen.de/gnu/%SUBDIR%/ \
	ftp://mirrors.rit.edu/gnu/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/gnu/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	https://ftp.gnu.org/gnu/%SUBDIR%/
.endif

# List: https://gnupg.org/download/mirrors.html (contains stale information)
.if !defined(IGNORE_MASTER_SITE_GNUPG)
MASTER_SITE_GNUPG+= \
	https://mirrors.dotsrc.org/gcrypt/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	http://www.ring.gr.jp/pub/net/gnupg/%SUBDIR%/ \
	https://gnupg.org/ftp/gcrypt/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUSTEP)
MASTER_SITE_GNUSTEP+= \
	ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/ \
	http://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU_ALPHA)
MASTER_SITE_GNU_ALPHA+= \
	https://alpha.gnu.org/gnu/%SUBDIR%/ \
	ftp://spinellicreations.com/alpha/gnu/%SUBDIR%/ \
	http://www.nic.funet.fi/pub/gnu/alpha/gnu/%SUBDIR%/ \
	http://mirror.thecodefactory.org/gnualpha/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/alpha.gnu.org/gnu/%SUBDIR%/ \
	http://gnu.c3sl.ufpr.br/alpha/%SUBDIR%/ \
	https://mirror.cedia.org.ec/gnualpha/%SUBDIR%/ \
	http://gnu-alpha.mirrors.hostinginnederland.nl/%SUBDIR%/ \
	https://gnualpha.uib.no/%SUBDIR%/ \
	https://mirrors.fe.up.pt/pub/gnu-alpha/%SUBDIR%/ \
	http://mirror.lihnidos.org/GNU/alpha/gnu/%SUBDIR%/ \
	https://alpha-gnu-org.ip-connect.vn.ua/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_HACKAGE)
MASTER_SITE_HACKAGE+= \
	https://hackage.haskell.org/package/ \
	http://hackage.haskell.org/package/
.endif

.if !defined(IGNORE_MASTER_SITE_IDSOFTWARE)
MASTER_SITE_IDSOFTWARE+= \
	https://ftp.gwdg.de/pub/misc/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	https://ftp.fu-berlin.de/pc/games/idgames/idstuff/%SUBDIR%/ \
	https://ftp.gamers.org/pub/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.omen.net.au/games/idstuff/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ISC)
MASTER_SITE_ISC+= \
	https://ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ciril.fr/pub/isc/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.iij.ad.jp/pub/network/isc/%SUBDIR%/ \
	ftp://ftp.u-aizu.ac.jp/pub/net/isc/%SUBDIR%/ \
	ftp://ftp.task.gda.pl/mirror/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.nominum.com/pub/isc/%SUBDIR%/ \
	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KDE)
MASTER_SITE_KDE+= \
	https://download.kde.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_LIBREOFFICE_DEV)
MASTER_SITE_LIBREOFFICE_DEV+= \
	https://dev-www.libreoffice.org/src/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MATE)
MASTER_SITE_MATE+= \
	https://pub.mate-desktop.org/releases/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZDEV)
MASTER_SITE_MOZDEV+= \
	http://mirrors.ibiblio.org/mozdev.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA)
MASTER_SITE_MOZILLA+= \
	https://download.cdn.mozilla.net/pub/%SUBDIR%/ \
	https://archive.mozilla.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA_ADDONS)
MASTER_SITE_MOZILLA_ADDONS+= \
	http://kyoto-mz-dl.sinet.ad.jp/pub/mozilla.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MYSQL)
MASTER_SITE_MYSQL+= \
	https://dev.mysql.com/get/Downloads/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NETBSD)
MASTER_SITE_NETBSD+= \
	https://ftp.netbsd.org/pub/pkgsrc/distfiles/%SUBDIR%/ \
	http://ftp.fr.netbsd.org/pub/pkgsrc/%SUBDIR%/ \
	ftp://ftp2.fr.netbsd.org/pub/pkgsrc/%SUBDIR%/ \
	ftp://ftp3.de.netbsd.org/pub/pkgsrc/%SUBDIR%/ \
	ftp://ftp2.jp.netbsd.org/pub/pkgsrc/%SUBDIR%/ \
	ftp://ftp7.jp.netbsd.org/pub/pkgsrc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NETLIB)
MASTER_SITE_NETLIB+= \
	http://www.netlib.org/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/netlib/%SUBDIR%/ \
	http://netlib.sandia.gov/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NVIDIA)
MASTER_SITE_NVIDIA+= \
	https://jp.download.nvidia.com/%SUBDIR%/ \
	http://us.download.nvidia.com/%SUBDIR%/ \
	https://tw.download.nvidia.com/%SUBDIR%/ \
	http://download.nvidia.com/%SUBDIR%/ \
	https://http.download.nvidia.com/%SUBDIR%/ \
	ftp://download.nvidia.com/%SUBDIR%/ \
	ftp://download1.nvidia.com/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OPENBSD)
MASTER_SITE_OPENBSD+= \
	https://cdn.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://cloudflare.cdn.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://ftp.OpenBSD.org/pub/OpenBSD/%SUBDIR%/ \
	https://ftp.eu.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://ftp.usa.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://mirror.leaseweb.com/pub/OpenBSD/%SUBDIR%/ \
	https://mirror.aarnet.edu.au/pub/OpenBSD/%SUBDIR%/
.endif

# Reference: https://osdn.net/docs/FileRelease_Guide#h2-Release.20File.20URL.20Formats
.if !defined(IGNORE_MASTER_SITE_OSDN)
MASTER_SITE_OSDN+= \
	https://osdn.net/dl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OSDN_CHAMBER)
MASTER_SITE_OSDN_CHAMBER+= \
	https://osdn.net/downloads/users/%SUBDIR%/
.endif

# From https://osdn.net/docs/FileRelease_Guide#h2-Direct.20Download
#   "Currently, when a release-file URL is accessed from wget, curl,
#   libwww-perl, PowerShell, apt, dnf, or other package management
#   tools, downloading of the file will begin right away without
#   having to go via html page."
# Unfortunately fetch(1) isn't included in such user agents. Therefore
# add --user-agent option to FETCH_ARGS so access is considered as
# that of ftp/curl.
.if !empty(MASTER_SITES:M*OSDN*) || !empty(PATCH_SITES:M*OSDN*)
FETCH_ARGS+=	--user-agent=curl/7.68.0
.endif

.if !defined(IGNORE_MASTER_SITE_OSSP)
MASTER_SITE_OSSP+= \
	http://ftp.ntua.gr/pub/utils/ossp/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/utils/ossp/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PACKETSTORM)
MASTER_SITE_PACKETSTORM+= \
	https://dl.packetstormsecurity.net/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PERL_CPAN)

_PERL_CPAN_SORT?= modules/by-module

# Please add URI to MASTER_SITE_PERL_CPAN_BY instead of this one.
MASTER_SITE_PERL_CPAN?=

MASTER_SITE_PERL_CPAN_BY+= \
	https://cpan.metacpan.org/%CPANSORT%/%SUBDIR%/ \
	https://cpan.metacpan.org/modules/by-module/%SUBDIRPLUS%/ \
	https://www.cpan.org/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/cpan.perl.org/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://backpan.perl.org/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/Lang/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIRPLUS%/

_PERL_CPAN_FLAG=${MASTER_SITE_SUBDIR:C/(CPAN):.*$/\1/}
_PERL_CPAN_ID=	${MASTER_SITE_SUBDIR:C/^CPAN:(.)(.)(.*)$/\1\/\1\2\/\1\2\3/}

.  if !empty(_PERL_CPAN_ID) && ${_PERL_CPAN_FLAG:tl} == "cpan"
    _PERL_CPAN_SORT=authors/id/${_PERL_CPAN_ID}
    MASTER_SITE_PERL_CPAN=${MASTER_SITE_PERL_CPAN_BY:S/%CPANSORT%/${_PERL_CPAN_SORT}/:S/%SUBDIR%\///:S/%SUBDIRPLUS%\//${PORTNAME:C/-.*//}\//}
.  else
    MASTER_SITE_PERL_CPAN=${MASTER_SITE_PERL_CPAN_BY:S/%CPANSORT%/${_PERL_CPAN_SORT}/:S/%SUBDIRPLUS%\///}
.  endif

.endif

#
# PostgreSQL master site
#
.if !defined(IGNORE_MASTER_SITE_PGSQL)
MASTER_SITE_PGSQL+= \
	https://ftp.postgresql.org/pub/%SUBDIR%/
.endif

# Currently MyraCloud is blocking fetch. Hence add php Github distributions
# untill it is fixed.
.if !defined(IGNORE_MASTER_SITE_PHP)
MASTER_SITE_PHP+= \
	https://www.php.net/distributions/ \
	https://raw.githubusercontent.com/php/web-php-distributions/master/
.endif

.if !defined(IGNORE_MASTER_SITE_PYPI)
MASTER_SITE_PYPI+= \
	https://files.pythonhosted.org/packages/%SUBDIR%/ \
	https://pypi.org/packages/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PYTHON)
MASTER_SITE_PYTHON+= \
	https://www.python.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QMAIL)
MASTER_SITE_QMAIL+= \
	http://qmail.glasswings.com.au/%SUBDIR%/ \
	http://qmail.psshee.com/%SUBDIR%/ \
	http://www.agria.hu/qmail/%SUBDIR%/ \
	http://qmail.omnis.ch/%SUBDIR%/ \
	http://www.qmail.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QT)
MASTER_SITE_QT+= \
	https://download.qt.io/%SUBDIR%/ \
	http://master.qt.io/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/download.qt-project.org/%SUBDIR%/ \
	http://www.nic.funet.fi/pub/mirrors/download.qt-project.org/%SUBDIR%/ \
	https://ftp.jaist.ac.jp/pub/qtproject/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_RUBY)
MASTER_SITE_RUBY+= \
	https://cache.ruby-lang.org/pub/ruby/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/unix/languages/ruby/%SUBDIR%/ \
	ftp://ftp.kr.FreeBSD.org/pub/ruby/%SUBDIR%/ \
	ftp://ftp.iDaemons.org/pub/mirror/ftp.ruby-lang.org/ruby/%SUBDIR%/
.endif

# See http://rubygems.org/pages/about
.if !defined(IGNORE_MASTER_SITE_RUBYGEMS)
MASTER_SITE_RUBYGEMS+= \
	https://rubygems.org/downloads/
.endif

.if !defined(IGNORE_MASTER_SITE_SAMBA)
MASTER_SITE_SAMBA+= \
	https://ftp.samba.org/pub/%SUBDIR%/
.endif

# List:	https://download-mirror.savannah.gnu.org/releases/00_MIRRORS.html
.if !defined(IGNORE_MASTER_SITE_SAVANNAH)
MASTER_SITE_SAVANNAH+= \
	https://download.savannah.gnu.org/releases/%SUBDIR%/ \
	https://nongnu.uib.no/%SUBDIR%/ \
	https://mirror.kumi.systems/nongnu/%SUBDIR%/ \
	https://mirrors.up.pt/pub/nongnu/%SUBDIR%/ \
	http://nongnu.askapache.com/%SUBDIR%/ \
	http://mirror.netcologne.de/savannah/%SUBDIR%/ \
	http://mirror.csclub.uwaterloo.ca/nongnu/%SUBDIR%/ \
	http://mirror.easyname.at/nongnu/%SUBDIR%/ \
	https://download-mirror.savannah.gnu.org/releases/%SUBDIR%/
.endif

# List:		https://sourceforge.net/p/forge/documentation/Mirrors/
# Updated:	2022-11-26
.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE)
.  for p in https http
MASTER_SITE_SOURCEFORGE+= ${p}://downloads.sourceforge.net/project/%SUBDIR%/
.    for m in cfhcable cytranet deac-ams deac-fra deac-riga excellmedia \
	freefr gigenet ixpeering jaist kumisystems liquidtelecom \
	nchc netactuate netcologne onboardcloud phoenixnap \
	razaoinfo sinalbr sitsa tenet ufpr versaweb
MASTER_SITE_SOURCEFORGE+= ${p}://${m}.dl.sourceforge.net/project/%SUBDIR%/
.    endfor
.  endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEWARE)
MASTER_SITE_SOURCEWARE+= \
	https://mirrors.kernel.org/sourceware/%SUBDIR%/ \
	https://ftp-stud.hs-esslingen.de/pub/Mirrors/sourceware.org/%SUBDIR%/ \
	https://ftp.funet.fi/pub/mirrors/sourceware.org/pub/%SUBDIR%/ \
	https://mirrorservice.org/sites/sourceware.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUDO)
MASTER_SITE_SUDO+= \
	https://www.sudo.ws/sudo/dist/ \
	http://ftp.arcane-networks.fr/pub/mirrors/sudo/ \
	http://sudo.p8ra.de/sudo/dist/ \
	http://sudo.cybermirror.org/ \
	http://sudo-ftp.basemirror.de/ \
	http://ftp.twaren.net/Unix/Security/Sudo/ \
	ftp://ftp.sudo.ws/pub/sudo/ \
	ftp://plier.ucar.edu/pub/sudo/ \
	ftp://obsd.isc.org/pub/sudo/ \
	ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
	ftp://ftp.tuwien.ac.at/utils/admin-tools/sudo/ \
	ftp://sunsite.ualberta.ca/pub/Mirror/sudo/ \
	ftp://zoot.tele.dk/pub/sudo/ \
	ftp://ftp.in2p3.fr/pub/sudo/ \
	ftp://ftp.arcane-networks.fr/pub/mirrors/sudo/ \
	ftp://ftp.usbm.de/pub/sudo/ \
	ftp://ftp.cs.tu-berlin.de/pub/misc/sudo/ \
	ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/sudo/ \
	ftp://ftp.st.ryukoku.ac.jp/pub/security/tool/sudo/ \
	ftp://ftp.cin.nihon-u.ac.jp/pub/misc/sudo/ \
	ftp://sunsite.icm.edu.pl/packages/sudo/ \
	ftp://mirror.cdmon.com/pub/sudo/ \
	ftp://ftp.twaren.net/Unix/Security/Sudo/
.endif

.if !defined(IGNORE_MASTER_SITE_SUNSITE)
MASTER_SITE_SUNSITE+= \
	https://www.ibiblio.org/pub/Linux/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/%SUBDIR%/ \
	ftp://ftp.sun.ac.za/pub/mirrors/sunsite.unc.edu/pub/Linux/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TCLTK)
MASTER_SITE_TCLTK+= \
	ftp://ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TEX)
MASTER_SITE_TEX+= \
	https://mirror.ctan.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TEX_CTAN)
MASTER_SITE_TEX_CTAN+= \
	https://ftp.tu-chemnitz.de/pub/tug/historic/%SUBDIR%/ \
	https://pi.kwarc.info/historic/%SUBDIR%/ \
	https://mirrors.tuna.tsinghua.edu.cn/tex-historic-archive/%SUBDIR%/ \
	https://mirror.nju.edu.cn/tex-historic/%SUBDIR%/ \
	https://ftp.math.utah.edu/pub/tex/historic/%SUBDIR%/
.endif

# Derived from: https://www.torproject.org/getinvolved/mirrors.html.en
# Please do not blindly follow and add URLs from the above list
.if !defined(IGNORE_MASTER_SITE_TOR)
MASTER_SITE_TOR+= \
		https://dist.torproject.org/%SUBDIR%/ \
		https://archive.torproject.org/tor-package-archive/%SUBDIR%/ \
		ftp://ftp.bit.nl/mirror/tor/%SUBDIR%/ \
		https://cyberside.net.ee/sibul/dist/%SUBDIR%/ \
		https://ftp.bit.nl/mirror/tor/%SUBDIR%/ \
		http://mirror.hessmo.com/tor/dist/%SUBDIR%/ \
		http://mirror.host4site.co.il/torproject.org/dist/%SUBDIR%/ \
		http://mirror.open-networx.org/torproject.org/dist/%SUBDIR%/ \
		http://mirror.tor.hu/dist/%SUBDIR%/ \
		http://mirrors.chaos-darmstadt.de/tor-mirror/dist/%SUBDIR%/ \
		http://theonionrouter.com/dist/%SUBDIR%/ \
		http://tor.amorphis.eu/dist/%SUBDIR%/ \
		http://tor.askapache.com/dist/%SUBDIR%/ \
		http://tor.beme-it.de/dist/%SUBDIR%/ \
		http://tor.borgmann.tv/dist/%SUBDIR%/ \
		http://tor.cyberarmy.at/dist/%SUBDIR%/ \
		http://tor.dont-know-me.at/dist/%SUBDIR%/ \
		http://tor.factor.cc/dist/%SUBDIR%/ \
		http://tor.idnr.ws/dist/%SUBDIR%/ \
		http://tor.kamagurka.org/dist/%SUBDIR%/ \
		http://tor.spline.de/dist/%SUBDIR%/ \
		http://tor.vesta.nu/dist/%SUBDIR%/ \
		http://torproj.xpdm.us/dist/%SUBDIR%/ \
		http://torproject.nwlinux.us/dist/%SUBDIR%/ \
		https://torproject.ph3x.at/dist/%SUBDIR%/ \
		http://www.oignon.net/dist/%SUBDIR%/ \
		http://www.torproject.org.nyud.net/dist/%SUBDIR%/ \
		http://www.torproject.us/dist/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_WINDOWMAKER)
MASTER_SITE_WINDOWMAKER+= \
	ftp://ftp.windowmaker.info/pub/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/X11/window-managers/windowmaker/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XCONTRIB)
MASTER_SITE_XCONTRIB+= \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_XFCE)
_XFCE_PATH=	${DISTNAME:S/-${DISTVERSIONFULL}//:tl}/${DISTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MASTER_SITE_XFCE+= \
	https://archive.xfce.org/src/%SUBDIR%/${_XFCE_PATH}/ \
	https://mirror.netcologne.de/xfce/src/%SUBDIR%/${_XFCE_PATH}/ \
	https://ftp.cixug.es/xfce/src/%SUBDIR%/${_XFCE_PATH}/ \
	https://archive.be.xfce.org/src/%SUBDIR%/${_XFCE_PATH}/ \
	https://archive.al-us.xfce.org/src/%SUBDIR%/${_XFCE_PATH}/
.endif

.if !defined(IGNORE_MASTER_SITE_XORG)
MASTER_SITE_XORG+= \
	https://xorg.freedesktop.org/releases/%SUBDIR%/ \
	https://mirror.csclub.uwaterloo.ca/x.org/%SUBDIR%/ \
	https://artfiles.org/x.org/pub/%SUBDIR%/ \
	https://ftp.gwdg.de/pub/x11/x.org/pub/%SUBDIR%/ \
	https://mirrors.ircam.fr/pub/x.org/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.x.org/pub/%SUBDIR%/ \
	https://ftp.yz.yamagata-u.ac.jp/pub/X11/x.org/%SUBDIR%/ \
	http://piotrkosoft.net/pub/mirrors/ftp.x.org/pub/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/x.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KERNEL_ORG)
MASTER_SITE_KERNEL_ORG+= \
	https://cdn.kernel.org/pub/%SUBDIR%/ \
	https://www.kernel.org/pub/%SUBDIR%/ \
	https://mirrors.mit.edu/kernel/%SUBDIR%/ \
	http://ftp.nara.wide.ad.jp/pub/kernel.org/%SUBDIR%/ \
	http://ftp.yandex.ru/pub/%SUBDIR%/ \
	ftp://ftp.ntu.edu.tw/%SUBDIR%/ \
	ftp://ftp.riken.jp/Linux/kernel.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ZI)
MASTER_SITE_ZI+= \
	https://ftpmirror.your.org/pub/zi/%SUBDIR%/ \
	https://mirrors.rit.edu/zi/%SUBDIR%/ \
	https://www.zi0r.com/mirrors/%SUBDIR%/ \
	${MASTER_SITE_LOCAL:S/%SUBDIR%/zi/}
.endif

# Macro magic

MASTER_SITES_ABBREVS=	CPAN:PERL_CPAN \
			GH:GITHUB \
			GHC:GITHUB_CLOUD \
			LODEV:LIBREOFFICE_DEV \
			NL:NETLIB \
			RG:RUBYGEMS \
			SF:SOURCEFORGE
MASTER_SITES_SUBDIRS=	APACHE_COMMONS_BINARIES:${PORTNAME:S,commons-,,} \
			APACHE_COMMONS_SOURCE:${PORTNAME:S,commons-,,} \
			APACHE_JAKARTA:${PORTNAME:S,-,/,}/source \
			BERLIOS:${PORTNAME:tl}.berlios \
			CRATESIO:${PORTNAME}/${DISTVERSIONFULL} \
			DEBIAN:pool/main/${PORTNAME:C/^((lib)?.).*$/\1/}/${PORTNAME} \
			FARSIGHT:${PORTNAME} \
			FESTIVAL:${PORTVERSION} \
			GCC:releases/${DISTNAME} \
			GENTOO:distfiles \
			GIMP:${PORTNAME}/${PORTVERSION:R}/ \
			GITHUB:${GH_ACCOUNT}/${GH_PROJECT}/tar.gz/${GH_TAGNAME}?dummy=/ \
			GITHUB_CLOUD:${GH_ACCOUNT}/${GH_PROJECT}/ \
			GNOME:sources/${DISTNAME:S/-${DISTVERSIONFULL}$//} \
			GNU:${PORTNAME} \
			GNUPG:${PORTNAME} \
			GNU_ALPHA:${PORTNAME} \
			LIBREOFFICE_DEV:${PORTNAME} \
			MATE:${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/} \
			MOZDEV:${PORTNAME:tl} \
			NETLIB:${PORTNAME} \
			PERL_CPAN:${PORTNAME:C/-.*//} \
			PYPI:source/${DISTNAME:C/(.).*/\1/}/${DISTNAME:S/-${DISTVERSIONFULL}$//} \
			QT:archive/qt/${PORTVERSION:R} \
			SAMBA:${PORTNAME} \
			SAVANNAH:${PORTNAME:tl} \
			SOURCEFORGE:${PORTNAME:tl}/${PORTNAME:tl}/${PORTVERSION} \
			XFCE:xfce

.if defined(MASTER_SITES) && ${MASTER_SITES:N*\:/*}

.  for _site__ in ${MASTER_SITES}
_site_=${_site__}
.    if ${_site_:M*\:/*}
MASTER_SITES_EXP+=	${_site_}
MASTER_SITES_EXP:=	${MASTER_SITES_EXP}
.    else
_site_urlpath_=	${_site_:C@^(.*):[^/:]+$@\1@}
.      if ${_site_urlpath_:M*/*}
_site_url_=		${_site_urlpath_:C@^([^/]+)/.*$@\1@}
_site_subdir_=	${_site_urlpath_:S/^${_site_urlpath_:C@^([^/]+)/.*$@\1@}//:S!^/!!:S!/$!!}
.      else
_site_url_=		${_site_urlpath_}
.undef _site_subdir_
.      endif
_site_group_=	${_site_:S/^${_site_:C@^(.*):[^/:]+$@\1@}//:S/^://}
.      for _abbrev_ in ${MASTER_SITES_ABBREVS}
.        if ${_site_url_} == ${_abbrev_:C/:.*//}
_site_url_=	${_abbrev_:C/.*://}
.        endif
.      endfor
.      if !defined(MASTER_SITE_SUBDIR)
.        for _subdir_ in ${MASTER_SITES_SUBDIRS}
.          if ${_site_url_} == ${_subdir_:C/:.*//}
_site_subdir_?=	${_subdir_:C/.*://}
.          endif
.        endfor
.      endif
.      ifdef MASTER_SITE_${_site_url_}
.        ifdef _site_subdir_
MASTER_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S^%SUBDIR%^${_site_subdir_}^:S/$/:${_site_group_}/:S/:$//}
.        else
MASTER_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S/$/:${_site_group_}/:S/:$//}
.        endif
MASTER_SITES_EXP:=	${MASTER_SITES_EXP}
.      endif
.    endif
.  endfor
MASTER_SITES=	${MASTER_SITES_EXP}

.endif

.if defined(PATCH_SITES) && ${PATCH_SITES:N*\:/*}

.  for _site__ in ${PATCH_SITES}
_site_=${_site__}
.    if ${_site_:M*\:/*}
PATCH_SITES_EXP+=	${_site_}
PATCH_SITES_EXP:=	${PATCH_SITES_EXP}
.    else
_site_urlpath_=	${_site_:C@^(.*):[^/:]+$@\1@}
.      if ${_site_urlpath_:M*/*}
_site_url_=		${_site_urlpath_:C@^([^/]+)/.*$@\1@}
_site_subdir_=	${_site_urlpath_:S/^${_site_urlpath_:C@^([^/]+)/.*$@\1@}//:S!^/!!:S!/$!!}
.      else
_site_url_=		${_site_urlpath_}
.undef _site_subdir_
.      endif
_site_group_=	${_site_:S/^${_site_:C@^(.*):[^/:]+$@\1@}//:S/^://}
.      for _abbrev_ in ${MASTER_SITES_ABBREVS}
.        if ${_site_url_} == ${_abbrev_:C/:.*//}
_site_url_=	${_abbrev_:C/.*://}
.        endif
.      endfor
.      if !defined(MASTER_SITE_SUBDIR)
.        for _subdir_ in ${MASTER_SITES_SUBDIRS}
.          if ${_site_url_} == ${_subdir_:C/:.*//}
_site_subdir_?=	${_subdir_:C/.*://}
.          endif
.        endfor
.      endif
.      ifdef MASTER_SITE_${_site_url_}
.        ifdef _site_subdir_
PATCH_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S^%SUBDIR%^${_site_subdir_}^:S/$/:${_site_group_}/:S/:$//}
.        else
PATCH_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S/$/:${_site_group_}/:S/:$//}
.        endif
PATCH_SITES_EXP:=	${PATCH_SITES_EXP}
.      endif
.    endif
.  endfor
PATCH_SITES=	${PATCH_SITES_EXP}

.endif
