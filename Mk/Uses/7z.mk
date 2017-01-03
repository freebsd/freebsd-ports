# $FreeBSD$
#
# Extract 7-Zip archives
#
# Feature:	7z
# Usage:	USES=7z or USES=7z:ARGS
# Valid ARGS:	p7zip, partial
#
# p7zip		Extract using 7z(1) instead of bsdtar(1)
# partial	Extract only files tagged with :7z or in EXTRACT_ONLY_7z
#
# MAINTAINER:	jbeich@FreeBSD.org

.if !defined(_INCLUDE_USES_7Z_MK)
_INCLUDE_USES_7Z_MK=	yes

P7ZIP_CMD?=		7z
P7ZIP_BEFORE_ARGS?=	x -bd -y -o${P7ZIP_WRKDIR} >/dev/null
P7ZIP_AFTER_ARGS?=	# empty
P7ZIP_WRKDIR?=		${EXTRACT_WRKDIR}

.if !empty(7z_ARGS:Np7zip:Npartial)
IGNORE=			USES=7z has invalid arguments: ${7z_ARGS:Np7zip:Npartial}
.endif

.if ${7z_ARGS:Mp7zip}
EXTRACT_DEPENDS+=	${P7ZIP_CMD}:archivers/p7zip
.endif

.if ! ${7z_ARGS:Mpartial}
EXTRACT_SUFX?=		.7z
.endif

.if ${7z_ARGS:Mp7zip} && ! ${7z_ARGS:Mpartial}
EXTRACT_CMD?=		${P7ZIP_CMD}
EXTRACT_BEFORE_ARGS?=	${P7ZIP_BEFORE_ARGS}
EXTRACT_AFTER_ARGS?=	${P7ZIP_AFTER_ARGS}
.endif

.if ! ${7z_ARGS:Mp7zip} && ${7z_ARGS:Mpartial} && defined(EXTRACT_ONLY)
EXTRACT_ONLY+=		${EXTRACT_ONLY_7z}
.endif

.if ${7z_ARGS:Mp7zip} && ${7z_ARGS:Mpartial}
EXTRACT_ONLY?=		${DISTFILES:N*\:*7z*:C/:.*//}
EXTRACT_ONLY_7z?=	${DISTFILES:M*\:*7z*:C/:.*//}

_USES_extract+=		520:do-p7zip-extract
do-p7zip-extract:
	@for file in ${EXTRACT_ONLY_7z}; do \
		if ! ${P7ZIP_CMD} ${P7ZIP_BEFORE_ARGS} \
			${_DISTDIR}/$$file ${P7ZIP_AFTER_ARGS}; \
		then \
			exit 1; \
		fi; \
	done
.endif

.endif
