# LTO Support
#
# This file enforces Link Time Optimization for ports.
# In order to use it, add WITH_LTO=yes to your /etc/make.conf.

.if !defined(_LTO_MK_INCLUDED)
_LTO_MK_INCLUDED=	yes
LTO_Include_MAINTAINER=	pkubaj@FreeBSD.org

.  if !defined(LTO_UNSAFE) || defined(LTO_DISABLE_CHECK)
.    if "${ARCH}" == "riscv64" && !defined(LTO_DISABLE_CHECK)
       DEV_WARNING+=	"LTO is currently broken on riscv64, to override set LTO_DISABLE_CHECK=yes"
.    elif defined(_INCLUDE_USES_CARGO_MK)
   CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO="true" \
		CARGO_PROFILE_RELEASE_PANIC="abort" \
		CARGO_PROFILE_RELEASE_CODEGEN_UNITS=1
.    elif defined(_INCLUDE_USES_MESON_MK)
   MESON_ARGS+=	-Db_lto=true
.    elif defined(_INCLUDE_USES_CABAL_MK)
   CABAL_LTO_ARGS=	--ghc-options=-split-sections \
			--gcc-options="-fdata-sections -ffunction-sections" \
			--ld-options=-Wl,--gc-sections,--build-id,--icf=all
.    else
# Overridable as a user may want to use -flto
   LTO_FLAGS?=	-flto=thin
   CFLAGS+=	${LTO_FLAGS}
   CXXFLAGS+=	${LTO_FLAGS}
   LDFLAGS+=	${LTO_FLAGS}
.    endif
.  else
.    if defined(_INCLUDE_USES_CARGO_MK)
   RUSTFLAGS+=	-C lto=no
.    endif
.  endif
.endif
