# New ports collection makefile for:	modula-3-socks
# Date created:		31 Oct 1996
# Whom:			John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	modula-3-socks
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/socks/A.B9.06/
DISTNAME=	socks

MAINTAINER=	jdp@polstra.com

NO_WRKSUBDIR=	yes

MANCOMPRESSED=	yes
MAN1=		m3socks.1
MAN5=		m3socks.conf.5

libm3socks_files=	accept.c bind.c close.c connect.c dup.c dup2.c \
			gethostbyaddr.c gethostbyname.c getpeername.c \
			getsockname.c listen.c read.c recv.c recvfrom.c \
			select.c send.c sendto.c shutdown.c socket.c \
			socksconf.h wrap.h write.c

m3socks_files=		m3socks.sh m3socks.1 m3socks.conf.5

post-extract:
	@${CP} -p ${FILESDIR}/Makefile.top ${WRKSRC}/Makefile
	@test -d ${WRKSRC}/libm3socks || ${MKDIR} ${WRKSRC}/libm3socks
	@cd ${FILESDIR}; \
	    ${CP} -p Makefile.libm3socks ${WRKSRC}/libm3socks/Makefile; \
	    ${CP} -p ${libm3socks_files} ${WRKSRC}/libm3socks
	@test -d ${WRKSRC}/m3socks || ${MKDIR} ${WRKSRC}/m3socks
	@cd ${FILESDIR}; \
	    ${CP} -p Makefile.m3socks ${WRKSRC}/m3socks/Makefile; \
	    ${CP} -p ${m3socks_files} ${WRKSRC}/m3socks

pre-install:
	@cd ${PREFIX}/lib; \
	    test -d m3/FreeBSD2 || { \
		${MKDIR} m3/FreeBSD2; \
		${CHOWN} ${BINOWN}.${BINGRP} m3 m3/FreeBSD2; \
	    }

post-install:
	@if [ ! -f ${PREFIX}/etc/m3socks.conf ]; then \
	    ${ECHO_MSG} -n "Please create a configuration file in "; \
	    ${ECHO_MSG} "${PREFIX}/etc/m3socks.conf"; \
	    ${ECHO_MSG} "Read m3socks.conf(5) for details"; \
	fi

.include <bsd.port.mk>
