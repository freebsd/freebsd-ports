# New ports collection makefile for:   m17n-db
# Date created:                29 May 2004
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	m17n-db
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.m17n.org/m17n-lib/download/:m17n \
		${MASTER_SITE_GNU:S/$/:glibc/}
MASTER_SITE_SUBDIR=	glibc/:glibc
DISTFILES=	${M17N_DISTFILE}:m17n \
		${GLIBC_DISTFILE}:glibc
EXTRACT_ONLY=	${M17N_DISTFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data files for the m17n library

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-charmaps=${CHARMAPSDIR}

M17N_DISTFILE=	${DISTNAME}${EXTRACT_SUFX}
GLIBC_VERSION=	2.3.3
GLIBC_DISTFILE=	glibc-${GLIBC_VERSION}.tar.bz2
CHARMAPSDIR=	glibc-${GLIBC_VERSION}/localedata/charmaps

post-extract:
	cd ${WRKSRC}; ${TAR} xjf ${DISTDIR}/${GLIBC_DISTFILE} ${CHARMAPSDIR}

.include <bsd.port.mk>
