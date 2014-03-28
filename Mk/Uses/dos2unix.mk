# $FreeBSD$
#
# Provide support to convert files from dos2unix
#
# DOS2UNIX_REGEX	a regular expression to match files that needs to be converted
# DOS2UNIX_FILES	list of files of glob pattern relative to ${WRKSRC}
# DOS2UNIX_GLOB		list of glob pattern find(1) will match with
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_DOS2UNIX_MK)
_INCLUDE_USES_DOS2UNIX_MK=	yes

.if !defined(DOS2UNIX_FILES) && !defined(DOS2UNIX_REGEX) && !defined(DOS2UNIX_GLOB)
_DOS2UNIX_ALL=	yes
.endif

dos2unix:
	@${ECHO_MSG} "===>   Converting DOS text files to UNIX text files"
.if defined(_DOS2UNIX_ALL)
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 ${SED} -i '' -e 's/$$//'
.else
.if defined(DOS2UNIX_FILES)
	@(cd ${WRKSRC}; \
		${ECHO_CMD} ${DOS2UNIX_FILES} | ${XARGS} ${SED} -i '' -e 's/$$//' )
.elif defined(DOS2UNIX_REGEX)
	@${FIND} -E ${WRKSRC} -type f -iregex '${DOS2UNIX_REGEX}' -print0 | \
		${XARGS} -0 ${SED} -i '' -e 's/$$//'
.else
.for f in ${DOS2UNIX_GLOB}
	@${FIND} ${WRKSRC} -type f -name '${f}' -print0 | \
		${XARGS} -0 ${SED} -i '' -e 's/$$//'
.endfor
.endif
.endif

.endif
