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
_USES_stage+=	810:elfctl-post-stage
elfctl-post-stage:
.    for feat in ${ELF_FEATURES}
	# XXX: need to save into temp variable,
	# XXX: perms from first match if used as featurelist:bin/smth-*
	${STAT} -f "%p" ${STAGEDIR}/${PREFIX}/${feat:C/.*://} | ${CUT} -c 3- | \
		${TAIL} -n 1 > ${WRKDIR}/.elfctlmode
	${CHMOD} 0755 ${STAGEDIR}/${PREFIX}/${feat:C/.*://}
	${ELFCTL} -i -e ${feat:C/:.*//} ${STAGEDIR}/${PREFIX}/${feat:C/.*://}
	${CHMOD} `${CAT} ${WRKDIR}/.elfctlmode` \
		${STAGEDIR}/${PREFIX}/${feat:C/.*://}
.    endfor
.  endif

.endif
