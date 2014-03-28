# -*- tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#
# Make files or directories 'unique', by adding a prefix or suffix.
#
# Feature:		uniquefiles
# Usage:		USES=uniquefiles or USES=uniquefiles:ARGS
# Valid ARGS:	dirs
#
# dirs:			The port needs a prefix (and only a prefix) based on
#				UNIQUE_PREFIX for the standard directories
#					DOCSDIR, EXAMPLESDIR, DATADIR, WWWDIR, ETCDIR
#
# Variables for ports:
#
# UNIQUE_PREFIX			- The prefix to be used for directories and files.
#						  Default: ${PKGNAMEPREFIX}.
# UNIQUE_PREFIX_FILES	- A list of files that need to be prefixed.
#						  Default: empty
# UNIQUE_SUFFIX			- The suffix to be used for files.
#						  Default: ${PKGNAMESUFFIX}.
# UNIQUE_SUFFIX_FILES	- A list of files that need to be suffixed.
#						  Default: empty
#
# Variables for the ports framework, but NOT individual ports:
#
# UNIQUE_DEFAULT_LINKS	- When set to "yes", symlinks of the original
#						  filenames are also created pointing to their
#						  UNIQUE_* counterparts.
#						  This is useful for supporting multiple logical
#						  instances from a single physical port, but where
#						  you want to mark only *one* of those instances to
#						  provide original filenames.
#
#						  category/py-foo, installed as:
#
#							py27-foo for Python 2.7 (DEFAULT_VERSION)
#							py33-foo for Python 3.3
#
#						  Results in:
#
#							py27-foo
#								bin/foo-2.7             (UNIQUE_SUFFIX)
#								bin/foo -> bin/foo-2.7  (symlinked original filename)
#							py33-foo creates:
#								bin/foo-3.3             (UNIQUE_SUFFIX)
#
#						  Default: no
#
# UNIQUE_FIND_PREFIX_FILES	- A shell command to be executed to find files for
#						  	  the specific port. This has to return a
#							  list of files to be iterated over.
#							  Default: empty
#
# UNIQUE_FIND_SUFFIX_FILES	- A shell command to be executed to find files for
#						  	  the specific port. This has to return a
#							  list of files to be iterated over.
#							  Default: empty
#
# NOTE:	multiple logical instances are not supported by pkg and the original
# pkg_tools at the moment.
#
# MAINTAINER:	portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_UNIQUEFILES_MK)
_INCLUDE_USES_UNIQUEFILES_MK=	yes

.if defined(NO_STAGE)
BROKEN=		uniquefiles USES can only be used for stage-safe ports
.endif

.if !defined(uniquefiles_ARGS)
uniquefiles_ARGS=	#empty
.endif

UNIQUE_PREFIX?=		${PKGNAMEPREFIX}
UNIQUE_SUFFIX?=		${PKGNAMESUFFIX}
UNIQUE_PREFIX_FILES?=		# empty
UNIQUE_SUFFIX_FILES?=		# empty

.if ${uniquefiles_ARGS:Mdirs}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUE_PREFIX}${PORTNAME}
EXAMPLESDIR=${PREFIX}/share/examples/${UNIQUE_PREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${UNIQUE_PREFIX}${PORTNAME}
WWWDIR=		${PREFIX}/www/${UNIQUE_PREFIX}${PORTNAME}
ETCDIR=		${PREFIX}/etc/${UNIQUE_PREFIX}${PORTNAME}
.endif

UNIQUE_DEFAULT_LINKS?=		no
UNIQUE_FIND_PREFIX_FILES?=	# empty
UNIQUE_FIND_SUFFIX_FILES?=	# empty

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_UNIQUEFILES_POST_MK)
_INCLUDE_USES_UNIQUEFILES_POST_MK=     yes

_UNIQUEPKGLIST=		${WRKDIR}/.PLIST.uniquefiles

