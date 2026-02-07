# Set ELF binary feature control notes
#
# Feature:	elfctl
# Usage:	USES=elfctl or USES=elfctl:ARGS
# Valid ARGS:	build (default, implicit), stage
#
# Files listed in ELF_FEATURES are relative to:
#   - ${BUILD_WRKSRC} when the `build` argument is supplied
#   - ${STAGEDIR} when the `stage` argument is supplied.
#
# Variables:
#
# ELF_FEATURES=	featurelist:path/to/file1 \
#		featurelist:path/to/file2
#

.if !defined(_INCLUDE_USES_ELFCTL_MK)
_INCLUDE_USES_ELFCTL_MK=	yes

.  if empty(elfctl_ARGS)
elfctl_ARGS=	build
.  endif

.  if ${elfctl_ARGS} == "build"
_ELFCTL_TOPDIR=	${BUILD_WRKSRC}
.  elif ${elfctl_ARGS} == "stage"
_ELFCTL_TOPDIR=	${STAGEDIR}
.  else
IGNORE=	USES=elfctl - invalid args: [${elfctl_ARGS}] specified
.  endif

.  if !empty(ELF_FEATURES)
_USES_${elfctl_ARGS}+=	720:elfctl-post-${elfctl_ARGS}
elfctl-post-${elfctl_ARGS}:
.    for feat in ${ELF_FEATURES}
	${ELFCTL} -i -e ${feat:C/:.*//} ${_ELFCTL_TOPDIR}/${feat:C/.*://}
.    endfor
.  endif

.endif
