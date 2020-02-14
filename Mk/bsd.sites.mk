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
#
# $FreeBSD$
#

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
	ftp://ftp.afterstep.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/X11/AfterStep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_APACHE)
MASTER_SITE_APACHE+= \
	https://www.apache.org/dist/%SUBDIR%/ \
	https://archive.apache.org/dist/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/Web/apache/%SUBDIR%/ \
	http://apache.mirror.uber.com.au/%SUBDIR%/ \
	http://apache.spd.co.il/%SUBDIR%/ \
	https://ftp.mirrorservice.org/sites/ftp.apache.org/%SUBDIR%/ \
	https://ftp-stud.hs-esslingen.de/pub/Mirrors/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://mir1.ovh.net/ftp.apache.org/dist/%SUBDIR%/ \
	ftp://ftp.forthnet.gr/pub/www/apache/%SUBDIR%/ \
	ftp://xenia.sote.hu/pub/mirrors/www.apache.org/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/www.apache.org/dist/%SUBDIR%/ \
	https://mirrors.ircam.fr/pub/apache/%SUBDIR%/
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

.if !defined(IGNORE_MASTER_SITE_CHEESESHOP)
MASTER_SITE_CHEESESHOP+= \
	https://files.pythonhosted.org/packages/%SUBDIR%/ \
	https://pypi.org/packages/%SUBDIR%/
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
	https://cran.cnr.berkeley.edu/%SUBDIR%/ \
	https://cran.csiro.au/%SUBDIR%/ \
	https://mirrors.tuna.tsinghua.edu.cn/CRAN/%SUBDIR%/ \
	http://camoruco.ing.uc.edu.ve/cran/%SUBDIR%/ \
	https://mirror.las.iastate.edu/CRAN/%SUBDIR%/ \
	https://cran.ma.imperial.ac.uk/%SUBDIR%/ \
	https://cran.gis-lab.info/%SUBDIR%/ \
	https://cran.ism.ac.jp/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CRAN_ARCHIVE)
MASTER_SITE_CRAN_ARCHIVE+= ${MASTER_SITE_CRAN:S,$,Archive/${PORTNAME}/,}
.endif

.if !defined(IGNORE_MASTER_SITE_CRATESIO)
MASTER_SITE_CRATESIO+=	https://crates.io/api/v1/crates/%SUBDIR%/download?dummy=/
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN)
MASTER_SITE_DEBIAN+= \
	http://cdn.debian.net/debian/%SUBDIR%/ \
	http://http.debian.net/debian/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/debian/%SUBDIR%/ \
	ftp://ftp.us.debian.org/debian/%SUBDIR%/ \
	http://ftp.au.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.bg.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.br.debian.org/debian/%SUBDIR%/ \
	http://ftp.cl.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.cz.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.de.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.ee.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.es.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.fi.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.fr.debian.org/debian/%SUBDIR%/ \
	http://ftp.hk.debian.org/debian/%SUBDIR%/ \
	http://ftp.hr.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.hu.debian.org/debian/%SUBDIR%/ \
	http://ftp.ie.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.is.debian.org/debian/%SUBDIR%/ \
	http://ftp.it.debian.org/debian/%SUBDIR%/ \
	http://ftp.jp.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.nl.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.no.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.pl.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.ru.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.se.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.si.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.sk.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.uk.debian.org/debian/%SUBDIR%/ \
	http://ftp.wa.au.debian.org/debian/%SUBDIR%/ \
	ftp://ftp2.de.debian.org/debian/%SUBDIR%/ \
	ftp://ftp.snt.utwente.nl/pub/linux/debian/%SUBDIR%/ \
	ftp://ftp.acc.umu.se/debian/%SUBDIR%/ \
	ftp://mirror.symnds.com/debian/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_DEBIAN_POOL)
MASTER_SITE_DEBIAN_POOL+= \
	${MASTER_SITE_DEBIAN:C|(/%SUBDIR%/)|/pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}/|}
.endif

.if !defined(IGNORE_MASTER_SITE_EASYSW)
MASTER_SITE_EASYSW+= \
	http://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ECLIPSE)
MASTER_SITE_ECLIPSE+= \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/eclipse.org/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/eclipse/%SUBDIR%/ \
	https://ftp-stud.hs-esslingen.de/pub/Mirrors/eclipse/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/download.eclipse.org/eclipseMirror/%SUBDIR%/ \
	http://eclipse.stu.edu.tw/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_EXIM)
MASTER_SITE_EXIM+= \
	ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
	ftp://mirror.easyname.at/exim-ftp/%SUBDIR%/ \
	http://dl.ambiweb.de/mirrors/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://exim.noris.de/exim/%SUBDIR%/ \
	ftp://ftp.bytemine.net/exim/exim/%SUBDIR%/ \
	ftp://ftp.heanet.ie/pub/exim/%SUBDIR%/ \
	https://ftp.heanet.ie/pub/exim/%SUBDIR%/ \
	http://washitake.com/mail/exim/mirror/exim/%SUBDIR%/ \
	ftp://ftp.kaist.ac.kr/exim/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/exim/%SUBDIR%/ \
	ftp://sunsite.uio.no/pub/mail/exim/exim/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/unix/mail/exim/exim/%SUBDIR%/ \
	https://sunsite.icm.edu.pl/pub/unix/mail/exim/exim/%SUBDIR%/ \
	ftp://mirrors.dominios.pt/pub/ftp.exim.org/exim/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/exim/exim/%SUBDIR%/ \
	http://mirror.switch.ch/ftp/mirror/exim/exim/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.exim.org/pub/%SUBDIR%/ \
	http://exim.telcom.net.ua/ftp/%SUBDIR/ \
	ftp://idcnetwork.org/pub/exim/exim/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_CENTOS_LINUX)
MASTER_SITE_CENTOS_LINUX+= \
	http://mirror.centos.org/%SUBDIR%/:DEFAULT,amd64,i386 \
	http://vault.centos.org/%SUBDIR%/:DEFAULT,amd64,i386,SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_EPEL)
MASTER_SITE_EPEL+= \
	https://dl.fedoraproject.org/pub/epel/6/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	https://dl.fedoraproject.org/pub/epel/6/i386/Packages/%SUBDIR%/:DEFAULT,i386 \
	https://dl.fedoraproject.org/pub/epel/6/SRPMS/Packages/%SUBDIR%/:SOURCE \
	http://dl.fedoraproject.org/pub/epel/6/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	http://dl.fedoraproject.org/pub/epel/6/i386/Packages/%SUBDIR%/:DEFAULT,i386 \
	http://dl.fedoraproject.org/pub/epel/6/SRPMS/Packages/%SUBDIR%/:SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_EPEL7)
MASTER_SITE_EPEL7+= \
	https://dl.fedoraproject.org/pub/epel/7/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	https://dl.fedoraproject.org/pub/epel/7/SRPMS/Packages/%SUBDIR%/:SOURCE \
	http://dl.fedoraproject.org/pub/epel/7/x86_64/Packages/%SUBDIR%/:DEFAULT,amd64 \
	http://dl.fedoraproject.org/pub/epel/7/SRPMS/Packages/%SUBDIR%/:SOURCE
