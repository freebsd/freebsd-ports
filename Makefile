# $Id: Makefile,v 1.11 1995/03/16 00:12:23 asami Exp $
#
SUBDIR= archivers audio cad comms databases devel editors games graphics \
	japanese lang mail math net news print shells utils x11

.include <bsd.port.subdir.mk>

index:
	@echo -n "Generating INDEX - please wait.."
	@make describe > ${.CURDIR}/INDEX
	@echo " Done."
