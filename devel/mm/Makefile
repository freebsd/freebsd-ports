# New ports collection makefile for:   mm
# Date Created:			14 March 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	mm
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Shared memory allocation library for pre-forked process models

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN1=		mm-config.1
MAN3=		mm.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
