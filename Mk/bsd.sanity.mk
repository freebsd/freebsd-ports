# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#

.if defined(WITHOUT_NLS)
WARNING+=	"WITHOUT_NLS is deprecated use OPTIONS_UNSET=NLS instead"
.endif

#.if defined(WITHOUT_X11)
#WARNING+=	"WITHOUT_X11 is deprecated use X11 option instead"
#.endif

#.if !defined(LICENSE)
#DEV_WARNING+=	"No license is defined consider adding one"
#.endif

.if defined(USE_PERL5) && ${USE_PERL5} == yes
DEV_ERROR+=	"USE_PERL5=yes is unsupported, please use USES=perl5 instead"
.endif

.if defined(USE_KDEBASE_VER)
DEV_ERROR+=	"USE_KDEBASE_VER is unsupported"
.endif

.if defined(USE_KDELIBS_VER)
DEV_ERROR+=	"USE_KDELIBS_VER is unsupported"
.endif

.if defined(USE_QT_VER)
DEV_ERROR+=	"USE_QT_VER is unsupported"
.endif

.if !empty(LIB_DEPENDS:M*/../*)
DEV_ERROR+=	"LIB_DEPENDS contains unsupported relative path to dependency"
.endif

.if !empty(RUN_DEPENDS:M*/../*)
DEV_ERROR+=	"RUN_DEPENDS contains unsupported relative path to dependency"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mpkgconfig}
DEV_ERROR+=	"USE_GNOME=pkgconfig is unsupported, please use USES=pkgconfig"
.endif

.if defined(USE_ZOPE) && ${USE_ZOPE} == yes
DEV_ERROR+=	"USE_ZOPE=yes is unsupported, please use USES=zope instead"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mgnomehack}
DEV_WARNING+=	"USE_GNOME=gnomehack is deprecated, please use USES=pathfix"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mdesktopfileutils}
DEV_WARNING+=	"USE_GNOME=desktopfileutils is deprecated, please use USES=desktop-file-utils"
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:Nlib*}
DEV_ERROR+=	"Please use the new format for LIB_DEPENDS, see handbook for details"
.endif

.if defined(USE_TCL) || defined(USE_TCL_BUILD) || defined(USE_TCL_RUN) || defined(USE_TCL_WRAPPER) || \
   defined(USE_TK)  || defined(USE_TK_BUILD)  || defined(USE_TK_RUN)  || defined(USE_TK_WRAPPER)
DEV_ERROR+=	"USE_TCL and USE_TK are no longer supported, please use USES=tcl or USES=tk"
.endif

# print warning if no reason given for NO_STAGE
.if defined(NO_STAGE)
DEV_ERROR+=	"NO_STAGE is unsupported, convert port to stage directory:"
DEV_ERROR+=	"https://wiki.freebsd.org/ports/StageDir"
.endif

.for a in 1 2 3 4 5 6 7 8 9 L N
.if defined(MAN${a})
DEV_WARNING+=	"MAN${a} macros are deprecated when using stage directory"
.endif
.endfor

.if defined(MLINKS)
DEV_WARNING+=	"MLINKS macros are deprecated when using stage directory"
.endif

.if defined(PYDISTUTILS_AUTOPLIST) && defined(PYTHON_PY3K_PLIST_HACK)
DEV_WARNING+=	"PYDISTUTILS_AUTOPLIST features Python 3.x support, PYTHON_PY3K_PLIST_HACK is not required"
.endif

.if defined(_PREMKINCLUDED)
DEV_ERROR+=	"you cannot include bsd.port[.pre].mk twice"
.endif

.if defined(USE_DOS2UNIX)
DEV_ERROR+=	"USE_DOS2UNIX is no longer supported, please use USES=dos2unix"
.endif

.if defined(LICENSE)
.if ${LICENSE:MBSD}
DEV_WARNING+=	"LICENSE must not contain BSD, instead use BSD[234]CLAUSE"
.endif
.endif

.if defined(USE_PYDISTUTILS) && ${USE_PYDISTUTILS} == "easy_install"
DEV_ERROR+=	"USE_PYDISTUTILS=easy_install is no longer supported, please use USE_PYDISTUTILS=yes"
.endif

.if defined(USE_PYDISTUTILS) && defined(PYDISTUTILS_AUTOPLIST) && defined(PYDISTUTILS_PKGNAME)
DEV_WARNING+=	"PYDISTUTILS_PKGNAME has no effect for USE_PYDISTUTILS=yes and PYDISTUTILS_AUTOPLIST=yes"
.endif

.if defined(USE_AUTOTOOLS)
.  if ${USE_AUTOTOOLS:Mlibtool} || ${USE_AUTOTOOLS:Mlibtool\:env}
DEV_WARNING+=	"USE_AUTOTOOLS=libtool is deprecated, please use USES=libtool"
.  endif
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mltverhack*}
DEV_WARNING+=	"USE_GNOME=ltverhack is deprecated, please use USES=libtool"
.endif

.if defined(USE_PYTHON) && (${USE_PYTHON} == "yes" || ${USE_PYTHON:C/[-0-9.+]*//} == "")
_PYTHON_VAL := ${USE_PYTHON}
.if ${_PYTHON_VAL} != "yes"
DEV_WARNING+=	"USE_PYTHON=${_PYTHON_VAL} is deprecated, please use USES=python:${_PYTHON_VAL}"
.else
DEV_WARNING+=	"USE_PYTHON=yes is deprecated, please use USES=python"
.endif
.endif
.if defined(USE_PYTHON_RUN)
.if ${USE_PYTHON_RUN} != "yes"
DEV_WARNING+=	"USE_PYTHON_RUN is deprecated, please use USES=python:${USE_PYTHON_RUN},run"
.else
DEV_WARNING+=	"USE_PYTHON_RUN is deprecated, please use USES=python:run"
.endif
.endif
.if defined(USE_PYTHON_BUILD)
.if ${USE_PYTHON_BUILD} != "yes"
DEV_WARNING+=	"USE_PYTHON_BUILD is deprecated, please use USES=python:${USE_PYTHON_BUILD},build"
.else
DEV_WARNING+=	"USE_PYTHON_BUILD is deprecated, please use USES=python:build"
.endif
.endif

