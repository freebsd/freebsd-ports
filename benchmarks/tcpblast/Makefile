# New ports collection makefile for:	tcpblast
# Version required:	<self contained>
# Date created:		22 August 1994
# Whom:			mr
#
# $Id: Makefile,v 1.2 1994/09/13 06:34:56 jkh Exp $
#

DISTNAME=	tcpblast
NO_EXTRACT=	yes
CONFIGURE_COOKIE=  ${.CURDIR}/.configure_done
INSTALL_COOKIE=    ${.CURDIR}/.install_done
BUILD_COOKIE=      ${.CURDIR}/.build_done

pre-clean:
	@echo "===>  Pre-clean for ${DISTNAME}"
	@(cd ${.CURDIR}/src; make clean)

.include <bsd.port.mk>
