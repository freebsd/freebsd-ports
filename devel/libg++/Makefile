# ex:ts=8
# Ports collection makefile for:	GNU glib++
# Date created:				Wed, 23 Feb 2000
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	libg++
PORTVERSION=	2.8.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC} \
		ftp://gatekeeper.dec.com/pub/GNU/
MASTER_SITE_SUBDIR=infrastructure

PATCH_SITES=	${MASTER_SITE_GCC} \
		http://people.redhat.com/manfredh/libgxx/
PATCH_SITE_SUBDIR=infrastructure
PATCHFILES=	${DISTNAME}-20000312.diff.gz  \
		${DISTNAME}-20000419.diff.gz  \
		${DISTNAME}-20000816.diff.gz  \
		${DISTNAME}-20000914.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A libg++ container classes for EGCS and later versions of GCC

USE_GCC=	2.95
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR}

pre-configure:
	@${CP} -p ${FILESDIR}/Makefile.libg++ ${WRKSRC}/Makefile

.include <bsd.port.mk>
