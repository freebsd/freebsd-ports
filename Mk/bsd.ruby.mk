#
# bsd.ruby.mk - Utility definitions for Ruby related ports.
#
# Created by: Akinori MUSHA <knu@FreeBSD.org>
#
# $FreeBSD$
#

.if !defined(Ruby_Include)

Ruby_Include=			bsd.ruby.mk
Ruby_Include_MAINTAINER=	knu@FreeBSD.org

#
# [variables that a user may define]
#
# RUBY_VER		- (See below)
# RUBY_DEFAULT_VER	- Set to (e.g.) "1.7" if you want to refer to "ruby17" just as "ruby".
# RUBY_ARCH		- (See below)
#
# [variables that each port can define]
#
# RUBY			- Set to full path of ruby.  If you set this, the values of the following variables are automatically obtained from the ruby executable: RUBY_VER, RUBY_VERSION, RUBY_NAME, RUBY_ARCH, RUBY_LIBDIR, RUBY_ARCHLIBDIR, RUBY_SITELIBDIR, and RUBY_SITEARCHLIBDIR.
# RUBY_VER		- Set to the alternative short version of ruby in the form of `x.y' (see below for current value).
# USE_RUBY		- Says that the port uses ruby for building and running.
# RUBY_NO_BUILD_DEPENDS	- Says that the port should not build-depend on ruby.
# RUBY_NO_RUN_DEPENDS	- Says that the port should not run-depend on ruby.
# USE_LIBRUBY		- Says that the port uses libruby.
# RUBY_WITH_PTHREAD	- Says that the port needs to be compiled with pthread.
# USE_RUBY_EXTCONF	- Says that the port uses extconf.rb to configure.  Implies USE_RUBY.
# RUBY_EXTCONF		- Set to the alternative name of extconf.rb (default: extconf.rb).
# RUBY_EXTCONF_SUBDIRS	- Set to list of subdirectories, if multiple modules are included.
# USE_RUBY_SETUP	- Says that the port uses setup.rb to configure and build.
# RUBY_SETUP		- Set to the alternative name of setup.rb (default: setup.rb).
# USE_RUBY_AMSTD	- Says that the port uses amstd for building and running.
# USE_RUBY_RD		- Says that the port uses rd to generate documents.
# RUBY_REQUIRE		- Set to a Ruby expression to evaluate before building the port.  The constant "Ruby" is set to the integer version number of ruby, and the result of the expression will be set to RUBY_PROVIDED, which is left undefined if the result is nil, false or a zero-length string.  Implies USE_RUBY.
# RUBY_SHEBANG_FILES	- Specify the files which shebang lines you want to fix.
#
# [variables that each port should not (re)define]
#
# RUBY_PKGNAMEPREFIX	- Common PKGNAMEPREFIX for ruby ports (default: ruby${RUBY_SUFFIX}-)
# RUBY_VERSION		- Full version of ruby without preview/beta suffix in the form of `x.y.z' (see below for current value).
# RUBY_VERSION_CODE	- Full integer version of ruby without preview/beta suffix in the form of `xyz'.
# RUBY_PORTVERSION	- PORTVERSION for the standard ruby ports (ruby, ruby-gdbm, etc.).
# RUBY_DISTNAME		- DISTNAME for the standard ruby ports, i.e. the basename of the ruby distribution tarball.
# RUBY_DISTVERSION	- The version number part of RUBY_DISTNAME.
# RUBY_PATCHFILES	- PATCHFILES for the standard ruby ports, i.e. the basename of the ruby distribution tarball.
# RUBY_WRKSRC		- WRKSRC for the ruby port.
#
# RUBY_SHLIBVER		- Major version of libruby (see below for current value).
# RUBY_ARCH		- Set to target architecture name. (e.g. i386-freebsdelf4.3)
# RUBY_R		- Extra suffix only defined when RUBY_WITH_PTHREAD is defined. (_r)
# RUBY_SUFFIX		- Suffix for ruby binaries and directories.  ${RUBY_R} or ${_RUBY_SUFFIX}.
# _RUBY_SUFFIX		- String to be used as RUBY_SUFFIX.  Always ${RUBY_VER:S/.//}${RUBY_R}.
# RUBY_WITHOUT_SUFFIX	- Always ${LOCALBASE}/bin/ruby.
# RUBY_WITH_SUFFIX	- Always ${RUBY_WITHOUT_SUFFIX}${_RUBY_SUFFIX}.
# RUBY_NAME		- Ruby's name with trailing suffix.
#
# RUBY_RD		- Full path of rd executable.
#
# RUBY_PORT		- Port path of ruby without PORTSDIR.
# RUBY_AMSTD_PORT	- Port path of ruby-amstd without PORTSDIR.
# RUBY_RD_PORT		- Port path of rd without PORTSDIR.
#
# DEPEND_LIBRUBY	- LIB_DEPENDS entry for libruby.
# DEPEND_RUBY		- BUILD_DEPENDS/RUN_DEPENDS entry for ruby.
# DEPEND_RUBY_AMSTD	- BUILD_DEPENDS/RUN_DEPENDS entry for ruby-amstd.
# DEPEND_RUBY_RD2	- BUILD_DEPENDS entry for rd.
#
# RUBY_LIBDIR		- Installation path for architecture independent libraries.
# RUBY_ARCHLIBDIR	- Installation path for architecture dependent libraries.
# RUBY_SITELIBDIR	- Installation path for site architecture independent libraries.
# RUBY_SITEARCHLIBDIR	- Installation path for site architecture dependent libraries.
# RUBY_DOCDIR		- Installation path for documents.
# RUBY_EXAMPLESDIR	- Installation path for examples.
# RUBY_ELISPDIR		- Installation path for emacs lisp files.
#

