# New ports collection makefile for:   pth
# Date Created:			17 Aug 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	pth
PORTVERSION=	1.4a1
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pth/ \
		ftp://ftp.engelschall.com/sw/pth/

MAINTAINER=	rse@engelschall.com

NO_LATEST_LINK=	yes
NO_CDROM=	yes

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
