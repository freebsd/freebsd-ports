# New ports collection makefile for:	abfackelns Server Utilities for UT
# Date created:				Thu Oct 4 23:38:00 CEST 2001
# Whom:			Martin Matuska <martin@tradex.sk>
#
# $FreeBSD$
#

PORTNAME=	asu
PORTVERSION=	0.5
MASTER_SITES=	ftp://ftp.abfackeln.com/pub/linux/ut/asu/
DISTNAME=	asu-${PORTVERSION}

MAINTAINER=	martin@tradex.sk

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
DONT_USE_ZIP=	yes
DO_USE_WRKSUBDIR=	yes
EXECUTABLES=	pl

post-extract:
	@${GZIP_CMD} -c ${FILESDIR}/ucc.init > ${WRKSRC}/ASU/ucc.init.gz

post-patch:
	@${SED} -e "s|%%LINUXBASE%%|${LINUXBASE}|" \
		-e "s|%%UTDIR%%|${UTDIR}|" \
		${FILESDIR}/template-settings.ini > ${WRKSRC}/ASU/settings.ini

UT_MASTER_PORT=	${.CURDIR}/../utserver-to

.include "${UT_MASTER_PORT}/Makefile"
