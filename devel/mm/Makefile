# New ports collection makefile for:   mm
# Version required:		1.0.6
# Date Created:			14 March 1999
# Whom:				Ralf S. Engelschall
#
# $Id: Makefile,v 1.8 1999/06/02 12:32:47 rse Exp $
#

DISTNAME=	mm-1.0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/mm/ \
		ftp://ftp.engelschall.com/sw/mm/

MAINTAINER=	rse@engelschall.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		mm-config.1
MAN3=		mm.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
