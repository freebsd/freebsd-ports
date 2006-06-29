# New ports collection makefile for:    linux_locale
# Date created:         Apr 20 1999
# Whom:                 cjh@kr.freebsd.org
#
# $FreeBSD$
#

PORTNAME=	linux_locale
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	korean emulators linux
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	cjh@kr.freebsd.org
COMMENT=	Glibc 2.0 Korean locale for linux compatibility

BUILD_DEPENDS=  ${LINUX_BASE_PORT}

ONLY_FOR_ARCHS=	i386 amd64

CONFLICTS=	linux_base-fc*

DEPRECATED=	the dependency is scheduled for removal and a recent glib does not need this
EXPIRATION_DATE=2006-09-01

USE_LINUX=	8
USE_LINUX_PREFIX=yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; ${PAX} -r)

.include <bsd.port.mk>
