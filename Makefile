# $Id: Makefile,v 1.10 1995/01/23 01:30:57 jkh Exp $
#
SUBDIR= archivers audio cad comms databases devel editors games graphics \
	japanese lang mail math net news print shells utils x11

.include <bsd.port.subdir.mk>

index:
	@echo -n "Generating INDEX - please wait.."
	@make describe | sed -e '/===/D' -e 's;${.CURDIR}/;;' \
		| expand -40 > ${.CURDIR}/INDEX
	@echo " Done."
