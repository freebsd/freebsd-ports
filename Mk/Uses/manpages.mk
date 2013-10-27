# $FreeBSD$
#
# Provide support for manpages
#
# MAINTAINER: dinoex@FreeBSD.org
#
# Feature:              manpages
# Usage:                USES=manpages or USES=manpages:ARGS
# Valid ARGS:           install
#			will install the manpages from MANSRC
#
#
# MAN<sect>     - A list of manpages, categorized by section.  For
#                 example, if your port has "man/man1/foo.1" and
#                 "man/mann/bar.n", set "MAN1=foo.1" and "MANN=bar.n".
#                 The available sections chars are "123456789LN".
# MAN<sect>_<lang>
#               - If your port does not install all man pages for all
#                 languages in MANLANG, language specific pages for
#                 a language can be specified with this. For example,
#                 if the port installs foo.1 in English, Japanese, and
#                 German, bar.1 in English only, and baz.3 in German
#                 only, set
#                   MANLANG=    "" de ja
#                   MAN1=       foo.1
#                   MAN1_EN=    bar.1
#                   MAN3_DE=    baz.3
# MANPREFIX     - The directory prefix for ${MAN<sect>} and ${MLINKS}.
#                 Default: ${PREFIX}
# MAN<sect>PREFIX
#               - If manual pages of some sections install in different
#                 locations than others, use these.
#                 Default: ${MANPREFIX}
# MANSRC        - The directory where the manpages are copied from
#                 during install.
#                 Default: ${WRKSRC}
#
#
# NO_INSTALL_MANPAGES
#               - If set, this port doesn't want to install any manpages.
#                 Default: not set, i.e. manpages are installed by default.
#

.if !defined(_INCLUDE_USES_MANPAGES_MK)
_INCLUDE_USES_MANPAGES_MK=	yes

MANSRC?=	${WRKSRC}
#MANPREFIX?=	${PREFIX}
#
#MANDIRS+=	${MANPREFIX}/man
#.for sect in 1 2 3 4 5 6 7 8 9 L N
#MAN${sect}PREFIX?=	${MANPREFIX}
#.endfor

MANLANG?=	""  # english only by default

#MANEXT=	.gz

#.for manlang in ${MANLANG:S%^%man/%:S%^man/""$%man%}
#
#.for sect in 1 2 3 4 5 6 7 8 9 L N
## MAN${sect} is for man pages installed for all languages in MANLANG for a given
## section.
#.if defined(MAN${sect})
#_MANPAGES+=	${MAN${sect}:S%^%${MAN${sect}PREFIX}/${manlang}/man${sect:L}/%}
#.endif
#
## Language specific MAN${sect} variables are for man pages installed in that
## language, but not necessarily all languages in MANLANG.
#.if defined(MAN${sect}_${manlang:S%^man/%%:U})
#_MANPAGES+=	${MAN${sect}_${manlang:S%^man/%%:U}:S%^%${MAN${sect}PREFIX}/${manlang}/man${sect:L}/%}
#.endif
#
#.endfor
#
#.endfor
#
## Special case for English, since it is defined with "" in MANLANG rather than
## a language name and does not have man pages installed in a lang subdirectory 
## of MAN${sect}PREFIX.
#.for sect in 1 2 3 4 5 6 7 8 9 L N
#.if defined(MAN${sect}_EN)
#_MANPAGES+=	${MAN${sect}_EN:S%^%${MAN${sect}PREFIX}/man/man${sect:L}/%}
#.endif
#.endfor

#__MANPAGES:=	${_MANPAGES:S%^${PREFIX}/%%:S%$%.gz%}

.if !defined(NO_INSTALL_MANPAGES)
PLIST_FILES+=	${__MANPAGES}
.endif

.if defined(manpages_ARGS)
.if ${manpages_ARGS} == "install"

install-all-manpages:

.if !defined(NO_INSTALL_MANPAGES)
.for manlang in ${MANLANG:S%^%man/%:S%^man/""$%man%}

.for sect in 1 2 3 4 5 6 7 8 9 L N
# MAN${sect} is for man pages installed for all languages in MANLANG for a given
# section.
.if defined(MAN${sect})
.for i in ${MAN${sect}}
	${INSTALL_MAN} ${MANSRC}/${i} \
	${STAGEDIR}${MAN${sect}PREFIX}/${manlang}/man${sect:L}/
.endfor
.endif

.endfor

.endfor
.endif

.endif
.endif

.endif

