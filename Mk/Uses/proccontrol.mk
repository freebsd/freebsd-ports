# Change execution parameters of port processes
#
# Feature:	proccontrol
# Usage:	USES=proccontrol
# Valid ARGS:	none
#
# Variables
#
#   PROCCONTROL_CMD     proccontrol(1) location
#   PROCCONTROL_MODE=	protmax:disable wxmap:enable

.if !defined(_INCLUDE_USES_PROCCONTROL_MK)
_INCLUDE_USES_PROCCONTROL_MK=	yes

PROCCONTROL_CMD?=	proccontrol

.  if ! empty(PROCCONTROL_MODE)
.    for mode in ${PROCCONTROL_MODE}
       PROCCONTROL_EXEC+=	${PROCCONTROL_CMD} -m ${mode:C/:.*//} -s ${mode:C/.*://}
.    endfor
.  endif

.endif
