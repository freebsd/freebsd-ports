# $Id: Makefile,v 1.12 1995/03/21 01:46:29 jkh Exp $
#
SUBDIR= archivers audio cad comms databases devel editors games graphics \
	japanese lang mail math net news print shells utils x11

.include <bsd.port.subdir.mk>

index:	${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@make describe | sed -e '/===/D' > ${.CURDIR}/INDEX
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	awk -F@ '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\n\n", $$1, $$2, $$4); }' < ${.CURDIR}/INDEX
