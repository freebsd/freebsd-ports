# Provide support for Ruby releated ports.
#
# Feature:		ruby
# Usage:		USES=ruby[:args,..]
# Valid ARGS:		build, extconf, run, setup
# ARGS description:
# build			Says that ruby is required only for build time.
# extconf		Says that the port uses extconf.rb to configure.
# none			Says that no dependency is added to the port.
#			Intended to be used with lang/ruby*.
# run			Says that ruby is required only for run time.
# setup			Says that the port uses setup.rb to configure and
#			build.
#
# [variables that a user may define]
#
# RUBY_VER		- (See below)
# RUBY_DEFAULT_VER	- Set to (e.g.) "3.2" if you want to refer to "ruby32"
#			  just as "ruby".
# RUBY_ARCH		- (See below)
#
# [variables that each port can define]
#
# RUBY			- Set to full path of ruby.  If you set this, the values
#			  of the following variables are automatically obtained
#			  from the ruby executable: RUBY_VER, RUBY_VERSION,
#			  RUBY_ARCH, RUBY_LIBDIR, RUBY_ARCHLIBDIR,
#			  RUBY_SITELIBDIR, and RUBY_SITEARCHLIBDIR.
# RUBY_VER		- Set to the alternative short version of ruby in the
#			  form of `x.y' (see below for current value).
# RUBY_EXTCONF		- Set to the alternative name of extconf.rb
#			  (default: extconf.rb).
# RUBY_EXTCONF_SUBDIRS	- Set to list of subdirectories, if multiple modules
#			  are included.
# RUBY_SETUP		- Set to the alternative name of setup.rb
#			  (default: setup.rb).
#
# [variables that each port should not (re)define]
#
# RUBY_PKGNAMEPREFIX	- Common PKGNAMEPREFIX for ruby ports
#			  (default: ruby${RUBY_SUFFIX}-)
# RUBY_VERSION		- Full version of ruby without preview/beta suffix in
#			  the form of `x.y.z' (see below for current value).
# RUBY_VERSION_CODE	- Integer version of RUBY_VERSION in the form of
#			  `xyz'.
# RUBY_DISTVERSION	- DISTVERSION for the standard ruby ports (ruby,
#			  ruby-gdbm, etc.).
# RUBY_PORTVERSION	- PORTVERSION for the standard ruby ports (ruby,
#			  ruby-gdbm, etc.).
# RUBY_PORTREVISION	- PORTREVISION for the standard ruby ports.
# RUBY_PORTEPOCH	- PORTEPOCH for the standard ruby ports.
# RUBY_DISTNAME		- DISTNAME for the standard ruby ports, i.e. the
#			  basename of the ruby distribution tarball.
# RUBY_PATCHFILES	- PATCHFILES for the standard ruby ports, i.e. the
#			  basename of the ruby distribution tarball.
# MASTER_SITE_SUBDIR_RUBY	- MASTER_SITE_SUBDIR for the ruby distfiles.
#
# RUBY_SHLIBVER		- Major version of libruby (see below for current
#			  value).
# RUBY_ARCH		- Set to target architecture name.
#			  (e.g. i386-freebsd7)
# RUBY_SUFFIX		- Suffix for ruby binaries and directories
#			  (${RUBY_VER:S/.//}).
# RUBY_WITHOUT_SUFFIX	- Always ${LOCALBASE}/bin/ruby.
# RUBY_WITH_SUFFIX	- Always ${RUBY_WITHOUT_SUFFIX}${RUBY_SUFFIX}.
#
# RUBY_MODNAME		- Set to the module name (default: ${PORTNAME}).
#
# RUBY_BASE_PORT	- Port path of base ruby without PORTSDIR, without
#			  suffix except version.
# RUBY_PORT		- Port path of ruby without PORTSDIR.
#
# DEPEND_RUBY		- BUILD_DEPENDS/RUN_DEPENDS entry for ruby.
#
# RUBY_LIBDIR		- Installation path for architecture independent
#			  libraries.
# RUBY_ARCHLIBDIR	- Installation path for architecture dependent
#			  libraries.
# RUBY_SITELIBDIR	- Installation path for site architecture independent
#			  libraries.
# RUBY_SITEARCHLIBDIR	- Installation path for site architecture dependent
#			  libraries.
# RUBY_DOCDIR		- Installation path for documents.
# RUBY_EXAMPLESDIR	- Installation path for examples.
# RUBY_RIDIR		- Installation path for site architecture independent ri
#			  documents.
# RUBY_SITERIDIR	- Installation path for site architecture dependent ri
#			  documents.
# RUBY_MODDOCDIR	- Installation path for the module's documents.
# RUBY_MODEXAMPLESDIR	- Installation path for the module's examples.
#
# MAINTAINER:		ruby@FreeBSD.org

