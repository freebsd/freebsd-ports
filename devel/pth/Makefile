# New ports collection makefile for:   pth
# Version required:		1.3.2
# Date Created:			23 May 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

DISTNAME=	pth-1.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.engelschall.com/sw/pth/
MASTER_SITE_SUBDIR=	pth

MAINTAINER=	rse@engelschall.com

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-pthread \
		--enable-syscall-soft \
		--enable-optimize \
		--enable-batch

MAN1=		pth-config.1 pthread-config.1
MAN3=		pth.3 pthread.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
