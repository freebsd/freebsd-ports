# New ports collection makefile for:    linux_locale
# Date created:         Apr 20 1999
# Whom:                 cjh@kr.freebsd.org
#
# $FreeBSD$
#

PORTNAME=	linux_locale
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	korean emulators linux
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	cjh@kr.freebsd.org
COMMENT=	Glibc 2.0 Korean locale for linux compatibility

BUILD_DEPENDS=  ${LINUXBASE}/usr/share/locale/ko:${PORTSDIR}/emulators/linux_base-8

ONLY_FOR_ARCHS=	i386

USE_LINUX_PREFIX=yes
USE_LINUX=	yes
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_FILTER_SHLIBS=	yes

do-install:
	@zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; ${PAX} -r)

.include <bsd.port.mk>