.endif

.if !defined(IGNORE_MASTER_SITE_FEDORA_LINUX)
MASTER_SITE_FEDORA_LINUX+= \
	https://archives.fedoraproject.org/pub/archive/fedora/linux/%SUBDIR%/:DEFAULT,SOURCE \
	https://archives.fedoraproject.org/pub/archive/fedora/linux/%SUBDIR%/:DEFAULT,SOURCE \
	ftp://ftp.pbone.net/vol4/archive.fedoraproject.org/fedora/linux/%SUBDIR%/:DEFAULT,SOURCE \
	ftp://ftp.gmd.de/archives.fedoraproject.org/fedora/linux/%SUBDIR%/:DEFAULT,SOURCE \
	ftp://mirror.fraunhofer.de/archives.fedoraproject.org/fedora/linux/%SUBDIR%/:DEFAULT,SOURCE \
	ftp://ftp-mirror.bi.fraunhofer.de/archives.fedoraproject.org/fedora/linux/%SUBDIR%/:DEFAULT,SOURCE
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
	ftp://ftp.tuwien.ac.at/opsys/linux/blinux/festival/mirror.ogi-synth_home/ \
	http://www.cslu.ogi.edu/tts/download/data/
.endif

#
# FreeBSD mirror sites
#
# For the full list, see the Handbook:
#
#    http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/mirrors-ftp.html
#
.if !defined(IGNORE_MASTER_SITE_FREEBSD_ORG)
MASTER_SITE_FREEBSD_ORG+= \
	https://download.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.se.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.uk.FreeBSD.org/pub/FreeBSD/%SUBDIR%/ \
	ftp://ftp.ru.FreeBSD.org/pub/FreeBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_FRUGALWARE)
MASTER_SITE_FRUGALWARE+= \
	ftp://ftp7.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp2.frugalware.org/mirror/ftp.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp6.frugalware.org/mirrors/linux/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp4.frugalware.org/pub/linux/distributions/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp12.frugalware.org/mirrors/ftp.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/ \
	ftp://ftp10.frugalware.org/pub/linux/frugalware/frugalware-stable/source/%SUBDIR%/
#	ftp://ftp5.frugalware.org/packages/frugalware/pub/frugalware/frugalware-stable/source/%SUBDIR%/
#	ftp://ftp3.frugalware.org/mirrors/frugalware/pub/frugalware/frugalware-stable/source/%SUBDIR%/
#	ftp://ftp9.frugalware.org/pub/frugalware/frugalware-stable/source/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GCC)
MASTER_SITE_GCC+= \
	https://mirrors.kernel.org/sourceware/gcc/%SUBDIR%/ \
	http://gcc.parentingamerica.com/%SUBDIR%/ \
	http://gcc.cybermirror.org/%SUBDIR%/ \
	http://gcc-uk.internet.bs/%SUBDIR%/ \
	http://www.netgull.com/gcc/%SUBDIR%/ \
	http://robotlab.itk.ppke.hu/gcc/%SUBDIR%/ \
	http://gcc.fyxm.net/%SUBDIR%/ \
	https://ftp-stud.hs-esslingen.de/pub/Mirrors/sourceware.org/gcc/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sourceware.org/pub/gcc/%SUBDIR%/ \
	ftp://gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/mirrors/gcc.gnu.org/gcc/%SUBDIR%/ \
	ftp://ftp.uvsq.fr/pub/gcc/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/misc/gcc/%SUBDIR%/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/gcc.gnu.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.nluug.nl/mirror/languages/gcc/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/sourceware.org/pub/gcc/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/gnu/gcc/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GENTOO)
MASTER_SITE_GENTOO+= \
	http://gentoo.mirrors.pair.com/%SUBDIR%/ \
	http://mirrors.tds.net/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/www.ibiblio.org/gentoo/%SUBDIR%/ \
	http://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	http://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	https://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	http://gentoo.inode.at/%SUBDIR%/ \
	http://gentoo.gg3.net/%SUBDIR%/ \
	http://mirrors.163.com/gentoo/%SUBDIR%/ \
	ftp://ftp.gtlib.gatech.edu/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.ussg.iu.edu/pub/linux/gentoo/%SUBDIR%/ \
	ftp://mirrors.tds.net/pub/gentoo/%SUBDIR%/ \
	ftp://ftp.belnet.be/mirror/rsync.gentoo.org/gentoo/%SUBDIR%/ \
	ftp://ftp.snt.utwente.nl/pub/os/linux/gentoo/%SUBDIR%/ \
	ftp://trumpetti.atm.tut.fi/gentoo/%SUBDIR%/ \
	ftp://ftp.tu-clausthal.de/pub/linux/gentoo/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/%SUBDIR%/ \
	ftp://linux.rz.ruhr-uni-bochum.de/gentoo-mirror/%SUBDIR%/ \
	ftp://ftp.uni-erlangen.de/pub/mirrors/gentoo/%SUBDIR%/ \
	ftp://gentoo.inode.at/source/%SUBDIR%/
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
.if defined(USE_GITHUB)
.  if defined(GH_TAGNAME) && ${GH_TAGNAME} == master
IGNORE?=	Using master as GH_TAGNAME is invalid. \
		Must use a tag or commit hash so the upstream does \
		not "reroll" as soon as the branch is updated
