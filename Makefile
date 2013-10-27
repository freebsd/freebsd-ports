# $FreeBSD$
#

SUBDIR += accessibility
SUBDIR += arabic
SUBDIR += archivers
SUBDIR += astro
SUBDIR += audio
SUBDIR += benchmarks
SUBDIR += biology
SUBDIR += cad
SUBDIR += chinese
SUBDIR += comms
SUBDIR += converters
SUBDIR += databases
SUBDIR += deskutils
SUBDIR += devel
SUBDIR += dns
SUBDIR += editors
SUBDIR += emulators
SUBDIR += finance
SUBDIR += french
SUBDIR += ftp
SUBDIR += games
SUBDIR += german
SUBDIR += graphics
SUBDIR += hebrew
SUBDIR += hungarian
SUBDIR += irc
SUBDIR += japanese
SUBDIR += java
SUBDIR += korean
SUBDIR += lang
SUBDIR += mail
SUBDIR += math
SUBDIR += misc
SUBDIR += multimedia
SUBDIR += net
SUBDIR += net-im
SUBDIR += net-mgmt
SUBDIR += net-p2p
SUBDIR += news
SUBDIR += palm
SUBDIR += polish
SUBDIR += ports-mgmt
SUBDIR += portuguese
SUBDIR += print
SUBDIR += russian
SUBDIR += science
SUBDIR += security
SUBDIR += shells
SUBDIR += sysutils
SUBDIR += textproc
SUBDIR += ukrainian
SUBDIR += vietnamese
SUBDIR += www
SUBDIR += x11
SUBDIR += x11-clocks
SUBDIR += x11-drivers
SUBDIR += x11-fm
SUBDIR += x11-fonts
SUBDIR += x11-servers
SUBDIR += x11-themes
SUBDIR += x11-toolkits
SUBDIR += x11-wm

PORTSTOP=	yes

.include <bsd.port.subdir.mk>

index:
	@rm -f ${INDEXDIR}/${INDEXFILE}
	@cd ${.CURDIR} && ${MAKE} ${INDEXDIR}/${INDEXFILE}

fetchindex: ${INDEXDIR}/${INDEXFILE}.bz2
	@bunzip2 < ${INDEXDIR}/${INDEXFILE}.bz2 > ${INDEXDIR}/${INDEXFILE} && \
	chmod a+r ${INDEXDIR}/${INDEXFILE} && ${RM} -f ${INDEXDIR}/${INDEXFILE}.bz2

${INDEXDIR}/${INDEXFILE}.bz2: .PHONY
	@${FETCHINDEX} ${INDEXDIR}/${INDEXFILE}.bz2 ${MASTER_SITE_INDEX}${INDEXFILE}.bz2

MASTER_SITE_INDEX?=	http://www.FreeBSD.org/ports/
SETENV?=	/usr/bin/env
FETCHINDEX?=	${SETENV} ${FETCH_ENV} fetch -am -o
INDEX_JOBS?=	2

.if !defined(INDEX_VERBOSE)
INDEX_ECHO_MSG=		true
INDEX_ECHO_1ST=		echo -n
.else
INDEX_ECHO_MSG=		echo 1>&2
INDEX_ECHO_1ST=		echo
.endif

# /rescue/sh is statically linked and much faster to execute than the
# dynamically linked /bin/sh.  This is significant for targets like
# make index that execute the shell tens of thousands of times.
.if exists(/rescue/sh)
INDEX_SHELL=		/rescue/sh
.else
INDEX_SHELL=		/bin/sh
.endif

.if !defined(INDEX_PORTS)
INDEX_PORTS=.
.endif

.if exists(/usr/libexec/make_index)
MAKE_INDEX=	/usr/libexec/make_index /dev/stdin
.else
MAKE_INDEX=	perl ${.CURDIR}/Tools/make_index
.endif

