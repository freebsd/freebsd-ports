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
MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/infrastructure/ \
		ftp://gatekeeper.dec.com/pub/GNU/

PATCH_SITES=	ftp://gcc.gnu.org/pub/gcc/infrastructure/ \
		http://people.redhat.com/manfredh/libgxx/
PATCHFILES=	${DISTNAME}-20000312.diff.gz  \
		${DISTNAME}-20000419.diff.gz  \
		${DISTNAME}-20000816.diff.gz  \
		${DISTNAME}-20000914.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR}

pre-configure:
	@${CP} -p ${FILESDIR}/Makefile.libg++ ${WRKSRC}/Makefile

.include <bsd.port.mk>
