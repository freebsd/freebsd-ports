# New ports collection makefile for:	hapy
# Date created:			Dec 24, 2003
# Whom:				rousskov
#
# $FreeBSD$
#

PORTNAME=	hapy
PORTVERSION=	0.0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Hapy-${PORTVERSION}

MAINTAINER=	rousskov@measurement-factory.com
COMMENT=	A runtime parser generator

GNU_CONFIGURE=	yes

post-build:
	@${ECHO_MSG} "Consider running 'make check' before 'make install'"
	@${ECHO_MSG} "to execute a library self-test"

check: build
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.mk>
