# ex:ts=8
# Ports collection makefile for:	GNU glib++
# Date created:				Wed, 23 Feb 2000
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

DISTNAME=	libg++-2.8.1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.valinux.com/pub/support/hjl/ \
		ftp://egcs.cygnus.com/pub/gcc/infrastructure/ \
		ftp://ftp.iij.ad.jp/pub/egcs/infrastructure/ \
		ftp://ftp.ninemoons.com/pub/mirrors/egcs/infrastructure/ \
		${MASTER_SITE_GNU}

MAINTAINER=	obrien@FreeBSD.org

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GCC28SUBDIR=${GCC28DIR}
USE_NEWGCC=	yes

pre-configure:
	@${CP} -p ${FILESDIR}/Makefile.libg++ ${WRKSRC}/Makefile

.include <bsd.port.mk>
