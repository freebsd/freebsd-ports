# $FreeBSD$
#

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
SUBDIR += mbone
SUBDIR += misc
SUBDIR += multimedia
SUBDIR += net
SUBDIR += news
SUBDIR += palm
SUBDIR += picobsd
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
SUBDIR += x11-fm
SUBDIR += x11-fonts
SUBDIR += x11-servers
SUBDIR += x11-toolkits
SUBDIR += x11-wm

PORTSTOP=	yes

.include <bsd.port.subdir.mk>

index:
	@rm -f ${.CURDIR}/${INDEXFILE}
	@cd ${.CURDIR} && make ${.CURDIR}/${INDEXFILE}

${.CURDIR}/${INDEXFILE}:
	@echo -n "Generating ${INDEXFILE} - please wait.."; \
	export LOCALBASE=/nonexistentlocal; \
	export X11BASE=/nonexistentx; \
	cd ${.CURDIR} && make describe ECHO_MSG="echo > /dev/null" | \
		perl ${.CURDIR}/Tools/make_index | \
	sed -e 's/  */ /g' -e 's/|  */|/g' -e 's/  *|/|/g' -e "s,${LOCALBASE},/usr/local," -e "s,${X11BASE},/usr/X11R6," > ${INDEXFILE}
.if !defined(INDEX_NOSORT)
	@sed -e 's./..g' ${.CURDIR}/${INDEXFILE} | \
		sort -t '|' +1 -2 | \
		sed -e 's../.g' > ${.CURDIR}/${INDEXFILE}.tmp; \
	mv -f ${.CURDIR}/${INDEXFILE}.tmp ${.CURDIR}/${INDEXFILE}
.endif
	@echo " Done."

print-index:	${.CURDIR}/${INDEXFILE}
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9); }' < ${.CURDIR}/${INDEXFILE}

parallel: ${.CURDIR}/${INDEXFILE}
.if !defined(branch)
	@echo "The parallel target requires a branch parameter,"
	@echo "e.g.: \"make parallel branch=X\""
	@false
.endif
.for dir in ${SUBDIR}
	@echo "all: ${dir}-all"
.endfor
	@awk -F '|' '{me=$$1; here=$$2; bdep=$$8; rdep=$$9; split(here, tmp, "/"); if (bdep != "") { gsub("$$", ".tgz", bdep); gsub(" ", ".tgz ", bdep); } if (rdep != "") { gsub("$$", ".tgz", rdep); gsub(" ", ".tgz ", rdep); } print tmp[4] "-all: " me ".tgz"; print me ": " me ".tgz"; print me ".tgz: " bdep " " rdep; printf("\t@/var/portbuild/scripts/pdispatch ${branch} /var/portbuild/scripts/portbuild %s.tgz %s", me, here); if (bdep != "") printf(" %s", bdep); if (rdep != "") printf(" %s", rdep); printf("\n")}' < ${.CURDIR}/${INDEXFILE}

CVS?= cvs
.if defined(SUPHOST)
SUPFLAGS+=	-h ${SUPHOST}
.endif
update:
.if defined(SUP_UPDATE) && defined(PORTSSUPFILE)
	@echo "--------------------------------------------------------------"
	@echo ">>> Running ${SUP}"
	@echo "--------------------------------------------------------------"
	@${SUP} ${SUPFLAGS} ${PORTSSUPFILE}
.elif defined(CVS_UPDATE)
	@echo "--------------------------------------------------------------"
	@echo ">>> Updating ${.CURDIR} from cvs repository" ${CVSROOT}
	@echo "--------------------------------------------------------------"
	cd ${.CURDIR}; ${CVS} -q update -P -d
.elif defined(SUP_UPDATE) && !defined(PORTSSUPFILE)
	@${ECHO_MSG} "Error: Please define PORTSSUPFILE before doing make update."
	@exit 1
.else
	@${ECHO_MSG} "Error: Please define either SUP_UPDATE or CVS_UPDATE first."
.endif
