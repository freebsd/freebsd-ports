# New ports collection makefile for:	str
# Date Created:			09 Jan 2000
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	str
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/str/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic String Library

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		str-config.1
MAN3=		str.3

.include <bsd.port.pre.mk>

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
