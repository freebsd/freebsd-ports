# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#

.if defined(USE_GMAKE)
DEV_WARNING+=	USE_GMAKE is deprecated consider using USES=gmake
.endif

.if defined(WITHOUT_NLS)
WARNING+=	WITHOUT_NLS is deprecated use NLS option instead
.endif

.if defined(WITHOUT_X11)
WARNING+=	WITHOUT_X11 is deprecated use X11 option instead
.endif

.if !defined(LICENSE)
DEV_WARNING+=	No license is defined consider adding one
.endif

.if defined(USE_PERL5) && ${USE_PERL5} == yes
DEV_ERROR+=	USE_PERL5=yes is unsupported please use USES=perl5 instead
.endif

.if defined(PERL_CONFIGURE)
DEV_ERROR+=	PERL_CONFIGURE is unsupported please use USES=perl5 along with USE_PERL5=configure
.endif

.if defined(PERL_MODBUILD)
DEV_ERROR+=	PERL_MODBUILD is unsupported please use USES=perl5 along with USE_PERL5=modbuild
.endif

.if defined(USE_PERL5_BUILD)
DEV_ERROR+=	USE_PERL5_BUILD is unsupported please use USES=perl5 along with USE_PERL5=build
.endif

.if defined(USE_PERL5_RUN)
DEV_ERROR+=	USE_PERL5_RUN is unsupported please use USES=perl5 along with USE_PERL5=run
.endif

.if defined(USE_KDEBASE_VER)
DEV_ERROR+=	USE_KDEBASE_VER is unsupported
.endif

.if defined(USE_KDELIBS_VER)
DEV_ERROR+=	USE_KDELIBS_VER is unsupported
.endif

.if defined(USE_QT_VER)
DEV_ERROR+=	USE_QT_VER is unsupported
.endif

.if defined(USE_DISPLAY)
DEV_WARNING+=	USE_DISPLAY is deprecated please use USES=display
.endif

.if defined(USE_ICONV)
DEV_ERROR+=	USE_ICONV is unsupported please use USES=iconv
.endif

.if defined(USE_CMAKE)
DEV_ERROR+=	USE_CMAKE is unsupported please use USES=cmake
.endif

.if defined(USE_READLINE)
DEV_ERROR+=	USE_READLINE is unsupported please use USES=readline
.endif

.if defined(USE_FUSE)
DEV_ERROR+=	USE_FUSE is unupported please use USES=fuse
.endif

.if defined(USE_GETTEXT)
DEV_ERROR+=	USE_GETTEXT is unsupported replaced by USES=gettext
.endif

.if defined(WARNING)
show-warnings:
	@${ECHO_MSG} "${WARNING}"
	@sleep 5

check-makefile:: show-warnings
.endif

.if defined(_PREMKINCLUDED)
DEV_ERROR+=	you cannot include bsd.port[.pre].mk twice
.endif

.if defined(DEVELOPER)
.if defined(DEV_WARNING)
show-dev-warnings:
	@${ECHO_MSG} "/!\\ ${PKGNAME}: Makefile warnings, please consider fixing /!\\"
	@${ECHO_MSG}
	@${ECHO_MSG} "${DEV_WARNING}"
	@${ECHO_MSG}
	@sleep 5
check-makefile:: show-dev-warnings
.endif

.if defined(DEV_ERROR)
show-dev-errors:
	@${ECHO_MSG} "/!\\ ${PKGNAME}: Makefile errors /!\\"
	@${ECHO_MSG}
	@${ECHO_MSG} "${DEV_ERROR}"
	@${FALSE}
check-makefile:: show-dev-errors
.endif
.endif
