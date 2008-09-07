# New ports collection makefile for:	linux-libmad
# Date created:		17 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmad
DISTVERSION=	0.15.1b-3.2
DISTVERSIONSUFFIX=	.${_LINUX_BASE_SUFFIX}
CATEGORIES=	audio linux
MASTER_SITES=	http://ftp.freshrpms.net/pub/freshrpms/%SUBDIR%/ \
		ftp://ftp.freshrpms.net/pub/freshrpms/%SUBDIR%/
MASTER_SITE_SUBDIR=	${LINUX_DIST}/linux/${LINUX_DIST_VER}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libmad library (part of MAD project)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-extract:
	@${RM} -rf ${WRKDIR}/usr/share

.include <bsd.port.mk>
