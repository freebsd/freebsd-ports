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
# [variables that each port can define]
#
# RUBY_VER		- Set to the alternative short version of ruby (see below for current value).
# USE_RUBY		- Says that the port uses ruby for building and running.
# RUBY_NO_BUILD_DEPENDS	- Says that the port should not build-depend on ruby.
# RUBY_NO_RUN_DEPENDS	- Says that the port should not run-depend on ruby.
# USE_LIBRUBY		- Says that the port uses libruby.
# USE_RUBY_EXTCONF	- Says that the port uses extconf.rb to configure.  Implies USE_RUBY.
# RUBY_EXTCONF		- Set to the alternative name of extconf.rb (default: extconf.rb).
# RUBY_EXTCONF_SUBDIRS	- Set to list of subdirectories, if multiple modules are included.
# USE_RUBY_SETUP	- Says that the port uses setup.rb to configure and build.  Implies USE_RUBY_AMSTD.
# RUBY_SETUP		- Set to the alternative name of setup.rb (default: setup.rb).
# USE_RUBY_AMSTD	- Says that the port uses amstd for building and running.
# USE_RUBY_RD		- Says that the port uses rd to generate documents.
# RUBY_SHEBANG_FILES	- Specify the files which shebang lines you want to fix.
#
# [variables that each port should not define]
#
# RUBY_PKGNAMEPREFIX	- Common PKGNAMEPREFIX for ruby ports (default: ruby${RUBY_SUFFIX}-)
# RUBY_VERSION		- Full version of ruby (see below for current value).
# RUBY_SHLIBVER		- Major version of libruby (see below for current value).
# RUBY_ARCH		- Directory name of architecture dependent libraries.
# RUBY_SUFFIX		- Suffix for ruby binaries and directories.
# _RUBY_SUFFIX		- String to be used as RUBY_SUFFIX.  Always ${RUBY_VER:S/.//}.
# RUBY_NAME		- Ruby's name with trailing suffix.
#
# RUBY			- Set to full path of ruby.
# RUBY_RD		- Set to full path of rd.
#
# RUBY_PORT		- Set to port path of ruby without PORTSDIR.
# RUBY_AMSTD_PORT	- Set to port path of ruby-amstd without PORTSDIR.
# RUBY_RD_PORT		- Set to port path of rd without PORTSDIR.
#
# RUBY_LIB_DEPENDS	- Set to LIB_DEPENDS entry for libruby.
# RUBY_DEPENDS		- Set to BUILD_DEPENDS/RUN_DEPENDS entry for ruby.
# RUBY_AMSTD_DEPENDS	- Set to BUILD_DEPENDS/RUN_DEPENDS entry for ruby-amstd.
# RUBY_RD2_DEPENDS	- Set to BUILD_DEPENDS entry for rd.
#
# RUBY_LIBDIR		- Installation path for architecture independent libraries.
# RUBY_ARCHLIBDIR	- Installation path for architecture dependent libraries.
# RUBY_SITELIBDIR	- Installation path for site architecture independent libraries.
# RUBY_SITEARCHLIBDIR	- Installation path for site architecture dependent libraries.
# RUBY_DOCDIR		- Installation path for documents.
# RUBY_EXAMPLESDIR	- Installation path for examples.
#