.if !defined(_INCLUDE_USES_RUBY_MK)
_INCLUDE_USES_RUBY_MK=	yes

_valid_ARGS=		build extconf none run setup

# "USES=gem" implies "USES=ruby"
.  if defined(_INCLUDE_USES_GEM_MK)
ruby_ARGS=
.  endif

# Sanity check
.  for arg in ${ruby_ARGS}
.    if empty(_valid_ARGS:M${arg})
IGNORE= Incorrect 'USES+= ruby:${ruby_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.  endfor


.  if defined(RUBY_DEFAULT_VER)
WARNING+=	"RUBY_DEFAULT_VER is defined, consider using DEFAULT_VERSIONS=ruby=${RUBY_DEFAULT_VER} instead"
.  endif

RUBY_DEFAULT_VER?=	${RUBY_DEFAULT}

RUBY_VER?=		${RUBY_DEFAULT_VER}

.  if defined(RUBY)
.    if !exists(${RUBY})
IGNORE=	cannot install: you set the variable RUBY to "${RUBY}", but it does not seem to exist.  Please specify an already installed ruby executable
.    endif

_RUBY_TEST!=		${RUBY} -e 'begin; require "rbconfig"; puts "ok" ; rescue LoadError; puts "error"; end'
.    if !empty(_RUBY_TEST) && ${_RUBY_TEST} != "ok"
IGNORE=	cannot install: you set the variable RUBY to "${RUBY}", but it failed to include rbconfig.  Please specify a properly installed ruby executable
.    endif

_RUBY_CONFIG=		${RUBY} -r rbconfig -e 'C = RbConfig::CONFIG' -e

RUBY_VERSION!=		${_RUBY_CONFIG} 'puts C["ruby_version"]'
RUBY_SUFFIX?=		# empty

RUBY_ARCH!=		${_RUBY_CONFIG} 'puts C["target"]'

_RUBY_SYSLIBDIR!=	${_RUBY_CONFIG} 'puts C["libdir"]'
_RUBY_SITEDIR!=		${_RUBY_CONFIG} 'puts C["sitedir"]'
_RUBY_VENDORDIR!=	${_RUBY_CONFIG} 'puts C["vendordir"]'
.  else
RUBY?=			${LOCALBASE}/bin/ruby${RUBY_SUFFIX}

.    if defined(RUBY_VER)
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
.      if ${RUBY_VER} == 3.2
#
# Ruby 3.2
#
RUBY_DISTVERSION=	3.2.9
RUBY_PORTREVISION=	0

.      elif ${RUBY_VER} == 3.3
#
# Ruby 3.3
#
RUBY_DISTVERSION=	3.3.9
RUBY_PORTREVISION=	0


.      elif ${RUBY_VER} == 3.4
#
# Ruby 3.4
#
RUBY_DISTVERSION=	3.4.6
RUBY_PORTREVISION=	0


.      elif ${RUBY_VER} == 3.5
#
# Ruby 3.5
#
RUBY_DISTVERSION=	3.5.0-preview1
RUBY_PORTREVISION=	0

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
.      else
#
# Other versions
#
IGNORE=	Only ruby 3,2, 3.3, 3.4 and 3.5 are supported
_INVALID_RUBY_VER=	1
.      endif
RUBY_PORTEPOCH=		1
RUBY_VERSION=	${RUBY_DISTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/}
.    endif # defined(RUBY_VER)

.    if !defined(_INVALID_RUBY_VER)

RUBY32?=		"@comment "
RUBY33?=		"@comment "
RUBY34?=		"@comment "
RUBY35?=		"@comment "

