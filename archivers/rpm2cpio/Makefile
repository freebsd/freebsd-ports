# New ports collection makefile for:	rpm2cpio
# Version required:	#no version#
# Date created:		Sun Jul 18 21:51:23 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/
EXTRACT_SUFX=

MAINTAINER=	nox@jelal.kn-bremen.de

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

USE_PERL5=	yes

do-build:
	${PERL5} -i.bak -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL}-;}" ${WRKDIR}/rpm2cpio

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin

.include <bsd.port.mk>