.if ${UNIQUE_DEFAULT_LINKS} == yes
_DO_CONDITIONAL_SYMLINK=	\
	if [ ! -e ${STAGEDIR}${PREFIX}/$${fname} -a ! -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
		${ECHO_MSG} "  $${newf} --> @$${fname}"; \
		${LN} -s ${PREFIX}/$${newf} ${STAGEDIR}${PREFIX}/$${fname}; \
		${ECHO_CMD} LINKED:$${newf}:$${fname} >> ${_UNIQUEPKGLIST}; \
	fi
.else
# We are not symlinking the renamed binary.
_DO_CONDITIONAL_SYMLINK=	${DO_NADA}
.endif

move-uniquefiles:
.if ${UNIQUE_PREFIX_FILES} || ${UNIQUE_FIND_PREFIX_FILES}
	@${ECHO_MSG} "===> Moving prefixed files around";
.endif
.for entry in ${UNIQUE_PREFIX_FILES}
	@fname=${entry}; \
	if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
		newf=$${fname%/*}/${UNIQUE_PREFIX}$${fname##*/} ; \
		${ECHO_MSG} "  $${fname} --> $${newf}" ; \
		${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
		${ECHO_CMD} MOVED:$${fname}:$${newf} >> ${_UNIQUEPKGLIST}; \
		${_DO_CONDITIONAL_SYMLINK}; \
	else \
		${ECHO_MSG} "Makefile error: UNIQUE (prefix): $${fname} not found"; \
		${FALSE}; \
	fi;
.endfor
.if ${UNIQUE_FIND_PREFIX_FILES}
	@for fname in `${UNIQUE_FIND_PREFIX_FILES}`; do \
		if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
			newf=$${fname%/*}/${UNIQUE_PREFIX}$${fname##*/} ; \
			${ECHO_MSG} "  $${fname} --> $${newf}" ; \
			${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
			${ECHO_CMD} MOVED:$${fname}:$${newf} >> ${_UNIQUEPKGLIST}; \
			${_DO_CONDITIONAL_SYMLINK}; \
		else \
			${ECHO_MSG} "Makefile error: UNIQUE (prefix): $${fname} not found"; \
			${FALSE}; \
		fi; \
	done;
.endif

.if ${UNIQUE_SUFFIX_FILES} || ${UNIQUE_FIND_SUFFIX_FILES}
	@${ECHO_MSG} "===> Moving suffixed files around";
.endif
.for entry in ${UNIQUE_SUFFIX_FILES}
	@fname=${entry}; \
	if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
		newf=$${fname%/*}/$${fname##*/}${UNIQUE_SUFFIX}; \
		${ECHO_MSG} "  $${fname} --> $${newf}"; \
		${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
		${ECHO_CMD} MOVED:$${fname}:$${newf} >> ${_UNIQUEPKGLIST}; \
		${_DO_CONDITIONAL_SYMLINK}; \
	else \
		${ECHO_MSG} "Makefile error: UNIQUE (suffix): $${fname} not found"; \
		${FALSE}; \
	fi;
.endfor
.if ${UNIQUE_FIND_SUFFIX_FILES}
	@for fname in `${UNIQUE_FIND_SUFFIX_FILES}`; do \
		if [ -e ${STAGEDIR}${PREFIX}/$${fname} -o -L ${STAGEDIR}${PREFIX}/$${fname} ]; then \
			newf=$${fname%/*}/$${fname##*/}${UNIQUE_SUFFIX}; \
			${ECHO_MSG} "  $${fname} --> $${newf}"; \
			${MV} ${STAGEDIR}${PREFIX}/$${fname} ${STAGEDIR}${PREFIX}/$${newf}; \
			${ECHO_CMD} MOVED:$${fname}:$${newf} >> ${_UNIQUEPKGLIST}; \
			${_DO_CONDITIONAL_SYMLINK}; \
		else \
			${ECHO_MSG} "Makefile error: UNIQUE (suffix): $${fname} not found"; \
			${FALSE}; \
		fi; \
	done;
.endif

# Using .if exists(${_UNIQUEPKGPLIST} below instead of the sh test
# does not work in poudriere. It works fine on the CLI, though...
move-uniquefiles-plist:
	@if [ -e ${_UNIQUEPKGLIST} ]; then \
		orgIFS=$$IFS; IFS=":"; while read command entry newentry; do \
			IFS=$$orgIFS; \
			case $${command} in \
			MOVED) \
				${REINPLACE_CMD} -e "s|^$${entry}$$|$${newentry}|" ${TMPPLIST}; \
				;; \
			LINKED) \
				${AWK} '$$0 ~ pe { print; print ne ;next }1' \
					pe="$${entry}" ne="$${newentry}" \
					${TMPPLIST} > ${TMPPLIST}.uniquefilestmp; \
				${MV} ${TMPPLIST}.uniquefilestmp ${TMPPLIST}; \
				;; \
			*) ;; \
			esac; \
			IFS=":"; \
		done < ${_UNIQUEPKGLIST}; \
	fi

.endif # defined(_POSTMKINCLUDED)
.endif # _INCLUDE_USES_UNIQUEFILES_MK