.      if defined(BROKEN_RUBY${RUBY_VER:R}${RUBY_VER:E})
.        if ${BROKEN_RUBY${RUBY_VER:R}${RUBY_VER:E}} == "yes"
BROKEN=			does not build with Ruby ${RUBY_VER}
.        else
BROKEN=			${BROKEN_RUBY${RUBY_VER:R}${RUBY_VER:E}}
.        endif
.      endif

RUBY_CONFIGURE_ARGS+=	--with-rubyhdrdir="${PREFIX}/include/ruby-${RUBY_VER}/" \
			--with-rubylibprefix="${PREFIX}/lib/ruby" \
			--docdir="${RUBY_DOCDIR}" \
			--with-soname=ruby${RUBY_SUFFIX}

CONFIGURE_TARGET?=	${ARCH}-portbld-${OPSYS:tl}${OSREL:C/\..*//}

RUBY_ARCH?=		${ARCH}-${OPSYS:tl}${OSREL:C/\..*//}

_RUBY_SYSLIBDIR?=	${PREFIX}/lib
_RUBY_SITEDIR?=		${_RUBY_SYSLIBDIR}/ruby/site_ruby
_RUBY_VENDORDIR?=	${_RUBY_SYSLIBDIR}/ruby/vendor_ruby
.    endif
.  endif
#      defined(RUBY)

.  if !defined(_INVALID_RUBY_VER)

RUBY_DEFAULT_SUFFIX?=	${RUBY_DEFAULT_VER:S/.//}

RUBY_PORTVERSION?=	${RUBY_DISTVERSION:tl:C/([a-z])[a-z]+/\1/g:C/([0-9])([a-z])/\1.\2/g:C/:(.)/\1/g:C/[^a-z0-9+]+/./g}
MASTER_SITE_SUBDIR_RUBY?=	${RUBY_VER}
RUBY_DISTNAME?=		ruby-${RUBY_DISTVERSION}

RUBY_RELVERSION_CODE?=	${RUBY_RELVERSION:S/.//g}
RUBY_VERSION_CODE?=	${RUBY_VERSION:S/.//g}
RUBY_VER=		${RUBY_VERSION:C/([[:digit:]]+\.[[:digit:]]+).*/\1/}
RUBY_SUFFIX=		${RUBY_VER:S/.//}

RUBY_WITHOUT_SUFFIX?=	${LOCALBASE}/bin/ruby
RUBY_WITH_SUFFIX?=	${RUBY_WITHOUT_SUFFIX}${RUBY_SUFFIX}

RUBY_PKGNAMEPREFIX?=	ruby${RUBY_SUFFIX}-
RUBY_SHLIBVER?=		${RUBY_VER:S/.//}

RUBY_CONFIGURE_ARGS+=	--program-prefix=""

.    if ${RUBY_VER} != ${RUBY_DEFAULT_VER}
DEPENDS_ARGS+=		RUBY_VER=${RUBY_VER}
.    endif

RUBY_CONFIGURE_ARGS+=	--program-suffix="${RUBY_SUFFIX}"

RUBY_MODNAME?=		${PORTNAME}

# Ports
RUBY_BASE_PORT?=	lang/ruby${RUBY_VER:S/.//}
RUBY_PORT?=		${RUBY_BASE_PORT}

# Depends
DEPEND_RUBY?=		${RUBY}:${RUBY_PORT}

# Directories
RUBY_LIBDIR?=		${_RUBY_SYSLIBDIR}/ruby/${RUBY_VER}
RUBY_ARCHLIBDIR?=	${RUBY_LIBDIR}/${RUBY_ARCH}
RUBY_SITELIBDIR?=	${_RUBY_SITEDIR}/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${RUBY_SITELIBDIR}/${RUBY_ARCH}
RUBY_VENDORLIBDIR?=	${_RUBY_VENDORDIR}/${RUBY_VER}
RUBY_VENDORARCHLIBDIR?=	${RUBY_VENDORLIBDIR}/${RUBY_ARCH}
RUBY_DOCDIR?=		${PREFIX}/share/doc/ruby${RUBY_SUFFIX}
RUBY_EXAMPLESDIR?=	${PREFIX}/share/examples/ruby${RUBY_SUFFIX}
RUBY_RIDIR?=		${PREFIX}/share/ri/${RUBY_VER}/system
RUBY_SITERIDIR?=	${PREFIX}/share/ri/${RUBY_VER}/site
RUBY_MODDOCDIR?=	${RUBY_DOCDIR}/${RUBY_MODNAME}
RUBY_MODEXAMPLESDIR?=	${RUBY_EXAMPLESDIR}/${RUBY_MODNAME}

# PLIST
PLIST_RUBY_DIRS=	RUBY_LIBDIR="${RUBY_LIBDIR}" \
			RUBY_ARCHLIBDIR="${RUBY_ARCHLIBDIR}" \
			RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" \
			RUBY_SITEARCHLIBDIR="${RUBY_SITEARCHLIBDIR}" \
			RUBY_VENDORLIBDIR="${RUBY_VENDORLIBDIR}" \
			RUBY_VENDORARCHLIBDIR="${RUBY_VENDORARCHLIBDIR}" \
			RUBY_MODDOCDIR="${RUBY_MODDOCDIR}" \
			RUBY_MODEXAMPLESDIR="${RUBY_MODEXAMPLESDIR}" \
			RUBY_DOCDIR="${RUBY_DOCDIR}" \
			RUBY_EXAMPLESDIR="${RUBY_EXAMPLESDIR}" \
			RUBY_RIDIR="${RUBY_RIDIR}" \
			RUBY_SITERIDIR="${RUBY_SITERIDIR}"

PLIST_SUB+=		${PLIST_RUBY_DIRS:C,DIR="(${LOCALBASE}|${PREFIX})/,DIR=",} \
			RUBY_VERSION="${RUBY_VERSION}" \
			RUBY_VER="${RUBY_VER}" \
			RUBY_SHLIBVER="${RUBY_SHLIBVER}" \
			RUBY_ARCH="${RUBY_ARCH}" \
			RUBY_SUFFIX="${RUBY_SUFFIX}" \
			RUBY_DEFAULT_SUFFIX="${RUBY_DEFAULT_SUFFIX}"

.    if ${PORT_OPTIONS:MDEBUG}
RUBY_FLAGS+=	-d
.    endif

#
# extconf.rb support
#
.    if ${ruby_ARGS:Mextconf}

RUBY_EXTCONF?=		extconf.rb
CONFIGURE_ARGS+=	--with-opt-dir="${LOCALBASE}"
CONFIGURE_ENV+=		RB_USER_INSTALL=yes

do-configure:	ruby-extconf-configure

ruby-extconf-configure:
.      if defined(RUBY_EXTCONF_SUBDIRS)
.        for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} in ${d} to configure"
	@cd ${CONFIGURE_WRKSRC}/${d}; \
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.        endfor
.      else
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} to configure"
	@cd ${CONFIGURE_WRKSRC}; \
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.      endif
.    endif

#
# setup.rb support
#
.    if ${ruby_ARGS:Msetup}
RUBY_SETUP?=		setup.rb

do-configure:	ruby-setup-configure

ruby-setup-configure:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to configure"
	@cd ${BUILD_WRKSRC}; \
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} config ${CONFIGURE_ARGS}

do-build:	ruby-setup-build

ruby-setup-build:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to build"
	@cd ${BUILD_WRKSRC}; \
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} setup

do-install:	ruby-setup-install

ruby-setup-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	@cd ${INSTALL_WRKSRC}; \
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install --prefix=${STAGEDIR}
.    endif

.    if !${ruby_ARGS:Mbuild} && !${ruby_ARGS:Mrun} && !${ruby_ARGS:Mnone}
EXTRACT_DEPENDS+=	${DEPEND_RUBY}
PATCH_DEPENDS+=		${DEPEND_RUBY}
BUILD_DEPENDS+=		${DEPEND_RUBY}
RUN_DEPENDS+=		${DEPEND_RUBY}
.    elif ${ruby_ARGS:Mbuild}
EXTRACT_DEPENDS+=	${DEPEND_RUBY}
PATCH_DEPENDS+=		${DEPEND_RUBY}
BUILD_DEPENDS+=		${DEPEND_RUBY}
.    elif ${ruby_ARGS:Mrun}
RUN_DEPENDS+=		${DEPEND_RUBY}
.    endif

.  endif # _INVALID_RUBY_VER
.endif
