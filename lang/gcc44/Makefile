# New ports collection makefile for:	egcs
# Version required:	1.0.1
# Date created:		9 Jan 1998
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.2 1998/01/13 05:18:16 asami Exp $
#

DISTNAME=	egcs-1.0.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cygnus.com/pub/egcs/releases/egcs-1.0.1/ \
		ftp://cambridge.cygnus.com/pub/egcs/releases/egcs-1.0.1/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/egcs-1.0.1/

MAINTAINER=	jdp@polstra.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386-unknown-freebsd
MAN1=		cccp.1 g++.1 g77.1 gcc.1

FME=${PREFIX}

post-install:
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ ${PREFIX}/bin/c++ \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.23/cc1 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.23/cc1obj \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.23/cc1plus \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.23/cpp \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.23/f771 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/egcs-2.90.23/ld ; \
		do strip $$prog ; \
		done)
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
