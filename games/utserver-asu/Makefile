# New ports collection makefile for:	abfackelns Server Utilities for UT
# Date created:				Thu Oct 4 23:38:00 CEST 2001
# Whom:			Martin Matuska <matuska@wu-wien.ac.at>
#
# $FreeBSD$
#

PORTNAME=	asu
PORTVERSION=	0.4
PORTREVISION=	2
MASTER_SITES=	ftp://ftp.abfackeln.com/pub/linux/ut/
DISTFILES=	asu-${PORTVERSION}.tar.gz \
		asu-0.4-redirectfix-0.1-patch.tar.gz \
		CSHP-4+-patch.tar.gz
EXTRACT_ONLY=	asu-${PORTVERSION}.tar.gz

MAINTAINER=	matuska@wu-wien.ac.at

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/Abfackeln.com
DONT_USE_ZIP=	yes
DO_USE_WRKSUBDIR=	yes
EXECUTABLES=	pl

post-extract:
	@${GZIP_CMD} -9c ${FILESDIR}/ucc.init > ${WRKSRC}/Lib/ucc.init.gz
	@${RM} -f ${WRKSRC}/Patches/*
.for files in ${DISTFILES:S/${EXTRACT_ONLY}//}
	@${CP} -f ${DISTDIR}/${files} ${WRKSRC}/Patches
.endfor

post-patch:
	@${SED} -e "s|%%LINUXBASE%%|${LINUXBASE}|" \
		-e "s|%%UTDIR%%|${UTDIR}|" \
		${FILESDIR}/template-settings.ini > ${WRKSRC}/Lib/settings.ini

UT_MASTER_PORT=	${.CURDIR}/../utserver-to

.include "${UT_MASTER_PORT}/Makefile"
