#
# $FreeBSD$
#

STAGEDIR?=	${WRKDIR}/stage
DESTDIRNAME?=	DESTDIR

.if defined(_DESTDIR_VIA_ENV)
MAKE_ENV+=	${DESTDIRNAME}=${STAGEDIR}
.else
MAKE_ARGS+=	${DESTDIRNAME}=${STAGEDIR}
.endif
QA_ENV+=	STAGEDIR=${STAGEDIR} \
		PREFIX=${PREFIX} \
		LOCALBASE=${LOCALBASE} \
		USESDESKTOPFILEUTILS=${USES:Mdesktop-file-utils} \
		USESSHAREDMIMEINFO=${USES:Mshared-mime-info} \
		"STRIP=${STRIP}"
CO_ENV+=	STAGEDIR=${STAGEDIR} \
		PREFIX=${PREFIX} \
		LOCALBASE=${LOCALBASE} \
		WRKDIR=${WRKDIR} \
		WRKSRC=${WRKSRC} \
		MTREE_FILE=${MTREE_FILE} \
		TMPPLIST=${TMPPLIST} \
		DATADIR=${DATADIR} \
		DOCSDIR=${DOCSDIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

.if !target(stage-dir)
stage-dir:
	@${MKDIR} ${STAGEDIR}${PREFIX}
.if !defined(NO_MTREE)
	@${MTREE_CMD} ${MTREE_ARGS} ${STAGEDIR}${PREFIX} > /dev/null
.endif
.endif

# Compress all manpage not already compressed which are not hardlinks
# Find all manpages which are not compressed and are hadlinks, and only get the list of inodes concerned, for each of them compress the first one found and recreate the hardlinks for the others
# Fixes all dead symlinks left by the previous round
.if !target(compress-man)
compress-man:
	@${ECHO_MSG} "====> Compressing man pages (compress-man)"
	@mdirs= ; \
	for dir in ${MANDIRS:S/^/${STAGEDIR}/} ; do \
		[ -d $$dir ] && mdirs="$$mdirs $$dir" ;\
	done ; \
	for dir in $$mdirs; do \
		${FIND} $$dir -type f \! -name "*.gz" -links 1 -exec ${GZIP_CMD} {} \; ; \
		${FIND} $$dir -type f \! -name "*.gz" \! -links 1 -exec ${STAT} -f '%i' {} \; | \
			${SORT} -u | while read inode ; do \
				unset ref ; \
				for f in $$(${FIND} $$dir -type f -inum $${inode} -print); do \
					if [ -z $$ref ]; then \
						ref=$${f}.gz ; \
						${GZIP_CMD} $${f} ; \
						continue ; \
					fi ; \
					${RM} -f $${f} ; \
					(cd $${f%/*}; ${LN} -f $${ref##*/} $${f##*/}.gz) ; \
				done ; \
			done ; \
		${FIND} $$dir -type l \! -name "*.gz" | while read link ; do \
				dest=$$(readlink $$link) ; \
				rm -f $$link ; \
				(cd $${link%/*} ; ${LN} -sf $${dest##*/}.gz $${link##*/}.gz) ;\
		done; \
	done
.endif

.if !target(makeplist)
makeplist: stage
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist
.endif

.if !target(check-orphans)
check-orphans: stage
	@${ECHO_MSG} "====> Items missing from pkg-plist (check-orphans)"
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh orphans
.endif

.if !target(stage-qa)
stage-qa:
	@${ECHO_MSG} "====> Running Q/A tests (stage-qa)"
	@${SETENV} ${QA_ENV} ${SH} ${SCRIPTSDIR}/qa.sh
.endif
