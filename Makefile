# $Id: Makefile,v 1.7 1994/10/06 01:41:37 jkh Exp $
#
SUBDIR=	audio comms devel editors games lang mail math net news print \
	shells utils x11

.include <bsd.port.subdir.mk>

index:
	@echo -n "Generating INDEX - please wait.."
	@make describe | sed -e '/===/D' -e 's;/usr/ports/;;' \
		| expand -40 > ${.CURDIR}/INDEX
	@echo " Done."
