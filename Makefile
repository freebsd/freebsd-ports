# $Id: Makefile,v 1.20 1995/07/13 00:57:24 asami Exp $
#

SUBDIR += archivers
SUBDIR += audio
SUBDIR += benchmarks
SUBDIR += cad
SUBDIR += comms
SUBDIR += databases
SUBDIR += devel
SUBDIR += editors
SUBDIR += emulators
SUBDIR += games
SUBDIR += graphics
SUBDIR += japanese
SUBDIR += lang
SUBDIR += mail
SUBDIR += math
SUBDIR += net
SUBDIR += news
SUBDIR += plan9
SUBDIR += print
SUBDIR += russian
SUBDIR += shells
SUBDIR += security
SUBDIR += sysutils
SUBDIR += utils
SUBDIR += x11

.include <bsd.port.subdir.mk>

index:
	@rm -f ${.CURDIR}/INDEX
	@make ${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@make describe ECHO_MSG="echo > /dev/null" > ${.CURDIR}/INDEX
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nKeywds:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8); }' < ${.CURDIR}/INDEX
