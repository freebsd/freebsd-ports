# New ports collection makefile for:	rpm2cpio
# Date created:		Sun Jul 18 21:51:23 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	rpm2cpio
PORTVERSION=	1.1.20020306
CATEGORIES=	archivers
MASTER_SITES=	http://www.iagora.com/~espel/
DISTFILES=	${PORTNAME}

MAINTAINER=	nox@jelal.kn-bremen.de

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

USE_PERL5=	yes

do-build:
	${PERL5} -i.bak -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL}-;}" ${WRKDIR}/rpm2cpio

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin

.include <bsd.port.mk>
