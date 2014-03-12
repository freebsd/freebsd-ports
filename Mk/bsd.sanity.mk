# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#

.if defined(USE_GMAKE)
DEV_WARNING+=	"USE_GMAKE is deprecated, consider using USES=gmake"
.endif

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

.if defined(PERL_CONFIGURE)
DEV_ERROR+=	"PERL_CONFIGURE is unsupported, please use USES=perl5 along with USE_PERL5=configure"
.endif

.if defined(PERL_MODBUILD)
DEV_ERROR+=	"PERL_MODBUILD is unsupported, please use USES=perl5 along with USE_PERL5=modbuild"
.endif

.if defined(USE_PERL5_BUILD)
DEV_ERROR+=	"USE_PERL5_BUILD is unsupported, please use USES=perl5 along with USE_PERL5=build"
.endif

.if defined(USE_PERL5_RUN)
DEV_ERROR+=	"USE_PERL5_RUN is unsupported, please use USES=perl5 along with USE_PERL5=run"
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

.if defined(USE_DISPLAY)
DEV_WARNING+=	"USE_DISPLAY is deprecated, please use USES=display"
.endif

.if defined(USE_ICONV)
DEV_ERROR+=	"USE_ICONV is unsupported, please use USES=iconv"
.endif

.if defined(USE_CMAKE)
DEV_ERROR+=	"USE_CMAKE is unsupported, please use USES=cmake"
.endif

.if defined(USE_READLINE)
DEV_ERROR+=	"USE_READLINE is unsupported, please use USES=readline"
.endif

.if defined(USE_FUSE)
DEV_ERROR+=	"USE_FUSE is unupported, please use USES=fuse"
.endif

.if defined(USE_GETTEXT)
DEV_ERROR+=	"USE_GETTEXT is unsupported, replaced by USES=gettext"
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

#.if defined(USE_GNOME) && ${USE_GNOME:Mltverhack*}
#DEV_WARNING+=	"USE_GNOME=ltverhack is now useless LIB_DEPENDS can properly handle all kind of library version"
#.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:Nlib*}
DEV_WARNING+=	"Please use the new format for LIB_DEPENDS, see handbook for details"
.endif

.if defined(USE_TCL) || defined(USE_TCL_BUILD) || defined(USE_TCL_RUN) || defined(USE_TCL_WRAPPER) || \
   defined(USE_TK)  || defined(USE_TK_BUILD)  || defined(USE_TK_RUN)  || defined(USE_TK_WRAPPER)
DEV_ERROR+=	"USE_TCL and USE_TK are no longer supported, please use USES=tcl or USES=tk"
.endif

.if defined(USE_SCONS)
DEV_WARNING+=	"USE_SCONS=yes is deprecated, please use USES=scons"
.endif

# print warning if no reason given for NO_STAGE
.if defined(NO_STAGE)
DEV_WARNING+=	"NO_STAGE is deprecated, convert port to stage directory:"
DEV_WARNING+=	"https://wiki.freebsd.org/ports/StageDir"
.endif

.if !defined(NO_STAGE)
.for a in 1 2 3 4 5 6 7 8 9 L N
.if defined(MAN${a})
DEV_WARNING+=	"MAN${a} macros are deprecated when using stage directory"
.endif
.endfor
.endif

.if !defined(NO_STAGE) && defined(MLINKS)
DEV_WARNING+=	"MLINKS macros are deprecated when using stage directory"
.endif

.if defined(PYDISTUTILS_AUTOPLIST) && defined(PYTHON_PY3K_PLIST_HACK)
DEV_WARNING+=	"PYDISTUTILS_AUTOPLIST features Python 3.x support, PYTHON_PY3K_PLIST_HACK is not required"
.endif

.if defined(_PREMKINCLUDED)
DEV_ERROR+=	"you cannot include bsd.port[.pre].mk twice"
.endif

.if defined(USE_DOS2UNIX)
DEV_WARNING+=	"USE_DOS2UNIX is deprecated, please use USES=dos2unix"
.endif

.if defined(LICENSE)
.if ${LICENSE:MBSD}
DEV_WARNING+=	"LICENSE must not contain BSD, instead use BSD[234]CLAUSE"
.endif
.endif

.if defined(USE_PYDISTUTILS) && ${USE_PYDISTUTILS} == "easy_install"
DEV_WARNING+=	"USE_PYDISTUTILS=easy_install is deprecated, please use USE_PYDISTUTILS=yes"
.endif

.if defined(USE_PYDISTUTILS) && ${USE_PYDISTUTILS} != "easy_install" && defined(PYDISTUTILS_AUTOPLIST) && defined(PYDISTUTILS_PKGNAME)
DEV_WARNING+=	"PYDISTUTILS_PKGNAME has no effect for USE_PYDISTUTILS=yes and PYDISTUTILS_AUTOPLIST=yes"
.endif

.if defined(USE_OPENAL)
DEV_ERROR+=	"USE_OPENAL is unsupported, please use USES=openal"
.endif

.if defined(USE_FAM)
DEV_ERROR+=	"USE_FAM is unsupported, please use USES=fam"
.endif

.if defined(USE_MAKESELF)
DEV_ERROR+=	"USE_MAKESELF is unsupported, please use USES=makeself"
.endif

.if defined(USE_ZIP)
DEV_ERROR+=	'USE_ZIP is unsupported, please use USES=zip'
.endif

.if defined(USE_LHA)
DEV_WARNING+=	'USE_LHA is deprecated, please use USES=lha'
.endif

.if defined(USE_XZ)
DEV_WARNING+=	'USE_XZ is deprecated, please use USES=tar:xz'
.endif

.if defined(USE_BZIP2)
DEV_WARNING+=	'USE_BZIP2 is deprecated, please use USES=tar:bzip2'
.endif