.  endif
.  if defined(GH_TUPLE)
.    for _tuple in ${GH_TUPLE}
_t_tmp=${_tuple}
.      if ${_t_tmp:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\4@:S/://:C/[a-zA-Z0-9_]//g}
check-makevars::
	@${ECHO_MSG} "The ${_tuple} GH_TUPLE line has"
	@${ECHO_MSG} "a tag containing something else than [a-zA-Z0-9_]"
	@${FALSE}
.      endif
.    endfor
GH_ACCOUNT+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\1\4@}
GH_PROJECT+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\2\4@}
GH_TAGNAME+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\3\4@}
GH_SUBDIR+=	${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*)((:[^:/]*)?)((/.*)?)@\6\4@:M/*:S/^\///}
.  endif
# We are cheating and using backend URLS for GitHub here. See ports/194898
# comment #15 for explanation as to why and how to deal with it if it breaks.
MASTER_SITE_GITHUB+=		https://codeload.github.com/%SUBDIR%
MASTER_SITE_GITHUB_CLOUD+=	https://cloud.github.com/downloads/%SUBDIR%

.  if !defined(MASTER_SITES) || !${MASTER_SITES:MGH} && !${MASTER_SITES:MGHC} && !${USE_GITHUB:Mnodefault}
MASTER_SITES+=	GH
.  endif
GH_ACCOUNT_DEFAULT=	${PORTNAME}
GH_ACCOUNT?=	${GH_ACCOUNT_DEFAULT}
GH_PROJECT_DEFAULT=	${PORTNAME}
GH_PROJECT?=	${GH_PROJECT_DEFAULT}
# Use full PREFIX/SUFFIX and converted DISTVERSION
GH_TAGNAME_DEFAULT=	${DISTVERSIONFULL}
GH_TAGNAME?=	${GH_TAGNAME_DEFAULT}
# Iterate over GH_ACCOUNT, GH_PROJECT, GH_TAGNAME and GH_SUBDIR to extract groups
_GITHUB_GROUPS= DEFAULT
.  for _gh_v in GH_ACCOUNT GH_PROJECT GH_TAGNAME GH_SUBDIR
.    for _v_ex in ${${_gh_v}}
_GH_GROUPS=	${_v_ex:S/^${_v_ex:C@:[^/:]+$@@}//:S/^://}
.      if !empty(_GH_GROUPS)
.        for _group in ${_GH_GROUPS:S/,/ /g}
.          if ${_group} == all || ${_group} == ALL || ${_group} == default
check-makevars::
		@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
		@${ECHO_MSG} "used in group definitions. Please fix your ${_gh_v}"
		@${FALSE}
.          endif
.          if !${_GITHUB_GROUPS:M${_group}}
_GITHUB_GROUPS+=	${_group}
.          endif
${_gh_v}_${_group}=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.        endfor
.      else
${_gh_v}_DEFAULT=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.      endif
.    endfor
.  endfor
# Put the default values back into the variables so that the *default* behavior
# is not changed.
GH_ACCOUNT:=	${GH_ACCOUNT_DEFAULT}
GH_PROJECT:=	${GH_PROJECT_DEFAULT}
GH_TAGNAME:=	${GH_TAGNAME_DEFAULT}
GH_SUBDIR:=	${GH_SUBDIR_DEFAULT}
.  if defined(GH_TAGNAME)
GH_TAGNAME_SANITIZED=	${GH_TAGNAME:S,/,-,g}
# GitHub silently converts tags starting with v to not have v in the filename
# and extraction directory.  It also replaces + with -.
GH_TAGNAME_EXTRACT=	${GH_TAGNAME_SANITIZED:C/^[vV]([0-9])/\1/:S/+/-/g}
.  endif
# This new scheme rerolls distfiles. Also ensure they are renamed to avoid
# conflicts. Use _GITHUB_REV in case github changes their zipping or structure
# which has happened before.
_GITHUB_REV=	0
_GITHUB_EXTRACT_SUFX=	.tar.gz
# Put the DEFAULT distfile first
_GITHUB_CLONE_DIR?=	${WRKDIR}/git-clone
_PORTS_DIRECTORIES+=	${_GITHUB_CLONE_DIR}
.  if !${USE_GITHUB:Mnodefault} && empty(MASTER_SITES:MGHC)
# GH_TAGNAME defaults to DISTVERSIONFULL; Avoid adding DISTVERSIONFULL in twice
.    if ${GH_TAGNAME} != ${DISTVERSIONFULL}
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}-${GH_TAGNAME_SANITIZED}
.    else
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME_SANITIZED}
.    endif
DISTNAME:=	${DISTNAME}_GH${_GITHUB_REV}
DISTFILES+=	${DISTNAME}${_GITHUB_EXTRACT_SUFX}
git-clone: git-clone-DEFAULT
git-clone-DEFAULT: ${_GITHUB_CLONE_DIR}
	@git clone https://github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}.git ${_GITHUB_CLONE_DIR}/${GH_PROJECT_DEFAULT}
	@${ECHO_MSG} "Cloned the default github repository into ${_GITHUB_CLONE_DIR}/${GH_PROJECT_DEFAULT}" | ${FMT_80}
.  endif
.  if !empty(GH_SUBDIR)
_SITES_extract:=	690:post-extract-gh-DEFAULT
post-extract-gh-DEFAULT:
	@${RMDIR} ${WRKSRC}/${GH_SUBDIR_DEFAULT} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GH_SUBDIR_DEFAULT:H} 2>/dev/null || :
	@${LN} -s ${GH_SUBDIR_DEFAULT:C/[^\/]//g:C/\//..\//g:S/^$/./} ${WRKSRC}/${GH_SUBDIR_DEFAULT}
.  endif
# If there are non default groups
.  if !empty(_GITHUB_GROUPS:NDEFAULT)
# Then for each of the remaining groups, add DISTFILES and MASTER_SITES
# entries with the correct group and create {WRKSRC,DISTNAME,DISTFILES}_group
# helper variables.
.    for _group in ${_GITHUB_GROUPS:NDEFAULT}
GH_ACCOUNT_${_group}?=	${GH_ACCOUNT_DEFAULT}
GH_PROJECT_${_group}?=	${GH_PROJECT_DEFAULT}
GH_TAGNAME_${_group}?=	${GH_TAGNAME_DEFAULT}
GH_TAGNAME_${_group}_SANITIZED=	${GH_TAGNAME_${_group}:S,/,-,}
GH_TAGNAME_${_group}_EXTRACT=	${GH_TAGNAME_${_group}_SANITIZED:C/^[vV]([0-9])/\1/}
_GH_TUPLE_OUT:=	${_GH_TUPLE_OUT} ${GH_ACCOUNT_${_group}}:${GH_PROJECT_${_group}}:${GH_TAGNAME_${_group}}:${_group}/${GH_SUBDIR_${_group}}
DISTNAME_${_group}:=	${GH_ACCOUNT_${_group}}-${GH_PROJECT_${_group}}-${GH_TAGNAME_${_group}_SANITIZED}
DISTFILE_${_group}:=	${DISTNAME_${_group}}_GH${_GITHUB_REV}${_GITHUB_EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DISTFILE_${_group}}:${_group}
MASTER_SITES:=	${MASTER_SITES} ${MASTER_SITE_GITHUB:S@%SUBDIR%@${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}/tar.gz/${GH_TAGNAME_${_group}}?dummy=/:${_group}@}
WRKSRC_${_group}:=	${WRKDIR}/${GH_PROJECT_${_group}}-${GH_TAGNAME_${_group}_EXTRACT}
.      if !empty(GH_SUBDIR_${_group})
# In order to sort the subdir extraction so that foo/bar is moved in before
# foo/bar/baz, we count the number of / in the path and use it to order the
# targets.  This handles up to 9 levels.  The max as of r463123 is 4.
_SITES_extract:=	${_SITES_extract} 69${GH_SUBDIR_${_group}:C=[^/]+= =g:[#]}:post-extract-gh-${_group}
post-extract-gh-${_group}:
	@${RMDIR} ${WRKSRC}/${GH_SUBDIR_${_group}} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GH_SUBDIR_${_group}:H} 2>/dev/null || :
	@${MV} ${WRKSRC_${_group}} ${WRKSRC}/${GH_SUBDIR_${_group}}
	@${LN} -s ${WRKSRC:T}/${GH_SUBDIR_${_group}} ${WRKSRC_${_group}}
.      endif
git-clone: git-clone-${_group}
git-clone-${_group}: ${_GITHUB_CLONE_DIR}
	@git clone https://github.com/${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}.git ${_GITHUB_CLONE_DIR}/${GH_PROJECT_${_group}}
	@${ECHO_MSG} "Cloned the ${_group} github repository into ${_GITHUB_CLONE_DIR}/${GH_PROJECT_${_group}}" | ${FMT_80}
.    endfor
.  endif
convert-to-gh-tuple:
	@${ECHO_MSG} ${GH_ACCOUNT}:${GH_PROJECT}:${GH_TAGNAME} ${_GH_TUPLE_OUT:S/\/$//}
.endif # defined(USE_GITHUB)
.endif # !defined(IGNORE_MASTER_SITE_GITHUB)

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
# GL_COMMIT     - the commit hash of the repository, must be the full hash and
#                 is a required variable for GitLab.
#
# GL_SUBDIR     - directory relative to WRKSRC where to move this distfile's
#                 content after extracting.
#
# GL_TUPLE      - above shortened to [site[:port][/webroot]:]account:project:commit:group[/subdir]
#
.if defined(USE_GITLAB)
.  if defined(GL_TUPLE)
.    for _tuple in ${GL_TUPLE}
.      if ${_tuple:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\7@:S/^://:C/[a-f0-9]{40}//g}
check-makevars::
	@${ECHO_MSG} "The ${_tuple}"
	@${ECHO_MSG} "GL_TUPLE is improperly formatted or, the commit"
	@${ECHO_MSG} "section contains something other than [a-f0-9]"
	@${FALSE}
.      endif
.    endfor
GL_SITE+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\1\8@:S@::@:@}
GL_ACCOUNT+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\5\8@}
GL_PROJECT+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\6\8@}
GL_COMMIT+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\7\8@}
GL_SUBDIR+=	${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\9\8@:M/*:S/^\///}
.  endif

.  if empty(USE_GITLAB:Mnodefault)
MASTER_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/repository/${GL_COMMIT}/archive.tar.gz?dummy=/
.  endif
GL_SITE_DEFAULT=	https://gitlab.com
GL_SITE?=	${GL_SITE_DEFAULT}
GL_ACCOUNT_DEFAULT=	${PORTNAME}
GL_ACCOUNT?=	${GL_ACCOUNT_DEFAULT}
GL_PROJECT_DEFAULT=	${PORTNAME}
GL_PROJECT?=	${GL_PROJECT_DEFAULT}
_GITLAB_GROUPS=	DEFAULT
.  for _gl_v in GL_SITE GL_ACCOUNT GL_PROJECT GL_COMMIT GL_SUBDIR
.    for _v_ex in ${${_gl_v}}
_GL_GROUPS=	${_v_ex:S/^${_v_ex:C@:[^/:]+$@@}//:S/^://}
.      if !empty(_GL_GROUPS)
.        for _group in ${_GL_GROUPS:S/,/ /g}
.          if ${_group} == all || ${_group} == ALL || ${_group} == default
check-makevars::
		@${ECHO_MSG} "Makefile error: the words all, ALL and default are reserved and cannot be"
		@${ECHO_MSG} "used in group definitions. Please fix your ${_gl_v}"
		@${FALSE}
.          endif
.          if !${_GITLAB_GROUPS:M${_group}}
_GITLAB_GROUPS+=	${_group}
.          endif
${_gl_v}_${_group}=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.        endfor
.      else
${_gl_v}_DEFAULT=	${_v_ex:C@^(.*):[^/:]+$@\1@}
.      endif
.    endfor
.  endfor
GL_SITE:=	${GL_SITE_DEFAULT}
GL_ACCOUNT:=	${GL_ACCOUNT_DEFAULT}
GL_PROJECT:=	${GL_PROJECT_DEFAULT}
GL_COMMIT:=	${GL_COMMIT_DEFAULT}
GL_SUBDIR:=	${GL_SUBDIR_DEFAULT}

_GITLAB_REV=	0

_GITLAB_EXTRACT_SUFX=	.tar.gz

_GITLAB_CLONE_DIR?=	${WRKDIR}/git-clone
_PORTS_DIRECTORIES+=	${_GITLAB_CLONE_DIR}
.  if !${USE_GITLAB:Mnodefault}
DISTNAME:=	${GL_ACCOUNT}-${GL_PROJECT}-${GL_COMMIT}_GL${_GITLAB_REV}
DISTFILES+=	${DISTNAME}${_GITLAB_EXTRACT_SUFX}
git-clone: git-clone-DEFAULT
git-clone-DEFAULT: ${_GITLAB_CLONE_DIR}
	@git clone ${GL_SITE_DEFAULT}/${GL_ACCOUNT_DEFAULT}/${GL_PROJECT_DEFAULT}.git ${_GITLAB_CLONE_DIR}/${GL_PROJECT_DEFAULT}
	@${ECHO_MSG} "Cloned the default GitLab repository into ${_GITLAB_CLONE_DIR}/${GL_PROJECT_DEFAULT}" | ${FMT_80}
.  endif
.  if !empty(GL_SUBDIR)
_SITES_extract:=	69${GL_SUBDIR_${_group}:C=[^/]+= =g:[#]}:post-extract-gl-DEFAULT
post-extract-gl-DEFAULT:
	@${RMDIR} ${WRKSRC}/${GL_SUBDIR_DEFAULT} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GL_SUBDIR_DEFAULT:H} 2>/dev/null || :
	@${LN} -s ${GL_SUBDIR_DEFAULT:C/[^\/]//g:C/\//..\//g:S/^$/./} ${WRKSRC}/${GL_SUBDIR_DEFAULT}
.  endif
.  if !empty(_GITLAB_GROUPS:NDEFAULT)
.    for _group in ${_GITLAB_GROUPS:NDEFAULT}
# We set GL_SITE earlier, we need to verify its not empty
.      if empty(GL_SITE_${_group})
GL_SITE_${_group}=	${GL_SITE_DEFAULT}
.      endif
GL_ACCOUNT_${_group}?=	${GL_ACCOUNT_DEFAULT}
GL_PROJECT_${_group}?=	${GL_PROJECT_DEFAULT}

_GL_TUPLE_OUT:=	${_GL_TUPLE_OUT} ${GL_SITE_${_group}}:${GL_ACCOUNT_${_group}}:${GL_PROJECT_${_group}}:${GL_COMMIT_${_group}}:${_group}/${GL_SUBDIR_${_group}}
DISTNAME_${_group}:=	${GL_ACCOUNT_${_group}}-${GL_PROJECT_${_group}}-${GL_COMMIT_${_group}}_GL${_GITLAB_REV}
DISTFILE_${_group}:=	${DISTNAME_${_group}}${_GITLAB_EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DISTFILE_${_group}}:${_group}
MASTER_SITES:=	${MASTER_SITES} ${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}/repository/${GL_COMMIT_${_group}}/archive.tar.gz?dummy=/:${_group}
WRKSRC_${_group}:=	${WRKDIR}/${GL_PROJECT_${_group}}-${GL_COMMIT_${_group}}-${GL_COMMIT_${_group}}
.      if !empty(GL_SUBDIR_${_group})
_SITES_extract:=	${_SITES_extract} 690:post-extract-gl-${_group}
post-extract-gl-${_group}:
	@${RMDIR} ${WRKSRC}/${GL_SUBDIR_${_group}} 2>/dev/null || :
	@${MKDIR} ${WRKSRC}/${GL_SUBDIR_${_group}:H} 2>/dev/null || :
	@${MV} ${WRKSRC_${_group}} ${WRKSRC}/${GL_SUBDIR_${_group}}
	@${LN} -s ${WRKSRC:T}/${GL_SUBDIR_${_group}} ${WRKSRC_${_group}}
.      endif
git-clone: git-clone-${_group}
git-clone-${_group}: ${_GITLAB_CLONE_DIR}
	@git clone ${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}.git ${_GITLAB_CLONE_DIR}/${GL_PROJECT_${_group}}
	@${ECHO_MSG} "Cloned the ${_group} GitLab repository into ${_GITLAB_CLONE_DIR}/${GL_PROJECT_${_group}}" | ${FMT_80}
.    endfor
.  endif
.endif # defined(USE_GITLAB)
.endif # !defined(IGNORE_MASTER_SITE_GITLAB)

.if !defined(IGNORE_MASTER_SITE_GNOME)
MASTER_SITE_GNOME+= \
	https://download.gnome.org/%SUBDIR%/ \
	http://download.gnome.org/%SUBDIR%/ \
	http://ftp.belnet.be/mirror/ftp.gnome.org/%SUBDIR%/ \
	ftp://ftp.belnet.be/mirror/ftp.gnome.org/%SUBDIR%/ \
	https://ftp.acc.umu.se/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/%SUBDIR%/ \
	https://fr2.rpmfind.net/linux/gnome.org/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/gnome/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnome.org/pub/GNOME/%SUBDIR%/ \
	ftp://ftp.nara.wide.ad.jp/pub/X11/GNOME/%SUBDIR%/ \
	https://ftp.gnome.org/pub/GNOME/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GIMP)
MASTER_SITE_GIMP+= \
	http://gimp.mirrors.hoobly.com/pub/%SUBDIR%/ \
	http://gimper.net/downloads/pub/%SUBDIR%/ \
	http://mirror.hessmo.com/gimp/pub/%SUBDIR%/ \
	http://de-mirror.gimper.net/pub/%SUBDIR%/ \
	http://gimp.afri.cc/pub/%SUBDIR%/ \
	https://download.gimp.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNU)
MASTER_SITE_GNU+= \
	https://ftpmirror.gnu.org/%SUBDIR%/ \
	https://ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.gnu.org/gnu/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/gnu/gnu/%SUBDIR%/ \
	https://mirrors.kernel.org/gnu/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/GNU/gnu/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.gnu.org/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/gnu/%SUBDIR%/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/mirror/ftp.gnu.org/pub/gnu/%SUBDIR%/ \
	http://ftp.funet.fi/pub/gnu/prep/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_GNUPG)
MASTER_SITE_GNUPG+= \
	https://gnupg.org/ftp/gcrypt/%SUBDIR%/ \
	https://ftp.heanet.ie/mirrors/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.franken.de/pub/crypt/mirror/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/gnupg/%SUBDIR%/ \
	https://mirrors.dotsrc.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	ftp://ftp.crysys.hu/pub/gnupg/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	https://artfiles.org/gnupg.org/%SUBDIR%/ \
	ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/ \
	http://mirror.tje.me.uk/pub/mirrors/ftp.gnupg.org/%SUBDIR%/
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

.if !defined(IGNORE_MASTER_SITE_GOOGLE_CODE)
PROJECTHOST?=	${PORTNAME}
MASTER_SITE_GOOGLE_CODE+= \
	http://${PROJECTHOST}.googlecode.com/files/
.endif

.if !defined(IGNORE_MASTER_SITE_HORDE)
MASTER_SITE_HORDE+= \
	https://ftp.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.at.horde.org/infosys/webapps/horde/%SUBDIR%/ \
	ftp://ftp.se.horde.org/mirror/horde/pub/%SUBDIR%/ \
	ftp://ftp.tw.horde.org/pub/%SUBDIR%/ \
	ftp://ftp.us.horde.org/pub/software/horde//%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_IDSOFTWARE)
MASTER_SITE_IDSOFTWARE+= \
	ftp://ftp.gwdg.de/pub/misc2/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	http://ftp4.de.freesbie.org/pub/misc/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pc/games/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.gamers.org/pub/idgames/idstuff/%SUBDIR%/ \
	http://ftp.iinet.net.au/games/idstuff/%SUBDIR%/ \
	ftp://ftp.mirror.nl/disk2/idsoftware/idstuff/%SUBDIR%/ \
	ftp://freebsd.nsu.ru/mirrors/ftp.idsoftware.com/idstuff/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/vendors/idgames/idstuff/%SUBDIR%/ \
	ftp://ftp.omen.net.au/games/idstuff/%SUBDIR%/ \
	ftp://ftp.idsoftware.com/idstuff/%SUBDIR%/
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

# List:		http://download.kde.org/extra/mirrors.html
# Updated:	2012-10-26
.if !defined(IGNORE_MASTER_SITE_KDE)
MASTER_SITE_KDE+= \
	https://download.kde.org/%SUBDIR%/ \
	ftp://ftp.gtlib.gatech.edu/pub/kde/%SUBDIR%/ \
	ftp://ftp.informatik.hu-berlin.de/pub/Mirrors/ftp.kde.org/%SUBDIR%/ \
	http://ftp.gtlib.gatech.edu/pub/kde/%SUBDIR%/ \
	http://kde.mirrors.tds.net/pub/kde/%SUBDIR%/ \
	ftp://ftp.rz.uni-wuerzburg.de/pub/unix/kde/%SUBDIR%/ \
	https://mirrors.dotsrc.org/kde/%SUBDIR%/ \
	ftp://mirrors.dotsrc.org/kde/%SUBDIR%/ \
	ftp://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	http://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	ftp://sunsite.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	https://sunsite.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	ftp://ftp.lip6.fr/pub/X11/kde/%SUBDIR%/ \
	http://www-ftp.lip6.fr/pub/X11/kde/%SUBDIR%/ \
	https://ftp-stud.hs-esslingen.de/Mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	ftp://ftp.cronyx.ru/pub/mirror/kde/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/X/KDE/%SUBDIR%/ \
	ftp://ftp.fu-berlin.de/pub/unix/X11/gui/kde/%SUBDIR%/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/kde/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/X11/kde/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.heanet.ie/mirrors/ftp.kde.org/%SUBDIR%/ \
	https://ftp.heanet.ie/mirrors/ftp.kde.org/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/X11/kde/%SUBDIR%/ \
	http://ftp.kddlabs.co.jp/pub/X11/kde/%SUBDIR%/ \
	ftp://ftp.ussg.iu.edu/pub/kde/%SUBDIR%/ \
	http://ftp.ussg.iu.edu/kde/%SUBDIR%/ \
	ftp://ftp.sayclub.com/pub/X/KDE/%SUBDIR%/ \
	http://ftp.sayclub.com/pub/X/KDE/%SUBDIR%/ \
	http://mirror.cc.columbia.edu/pub/software/kde/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.kde.org/pub/kde/%SUBDIR%/ \
	https://ftp.icm.edu.pl/pub/unix/kde/%SUBDIR%/ \
	http://ftp.fi.muni.cz/pub/kde/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://ftp.funet.fi/pub/mirrors/ftp.kde.org/pub/kde/%SUBDIR%/ \
	http://kde.cs.nctu.edu.tw/%SUBDIR%/
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
	http://ftp.scarlet.be/pub/mozdev/%SUBDIR%/ \
	http://ftp.rz.tu-bs.de/pub/mirror/downloads.mozdev.org/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/www/mozdev/%SUBDIR%/ \
	https://ftp.heanet.ie/pub/mozdev/%SUBDIR%/ \
	http://mozdev.oregonstate.edu/%SUBDIR%/ \
	http://ftp.ntua.gr/pub/www/mozdev/%SUBDIR%/ \
	http://www.devlib.org/mozdev/%SUBDIR%/ \
	ftp://ftp.heanet.ie/pub/mozdev/%SUBDIR%/ \
	http://mirrors.ibiblio.org/mozdev.org/%SUBDIR%/ \
	https://ftp.osuosl.org/pub/mozdev/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA)
MASTER_SITE_MOZILLA+= \
	https://download.cdn.mozilla.net/pub/%SUBDIR%/ \
	https://archive.mozilla.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MOZILLA_ADDONS)
MASTER_SITE_MOZILLA_ADDONS+= \
	https://addons.cdn.mozilla.net/user-media/%SUBDIR%/ \
	http://kyoto-mz-dl.sinet.ad.jp/pub/mozilla.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_MYSQL)
MASTER_SITE_MYSQL+= \
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/%SUBDIR%/ \
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/%SUBDIR%/ \
	http://mirrors.ntua.gr/MySQL/Downloads/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/databases/mysql/Downloads/%SUBDIR%/ \
	ftp://mirror.switch.ch/mirror/mysql/Downloads/%SUBDIR%/ \
	http://mysql.mirrors.pair.com/Downloads/%SUBDIR%/ \
	http://download.softagency.net/MySQL/Downloads/%SUBDIR%/
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
	https://ftp.mirrorservice.org/sites/ftp.netlib.org/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.netlib.org/%SUBDIR%/ \
	ftp://ftp.irisa.fr/pub/netlib/%SUBDIR%/ \
	http://netlib.sandia.gov/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_NVIDIA)
MASTER_SITE_NVIDIA+= \
	https://jp.download.nvidia.com/%SUBDIR%/ \
	http://us.download.nvidia.com/%SUBDIR%/ \
	https://tw.download.nvidia.com/%SUBDIR%/ \
	http://download.nvidia.com/%SUBDIR%/ \
	https://download1.nvidia.com/%SUBDIR%/ \
	ftp://download.nvidia.com/%SUBDIR%/ \
	ftp://download1.nvidia.com/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OPENBSD)
MASTER_SITE_OPENBSD+= \
	https://cdn.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://ftp.OpenBSD.org/pub/OpenBSD/%SUBDIR%/ \
	https://ftp.eu.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://ftp3.usa.openbsd.org/pub/OpenBSD/%SUBDIR%/ \
	https://mirror.leaseweb.com/pub/OpenBSD/%SUBDIR%/ \
	https://openbsd.hk/pub/OpenBSD/%SUBDIR%/ \
	https://mirror.aarnet.edu.au/pub/OpenBSD/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_OSDN)
.for mirror in aarnet acc c3sl cznic gigenet iij jaist nchc onet osdn pumath rwthaachen ymu
MASTER_SITE_OSDN+= \
	http://${mirror}.dl.osdn.jp/%SUBDIR%/
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_OSSP)
MASTER_SITE_OSSP+= \
	ftp://ftp.ossp.org/pkg/%SUBDIR%/ \
	ftp://ftp.ntua.gr/pub/utils/ossp/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PACKETSTORM)
MASTER_SITE_PACKETSTORM+= \
	https://dl.packetstormsecurity.net/%SUBDIR%/ \
	https://packetstorm.foofus.com/%SUBDIR%/
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
	ftp://ftp.kddlabs.co.jp/lang/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://ftp.jaist.ac.jp/pub/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/cpan.perl.org/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.auckland.ac.nz/pub/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://backpan.perl.org/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/%CPANSORT%/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/Lang/CPAN/%CPANSORT%/%SUBDIR%/ \
	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/%SUBDIRPLUS%/

_PERL_CPAN_FLAG=${MASTER_SITE_SUBDIR:C/(CPAN):.*$/\1/}
_PERL_CPAN_ID=	${MASTER_SITE_SUBDIR:C/^CPAN:(.)(.)(.*)$/\1\/\1\2\/\1\2\3/}

.if !empty(_PERL_CPAN_ID) && ${_PERL_CPAN_FLAG:tl} == "cpan"
    _PERL_CPAN_SORT=authors/id/${_PERL_CPAN_ID}
    MASTER_SITE_PERL_CPAN=${MASTER_SITE_PERL_CPAN_BY:S/%CPANSORT%/${_PERL_CPAN_SORT}/:S/%SUBDIR%\///:S/%SUBDIRPLUS%\//${PORTNAME:C/-.*//}\//}
