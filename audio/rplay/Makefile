# New ports collection makefile for:	rplay - Network audio player
# Date created:		16 March 1995
# Whom:			rmallory@csusb.edu
#
# $FreeBSD$
#

PORTNAME=	rplay
PORTVERSION=	3.2.0b6
CATEGORIES=	audio
MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	rmallory@csusb.edu

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		rplay.1 xrplay.1 rplayd.1 rptp.1
MAN5=		rplay.conf.5 rplay.hosts.5 rplay.servers.5

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/rplayd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/rplayd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/rplayd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/rplayd ] && ( ${PREFIX}/sbin/rplayd & ) && ${ECHO} -n ' rplayd'" >> ${PREFIX}/etc/rc.d/rplayd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/rplayd.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/rplay.hosts ]; then \
		${ECHO} localhost > ${PREFIX}/etc/rplay.hosts; \
	fi

.include <bsd.port.mk>
