# $Id: Makefile,v 1.44 1999/01/13 04:08:05 jkh Exp $
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
SUBDIR += games
SUBDIR += german
SUBDIR += graphics
SUBDIR += japanese
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
		perl ${.CURDIR}/templates/make_index > ${.CURDIR}/INDEX
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
