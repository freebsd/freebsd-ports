# Provide support for easy porting of Electron applications that are distributed
# in binary form.
#
# Feature:	electronfix
# Usage:	USES=electronfix:version
#
# An example usage might be:
#         USES=   electronfix:24
#
# Variables, which can be set by the port:
#
#  ELECTRONFIX_SYMLINK_FILES	List of files to be symlinked from Electron distribution.
#
#  ELECTRONFIX_MAIN_EXECUTABLE	File name of the main executable to be replaced
#				with the original Electron binary.

.if !defined(_INCLUDE_USES_ELECTRONFIX_MK)
_INCLUDE_USES_ELECTRONFIX_MK=	yes

.  if empty(electronfix_ARGS)
.    error USES=electronfix requires a version argument
.  endif

_ELECTRON_MAKEFILE_VERSION=	${.CURDIR}/../../devel/electron${electronfix_ARGS}/Makefile.version

.  if !exists(${_ELECTRON_MAKEFILE_VERSION})
.    warning Unknown Electron version in USES=electronfix:${electronfix_ARGS}
.  endif

BUILD_DEPENDS+=	electron${electronfix_ARGS}:devel/electron${electronfix_ARGS}
RUN_DEPENDS+=	electron${electronfix_ARGS}:devel/electron${electronfix_ARGS}

ELECTRONFIX_SYMLINK_FILES?= \
			chromedriver \
			libEGL.so \
			libGLESv2.so \
			libffmpeg.so \
			libvk_swiftshader.so \
			libvulkan.so \
			resources.pak \
			snapshot_blob.bin \
			v8_context_snapshot.bin

_USES_install=		701:electronfix-post-install

.  if defined(DEVELOPER)
_USES_stage=		995:electronfix-stage-qa
.  endif

electronfix-post-install:
	${RM} ${STAGEDIR}${DATADIR}/chrome-sandbox
	${RM} ${STAGEDIR}${DATADIR}/libvulkan.so.1
.  for f in ${ELECTRONFIX_SYMLINK_FILES}
	${RM} ${STAGEDIR}${DATADIR}/${f}
	${LN} -s ${LOCALBASE}/share/electron${electronfix_ARGS}/${f} ${STAGEDIR}${DATADIR}/${f}
.  endfor
.  ifdef ELECTRONFIX_MAIN_EXECUTABLE
# We have to copy the electron binary instead of symlinking
	${CP} ${LOCALBASE}/share/electron${electronfix_ARGS}/electron ${STAGEDIR}${DATADIR}/${ELECTRONFIX_MAIN_EXECUTABLE}
.  endif

electronfix-stage-qa:
	@${ECHO_CMD} "====> Checking for non-FreeBSD ELF binaries"
	@${FIND} ${STAGEDIR}${DATADIR} -type f -exec brandelf {} ';' 2> /dev/null | grep -v "'FreeBSD' (9)"

.endif
