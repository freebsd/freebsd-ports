# $Id: Makefile,v 1.14 1995/03/21 03:57:19 jkh Exp $
#
SUBDIR= archivers audio cad comms databases devel editors games graphics \
	japanese lang mail math net news print shells utils x11

.include <bsd.port.subdir.mk>

index:	${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@make describe ECHO_MSG="echo > /dev/null" > ${.CURDIR}/INDEX
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\n\n", $$1, $$2, $$4, $$6); }' < ${.CURDIR}/INDEX
