#
# $FreeBSD$
#

STAGEDIR?=	${WRKDIR}/stage
DESTDIRNAME?=	DESTDIR

MAKE_ARGS+=	${DESTDIRNAME}=${STAGEDIR}
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
.if defined(USE_LINUX) && ${PREFIX} != ${LINUXBASE}
	@${MKDIR} ${STAGEDIR}${LINUXBASE}
	@${MTREE_CMD} ${MTREE_LINUX_ARGS} ${STAGEDIR}${LINUXBASE} > /dev/null
.endif
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

.if !target(add-plist-info)
add-plist-info:
.for i in ${INFO}
.if !defined(WITH_PKGNG)
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec install-info --quiet --delete %D/${INFO_PATH}/$i.info %D/${INFO_PATH}/dir" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec [ \`info -d %D/${INFO_PATH}  --output - 2>/dev/null | grep -c '^*'\` -eq 1 ] && rm -f %D/${INFO_PATH}/dir || :"\
		>> ${TMPPLIST}
	@${LS} ${STAGEDIR}${PREFIX}/${INFO_PATH}/$i.info* | ${SED} -e s:${STAGEDIR}${PREFIX}/::g >> ${TMPPLIST}
	@${ECHO_CMD} "@exec install-info --quiet %D/${INFO_PATH}/$i.info %D/${INFO_PATH}/dir" \
		>> ${TMPPLIST}
.else
	@${LS} ${STAGEDIR}${PREFIX}/${INFO_PATH}/$i.info* | ${SED} -e s:${STAGEDIR}${PREFIX}/:@info\ :g >> ${TMPPLIST}
.endif
.endfor
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
