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
MASTER_SITES=	http://www.m-hollstein.de/libgxx/  \
		ftp://ftp.valinux.com/pub/support/hjl/  \
		ftp://egcs.cygnus.com/pub/gcc/infrastructure/  \
		ftp://ftp.iij.ad.jp/pub/egcs/infrastructure/  \
		ftp://ftp.ninemoons.com/pub/mirrors/egcs/infrastructure/  \
		${MASTER_SITE_GNU}

PATCH_SITES=	http://www.cygnus.com/~manfredh/libgxx/  \
PATCHFILES=	${DISTNAME}-20000312.diff.gz  \
		${DISTNAME}-20000419.diff.gz  \
		${DISTNAME}-20000816.diff.gz  \
		${DISTNAME}-20000914.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A libg++ container classes for EGCS and later versions of GCC

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR}

pre-configure:
	@${CP} -p ${FILESDIR}/Makefile.libg++ ${WRKSRC}/Makefile

.include <bsd.port.mk>