.if defined(PYDISTUTILS_INSTALLNOSINGLE)
DEV_WARNING+=	"PYDISTUTILS_INSTALLNOSINGLE is deprecated, please do not use it anymore"
.endif

.if defined(INSTALLS_EGGINFO)
DEV_WARNING+=	"INSTALLS_EGGINFO is deprecated, please add the entry directly to the plist"
.endif

SANITY_UNSUPPORTED=	USE_OPENAL USE_FAM USE_MAKESELF USE_ZIP USE_LHA USE_CMAKE \
		USE_READLINE USE_ICONV PERL_CONFIGURE PERL_MODBUILD \
		USE_PERL5_BUILD USE_PERL5_RUN USE_DISPLAY USE_FUSE \
		USE_GETTEXT USE_GMAKE USE_SCONS USE_DRUPAL
SANITY_DEPRECATED=	USE_XZ USE_BZIP2 USE_PYDISTUTILS PYTHON_CONCURRENT_INSTALL \
		PYDISTUTILS_AUTOPLIST PYTHON_PY3K_PLIST_HACK PYDISTUTILS_NOEGGINFO \
		USE_PYTHON_PREFIX PYTHON_PKGNAMESUFFIX NO_INSTALL_MANPAGES

USE_OPENAL_ALT=		USES=openal
USE_FAM_ALT=		USES=fam
USE_MAKESELF_ALT=	USES=makeself
USE_ZIP_ALT=		USES=zip
USE_LHA_ALT=		USES=lha
USE_BZIP2_ALT=		USES=tar:bzip2
USE_XZ_ALT=		USES=tar:xz
USE_CMAKE_ALT=		USES=cmake
USE_READLINE_ALT=	USES=readline
USE_ICONV_ALT=		USES=iconv
USE_GMAKE_ALT=		USES=gmake
PERL_CONFIGURE_ALT=	USES=perl5 along with USE_PERL5=configure
PERL_MODBUILD_ALT=	USES=perl5 along with USE_PERL5=modbuild
USE_PERL5_BUILD_ALT=	USES=perl5 along with USE_PERL5=build
USE_PERL5_RUN_ALT=	USES=perl5 along with USE_PERL5=run
USE_DISPLAY_ALT=	USES=display
USE_FUSE_ALT=		USES=fuse
USE_GETTEXT_ALT=	USES=gettext
USE_SCONS_ALT=		USES=scons
USE_DRUPAL_ALT=		USES=drupal
USE_PYDISTUTILS_ALT=		USE_PYTHON=distutils
PYTHON_CONCURRENT_INSTALL_ALT=	USE_PYTHON=concurrent
PYDISTUTILS_AUTOPLIST_ALT=	USE_PYTHON=autoplist
PYTHON_PY3K_PLIST_HACK_ALT=	USE_PYTHON=py3kplist
PYDISTUTILS_NOEGGINFO_ALT=	USE_PYTHON=noegginfo
USE_PYTHON_PREFIX_ALT=		USE_PYTHON=pythonprefix
PYTHON_PKGNAMESUFFIX_ALT=	PYTHON_PKGNAMEPREFIX
NO_INSTALL_MANPAGES_ALT=	USES=imake:noman

.for a in ${SANITY_DEPRECATED}
.if defined(${a})
DEV_WARNING+=	"${a} is deprecated, please use ${${a}_ALT}"
.endif
.endfor

.for a in ${SANITY_UNSUPPORTED}
.if defined(${a})
DEV_ERROR+=	"${a} is unsupported, please use ${${a}_ALT}"
.endif
.endfor
