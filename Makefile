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
SUBDIR += ftp
SUBDIR += games
SUBDIR += german
SUBDIR += graphics
SUBDIR += irc
SUBDIR += japanese
SUBDIR += java
SUBDIR += korean
SUBDIR += lang
SUBDIR += mail
SUBDIR += math
SUBDIR += mbone
SUBDIR += misc
SUBDIR += net
SUBDIR += news
SUBDIR += palm
SUBDIR += print
SUBDIR += russian
SUBDIR += security
SUBDIR += shells
SUBDIR += sysutils
SUBDIR += textproc
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
	@rm -f ${.CURDIR}/INDEX
	@make ${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@make describe ECHO_MSG="echo > /dev/null" | \
		perl ${.CURDIR}/Tools/make_index > ${.CURDIR}/INDEX
.if !defined(INDEX_NOSORT)
	@sed -e 's./..g' ${.CURDIR}/INDEX | \
		sort -t '|' +1 -2 | \
		sed -e 's../.g' > ${.CURDIR}/INDEX.tmp
	@mv -f ${.CURDIR}/INDEX.tmp ${.CURDIR}/INDEX
.endif
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9); }' < ${.CURDIR}/INDEX

search:	${.CURDIR}/INDEX
.if !defined(key)
	@echo "The search target requires a keyword parameter,"
	@echo "e.g.: \"make search key=somekeyword\""
.else
	@grep -i "${key}" ${.CURDIR}/INDEX | awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9); }'
.endif

parallel: ${.CURDIR}/INDEX
.for dir in ${SUBDIR}
	@echo "all:: ${dir}-all"
.endfor
	@sed -e 's/|/.tgz|/' ${.CURDIR}/INDEX | awk -F '|' '{me=$$1; here=$$2; bdep=$$8; rdep=$$9; split(here, tmp, "/"); if (bdep != "") { gsub("$$", ".tgz", bdep); gsub(" ", ".tgz ", bdep); } if (rdep != "") { gsub("$$", ".tgz", rdep); gsub(" ", ".tgz ", rdep); } print tmp[4] "-all:: " me; print me ": " bdep " " rdep; printf("\t@/a/asami/portbuild/scripts/pdispatch /a/asami/portbuild/scripts/portbuild %s %s", me, here); if (bdep != "") printf(" %s", bdep); if (rdep != "") printf(" %s", rdep); printf("\n")}'

CVS?= cvs
update:
.if defined(SUP_UPDATE)
.if !defined(PORTSSUPFILE)
	@${ECHO_MSG} "Error: Please define PORTSSUPFILE before doing make update."
	@exit 1
.endif
	@echo "--------------------------------------------------------------"
	@echo ">>> Running ${SUP}"
	@echo "--------------------------------------------------------------"
	@${SUP} ${SUPFLAGS} ${PORTSSUPFILE}
.elif defined(CVS_UPDATE)
	@echo "--------------------------------------------------------------"
	@echo ">>> Updating ${.CURDIR} from cvs repository" ${CVSROOT}
	@echo "--------------------------------------------------------------"
	cd ${.CURDIR}; ${CVS} -q update -P -d
.else
	@${ECHO_MSG} "Error: Please define either SUP_UPDATE or CVS_UPDATE first."
.endif
