# New ports collection makefile for:   nps
# Version required:		1.0b1
# Date Created:			23 May 1999
# Whom:				Ralf S. Engelschall
#
# $Id: Makefile,v 1.14 1999/06/26 13:57:48 rse Exp $
#

DISTNAME=	nps-1.0b1
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/nps/ \
		ftp://ftp.engelschall.com/sw/nps/

MAINTAINER=	rse@engelschall.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-batch

MAN1=		nps-config.1
MAN3=		nps.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
