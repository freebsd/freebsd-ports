# New ports collection makefile for:	rplay - Network audio player   
# Version required:     3.2.0b6
# Date created:		16 March 1995  
# Whom:			rmallory@csusb.edu
#
# $Id: Makefile,v 1.9 1998/01/21 20:02:07 fenner Exp $
#

DISTNAME=       rplay-3.2.0b6
CATEGORIES=	audio
MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	rmallory@csusb.edu

LIB_DEPENDS=    gsm.1:${PORTSDIR}/audio/gsm

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=           rplay.1 xrplay.1 rplayd.1 rptp.1
MAN5=		rplay.conf.5 rplay.hosts.5 rplay.servers.5

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/rplayd.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/rplayd.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/rplayd.sh; \
		echo "[ -x /usr/local/sbin/rplayd ] && ( /usr/local/sbin/rplayd & ) && echo -n ' rplayd'" >> ${PREFIX}/etc/rc.d/rplayd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/rplayd.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/rplay.hosts ]; then \
		echo localhost > ${PREFIX}/etc/rplay.hosts; \
	fi

.include <bsd.port.mk>
