# Extract 7-Zip archives
#
# Feature:	7z
# Usage:	USES=7z or USES=7z:ARGS
# Valid ARGS:	7-zip, partial
#
# 7-zip		Extract using 7zz(1) instead of bsdtar(1)
# partial	Extract only files tagged with :7z or in EXTRACT_ONLY_7z
#
# MAINTAINER:	jbeich@FreeBSD.org

.if !defined(_INCLUDE_USES_7Z_MK)
_INCLUDE_USES_7Z_MK=	yes

7-ZIP_CMD?=		7zz
7-ZIP_BEFORE_ARGS?=	x -bd -y -o${7-ZIP_WRKDIR} >/dev/null
7-ZIP_AFTER_ARGS?=	# empty
7-ZIP_WRKDIR?=		${EXTRACT_WRKDIR}

.if !empty(7z_ARGS:N7-zip:Npartial)
IGNORE=			USES=7z has invalid arguments: ${7z_ARGS:N7-zip:Npartial}
.endif

.if ${7z_ARGS:M7-zip}
EXTRACT_DEPENDS+=	${7-ZIP_CMD}:archivers/7-zip
.endif

.if ! ${7z_ARGS:Mpartial}
EXTRACT_SUFX?=		.7z
.endif

.if ${7z_ARGS:M7-zip} && ! ${7z_ARGS:Mpartial}
EXTRACT_CMD?=		${7-ZIP_CMD}
EXTRACT_BEFORE_ARGS?=	${7-ZIP_BEFORE_ARGS}
EXTRACT_AFTER_ARGS?=	${7-ZIP_AFTER_ARGS}
.endif

.if ! ${7z_ARGS:M7-zip} && ${7z_ARGS:Mpartial} && defined(EXTRACT_ONLY)
EXTRACT_ONLY+=		${EXTRACT_ONLY_7z}
.endif

.if ${7z_ARGS:M7-zip} && ${7z_ARGS:Mpartial}
EXTRACT_ONLY?=		${DISTFILES:N*\:*7z*:C/:.*//}
EXTRACT_ONLY_7z?=	${DISTFILES:M*\:*7z*:C/:.*//}

_USES_extract+=		520:do-7-zip-extract
do-7-zip-extract:
	@for file in ${EXTRACT_ONLY_7z}; do \
		if ! ${7-ZIP_CMD} ${7-ZIP_BEFORE_ARGS} \
			${_DISTDIR}/$$file ${7-ZIP_AFTER_ARGS}; \
		then \
			exit 1; \
		fi; \
	done
.endif

.endif