.else
    MASTER_SITE_PERL_CPAN=${MASTER_SITE_PERL_CPAN_BY:S/%CPANSORT%/${_PERL_CPAN_SORT}/:S/%SUBDIRPLUS%\///}
.endif

.endif

#
# PostgreSQL master site
#
.if !defined(IGNORE_MASTER_SITE_PGSQL)
MASTER_SITE_PGSQL+= \
	https://ftp.postgresql.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PHP)
MASTER_SITE_PHP+= \
	http://de.php.net/%SUBDIR%/ \
	http://es.php.net/%SUBDIR%/ \
	http://fr.php.net/%SUBDIR%/ \
	http://it.php.net/%SUBDIR%/ \
	http://jp.php.net/%SUBDIR%/ \
	http://se.php.net/%SUBDIR%/ \
	http://uk3.php.net/%SUBDIR%/ \
	http://us2.php.net/%SUBDIR%/ \
	http://br.php.net/%SUBDIR%/ \
	http://cn.php.net/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_PYTHON)
MASTER_SITE_PYTHON+= \
	https://www.python.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QMAIL)
MASTER_SITE_QMAIL+= \
	http://qmail.glasswings.com.au/%SUBDIR%/ \
	http://qmail.psshee.com/%SUBDIR%/ \
	https://mirrors.sunsite.dk/qmailwww/%SUBDIR%/ \
	http://www.agria.hu/qmail/%SUBDIR%/ \
	http://qmail.netvisao.pt/%SUBDIR%/ \
	http://qmail.ipg.sk/%SUBDIR%/ \
	http://qmail.omnis.ch/%SUBDIR%/ \
	http://www.qmail.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_QT)
MASTER_SITE_QT+= \
	https://download.qt.io/%SUBDIR%/ \
	http://master.qt.io/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/download.qt-project.org/%SUBDIR%/ \
	http://www.nic.funet.fi/pub/mirrors/download.qt-project.org/%SUBDIR%/ \
	http://qtmirror.ics.com/pub/qtproject/%SUBDIR%/ \
	https://ftp.jaist.ac.jp/pub/qtproject/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_REDHAT_LINUX)
MASTER_SITE_REDHAT_LINUX+= \
	http://mirrors.usc.edu/pub/linux/distributions/redhat/redhat/linux/%SUBDIR%/ \
	http://www.gtlib.gatech.edu/pub/redhat/linux/%SUBDIR%/ \
	ftp://mirror.cs.wisc.edu/pub/mirrors/linux/redhat/%SUBDIR%/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/%SUBDIR%/ \
	ftp://ftp.icm.edu.pl/pub/linux/redhat/linux/%SUBDIR%/ \
	ftp://ftp.riken.go.jp/pub/Linux/redhat/linux/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/%SUBDIR%/
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

# List:	https://download.savannah.gnu.org/mirmon/
.if !defined(IGNORE_MASTER_SITE_SAVANNAH)
MASTER_SITE_SAVANNAH+= \
	https://download.savannah.gnu.org/releases/%SUBDIR%/ \
	https://download-mirror.savannah.gnu.org/releases/%SUBDIR%/ \
	http://nongnu.askapache.com/%SUBDIR%/ \
	http://mirror.lihnidos.org/GNU/savannah/%SUBDIR%/ \
	http://ftp.twaren.net/Unix/NonGNU/%SUBDIR%/ \
	ftp://ftp.twaren.net/Unix/NonGNU/%SUBDIR%/ \
	http://gnu.mirrors.pair.com/savannah/savannah/%SUBDIR%/
.endif

# List:		https://sourceforge.net/p/forge/documentation/Mirrors/
# Updated:	2017-03-13
.if !defined(IGNORE_MASTER_SITE_SOURCEFORGE)
.for p in https http
MASTER_SITE_SOURCEFORGE+= ${p}://downloads.sourceforge.net/project/%SUBDIR%/
.for m in excellmedia freefr jaist kent nchc \
	netcologne netix superb-dca2 superb-sea2 ufpr vorboss
MASTER_SITE_SOURCEFORGE+= ${p}://${m}.dl.sourceforge.net/project/%SUBDIR%/
.endfor
.endfor
.endif

.if !defined(IGNORE_MASTER_SITE_SOURCEWARE)
MASTER_SITE_SOURCEWARE+= \
	https://mirrors.kernel.org/sourceware/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sourceware.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_SUDO)
MASTER_SITE_SUDO+= \
	https://www.sudo.ws/sudo/dist/ \
	http://ftp.arcane-networks.fr/pub/mirrors/sudo/ \
	http://sudo.p8ra.de/sudo/dist/ \
	http://sudo.cybermirror.org/ \
	http://sudo-ftp.basemirror.de/ \
	http://core.ring.gr.jp/archives/misc/sudo/ \
	http://www.ring.gr.jp/archives/misc/sudo/ \
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
	ftp://core.ring.gr.jp/pub/misc/sudo/ \
	ftp://ftp.ring.gr.jp/pub/misc/sudo/ \
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
	ftp://ftp.kddlabs.co.jp/lang/tcl/ftp.scriptics.com/%SUBDIR%/ \
	ftp://ftp.mirrorservice.org/sites/ftp.tcl.tk/pub/tcl/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/languages/tcl/tcl/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TEX_CTAN)
MASTER_SITE_TEX_CTAN+= \
	http://ctan.unsw.edu.au/%SUBDIR%/ \
	ftp://ftp.kddlabs.co.jp/CTAN/%SUBDIR%/ \
	ftp://ctan.tug.org/tex-archive/%SUBDIR%/ \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/ \
	ftp://mirror.macomnet.net/pub/CTAN/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/
.endif

# Derived from: https://www.torproject.org/getinvolved/mirrors.html.en
.if !defined(IGNORE_MASTER_SITE_TOR)
MASTER_SITE_TOR+= \
		https://dist.torproject.org/%SUBDIR%/ \
		https://archive.torproject.org/tor-package-archive/%SUBDIR%/ \
		ftp://ftp.bit.nl/mirror/tor/%SUBDIR%/ \
		https://cyberside.net.ee/tor/%SUBDIR%/ \
		https://ftp.bit.nl/mirror/tor/%SUBDIR%/ \
		http://mirror.hessmo.com/tor/dist/%SUBDIR%/ \
		http://mirror.host4site.co.il/torproject.org/dist/%SUBDIR%/ \
		http://mirror.open-networx.org/torproject.org/dist/%SUBDIR%/ \
		http://mirror.tor.hu/dist/%SUBDIR%/ \
		https://mirror.torland.me/torproject.org/dist/%SUBDIR%/ \
		http://mirrors.chaos-darmstadt.de/tor-mirror/dist/%SUBDIR%/ \
		http://theonionrouter.com/dist/%SUBDIR%/ \
		http://tor.amorphis.eu/dist/%SUBDIR%/ \
		http://tor.askapache.com/dist/%SUBDIR%/ \
		http://tor.beme-it.de/dist/%SUBDIR%/ \
		http://tor.borgmann.tv/dist/%SUBDIR%/ \
		https://tor.ccc.de/dist/%SUBDIR%/ \
		http://tor.cyberarmy.at/dist/%SUBDIR%/ \
		http://tor.dont-know-me.at/dist/%SUBDIR%/ \
		http://tor.factor.cc/dist/%SUBDIR%/ \
		http://tor.homosu.net/dist/%SUBDIR%/ \
		http://tor.idnr.ws/dist/%SUBDIR%/ \
		https://tor.myrl.net/dist/%SUBDIR%/ \
		http://tor.kamagurka.org/dist/%SUBDIR%/ \
		http://tor.spline.de/dist/%SUBDIR%/ \
		http://tor.vesta.nu/dist/%SUBDIR%/ \
		http://torproj.xpdm.us/dist/%SUBDIR%/ \
		https://torproject.antagonism.org/dist/%SUBDIR%/ \
		https://torproject.crypto.is/dist/%SUBDIR%/ \
		https://torproject.is/dist/%SUBDIR%/ \
		http://torproject.nwlinux.us/dist/%SUBDIR%/ \
		https://torproject.ph3x.at/dist/%SUBDIR%/ \
		https://www.coevoet.nl/tor/dist/%SUBDIR%/ \
		http://www.oignon.net/dist/%SUBDIR%/ \
		https://www.torproject.nl/dist/%SUBDIR%/ \
		http://www.torproject.org.nyud.net/dist/%SUBDIR%/ \
		http://www.torproject.us/dist/%SUBDIR%/ \
		https://www.torservers.net/mirrors/torproject.org/dist/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_TUCOWS)
MASTER_SITE_TUCOWS+= \
	http://iinets.linux.tucows.com/files/%SUBDIR%/
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
	https://archive.al-us.xfce.org/src/%SUBDIR%/${_XFCE_PATH}/ \
	http://mirror.perldude.de/archive.xfce.org/src/%SUBDIR%/${_XFCE_PATH}/
.endif

.if !defined(IGNORE_MASTER_SITE_XORG)
MASTER_SITE_XORG+= \
	https://xorg.freedesktop.org/releases/%SUBDIR%/ \
	https://mirror.csclub.uwaterloo.ca/x.org/%SUBDIR%/ \
	https://artfiles.org/x.org/pub/%SUBDIR%/ \
	https://ftp.gwdg.de/pub/x11/x.org/pub/%SUBDIR%/ \
	https://mi.mirror.garr.it/mirrors/x.org/%SUBDIR%/ \
	https://mirrors.ircam.fr/pub/x.org/%SUBDIR%/ \
	https://www.mirrorservice.org/sites/ftp.x.org/pub/%SUBDIR%/ \
	https://mirror.nl.leaseweb.net/xorg/%SUBDIR%/ \
	https://ftp.yz.yamagata-u.ac.jp/pub/X11/x.org/%SUBDIR%/ \
	http://piotrkosoft.net/pub/mirrors/ftp.x.org/pub/%SUBDIR%/ \
	http://xorg.mirrors.pair.com/%SUBDIR%/ \
	http://ftp.kaist.ac.kr/x.org/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_KERNEL_ORG)
MASTER_SITE_KERNEL_ORG+= \
	https://www.kernel.org/pub/%SUBDIR%/ \
	ftp://ftp.ntu.edu.tw/%SUBDIR%/ \
	https://ftp.yandex.ru/pub/%SUBDIR%/ \
	https://ftp.heanet.ie/pub/%SUBDIR%/ \
	http://slackware.cs.utah.edu/pub/kernel.org/pub/%SUBDIR%/
.endif

.if !defined(IGNORE_MASTER_SITE_ZI)
MASTER_SITE_ZI+= \
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
			CHEESESHOP:source/${DISTNAME:C/(.).*/\1/}/${DISTNAME:S/-${DISTVERSIONFULL}$//} \
			CRATESIO:${PORTNAME}/${DISTVERSIONFULL} \
			DEBIAN:pool/main/${PORTNAME:C/^((lib)?.).*$/\1/}/${PORTNAME} \
			FARSIGHT:${PORTNAME} \
			FESTIVAL:${PORTVERSION} \
			GCC:releases/${DISTNAME} \
			GENTOO:distfiles \
			GIMP:${PORTNAME}/${PORTVERSION:R}/ \
			GITHUB:${GH_ACCOUNT}/${GH_PROJECT}/tar.gz/${GH_TAGNAME}?dummy=/ \
			GITHUB_CLOUD:${GH_ACCOUNT}/${GH_PROJECT}/ \
			GNOME:sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/} \
			GNU:${PORTNAME} \
			GNUPG:${PORTNAME} \
			GNU_ALPHA:${PORTNAME} \
			HORDE:${PORTNAME} \
			LIBREOFFICE_DEV:${PORTNAME} \
			MATE:${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/} \
			MOZDEV:${PORTNAME:tl} \
			NETLIB:${PORTNAME} \
			PERL_CPAN:${PORTNAME:C/-.*//} \
			QT:archive/qt/${PORTVERSION:R} \
			SAMBA:${PORTNAME} \
			SAVANNAH:${PORTNAME:tl} \
			SOURCEFORGE:${PORTNAME:tl}/${PORTNAME:tl}/${PORTVERSION} \
			XFCE:xfce

.if defined(MASTER_SITES) && ${MASTER_SITES:N*\:/*}

.for _site__ in ${MASTER_SITES}
_site_=${_site__}
.	if ${_site_:M*\:/*}
MASTER_SITES_EXP+=	${_site_}
MASTER_SITES_EXP:=	${MASTER_SITES_EXP}
.	else
_site_urlpath_=	${_site_:C@^(.*):[^/:]+$@\1@}
.		if ${_site_urlpath_:M*/*}
_site_url_=		${_site_urlpath_:C@^([^/]+)/.*$@\1@}
_site_subdir_=	${_site_urlpath_:S/^${_site_urlpath_:C@^([^/]+)/.*$@\1@}//:S!^/!!:S!/$!!}
.		else
_site_url_=		${_site_urlpath_}
.undef _site_subdir_
.		endif
_site_group_=	${_site_:S/^${_site_:C@^(.*):[^/:]+$@\1@}//:S/^://}
.		for _abbrev_ in ${MASTER_SITES_ABBREVS}
.			if ${_site_url_} == ${_abbrev_:C/:.*//}
_site_url_=	${_abbrev_:C/.*://}
.			endif
.		endfor
.		if !defined(MASTER_SITE_SUBDIR)
.			for _subdir_ in ${MASTER_SITES_SUBDIRS}
.				if ${_site_url_} == ${_subdir_:C/:.*//}
_site_subdir_?=	${_subdir_:C/.*://}
.				endif
.			endfor
.		endif
.		ifdef MASTER_SITE_${_site_url_}
.			ifdef _site_subdir_
MASTER_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S^%SUBDIR%^${_site_subdir_}^:S/$/:${_site_group_}/:S/:$//}
.			else
MASTER_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S/$/:${_site_group_}/:S/:$//}
.			endif
MASTER_SITES_EXP:=	${MASTER_SITES_EXP}
.		endif
.	endif
.endfor
MASTER_SITES=	${MASTER_SITES_EXP}

.endif

.if defined(PATCH_SITES) && ${PATCH_SITES:N*\:/*}

.for _site__ in ${PATCH_SITES}
_site_=${_site__}
.	if ${_site_:M*\:/*}
PATCH_SITES_EXP+=	${_site_}
PATCH_SITES_EXP:=	${PATCH_SITES_EXP}
.	else
_site_urlpath_=	${_site_:C@^(.*):[^/:]+$@\1@}
.		if ${_site_urlpath_:M*/*}
_site_url_=		${_site_urlpath_:C@^([^/]+)/.*$@\1@}
_site_subdir_=	${_site_urlpath_:S/^${_site_urlpath_:C@^([^/]+)/.*$@\1@}//:S!^/!!:S!/$!!}
.		else
_site_url_=		${_site_urlpath_}
.undef _site_subdir_
.		endif
_site_group_=	${_site_:S/^${_site_:C@^(.*):[^/:]+$@\1@}//:S/^://}
.		for _abbrev_ in ${MASTER_SITES_ABBREVS}
.			if ${_site_url_} == ${_abbrev_:C/:.*//}
_site_url_=	${_abbrev_:C/.*://}
.			endif
.		endfor
.		if !defined(MASTER_SITE_SUBDIR)
.			for _subdir_ in ${MASTER_SITES_SUBDIRS}
.				if ${_site_url_} == ${_subdir_:C/:.*//}
_site_subdir_?=	${_subdir_:C/.*://}
.				endif
.			endfor
.		endif
.		ifdef MASTER_SITE_${_site_url_}
.			ifdef _site_subdir_
PATCH_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S^%SUBDIR%^${_site_subdir_}^:S/$/:${_site_group_}/:S/:$//}
.			else
PATCH_SITES_EXP+=	${MASTER_SITE_${_site_url_}:S/$/:${_site_group_}/:S/:$//}
.			endif
PATCH_SITES_EXP:=	${PATCH_SITES_EXP}
.		endif
.	endif
.endfor
PATCH_SITES=	${PATCH_SITES_EXP}

.endif
