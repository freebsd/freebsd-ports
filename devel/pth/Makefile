# New ports collection makefile for:   pth
# Version required:		1.0b7
# Date Created:			23 May 1999
# Whom:				Ralf S. Engelschall
#
# $Id: Makefile,v 1.20 1999/07/14 06:45:01 rse Exp $
#

DISTNAME=	pth-1.0b7
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/

MAINTAINER=	rse@engelschall.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-syscall-soft \
		--enable-batch

MAN1=		pth-config.1
MAN3=		pth.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
