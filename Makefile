# $Id: Makefile,v 1.16 1995/04/01 13:05:35 jkh Exp $
#
SUBDIR= archivers audio cad comms databases devel editors games graphics \
	japanese lang mail math net news print shells utils x11

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
