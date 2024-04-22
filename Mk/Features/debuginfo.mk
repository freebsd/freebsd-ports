# DEBUGINFO Support
#
# Add WITH_DEBUGINFO=yes into make.conf:
# - If set, the port will be compiled in the release mode but with debugging
#   info generated. The debugging info is then extracted from binaries and put
#   into a separate subpackage called debuginfo.
# - If used in conjunction with WITH_DEBUG the port will be compiled in the
#   debug mode.

.if !defined(_DEBUGINFO_MK_INCLUDED)
_DEBUGINFO_MK_INCLUDED=		yes
DEBUGINFO_Include_MAINTAINER=	portmgr@FreeBSD.org

# We need to do everything that Features/debug.mk does, but without setting
# WITH_DEBUG to prevent build systems from building in the complete debug mode.
# instead let them detect WITH_DEBUGINFO and build what meson calls "debugoptimized"
# and CMake calls "RelWithDebInfo".
.  if !defined(WITH_DEBUG)
.    include "debug.mk"
.  endif

SUBPACKAGES+=		debuginfo
DESCR.debuginfo=	${WRKDIR}/descr.debuginfo
DEBUGINFO_EXTRACT_ENV=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} STAGEDIR=${STAGEDIR} \
			TMPPLIST=${TMPPLIST} PREPEND_SUBPACKAGE_PREFIX=yes

_FEATURES_stage=	751:debuginfo-extract

debuginfo-extract:
	@${ECHO_CMD} "Debugging symbols for the ${PKGNAME} package" > ${DESCR.debuginfo}
	@${ECHO_CMD} "====> Extracting debugging symbols from binaries"
	@${SETENV} ${DEBUGINFO_EXTRACT_ENV} ${SH} ${SCRIPTSDIR}/generate-symbols.sh

.endif
