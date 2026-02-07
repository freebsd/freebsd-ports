# handle terminfo.db and *.terminfo files used by ncurses
#
# Feature:	terminfo
# Usage:	USES=terminfo
# Valid ARGS:	does not require args

.if !defined(_INCLUDE_USES_TERMINFO_MK)
_INCLUDE_USES_TERMINFO_MK=	yes

.  if !empty(terminfo_ARGS)
IGNORE=	USES=terminfo does not require args
.  endif

PLIST_FILES+=	@terminfo

.endif