RUBY_VER?=		1.6
_RUBY_SUFFIX=		${RUBY_VER:S/.//}

.if ${RUBY_VER} == 1.4
RUBY_VERSION?=		1.4.6
RUBY_SUFFIX?=		${_RUBY_SUFFIX}
.else
RUBY_VERSION?=		1.6.1
RUBY_SUFFIX?=		# empty
.endif

RUBY_PKGNAMEPREFIX?=	ruby${RUBY_SUFFIX}-	# could be rb${RUBY_SUFFIX}-
RUBY_VER=      	${RUBY_VERSION:R}
RUBY_SHLIBVER?=		${_RUBY_SUFFIX}
RUBY_ARCH?=     	${ARCH}-freebsd${OSREL}
RUBY_NAME?=		ruby${RUBY_SUFFIX}

# Commands
RUBY?=          	${LOCALBASE}/bin/${RUBY_NAME}
RUBY_RD?=		${LOCALBASE}/bin/rd2

# Ports
RUBY_PORT?=		lang/ruby${RUBY_SUFFIX}
RUBY_AMSTD_PORT?=	devel/ruby-amstd
RUBY_RD_PORT?=		textproc/ruby-rdtool

# Depends
RUBY_LIB_DEPENDS?=	${RUBY_NAME}.${RUBY_SHLIBVER}:${PORTSDIR}/${RUBY_PORT}
RUBY_DEPENDS?=		${RUBY}:${PORTSDIR}/${RUBY_PORT}
RUBY_AMSTD_DEPENDS?=	${RUBY_SITELIBDIR}/amstd/info.rb:${PORTSDIR}/${RUBY_AMSTD_PORT}
RUBY_RD2_DEPENDS?=	${RUBY_RD}:${PORTSDIR}/${RUBY_RD_PORT}

# Directories
RUBY_LIBDIR?=		${LOCALBASE}/lib/ruby/${RUBY_VER}
RUBY_ARCHLIBDIR?=	${RUBY_LIBDIR}/${RUBY_ARCH}
RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${RUBY_SITELIBDIR}/${RUBY_ARCH}
RUBY_DOCDIR?=		${LOCALBASE}/share/doc/${RUBY_NAME}
RUBY_EXAMPLESDIR?=	${LOCALBASE}/share/examples/${RUBY_NAME}

# PLIST
PLIST_RUBY_DIRS=	RUBY_LIBDIR="${RUBY_LIBDIR}" \
			RUBY_ARCHLIBDIR="${RUBY_ARCHLIBDIR}" \
			RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" \
			RUBY_SITEARCHLIBDIR="${RUBY_SITEARCHLIBDIR}" \
			RUBY_DOCDIR="${RUBY_DOCDIR}" \
			RUBY_EXAMPLESDIR="${RUBY_EXAMPLESDIR}"

PLIST_SUB+=		RUBY_VERSION="${RUBY_VERSION}" \
			RUBY_VER="${RUBY_VER}" \
			RUBY_SHLIBVER="${RUBY_SHLIBVER}" \
			RUBY_ARCH="${RUBY_ARCH}" \
			_RUBY_SUFFIX="${_RUBY_SUFFIX}" \
			RUBY_SUFFIX="${RUBY_SUFFIX}" \
			RUBY_NAME="${RUBY_NAME}" \
			${PLIST_RUBY_DIRS:S,DIR="${LOCALBASE}/,DIR=",}

# fix shebang lines
.if defined(RUBY_SHEBANG_FILES) && !empty(RUBY_SHEBANG_FILES)
USE_RUBY=		yes

post-patch:	ruby-shebang-patch

ruby-shebang-patch:
	@for f in ${RUBY_SHEBANG_FILES}; do \
	${ECHO_MSG} "===>  Fixing the #! line of $$f"; \
	${RUBY} -i -pe '$$. == 1 and sub /^#!\s*\S*(\benv\s+)?\bruby/, "#!${RUBY}"' $$f; \
	done
.endif

# extconf.rb
.if defined(USE_RUBY_EXTCONF)
USE_RUBY=		yes

RUBY_EXTCONF?=		extconf.rb
CONFIGURE_ARGS+=	--with-opt-dir="${LOCALBASE}"

do-configure:	ruby-extconf-configure

ruby-extconf-configure:
.if defined(RUBY_EXTCONF_SUBDIRS)
.for d in ${RUBY_EXTCONF_SUBDIRS}
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} in ${d} to configure"
	@cd ${WRKSRC}/${d}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.endfor
.else
	@${ECHO_MSG} "===>  Running ${RUBY_EXTCONF} to configure"
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_EXTCONF} ${CONFIGURE_ARGS}
.endif
.endif

# setup.rb
.if defined(USE_RUBY_SETUP)
USE_RUBY_AMSTD=		yes

RUBY_SETUP?=		setup.rb

do-configure:	ruby-setup-configure

ruby-setup-configure:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to configure"
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_SETUP} config ${CONFIGURE_ARGS}

do-build:	ruby-setup-build

ruby-setup-build:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to build"
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_SETUP} setup

do-install:	ruby-setup-install

ruby-setup-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_SETUP} install
.endif

.if defined(USE_LIBRUBY)
LIB_DEPENDS+=		${RUBY_LIB_DEPENDS}
.endif

.if defined(USE_RUBY)
.if !defined(RUBY_NO_BUILD_DEPENDS)
BUILD_DEPENDS+=		${RUBY_DEPENDS}
.endif
.if !defined(RUBY_NO_RUN_DEPENDS)
RUN_DEPENDS+=		${RUBY_DEPENDS}
.endif
.endif

.if defined(USE_RUBY_AMSTD)
BUILD_DEPENDS+=		${RUBY_AMSTD_DEPENDS}
RUN_DEPENDS+=		${RUBY_AMSTD_DEPENDS}
.endif

.if defined(USE_RUBY_RD) && !defined(NOPORTDOCS)
BUILD_DEPENDS+=		${RUBY_RD2_DEPENDS}
.endif

.endif
