# New ports collection makefile for:	rpm2cpio
# Date created:		Sun Jul 18 21:51:23 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	rpm2cpio
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Convert .rpm files for extraction with /usr/bin/cpio, needs just perl

NO_WRKSUBDIR=	yes

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/rpm2cpio.pl

do-fetch:
	@${DO_NADA}

do-extract:
	@${MKDIR} ${WRKSRC}
	${PERL5} -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL}-;}" ${FILESDIR}/${PORTNAME} >${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}.pl

.include <bsd.port.mk>
