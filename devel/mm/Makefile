# New ports collection makefile for:   mm
# Date Created:			14 March 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	mm
PORTVERSION=	1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/mm/ \
		ftp://ftp.engelschall.com/sw/mm/

MAINTAINER=	rse@engelschall.com

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		mm-config.1
MAN3=		mm.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