.if defined(RUBY)
.if !exists(${RUBY})
.error You set the variable RUBY to "${RUBY}", but it does not seem to exist.  Please specify an already installed ruby executable.
.endif

_RUBY_TEST!=		${RUBY} -e 'begin; require "rbconfig"; rescue LoadError; puts "error"; end'
.if !empty(_RUBY_TEST)
.error You set the variable RUBY to "${RUBY}", but it failed to include rbconfig.  Please specify a properly installed ruby executable.
.endif

_RUBY_CONFIG=		${RUBY} -r rbconfig -e 'C = Config::CONFIG' -e

RUBY_VERSION!=		${_RUBY_CONFIG} 'puts VERSION'
RUBY_SUFFIX?=		# empty

RUBY_ARCH!=		${_RUBY_CONFIG} 'puts C["target"]'
RUBY_NAME!=		${_RUBY_CONFIG} 'puts C["ruby_install_name"]'

_RUBY_SYSLIBDIR!=	${_RUBY_CONFIG} 'puts C["libdir"]'
_RUBY_SITEDIR!=		${_RUBY_CONFIG} 'puts C["sitedir"]'
.else
RUBY?=			${LOCALBASE}/bin/${RUBY_NAME}

.if defined(RUBY_VER) && ${RUBY_VER} == 1.7
RUBY_VERSION?=		1.7.2
RUBY_PORT?=		lang/ruby${RUBY_R}-devel
RUBY_DISTVERSION?=	${RUBY_VERSION:R}-2001.12.25
RUBY_DISTPATCHVERSION?=	${RUBY_DISTVERSION}-2002.01.26
RUBY_PORTVERSION?=	${RUBY_VERSION}.2002.01.26
.else
RUBY_VERSION?=		1.6.6
RUBY_DISTVERSION?=	${RUBY_VERSION}
RUBY_DISTPATCHVERSION?=	${RUBY_DISTVERSION}-2002.01.26
RUBY_PORTVERSION?=	${RUBY_VERSION}.2002.01.26
.endif

