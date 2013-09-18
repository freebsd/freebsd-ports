# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#

.if defined(USE_GMAKE)
DEV_WARNING+=	"USE_GMAKE is deprecated consider using USES=gmake"
.endif

#.if defined(WITHOUT_NLS)
#WARNING+=	"WITHOUT_NLS is deprecated use NLS option instead"
#.endif
#
#.if defined(WITHOUT_X11)
#WARNING+=	"WITHOUT_X11 is deprecated use X11 option instead"
#.endif

#.if !defined(LICENSE)
#DEV_WARNING+=	"No license is defined consider adding one"
#.endif

.if defined(USE_PERL5) && ${USE_PERL5} == yes
DEV_ERROR+=	"USE_PERL5=yes is unsupported please use USES=perl5 instead"
.endif

.if defined(PERL_CONFIGURE)
DEV_ERROR+=	"PERL_CONFIGURE is unsupported please use USES=perl5 along with USE_PERL5=configure"
.endif

.if defined(PERL_MODBUILD)
DEV_ERROR+=	"PERL_MODBUILD is unsupported please use USES=perl5 along with USE_PERL5=modbuild"
.endif

.if defined(USE_PERL5_BUILD)
DEV_ERROR+=	"USE_PERL5_BUILD is unsupported please use USES=perl5 along with USE_PERL5=build"
.endif

.if defined(USE_PERL5_RUN)
DEV_ERROR+=	"USE_PERL5_RUN is unsupported please use USES=perl5 along with USE_PERL5=run"
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

.if defined(USE_DISPLAY)
DEV_WARNING+=	"USE_DISPLAY is deprecated please use USES=display"
.endif

.if defined(USE_ICONV)
DEV_ERROR+=	"USE_ICONV is unsupported please use USES=iconv"
.endif

.if defined(USE_CMAKE)
DEV_ERROR+=	"USE_CMAKE is unsupported please use USES=cmake"
.endif

.if defined(USE_READLINE)
DEV_ERROR+=	"USE_READLINE is unsupported please use USES=readline"
.endif

.if defined(USE_FUSE)
DEV_ERROR+=	"USE_FUSE is unupported please use USES=fuse"
.endif

.if defined(USE_GETTEXT)
DEV_ERROR+=	"USE_GETTEXT is unsupported replaced by USES=gettext"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mpkgconfig}
DEV_ERROR+=	"USE_GNOME=pkgconfig is unsupported please use USES=pkgconfig"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mgnomehack}
DEV_WARNING+=	"USE_GNOME=gnomehack is deprecated please use USES=pathfix"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mltverhack*}
DEV_WARNING+=	"USE_GNOME=ltverhack is now useless LIB_DEPENDS can properly handle all kind of library version"
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:Nlib*}
DEV_WARNING+=	"Please use the new format for LIB_DEPENDS, see handbook for details"
.endif

.if defined(WARNING)
show-warnings:
.for m in ${WARNING}
	@${ECHO_MSG} "${m}"
.endfor
	@sleep 5

check-makefile:: show-warnings
.endif

.if defined(_PREMKINCLUDED)
DEV_ERROR+=	"you cannot include bsd.port[.pre].mk twice"
.endif

.if defined(DEVELOPER)
.if defined(DEV_WARNING)
show-dev-warnings:
	@${ECHO_MSG} "/!\\ ${PKGNAME}: Makefile warnings, please consider fixing /!\\"
	@${ECHO_MSG}
.for m in ${DEV_WARNING}
	@${ECHO_MSG} "${m}"
.endfor
	@${ECHO_MSG}
	@sleep 5
check-makefile:: show-dev-warnings
.endif

.if defined(DEV_ERROR)
show-dev-errors:
	@${ECHO_MSG} "/!\\ ${PKGNAME}: Makefile errors /!\\"
	@${ECHO_MSG}
.for m in ${DEV_WARNING}
	@${ECHO_MSG} "${m}"
.endfor
	@${FALSE}
check-makefile:: show-dev-errors
.endif
.endif
