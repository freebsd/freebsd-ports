# New ports collection makefile for:	str
# Date Created:			09 Jan 2000
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	str
PORTVERSION=	0.9.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic String Library

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

MAN1=		str-config.1
MAN3=		str.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
