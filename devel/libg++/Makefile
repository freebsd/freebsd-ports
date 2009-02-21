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

DEPRECATED=	unmaintained, does not work with current versions of GCC, needs gcc295 which has been failing to build for months
EXPIRATION_DATE=2009-03-22

USE_GCC=	2.95
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR}

pre-configure:
	@${CP} -p ${FILESDIR}/Makefile.libg++ ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
