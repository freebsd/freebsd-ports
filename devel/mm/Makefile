# New ports collection makefile for:   mm
# Date Created:			14 March 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	mm
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shared memory allocation library for pre-forked process models

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		mm-config.1
MAN3=		mm.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