${INDEXDIR}/${INDEXFILE}:
	@${INDEX_ECHO_1ST} "Generating ${INDEXFILE} - please wait.."; \
	if [ "${INDEX_PRISTINE}" != "" ]; then \
		export LOCALBASE=/nonexistentlocal; \
	fi; \
	tmpdir=`/usr/bin/mktemp -d -t index` || exit 1; \
	trap "rm -rf $${tmpdir}; exit 1" 1 2 3 5 10 13 15; \
	( cd ${.CURDIR}; for i in ${INDEX_PORTS}; do (cd $${i} && ${MAKE} -j${INDEX_JOBS} INDEX_TMPDIR=$${tmpdir} BUILDING_INDEX=1 \
		__MAKE_SHELL=${INDEX_SHELL} \
		ECHO_MSG="${INDEX_ECHO_MSG}" describe); done ) || \
		(rm -rf $${tmpdir} ; \
		if [ "${INDEX_QUIET}" = "" ]; then \
			echo; \
			echo "********************************************************************"; \
			echo "Before reporting this error, verify that you are running a supported"; \
			echo "version of FreeBSD (see http://www.FreeBSD.org/ports/) and that you"; \
			echo "have a complete and up-to-date ports collection.  (INDEX builds are"; \
			echo "not supported with partial or out-of-date ports collections."; \
			echo "If that is the case, then"; \
			echo "report the failure to ports@FreeBSD.org together with relevant"; \
			echo "details of your ports configuration (including FreeBSD version,"; \
			echo "your architecture, your environment, and your /etc/make.conf"; \
			echo "settings, especially compiler flags and OPTIONS_SET/UNSET settings)."; \
			echo; \
			echo "Note: the latest pre-generated version of INDEX may be fetched"; \
			echo "automatically with \"make fetchindex\"."; \
			echo "********************************************************************"; \
			echo; \
		fi; \
		exit 1); \
	cat $${tmpdir}/${INDEXFILE}.desc.* | (cd ${.CURDIR} ; ${MAKE_INDEX}) | \
		sed -e 's/  */ /g' -e 's/|  */|/g' -e 's/  *|/|/g' -e 's./..g' | \
		sort -t '|' +1 -2 | \
		sed -Ee 's../.g' -e ':a' -e 's|/[^/]+/\.\.||; ta' \
		-e 's|${.CURDIR}|/usr/ports|g' > ${INDEXDIR}/${INDEXFILE}.tmp; \
	if [ "${INDEX_PRISTINE}" != "" ]; then \
		sed -e "s,$${LOCALBASE},/usr/local," ${INDEXDIR}/${INDEXFILE}.tmp > ${INDEXDIR}/${INDEXFILE}; \
	else \
		mv ${INDEXDIR}/${INDEXFILE}.tmp ${INDEXDIR}/${INDEXFILE}; \
	fi; \
	rm -rf $${tmpdir}; \
	echo " Done."

print-index:	${INDEXDIR}/${INDEXFILE}
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nE-deps:\t%s\nP-deps:\t%s\nF-deps:\t%s\nWWW:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$11, $$12, $$13, $$10); }' < ${INDEXDIR}/${INDEXFILE}

GIT?= git
SVN?= svn
PORTSNAP?= portsnap
PORTSNAP_FLAGS?= -p ${.CURDIR}
.if !target(update)
update:
.if exists(${.CURDIR}/.svn)
	@echo "--------------------------------------------------------------"
	@echo ">>> Updating ${.CURDIR} using Subversion"
	@echo "--------------------------------------------------------------"
	cd ${.CURDIR}; ${SVN} update
.elif exists(${.CURDIR}/.git)
	@echo "--------------------------------------------------------------"
	@echo ">>> Updating ${.CURDIR} from git+svn repository"
	@echo "--------------------------------------------------------------"
	cd ${.CURDIR}; ${GIT} svn rebase
.else
	@echo "--------------------------------------------------------------"
	@echo ">>> Running ${PORTSNAP}"
	@echo "--------------------------------------------------------------"
.if !exists(${PORTSDIR}/.portsnap.INDEX)
	@echo "Error: 'make update' uses portsnap(8) by default and"
	@echo "needs ${PORTSDIR} to be created by portsnap on its first run."
	@echo "Please run 'portsnap fetch extract' first."
.else
	@${PORTSNAP} ${PORTSNAP_FLAGS} fetch
	@${PORTSNAP} ${PORTSNAP_FLAGS} update
.endif
.endif
.endif
