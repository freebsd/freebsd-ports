# Change an ELF binary's feature control note
#
# Feature:	elfctl
# Usage:	USES=elfctl
# Valid ARGS:	none
#
# Variables
#
#   ELF_FEATURES=	featurelist:path/to/file1 \
#			featurelist:path/to/file1 \
			featurelist:path/to/file2
#
# The file paths listed in ELF_FEATURES are relative to ${BUILD_WRKSRC}.
#

.if !defined(_INCLUDE_USES_ELFCTL_MK)
_INCLUDE_USES_ELFCTL_MK=	yes

.  if ! empty(ELF_FEATURES)
_USES_build+=	720:elfctl-post-build
elfctl-post-build:
.    for feat in ${ELF_FEATURES}
	${ELFCTL} -i -e ${feat:C/:.*//} ${BUILD_WRKSRC}/${feat:C/.*://}
.    endfor
.  endif

.endif
