# $FreeBSD$
#
# Add __FreeSBD__ definition to CFLAGS
# Used by DPorts when masquerading as FreeBSD allows port to build without
# additional patches
#
# Feature:      alias
# Usage:        USES=alias or USES=alias:ARGS
# Valid ARGS:   8, 9 (default), 10, 11
#
# MAINTAINER:	marino@FreeBSD.org

.if !defined(_INCLUDE_USES_ALIAS_MK)
_INCLUDE_USES_ALIAS_MK=    yes

.if ${OPSYS} != FreeBSD

.if empty(alias_ARGS)
CFLAGS+=	-D__FreeBSD__=9
.else
.  if ${alias_ARGS} == 8 || ${alias_ARGS} == 10 \
   || ${alias_ARGS} == 9 || ${alias_ARGS} == 11
CFLAGS+=	-D__FreeBSD__=${alias_ARGS}
.  else
IGNORE=	invalid MAJOR RELEASE argument (${alias_ARGS}) for USES=alias
.  endif
.endif

.endif # OPSYS != FreeBSD

.endif
