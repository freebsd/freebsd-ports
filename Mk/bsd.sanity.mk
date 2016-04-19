# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#

.if defined(WITHOUT_NLS)
WARNING+=	"WITHOUT_NLS is deprecated use OPTIONS_UNSET=NLS instead"
.endif

.if defined(WITH_NEW_XORG) || defined(WITHOUT_NEW_XORG)
WARNING+=	"WITH_NEW_XORG and WITHOUT_NEW_XORG knobs were removed and have no effect"
.endif

.if defined(WITH_KMS) || defined(WITHOUT_KMS)
WARNING+=	"WITH_KMS was removed and has no effect"
.endif

.if exists(${.CURDIR}/../../Mk/bsd.port.mk)
.if ${.CURDIR:H:T} != ${PKGCATEGORY}
DEV_ERROR+=	"The first entry in CATEGORIES should be the directory where the port lives"
.endif
.else
DEV_WARNING+=	"Not validating first entry in CATEGORIES due to being outside of PORTSDIR. Please ensure this is proper when committing."
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

.if defined(USE_GHOSTSCRIPT) || defined(USE_GHOSTSCRIPT_BUILD) || defined(USE_GHOSTSCRIPT_RUN)
DEV_ERROR+=	"USE_GHOSTSCRIPT is unsupported, please use USES=ghostscript instead"
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

.if defined(USE_GITHUB) && defined(GH_COMMIT)
DEV_ERROR+=	"GH_COMMIT is unsupported, please convert GHL-\>GH in MASTER_SITES and set GH_TAGNAME to tag or commit hash and remove GH_COMMIT"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mgnomehack}
DEV_WARNING+=	"USE_GNOME=gnomehack is deprecated, please use USES=pathfix"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mdesktopfileutils}
DEV_WARNING+=	"USE_GNOME=desktopfileutils is deprecated, please use USES=desktop-file-utils"
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:Nlib*}
DEV_ERROR+=	"All LIB_DEPENDS should use the new format and start out with lib.  \(libfoo.so vs foo.so\)"
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

.if defined(USE_PYTHON) && (${USE_PYTHON} == "yes" || ${USE_PYTHON:C/[-0-9.+]*//} == "")
_PYTHON_VAL := ${USE_PYTHON}
.if ${_PYTHON_VAL} != "yes"
DEV_ERROR+=	"USE_PYTHON=${_PYTHON_VAL} is no longer supported, please use USES=python:${_PYTHON_VAL}"
.else
DEV_ERROR+=	"USE_PYTHON=yes is no longer supported, please use USES=python"
.endif
.endif
.if defined(USE_PYTHON_RUN)
.if ${USE_PYTHON_RUN} != "yes"
DEV_ERROR+=	"USE_PYTHON_RUN is no longer supported, please use USES=python:${USE_PYTHON_RUN},run"
.else
DEV_ERROR+=	"USE_PYTHON_RUN is no longer supported, please use USES=python:run"
.endif
.endif
.if defined(USE_PYTHON_BUILD)
.if ${USE_PYTHON_BUILD} != "yes"
DEV_ERROR+=	"USE_PYTHON_BUILD is no longer supported, please use USES=python:${USE_PYTHON_BUILD},build"
.else
DEV_ERROR+=	"USE_PYTHON_BUILD is no longer supported, please use USES=python:build"
.endif
.endif

.if defined(PYDISTUTILS_INSTALLNOSINGLE)
DEV_WARNING+=	"PYDISTUTILS_INSTALLNOSINGLE is deprecated, please do not use it anymore"
.endif

.if defined(INSTALLS_EGGINFO)
DEV_ERROR+=	"INSTALLS_EGGINFO is no longer supported, please add the entry directly to the plist"
.endif

.if defined(WANT_SDL)
DEV_ERROR+=	"WANT_SDL is no longer supported. If you need SDL, use USE_SDL, if you need optional dependency, use options"
.endif

.if defined(USE_RC_SUBR) && ${USE_RC_SUBR:tu} == YES
DEV_ERROR+=	"USE_RC_SUBR=yes has not been supported for a long time, remove it."
.endif

SANITY_UNSUPPORTED=	USE_OPENAL USE_FAM USE_MAKESELF USE_ZIP USE_LHA USE_CMAKE \
		USE_READLINE USE_ICONV PERL_CONFIGURE PERL_MODBUILD \
		USE_PERL5_BUILD USE_PERL5_RUN USE_DISPLAY USE_FUSE \
		USE_GETTEXT USE_GMAKE USE_SCONS USE_DRUPAL NO_INSTALL_MANPAGES \
		INSTALLS_SHLIB USE_PYDISTUTILS PYTHON_CONCURRENT_INSTALL \
		PYDISTUTILS_AUTOPLIST PYTHON_PY3K_PLIST_HACK PYDISTUTILS_NOEGGINFO \
		USE_PYTHON_PREFIX USE_BZIP2 USE_XZ USE_PGSQL NEED_ROOT \
		UNIQUENAME LATEST_LINK
SANITY_DEPRECATED=	PYTHON_PKGNAMESUFFIX USE_AUTOTOOLS PLIST_DIRSTRY USE_SQLITE \
			USE_FIREBIRD
SANITY_NOTNEEDED=	WX_UNICODE

USE_AUTOTOOLS_ALT=	USES=autoreconf and GNU_CONFIGURE=yes
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
USE_PGSQL_ALT=		USES=pgsql
INSTALLS_SHLIB_ALT=	USE_LDCONFIG
NEED_ROOT_ALT=		USES=fakeroot or USES=uidfix
PYTHON_CONCURRENT_INSTALL_ALT=	USE_PYTHON=concurrent
PYDISTUTILS_AUTOPLIST_ALT=	USE_PYTHON=autoplist
PYTHON_PY3K_PLIST_HACK_ALT=	USE_PYTHON=py3kplist
PYDISTUTILS_NOEGGINFO_ALT=	USE_PYTHON=noegginfo
USE_PYTHON_PREFIX_ALT=		USE_PYTHON=pythonprefix
PYTHON_PKGNAMESUFFIX_ALT=	PYTHON_PKGNAMEPREFIX
NO_INSTALL_MANPAGES_ALT=	USES=imake:noman
UNIQUENAME_ALT=		PKGBASE
LATEST_LINK_ALT=	PKGBASE
WX_UNICODE_REASON=	Now no-op as only unicode is supported now
PLIST_DIRSTRY_ALT=	PLIST_DIRS
USE_SQLITE_ALT=		USES=sqlite
USE_FIREBIRD_ALT=	USES=firebird

.for a in ${SANITY_DEPRECATED}
.if defined(${a})
DEV_WARNING+=	"${a} is deprecated, please use ${${a}_ALT}"
.endif
.endfor

.for a in ${SANITY_NOTNEEDED}
.if defined(${a})
DEV_WARNING+=	"${a} is not needed: ${${a}_REASON}"
.endif
.endfor

.for a in ${SANITY_UNSUPPORTED}
.if defined(${a})
DEV_ERROR+=	"${a} is unsupported, please use ${${a}_ALT}"
.endif
.endfor
