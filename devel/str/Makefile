# New ports collection makefile for:	str
# Date Created:			09 Jan 2000
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	str
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/str/ \
		ftp://ftp.engelschall.com/sw/str/

MAINTAINER=	rse@engelschall.com

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		str-config.1
MAN3=		str.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