RUBY_DEFAULT_VER?=	1.6
RUBY_DEFAULT_SUFFIX?=	${RUBY_DEFAULT_VER:S/.//}

RUBY_DISTVERSION?=	${RUBY_VERSION}
RUBY_PORTVERSION?=	${RUBY_VERSION}
.if defined(RUBY_DISTPATCHVERSION) && !empty(RUBY_DISTPATCHVERSION)
RUBY_PATCHFILES?=	ruby-${RUBY_DISTPATCHVERSION}.diff.bz2
.endif
RUBY_DISTNAME?=		ruby-${RUBY_DISTVERSION}

RUBY_WRKSRC?=		${WRKDIR}/${RUBY_DISTNAME}

RUBY_ARCH?=		${ARCH}-freebsd${OSREL:C/\..*//}${RUBY_R}
RUBY_NAME?=		ruby${RUBY_SUFFIX}

_RUBY_SYSLIBDIR?=	${LOCALBASE}/lib
_RUBY_SITEDIR?=		${_RUBY_SYSLIBDIR}/ruby/site_ruby
.endif

RUBY_VERSION_CODE?=	${RUBY_VERSION:S/.//g}
RUBY_VER=		${RUBY_VERSION:R}
_RUBY_SUFFIX=		${RUBY_VER:S/.//}${RUBY_R}

.if ${RUBY_VER} == ${RUBY_DEFAULT_VER}
RUBY_SUFFIX?=		${RUBY_R}
.else
RUBY_SUFFIX?=		${_RUBY_SUFFIX}
.endif

RUBY_WITHOUT_SUFFIX?=	${LOCALBASE}/bin/ruby
RUBY_WITH_SUFFIX?=	${RUBY_WITHOUT_SUFFIX}${_RUBY_SUFFIX}

RUBY_PKGNAMEPREFIX?=	ruby${RUBY_SUFFIX}-	# could be rb${RUBY_SUFFIX}-
RUBY_SHLIBVER?=		${RUBY_VER:S/.//}

CONFIGURE_TARGET?=	${RUBY_ARCH}

.if defined(RUBY_WITH_PTHREAD)
RUBY_CONFIGURE_ARGS+=	--with-libc_r=yes
RUBY_R=			_r
.else
RUBY_CONFIGURE_ARGS+=	--with-libc_r=no
RUBY_R=			# none
.endif

.if !empty(RUBY_SUFFIX)
RUBY_CONFIGURE_ARGS+=	--program-suffix="${RUBY_SUFFIX}"
.endif

# Commands
RUBY_RD?=		${LOCALBASE}/bin/rd2

# Ports
RUBY_PORT?=		lang/ruby${RUBY_SUFFIX}
RUBY_AMSTD_PORT?=	devel/ruby-amstd
RUBY_RD_PORT?=		textproc/ruby-rdtool

# Depends
DEPEND_LIBRUBY?=	${RUBY_NAME}.${RUBY_SHLIBVER}:${PORTSDIR}/${RUBY_PORT}
DEPEND_RUBY?=		${RUBY}:${PORTSDIR}/${RUBY_PORT}
DEPEND_RUBY_AMSTD?=	${RUBY_SITELIBDIR}/amstd/info.rb:${PORTSDIR}/${RUBY_AMSTD_PORT}
DEPEND_RUBY_RD2?=	${RUBY_RD}:${PORTSDIR}/${RUBY_RD_PORT}

# Directories
RUBY_LIBDIR?=		${_RUBY_SYSLIBDIR}/ruby/${RUBY_VER}
RUBY_ARCHLIBDIR?=	${RUBY_LIBDIR}/${RUBY_ARCH}
RUBY_SITELIBDIR?=	${_RUBY_SITEDIR}/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${RUBY_SITELIBDIR}/${RUBY_ARCH}
RUBY_DOCDIR?=		${LOCALBASE}/share/doc/${RUBY_NAME}
RUBY_EXAMPLESDIR?=	${LOCALBASE}/share/examples/${RUBY_NAME}
RUBY_ELISPDIR?=		${_RUBY_SYSLIBDIR}/ruby/elisp

# PLIST
PLIST_RUBY_DIRS=	RUBY_LIBDIR="${RUBY_LIBDIR}" \
			RUBY_ARCHLIBDIR="${RUBY_ARCHLIBDIR}" \
			RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" \
			RUBY_SITEARCHLIBDIR="${RUBY_SITEARCHLIBDIR}" \
			RUBY_DOCDIR="${RUBY_DOCDIR}" \
			RUBY_EXAMPLESDIR="${RUBY_EXAMPLESDIR}" \
			RUBY_ELISPDIR="${RUBY_ELISPDIR}"

PLIST_SUB+=		RUBY_VERSION="${RUBY_VERSION}" \
			RUBY_VER="${RUBY_VER}" \
			RUBY_SHLIBVER="${RUBY_SHLIBVER}" \
			RUBY_ARCH="${RUBY_ARCH}" \
			_RUBY_SUFFIX="${_RUBY_SUFFIX}" \
			RUBY_SUFFIX="${RUBY_SUFFIX}" \
			RUBY_NAME="${RUBY_NAME}" \
			RUBY_R="${RUBY_R}" \
			RUBY_DEFAULT_SUFFIX="${RUBY_DEFAULT_SUFFIX}" \
			${PLIST_RUBY_DIRS:S,DIR="${LOCALBASE}/,DIR=",}

# require check
.if defined(RUBY_REQUIRE)
USE_RUBY=		yes

.if exists(${RUBY})
RUBY_PROVIDED!=		${RUBY} -e '\
	Ruby = ${RUBY_VERSION_CODE}; \
	value = begin; ${RUBY_REQUIRE}; end and puts value'
.else
RUBY_PROVIDED=		"should be"	# the latest version is going to be installed
.endif

.if empty(RUBY_PROVIDED)
.undef RUBY_PROVIDED
.endif
.endif

# fix shebang lines
.if defined(RUBY_SHEBANG_FILES) && !empty(RUBY_SHEBANG_FILES)
USE_RUBY=		yes

post-patch:	ruby-shebang-patch

ruby-shebang-patch:
	@for f in ${RUBY_SHEBANG_FILES}; do \
	${ECHO_MSG} "===>  Fixing the #! line of $$f"; \
	${RUBY} ${RUBY_FLAGS} -i -p \
			-e 'if $$. == 1; ' \
			-e ' if /^#!/; ' \
			-e '  sub /^#!\s*\S*(\benv\s+)?\bruby/, "#!${RUBY}";' \
			-e ' else;' \
			-e '  $$_ = "#!${RUBY}\n" + $$_;' \
			-e ' end;' \
			-e 'end' \
			$$f; \
	done
.endif

.if defined(DEBUG)
RUBY_FLAGS+=	-d
.endif

# extconf.rb
.if defined(USE_RUBY_EXTCONF)
USE_RUBY=		yes

RUBY_EXTCONF?=		extconf.rb
CONFIGURE_ARGS+=	--with-opt-dir="${LOCALBASE}" \
			--with-pthread-cflags="${PTHREAD_CFLAGS}" \
			--with-pthread-libs="${PTHREAD_LIBS}"

do-configure:	ruby-extconf-configure

ruby-extconf-configure:
.if defined(RUBY_EXTCONF_SUBDIRS)
.for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} in ${d} to configure"
.if defined(RUBY_WITH_PTHREAD)
	cd ${WRKSRC}/${d}; \
	${RUBY} ${RUBY_FLAGS} -i -pe '~ /\brequire\s+[\047"]mkmf[\047"]/ \
	and $$_ += %Q|\
		$$libs.sub!(/-lc\\b/, "")\n \
		$$libs += " " + with_config("pthread-libs") + " "\n \
		$$CFLAGS += " " + with_config("pthread-cflags") + " "\n \
	|' ${RUBY_EXTCONF}
.endif
	@cd ${WRKSRC}/${d}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.endfor
.else
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} to configure"
.if defined(RUBY_WITH_PTHREAD)
	cd ${WRKSRC}; \
	${RUBY} ${RUBY_FLAGS} -i -pe '~ /\brequire\s+[\047"]mkmf[\047"]/ \
	and $$_ += %Q|\
		$$libs.sub!(/-lc\\b/, "")\n \
		$$libs += " " + with_config("pthread-libs") + " "\n \
		$$CFLAGS += " " + with_config("pthread-cflags") + " "\n \
	|' ${RUBY_EXTCONF}
.endif
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.endif
.endif

# setup.rb
.if defined(USE_RUBY_SETUP)
RUBY_SETUP?=		setup.rb

do-configure:	ruby-setup-configure

ruby-setup-configure:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to configure"
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} config ${CONFIGURE_ARGS}

do-build:	ruby-setup-build

ruby-setup-build:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to build"
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} setup

do-install:	ruby-setup-install

ruby-setup-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install
.endif

.if defined(USE_LIBRUBY)
LIB_DEPENDS+=		${DEPEND_LIBRUBY}
.endif

.if defined(USE_RUBY)
.if !defined(RUBY_NO_BUILD_DEPENDS)
BUILD_DEPENDS+=		${DEPEND_RUBY}
.endif
.if !defined(RUBY_NO_RUN_DEPENDS)
RUN_DEPENDS+=		${DEPEND_RUBY}
.endif
.endif

.if defined(USE_RUBY_AMSTD)
BUILD_DEPENDS+=		${DEPEND_RUBY_AMSTD}
RUN_DEPENDS+=		${DEPEND_RUBY_AMSTD}
.endif

.if defined(USE_RUBY_RD) && !defined(NOPORTDOCS)
BUILD_DEPENDS+=		${DEPEND_RUBY_RD2}
.endif

.endif
