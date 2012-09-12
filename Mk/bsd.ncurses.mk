# $FreeBSD$
#
# the user/port can now set this options in the makefiles.
#
# WITH_NCURSES_BASE=yes	- Use the version in the base system.
# WITH_NCURSES_PORT=yes	- Use the port, even if base is up to date
#
# USE_NCURSES_RPATH=yes	- Pass RFLAGS options in CFLAGS,
#			  needed for ports who don't use LDFLAGS
#
# Overrideable defaults:
#
# NCURSES_SHLIBVER=	5
# NCURSES_PORT=		devel/ncurses
#
# The makefile sets this variables:
# NCURSESBASE		- "/usr" or ${LOCALBASE}
# NCURSESLIB		- path to the libs
# NCURSESINC		- path to the matching includes
# NCURSESRPATH		- rpath for dynamic linker
#
# MAKE_ENV		- extended with the variables above
# CONFIGURE_ENV		- extended with LDFLAGS
# BUILD_DEPENDS		- are added if needed
# RUN_DEPENDS		- are added if needed

#	if no preference was set, check for an installed base version
#	but give an installed port preference over it.
.if	!defined(WITH_NCURSES_BASE) && \
	!defined(WITH_NCURSES_PORT) && \
	!exists(${DESTDIR}/${LOCALBASE}/lib/libncurses.so) && \
	exists(${DESTDIR}/usr/include/ncurses.h)
WITH_NCURSES_BASE=yes
.endif

.if defined(WITH_NCURSES_BASE)
NCURSESBASE=		/usr
NCURSESINC=		${NCURSESBASE}/include

.if exists(${LOCALBASE}/lib/libncurses.so)
check-depends::
	@${ECHO_CMD} "Dependency error: this port wants the ncurses library from the FreeBSD"
	@${ECHO_CMD} "base system. You can't build against it, while a newer"
	@${ECHO_CMD} "version is installed by a port."
	@${ECHO_CMD} "Please deinstall the port or undefine WITH_NCURSES_BASE."
	@${FALSE}
.endif

NCURSESRPATH=		/usr/lib:${LOCALBASE}/lib

.else

NCURSESBASE=		${LOCALBASE}
NCURSESINC=		${NCURSESBASE}/include/ncurses
.if	!defined(NCURSES_PORT) && \
	exists(${DESTDIR}/${LOCALBASE}/lib/libncurses.so)
# find installed port and use it for dependency
PKG_DBDIR?=		${DESTDIR}/var/db/pkg
.if !defined(NCURSES_INSTALLED)
.if defined(WITH_PKGNG)
.if defined(DESTDIR)
PKGARGS=	-c ${DESTDIR}
.else
PKGARGS=
.endif
NCURSES_INSTALLED!=	${PKG_BIN} ${PKGARGS} which -qo ${LOCALBASE}/lib/libncurses.so || :
.else
NCURSES_INSTALLED!=	find "${PKG_DBDIR}/" -type f -name "+CONTENTS" -print0 | \
			xargs -0 grep -l "^lib/libncurses.so." | \
			while read contents; do \
				ncursesprefix=`grep "^@cwd " "$${contents}" | ${HEAD} -n 1`; \
				if test "$${ncursesprefix}" = "@cwd ${LOCALBASE}" ; then \
					echo "$${contents}"; break; fi; done
.endif
.endif
.if defined(NCURSES_INSTALLED) && ${NCURSES_INSTALLED} != ""
.if defined(WITH_PKGNG)
NCURSES_PORT=		${NCURSES_INSTALLED}
NCURSES_SHLIBFILE!=	${PKG_INFO} -ql ${NCURSES_INSTALLED} | grep -m 1 "^`pkg query "%p" ${NCURSES_INSTALLED}`/lib/libncurses.so."
.else
NCURSES_PORT!=		grep "^@comment ORIGIN:" "${NCURSES_INSTALLED}" | ${CUT} -d : -f 2
NCURSES_SHLIBFILE!=	grep -m 1 "^lib/libncurses.so." "${NCURSES_INSTALLED}"
.endif
NCURSES_SHLIBVER?=	${NCURSES_SHLIBFILE:E}
.else
# PKG_DBDIR was not found, default
NCURSES_PORT?=		devel/ncurses
NCURSES_SHLIBVER?=	5
.endif
.endif
NCURSES_PORT?=		devel/ncurses
NCURSES_SHLIBVER?=	5

BUILD_DEPENDS+=		${LOCALBASE}/lib/libncurses.so.${NCURSES_SHLIBVER}:${PORTSDIR}/${NCURSES_PORT}
RUN_DEPENDS+=		${LOCALBASE}/lib/libncurses.so.${NCURSES_SHLIBVER}:${PORTSDIR}/${NCURSES_PORT}
NCURSESRPATH=		${LOCALBASE}/lib

.endif

NCURSESLIB=		${NCURSESBASE}/lib

.if defined(USE_NCURSES_RPATH)
CFLAGS+=		-Wl,-rpath,${NCURSESRPATH}
.endif
NCURSES_LDFLAGS+=	-rpath=${NCURSESRPATH}

.if defined(LDFLAGS)
LDFLAGS+=${NCURSES_LDFLAGS}
.else
LDFLAGS+=${NCURSES_LDFLAGS}
.endif

