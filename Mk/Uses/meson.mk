# Provide support for Meson based projects
#
# Feature:		meson
# Usage:		USES=meson
# Valid ARGS:		muon
#
# muon			use muon instead of meson, intended for bootstrapping
#			dependencies that python uses
#
# The following files are bundled in source tar files.
# meson.build		- Instructions for meson like autoconf configure,
#			there is no changeable parts in the file.
# meson_options.txt	- All the options meson understands
#
# Variables for ports:
# MESON_ARGS		- Arguments passed to meson
#			format: -Denable_foo=true
# MESON_BUILD_DIR	- Path to the build directory relative to ${WRKSRC}
#			Default: _build
#
# MAINTAINER: desktop@FreeBSD.org

.if !defined(_INCLUDE_USES_MESON_MK)
_INCLUDE_USES_MESON_MK=	yes

_valid_ARGS=		muon

# Sanity check
.  for _arg in ${meson_ARGS}
.    if empty(_valid_ARGS:M${_arg})
IGNORE=	'USES+= meson:${meson_ARGS}' usage: argument [${_arg}] is not recognized
.    endif
.  endfor

.  if !empty(meson_ARGS:Mmuon)
BUILD_DEPENDS+=	muon:devel/muon
.  else
BUILD_DEPENDS+=	meson:devel/meson
.  endif

# meson uses ninja
.include "${USESDIR}/ninja.mk"

# meson might have issues with non-unicode locales
USE_LOCALE?=	en_US.UTF-8

# Enable muon's meson compatibility mode
.  if !empty(meson_ARGS:Mmuon)
CONFIGURE_ARGS+=	meson
.  endif

CONFIGURE_ARGS+=	--prefix ${PREFIX} \
			--localstatedir /var \
			--infodir ${INFO_PATH}

# Enable all optional features to make builds deterministic. Consumers can
# expose those as port OPTIONS_* or explicitly pass -D<option>=disabled
CONFIGURE_ARGS+=	--auto-features=enabled

# Temporarily disable bytecode due to embedding STAGEDIR
CONFIGURE_ARGS+=	-Dpython.bytecompile=-1

# Disable color output.  Meson forces it on by default, Ninja
# strips it before it goes to the log, but Samurai does not, so we
# might end up with ANSI escape sequences in the logs.
CONFIGURE_ARGS+=	-Db_colorout=never

# meson has it own strip mechanic
INSTALL_TARGET=		install

# should we have strip separate from WITH_DEBUG?
.  if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--buildtype debug
.  elif defined(WITH_DEBUGINFO)
CONFIGURE_ARGS+=	--buildtype debugoptimized
.  else
CONFIGURE_ARGS+=	--buildtype release \
			--optimization plain \
			--strip
.  endif

.  for _bool in true false enabled disabled
.    if defined(MESON_${_bool:tu})
.      for _meson_arg in ${MESON_${_bool:tu}}
MESON_ARGS+=		-D${_meson_arg}=${_bool}
.      endfor
.    endif
.  endfor

HAS_CONFIGURE=		yes
.  if !empty(meson_ARGS:Mmuon)
CONFIGURE_CMD=		muon
.  else
CONFIGURE_CMD=		meson
.  endif

# Pull in manual set settings and from options
CONFIGURE_ARGS+=	${MESON_ARGS}

BUILD_WRKSRC=		${WRKSRC}/${MESON_BUILD_DIR}

INSTALL_WRKSRC=		${WRKSRC}/${MESON_BUILD_DIR}

TEST_ENV+=		MESON_TESTTHREADS=${MAKE_JOBS_NUMBER}
TEST_WRKSRC=		${WRKSRC}/${MESON_BUILD_DIR}
TEST_TARGET=		test

MESON_BUILD_DIR?=	_build

CONFIGURE_LOG=		${MESON_BUILD_DIR}/meson-logs/meson-log.txt

# Add meson build dir at the end.
CONFIGURE_ARGS+=	${MESON_BUILD_DIR}

.endif #!defined(_INCLUDE_USES_MESON_MK)
