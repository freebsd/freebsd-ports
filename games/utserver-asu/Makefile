# New ports collection makefile for:	abfackelns Server Utilities for UT
# Date created:				Thu Oct 4 23:38:00 CEST 2001
# Whom:			Martin Matuska <matuska@wu-wien.ac.at>
#
# $FreeBSD$
#

PORTNAME=	asu
PORTVERSION=	0.4
MASTER_SITES=	ftp://ftp.abfackeln.com/pub/linux/ut/
DISTNAME=	asu-${PORTVERSION}

MAINTAINER=	matuska@wu-wien.ac.at

WRKSRC=		${WRKDIR}/Abfackeln.com
DONT_USE_ZIP=	yes
DO_USE_WRKSUBDIR=	yes
EXECUTABLES=	pl	

post-patch:
	@${SED} -e "s|%%LINUXBASE%%|${LINUXBASE}|" \
		-e "s|%%UTDIR%%|${UTDIR}|" \
		${FILESDIR}/template-settings.ini > ${WRKSRC}/Lib/settings.ini

UT_MASTER_PORT=	${.CURDIR}/../utserver-to

.include "${UT_MASTER_PORT}/Makefile"
