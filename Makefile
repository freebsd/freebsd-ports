# $Id: Makefile,v 1.8 1995/01/14 11:27:06 jkh Exp $
#
SUBDIR= archivers audio cad comms databases devel editors games graphics \
	lang mail math net news print shells utils x11

.include <bsd.port.subdir.mk>

index:
	@echo -n "Generating INDEX - please wait.."
	@make describe | sed -e '/===/D' -e 's;/usr/ports/;;' \
		| expand -40 > ${.CURDIR}/INDEX
	@echo " Done."
