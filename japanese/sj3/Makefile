# New ports collection makefile for:	SJ3
# Date created:		18 Aug 1998
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sj3
PORTVERSION=	2.0.1.20
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sony.co.jp/pub/unsupported/src/ \
		ftp://ftp.cs.titech.ac.jp/pub/japanese/sj3/

MAINTAINER=	hidekazu@cs.titech.ac.jp

BUILD_DEPENDS=	xmkmf:${PORTSDIR}/x11/XFree86

MAN1=		sj3.1 sj3dic.1 sj3mkdic.1 sj3serv.1
MANLANG=	ja

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/sj3.sh

# This port requires xmkmf but installs in /usr/local
#
# NOTE : You must not use 'xmkmf -a', because the running 'make depend' caused a error.

do-configure:
	( cd $(WRKSRC) ; xmkmf ; make Makefiles )

post-install:
	if [ ! -f ${STARTUP_SCRIPT} ]; then 				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; 	\
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT}; 			\
		${ECHO} 'sj3=${PREFIX}/bin/sj3serv' >> ${STARTUP_SCRIPT} ; \
		${ECHO} 'if [ -f $$sj3 ]; then' >> ${STARTUP_SCRIPT} ;	\
		${ECHO} '     $$sj3' >> ${STARTUP_SCRIPT} ;		\
		${ECHO} "fi" >> ${STARTUP_SCRIPT} ;			\
		${CHMOD} 755 ${STARTUP_SCRIPT} ;				\
		${CHOWN} bin.bin ${STARTUP_SCRIPT};			\
	fi
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
